/**
 * Segment Tree Implementation in C++
 * 
 * Segment Tree is a tree data structure used for storing information about intervals or segments.
 * It allows answering range queries over an array efficiently, while still being flexible 
 * enough to allow modifying the array.
 * 
 * Time Complexities:
 * - Build: O(n)
 * - Query: O(log n)
 * - Update: O(log n)
 * 
 * Space Complexity: O(4*n)
 * 
 * @author Hacktoberfest2025 Contributor
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;
    
    // Build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build left and right subtrees
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            // Merge the results (sum in this case)
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    // Update a single element
    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                // If idx is in the left child, recurse on the left child
                updateHelper(2 * node, start, mid, idx, val);
            } else {
                // If idx is in the right child, recurse on the right child
                updateHelper(2 * node + 1, mid + 1, end, idx, val);
            }
            // Merge the results
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    // Range sum query
    int queryHelper(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // Range represented by a node is completely outside the given range
            return 0;
        }
        if (l <= start && end <= r) {
            // Range represented by a node is completely inside the given range
            return tree[node];
        }
        // Range represented by a node is partially inside and partially outside
        int mid = (start + end) / 2;
        int p1 = queryHelper(2 * node, start, mid, l, r);
        int p2 = queryHelper(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
    
public:
    // Constructor
    SegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    
    // Public update method
    void update(int idx, int val) {
        updateHelper(1, 0, n - 1, idx, val);
    }
    
    // Public query method
    int query(int l, int r) {
        return queryHelper(1, 0, n - 1, l, r);
    }
    
    // Display the original array
    void displayArray() {
        cout << "Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Range Minimum Query Segment Tree
class RMQSegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateHelper(2 * node, start, mid, idx, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    int queryHelper(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = queryHelper(2 * node, start, mid, l, r);
        int p2 = queryHelper(2 * node + 1, mid + 1, end, l, r);
        return min(p1, p2);
    }
    
public:
    RMQSegmentTree(vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    
    void update(int idx, int val) {
        updateHelper(1, 0, n - 1, idx, val);
    }
    
    int query(int l, int r) {
        return queryHelper(1, 0, n - 1, l, r);
    }
    
    void displayArray() {
        cout << "Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Test functions
void testRangeSumQuery() {
    cout << "\n=== Range Sum Query Segment Tree ===\n";
    
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    
    st.displayArray();
    
    // Test queries
    cout << "Sum of range [1, 3]: " << st.query(1, 3) << endl;  // 3 + 5 + 7 = 15
    cout << "Sum of range [0, 2]: " << st.query(0, 2) << endl;  // 1 + 3 + 5 = 9
    cout << "Sum of range [2, 5]: " << st.query(2, 5) << endl;  // 5 + 7 + 9 + 11 = 32
    
    // Test update
    cout << "\nUpdating index 1 to value 10\n";
    st.update(1, 10);
    st.displayArray();
    
    cout << "Sum of range [1, 3]: " << st.query(1, 3) << endl;  // 10 + 5 + 7 = 22
    cout << "Sum of range [0, 2]: " << st.query(0, 2) << endl;  // 1 + 10 + 5 = 16
}

void testRangeMinimumQuery() {
    cout << "\n=== Range Minimum Query Segment Tree ===\n";
    
    vector<int> arr = {18, 17, 13, 19, 15, 11, 20};
    RMQSegmentTree rmq(arr);
    
    rmq.displayArray();
    
    // Test queries
    cout << "Minimum in range [1, 3]: " << rmq.query(1, 3) << endl;  // min(17, 13, 19) = 13
    cout << "Minimum in range [4, 6]: " << rmq.query(4, 6) << endl;  // min(15, 11, 20) = 11
    cout << "Minimum in range [0, 6]: " << rmq.query(0, 6) << endl;  // min of all = 11
    
    // Test update
    cout << "\nUpdating index 5 to value 8\n";
    rmq.update(5, 8);
    rmq.displayArray();
    
    cout << "Minimum in range [4, 6]: " << rmq.query(4, 6) << endl;  // min(15, 8, 20) = 8
    cout << "Minimum in range [0, 6]: " << rmq.query(0, 6) << endl;  // min of all = 8
}

int main() {
    cout << "🌟 Segment Tree Implementation 🌟\n";
    cout << "==================================\n";
    
    testRangeSumQuery();
    testRangeMinimumQuery();
    
    cout << "\n✨ Segment Tree operations completed successfully! ✨\n";
    
    return 0;
}