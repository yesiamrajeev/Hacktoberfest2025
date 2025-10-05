import java.util.Scanner;

/**
 * Selection Sort Algorithm Implementation
 * 
 * Selection Sort is a simple sorting algorithm that divides the input list into two parts:
 * a sorted portion at the left end and an unsorted portion at the right end.
 * Initially, the sorted portion is empty and the unsorted portion is the entire list.
 * The algorithm proceeds by finding the smallest element in the unsorted portion,
 * exchanging it with the leftmost unsorted element, and moving the subarray boundaries one element to the right.
 * 
 * Time Complexity: O(n²) - in all cases (best, average, and worst)
 * Space Complexity: O(1) - in-place sorting algorithm
 * 
 * @author Sourav Saha (yashsaha555)
 */
public class SelectionSort {
    
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
     * Sorts the array using Selection Sort algorithm
     * @param arr the array to be sorted
     */
    void sort(int[] arr) {
        int n = arr.length;
        
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            
            // Swap the found minimum element with the first element
            if (minIndex != i) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
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
            SelectionSort sorter = new SelectionSort();
            
            sorter.initialize(arr);
            System.out.println("Before sorting:");
            sorter.display(arr);
            
            sorter.sort(arr);
            System.out.println("After sorting:");
            sorter.display(arr);
        }
    }

    public static void main(String[] args) {
        // Default demonstration with fixed array
        System.out.println("=== Selection Sort Demo ===");
        int[] arr = {64, 25, 12, 22, 11};
        SelectionSort sorter = new SelectionSort();
        
        System.out.println("Before sorting:");
        sorter.display(arr);
        
        sorter.sort(arr);
        System.out.println("After sorting:");
        sorter.display(arr);
        
        System.out.println("\n=== Custom Size Demo ===");
        demonstrateWithCustomSize();
    }
}
