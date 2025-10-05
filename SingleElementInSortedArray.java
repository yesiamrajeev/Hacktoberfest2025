public class SingleElementInSortedArray {
    public int singleNonDuplicate(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) {
                mid--;
            }

            // Check pair
            if (nums[mid] == nums[mid + 1]) {
                // Single element lies on the right side
                left = mid + 2;
            } else {
                // Single element lies on the left side
                right = mid;
            }
        }

        // Left will point to the single element
        return nums[left];
    }

    // Main method for testing
    public static void main(String[] args) {
        SingleElementInSortedArray solution = new SingleElementInSortedArray();
        int[] nums = {1,1,2,3,3,4,4,8,8};
        System.out.println(solution.singleNonDuplicate(nums)); // Output: 2
    }
}
