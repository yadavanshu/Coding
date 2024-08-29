import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("File Compression and Decompression");
        System.out.println("1. Compress a File");
        System.out.println("2. Decompress a File");
        System.out.print("Choose an option: ");
        int choice = scanner.nextInt();

        scanner.nextLine(); // Consume the newline

        // Read paths from environment variables
        String inputFile = System.getenv("INPUT_FILE");
        String outputFile = System.getenv("OUTPUT_FILE");

        switch (choice) {
            case 1:
                if (inputFile != null && outputFile != null) {
                    FileCompressor.compressFile(inputFile, outputFile);
                } else {
                    System.out.println("Please set INPUT_FILE and OUTPUT_FILE environment variables.");
                }
                break;
            case 2:
                if (inputFile != null && outputFile != null) {
                    FileDecompressor.decompressFile(inputFile, outputFile);
                } else {
                    System.out.println("Please set INPUT_FILE and OUTPUT_FILE environment variables.");
                }
                break;
            default:
                System.out.println("Invalid option.");
        }

        scanner.close();
    }
}
