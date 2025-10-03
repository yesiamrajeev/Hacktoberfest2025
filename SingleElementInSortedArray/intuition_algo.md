# Single Element in a Sorted Array  

## 🧠 Intuition  
We are given a **sorted array** where every element appears exactly **twice**, except for **one element** that appears only once.  

Key observations:  
1. Since the array is sorted, duplicate elements will always appear **in pairs**.  
2. Before the unique element, the **first element of the pair** will appear at an **even index**, and the **second element** will appear at an **odd index**.  
   - Example: `[1, 1, 2, 2, 3, ...]` → `(0,1), (2,3), ...`  
3. After the unique element, this pattern **breaks**.  
   - Example: `[1, 1, 2, 3, 3, ...]` → At index 2 (even), `2` does **not** have its pair next.  

Using this property, we can apply **binary search** to efficiently find the single element in **O(log n)** time.  

---

## ⚙️ Algorithm  

1. **Handle edge cases**:  
   - If the array has only **one element**, return it.  
   - If the unique element is at the **start** or **end**, check the first/last two elements.  

2. **Binary Search**:  
   - Initialize `start = 1`, `end = n-2`.  
   - While `start <= end`:  
     - Find `mid = (start + end) / 2`.  
     - If `nums[mid]` is **not equal** to both neighbors, it’s the unique element.  
     - Otherwise, check parity (`mid % 2`) to decide the search direction:  
       - If `(mid is even and nums[mid] == nums[mid+1])` OR `(mid is odd and nums[mid] == nums[mid-1])`, then the unique element lies on the **right half** → `start = mid + 1`.  
       - Else, search in the **left half** → `end = mid - 1`.  

3. Return the found element.  

---

## ⏱️ Time and Space Complexity  
- **Time Complexity**: `O(log n)` (binary search)  
- **Space Complexity**: `O(1)` (constant extra space)  

---