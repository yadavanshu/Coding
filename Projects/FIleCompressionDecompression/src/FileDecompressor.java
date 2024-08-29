import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.GZIPInputStream;

public class FileDecompressor {

    // Method to decompress a GZIP file
    public static void decompressFile(String compressedFile, String destinationFile) {
        try (FileInputStream fis = new FileInputStream(compressedFile);
                GZIPInputStream gzipIS = new GZIPInputStream(fis);
                FileOutputStream fos = new FileOutputStream(destinationFile)) {

            byte[] buffer = new byte[1024];
            int len;
            while ((len = gzipIS.read(buffer)) != -1) {
                fos.write(buffer, 0, len);
            }

            System.out.println("File decompressed successfully: " + destinationFile);
        } catch (IOException e) {
            System.err.println("Error decompressing file: " + e.getMessage());
        }
    }
}
