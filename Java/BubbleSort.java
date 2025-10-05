import java.util.Scanner;

/**
 * Bubble Sort Algorithm Implementation
 * 
 * Bubble Sort is a simple sorting algorithm that repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * 
 * Time Complexity: O(n²) - worst and average case, O(n) - best case (optimized version)
 * Space Complexity: O(1) - in-place sorting algorithm
 * 
 * @author Sourav Saha (yashsaha555)
 */
public class BubbleSort {
    
    /**
     * Initializes the array with user input
     * @param arr the array to be initialized
     */
    void initialize(int[] arr) {
        System.out.println("Enter " + arr.length + " array elements:");
        try (Scanner scanner = new Scanner(System.in)) {
            for (int i = 0; i < arr.length; i++) {
                arr[i] = scanner.nextInt();
            }
        }
    }

    /**
     * Displays the array elements
     * @param arr the array to be displayed
     */
    void display(int[] arr) {
        System.out.println("Array elements:");
        for (int element : arr) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    /**
     * Sorts the array using Bubble Sort algorithm
     * @param arr the array to be sorted
     */
    void sort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        
        // Traverse through all array elements
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            
            // Last i elements are already in place
            for (int j = 0; j < n - 1 - i; j++) {
                // Traverse the array from 0 to n-i-1
                // Swap if the element found is greater than the next element
                if (arr[j] > arr[j + 1]) {
                    // Standard swap using temporary variable
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            
            // If no two elements were swapped in inner loop, array is sorted
            if (!swapped) {
                break;
            }
        }
    }

    /**
     * Alternative implementation with array size input
     */
    public static void demonstrateWithCustomSize() {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the size of array: ");
            int size = scanner.nextInt();
            
            if (size <= 0) {
                System.out.println("Invalid array size!");
                return;
            }
            
            int[] arr = new int[size];
            BubbleSort sorter = new BubbleSort();
            
            sorter.initialize(arr);
            System.out.println("Before sorting:");
            sorter.display(arr);
            
            sorter.sort(arr);
            System.out.println("After sorting:");
            sorter.display(arr);
        }
    }

    public static void main(String[] args) {
        // Default demonstration with fixed size
        System.out.println("=== Bubble Sort Demo ===");
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        BubbleSort sorter = new BubbleSort();
        
        System.out.println("Before sorting:");
        sorter.display(arr);
        
        sorter.sort(arr);
        System.out.println("After sorting:");
        sorter.display(arr);
        
        System.out.println("\n=== Custom Size Demo ===");
        demonstrateWithCustomSize();
    }
}