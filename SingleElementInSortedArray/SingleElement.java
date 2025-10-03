public class SingleElement {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        
        // Case 1: Only one element in array
        if (n == 1) {
            return nums[0];
        }
        
        // Case 2: Unique element is at the beginning
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        
        // Case 3: Unique element is at the end
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        // Binary search in between
        int start = 1;
        int end = n - 2;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // If nums[mid] is the unique element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            
            // If mid is even and matches with next OR mid is odd and matches with previous,
            // then unique element lies on the right half
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                start = mid + 1;
            } 
            // Otherwise, it lies on the left half
            else {
                end = mid - 1;
            }
        }
        return -1; // This case won't occur as per problem constraints
    }

    // Main method to test
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
        int[] nums2 = {3, 3, 7, 7, 10, 11, 11};
        int[] nums3 = {5};
        
        System.out.println("Unique element in nums1: " + sol.singleNonDuplicate(nums1)); // Output: 2
        System.out.println("Unique element in nums2: " + sol.singleNonDuplicate(nums2)); // Output: 10
        System.out.println("Unique element in nums3: " + sol.singleNonDuplicate(nums3)); // Output: 5
    }
}
