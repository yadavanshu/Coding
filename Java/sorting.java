import java.util.*;
public class sorting {

    static void swap(int arr[], int a, int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }


    static void bubblesort(int [] arr){
        for(int i=0;i<arr.length-1;i++){
            boolean flag = false;
            for(int j=i;j<arr.length;j++){
                if(arr[j]<arr[i]){
                    swap(arr,i,j);
                    flag=true;
                }
            }
            if(!flag) break;
        }
    }
    public static void main(String[] args) {
        int[] arr = {45, 23, 67, 12, 89, 34, 56, 78, 9, 41, 55, 88, 22, 37, 61, 19, 73, 85, 29, 50};
        System.out.println("Before Sorting: ");
        for (int i : arr) {
            System.err.print(i+" ");
        }
        bubblesort(arr);
        System.out.println();
        System.out.println("After Sorting: ");
        for (int i : arr) {
            System.err.print(i+" ");
        }
        
    }
}