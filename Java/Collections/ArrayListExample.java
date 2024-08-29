package Java.Collections;
import java.util.ArrayList;
import java.util.Scanner;

class ArrayListExample {
    public static void main(String[] args)
    {
        int n = 5;
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> arr1 = new ArrayList<Integer>(n);

        ArrayList<Integer> arr2 = new ArrayList<Integer>();

        System.out.println("Array 1:" + arr1);
        System.out.println("Array 2:" + arr2);


        for (int i = 1; i <= n; i++) {
            // int value = sc.nextInt();
            arr1.add(i);
            arr2.add(i);
        }

        // Printing the ArrayList
        System.out.println("Array 1:" + arr1);
        System.out.println("Array 2:" + arr2);
    }
}