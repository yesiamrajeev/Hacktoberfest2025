# LeetCode 2149: Rearrange Array Elements by Sign
# Problem Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
# Author: Daddy-Myth

from typing import List

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        """
        Rearranges the input array so that:
        1. Every consecutive pair of numbers have opposite signs.
        2. Relative order of positive and negative numbers is preserved.
        3. Array starts with a positive integer.

        Approach:
        - Separate positive and negative numbers into separate stacks.
        - Pop from each stack and append alternately to the final array.
        """
        arrF = []  # final array
        ptv = []   # stack for positive numbers
        ntv = []   # stack for negative numbers

        # Separate numbers into positive and negative stacks (reversed to preserve order)
        for i in nums[::-1]:
            if i > 0:
                ptv.append(i)
            else:
                ntv.append(i)

        # Build final array by popping from each stack alternately
        while ptv and ntv:
            arrF.append(ptv.pop())
            arrF.append(ntv.pop())

        return arrF

# Quick test
if __name__ == "__main__":
    s = Solution()
    print(s.rearrangeArray([3,1,-2,-5,2,-4]))  # expected: [3,-2,1,-5,2,-4]
