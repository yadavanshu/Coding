#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <vector>
#include <cstring>

namespace fs = std::filesystem;

constexpr size_t SHA1_BLOCK_SIZE = 64;
constexpr size_t SHA1_DIGEST_SIZE = 20;

struct SHA1
{
    uint32_t h[5];
    uint64_t length;
    uint8_t buffer[SHA1_BLOCK_SIZE];
    size_t buffer_size;

    SHA1() : length(0), buffer_size(0)
    {
        h[0] = 0x67452301;
        h[1] = 0xEFCDAB89;
        h[2] = 0x98BADCFE;
        h[3] = 0x10325476;
        h[4] = 0xC3D2E1F0;
    }

    void process(const uint8_t *data, size_t length);
    void finalize(uint8_t hash[SHA1_DIGEST_SIZE]);
    void update(const uint8_t *data, size_t length);
};

void SHA1::process(const uint8_t *data, size_t length)
{
    // Process the data in 512-bit (64-byte) chunks
    const uint32_t K[] = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};
    uint32_t W[80];
    uint32_t a, b, c, d, e;

    size_t i = 0;
    while (length >= SHA1_BLOCK_SIZE)
    {
        // Copy the block into W
        for (i = 0; i < 16; ++i)
        {
            W[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
                   (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
        }

        for (i = 16; i < 80; ++i)
        {
            W[i] = (W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16]);
            W[i] = (W[i] << 1) | (W[i] >> 31);
        }

        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];

        for (i = 0; i < 80; ++i)
        {
            uint32_t temp = (a << 5) | (a >> 27);
            if (i < 20)
            {
                temp += ((b & c) | (~b & d)) + e + W[i] + K[0];
            }
            else if (i < 40)
            {
                temp += (b ^ c ^ d) + e + W[i] + K[1];
            }
            else if (i < 60)
            {
                temp += ((b & c) | (b & d) | (c & d)) + e + W[i] + K[2];
            }
            else
            {
                temp += (b ^ c ^ d) + e + W[i] + K[3];
            }

            e = d;
            d = c;
            c = (b << 30) | (b >> 2);
            b = a;
            a = temp;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;

        data += SHA1_BLOCK_SIZE;
        length -= SHA1_BLOCK_SIZE;
    }
}

void SHA1::update(const uint8_t *data, size_t length)
{
    size_t remaining = SHA1_BLOCK_SIZE - buffer_size;
    if (length < remaining)
    {
        std::memcpy(buffer + buffer_size, data, length);
        buffer_size += length;
        return;
    }

    std::memcpy(buffer + buffer_size, data, remaining);
    process(buffer, SHA1_BLOCK_SIZE);
    data += remaining;
    length -= remaining;
    buffer_size = 0;

    while (length >= SHA1_BLOCK_SIZE)
    {
        process(data, SHA1_BLOCK_SIZE);
        data += SHA1_BLOCK_SIZE;
        length -= SHA1_BLOCK_SIZE;
    }

    std::memcpy(buffer, data, length);
    buffer_size = length;
    this->length += length;
}

void SHA1::finalize(uint8_t hash[SHA1_DIGEST_SIZE])
{
    uint8_t final[SHA1_BLOCK_SIZE];
    std::memset(final, 0, SHA1_BLOCK_SIZE);
    size_t final_size = buffer_size;
    buffer[buffer_size++] = 0x80;

    if (buffer_size > 56)
    {
        process(buffer, buffer_size);
        std::memset(buffer, 0, SHA1_BLOCK_SIZE);
        buffer_size = 0;
    }

    uint64_t length_bits = this->length * 8;
    buffer[56] = (length_bits >> 56) & 0xFF;
    buffer[57] = (length_bits >> 48) & 0xFF;
    buffer[58] = (length_bits >> 40) & 0xFF;
    buffer[59] = (length_bits >> 32) & 0xFF;
    buffer[60] = (length_bits >> 24) & 0xFF;
    buffer[61] = (length_bits >> 16) & 0xFF;
    buffer[62] = (length_bits >> 8) & 0xFF;
    buffer[63] = length_bits & 0xFF;

    process(buffer, SHA1_BLOCK_SIZE);

    for (size_t i = 0; i < SHA1_DIGEST_SIZE; ++i)
    {
        hash[i] = (h[i / 4] >> (24 - (i % 4) * 8)) & 0xFF;
    }
}

// Convert hash to a hexadecimal string
std::string toHexString(const uint8_t *data, size_t length)
{
    std::stringstream ss;
    for (size_t i = 0; i < length; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
    }
    return ss.str();
}

std::string computeFileHash(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    SHA1 sha1;
    std::vector<uint8_t> buffer(8192);
    while (file.read(reinterpret_cast<char *>(buffer.data()), buffer.size()))
    {
        sha1.update(buffer.data(), file.gcount());
    }
    sha1.update(buffer.data(), file.gcount());

    uint8_t hash[SHA1_DIGEST_SIZE];
    sha1.finalize(hash);
    return toHexString(hash, SHA1_DIGEST_SIZE);
}

std::unordered_map<std::string, std::string> loadHashes(const std::string &filePath)
{
    std::unordered_map<std::string, std::string> hashes;
    std::ifstream file(filePath);
    if (!file)
    {
        return hashes; // File does not exist yet
    }

    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find(' ');
        if (pos != std::string::npos)
        {
            std::string filePath = line.substr(0, pos);
            std::string fileHash = line.substr(pos + 1);
            hashes[filePath] = fileHash;
        }
    }
    return hashes;
}

void saveHashes(const std::unordered_map<std::string, std::string> &hashes, const std::string &filePath)
{
    std::ofstream file(filePath);
    for (const auto &[path, hash] : hashes)
    {
        file << path << ' ' << hash << '\n';
    }
}

void compareHashes(const std::unordered_map<std::string, std::string> &oldHashes, const std::unordered_map<std::string, std::string> &newHashes)
{
    // Check for added or modified files
    for (const auto &[path, newHash] : newHashes)
    {
        auto it = oldHashes.find(path);
        if (it == oldHashes.end())
        {
            std::cout << "New file added: " << path << '\n';
        }
        else if (it->second != newHash)
        {
            std::cout << "File modified: " << path << '\n';
        }
    }

    // Check for deleted files
    for (const auto &[path, oldHash] : oldHashes)
    {
        if (newHashes.find(path) == newHashes.end())
        {
            std::cout << "File deleted: " << path << '\n';
        }
    }
}

int main()
{
    const std::string oldHashesFile = "old_hashes.txt";
    const std::string newHashesFile = "new_hashes.txt";

    std::unordered_map<std::string, std::string> oldHashes = loadHashes(oldHashesFile);
    std::unordered_map<std::string, std::string> newHashes;

    // Traverse current directory and compute hashes
    for (const auto &entry : fs::recursive_directory_iterator(fs::current_path()))
    {
        if (fs::is_regular_file(entry.status()))
        {
            try
            {
                std::string filePath = entry.path().string();
                std::string fileHash = computeFileHash(filePath);
                newHashes[filePath] = fileHash;
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "Error processing file: " << e.what() << '\n';
            }
        }
    }

    // Compare old and new hashes
    compareHashes(oldHashes, newHashes);

    // Save the current state
    saveHashes(newHashes, oldHashesFile);

    return 0;
}
