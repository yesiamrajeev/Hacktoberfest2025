"""
Heap Sort Algorithm Implementation in Python
Time Complexity: O(n log n)
Space Complexity: O(1)

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.
It divides the input into a sorted and unsorted region, and iteratively shrinks the 
unsorted region by extracting the largest element and moving it to the sorted region.
"""

def heapify(arr, n, i):
    """
    To heapify a subtree rooted with node i which is an index in arr[].
    n is size of heap
    """
    largest = i  # Initialize largest as root
    left = 2 * i + 1     # left = 2*i + 1
    right = 2 * i + 2     # right = 2*i + 2

    # See if left child of root exists and is greater than root
    if left < n and arr[largest] < arr[left]:
        largest = left

    # See if right child of root exists and is greater than root
    if right < n and arr[largest] < arr[right]:
        largest = right

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap

        # Heapify the root.
        heapify(arr, n, largest)


def heap_sort(arr):
    """
    Main function to do heap sort
    """
    n = len(arr)

    # Build a maxheap.
    # Since last parent will be at ((n//2)-1) we can start at that location.
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # One by one extract elements
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]   # swap
        heapify(arr, i, 0)

    return arr


def print_array(arr):
    """Helper function to print array"""
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()


# Example usage and test cases
if __name__ == "__main__":
    # Test case 1: Random array
    print("=== Heap Sort Algorithm ===")
    test_arr1 = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", test_arr1)
    
    sorted_arr1 = heap_sort(test_arr1.copy())
    print("Sorted array:  ", sorted_arr1)
    
    # Test case 2: Already sorted array
    test_arr2 = [1, 2, 3, 4, 5]
    print("\nAlready sorted array:", test_arr2)
    sorted_arr2 = heap_sort(test_arr2.copy())
    print("After heap sort:     ", sorted_arr2)
    
    # Test case 3: Reverse sorted array
    test_arr3 = [5, 4, 3, 2, 1]
    print("\nReverse sorted array:", test_arr3)
    sorted_arr3 = heap_sort(test_arr3.copy())
    print("After heap sort:     ", sorted_arr3)
    
    # Test case 4: Array with duplicates
    test_arr4 = [3, 7, 8, 5, 2, 1, 9, 5, 4]
    print("\nArray with duplicates:", test_arr4)
    sorted_arr4 = heap_sort(test_arr4.copy())
    print("After heap sort:      ", sorted_arr4)
    
    print("\n✨ Heap Sort completed successfully! ✨")