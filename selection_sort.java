
import java.io.*;
public class selection_sort
{
    void sort(int arr[])
    {
        int n = arr.length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    // Prints the array
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    // Driver code to test above
    public static void main(String args[])
    {
        selection_sort ob = new selection_sort();
        int arr[] = {64,25,12,22,11};

        System.out.println("Given Array:");
        printArray(arr);

        long start = System.nanoTime();
        System.out.println(start);
        ob.sort(arr);

        System.out.println();

        System.out.println("Sorted array:");
        printArray(arr);

        long end = System.nanoTime();
        System.out.println(end);
    }
}