/**
 * Fenwick Tree (Binary Indexed Tree) Implementation in C++
 * 
 * A Fenwick Tree or Binary Indexed Tree is a data structure that can efficiently 
 * calculate prefix sums in O(log n) time and update values in O(log n) time.
 * 
 * Key Properties:
 * - Each index i is responsible for elements in range [i-2^r+1, i] where r is the 
 *   position of the last set bit in i
 * - Tree uses 1-based indexing for easier bit manipulation
 * - Extremely space efficient compared to Segment Trees
 * 
 * Applications:
 * - Range sum queries with point updates
 * - Counting inversions in arrays
 * - 2D range sum queries (2D Fenwick Tree)
 * - Coordinate compression problems
 * 
 * Time Complexities:
 * - Build: O(n log n) or O(n) with optimized construction
 * - Query (prefix sum): O(log n)
 * - Update: O(log n)
 * - Range Query: O(log n)
 * 
 * Space Complexity: O(n)
 * 
 * @author Hacktoberfest2025 Advanced Contributor
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono;

class FenwickTree {
private:
    vector<long long> tree;
    int n;
    
    /**
     * Get the value of the least significant bit
     * This is equivalent to i & (-i)
     */
    int lowBit(int x) {
        return x & (-x);
    }
    
public:
    /**
     * Constructor: Initialize Fenwick Tree with size n
     */
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    /**
     * Constructor: Build Fenwick Tree from existing array
     */
    FenwickTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]);
        }
    }
    
    /**
     * Optimized constructor: Build tree in O(n) time
     */
    void buildOptimized(const vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        
        // Copy array values (1-indexed)
        for (int i = 1; i <= n; i++) {
            tree[i] = arr[i - 1];
        }
        
        // Build tree bottom-up
        for (int i = 1; i <= n; i++) {
            int parent = i + lowBit(i);
            if (parent <= n) {
                tree[parent] += tree[i];
            }
        }
    }
    
    /**
     * Update element at position idx (1-indexed) by adding delta
     */
    void update(int idx, long long delta) {
        assert(idx >= 1 && idx <= n);
        
        while (idx <= n) {
            tree[idx] += delta;
            idx += lowBit(idx);
        }
    }
    
    /**
     * Set element at position idx (1-indexed) to value
     */
    void set(int idx, long long value) {
        long long currentValue = query(idx) - query(idx - 1);
        update(idx, value - currentValue);
    }
    
    /**
     * Get prefix sum from index 1 to idx (1-indexed)
     */
    long long query(int idx) {
        if (idx <= 0) return 0;
        
        long long sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= lowBit(idx);
        }
        return sum;
    }
    
    /**
     * Get range sum from left to right (1-indexed, inclusive)
     */
    long long rangeQuery(int left, int right) {
        assert(left >= 1 && right >= left && right <= n);
        return query(right) - query(left - 1);
    }
    
    /**
     * Find the k-th smallest element (1-indexed)
     * Requires all elements to be non-negative
     */
    int findKth(long long k) {
        int pos = 0;
        int bitMask = 1;
        
        // Find the highest bit set in n
        while (bitMask <= n) bitMask <<= 1;
        bitMask >>= 1;
        
        while (bitMask > 0) {
            int next = pos + bitMask;
            if (next <= n && tree[next] < k) {
                pos = next;
                k -= tree[pos];
            }
            bitMask >>= 1;
        }
        
        return pos + 1;  // Return 1-indexed position
    }
    
    /**
     * Get the size of the tree
     */
    int size() const {
        return n;
    }
    
    /**
     * Display the tree structure for debugging
     */
    void display() {
        cout << "Fenwick Tree (1-indexed): ";
        for (int i = 1; i <= n; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
        
        cout << "Original array: ";
        for (int i = 1; i <= n; i++) {
            cout << rangeQuery(i, i) << " ";
        }
        cout << endl;
    }
    
    /**
     * Reset all values to zero
     */
    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
};

/**
 * 2D Fenwick Tree for 2D range sum queries
 */
class FenwickTree2D {
private:
    vector<vector<long long>> tree;
    int rows, cols;
    
    int lowBit(int x) {
        return x & (-x);
    }
    
public:
    FenwickTree2D(int r, int c) {
        rows = r;
        cols = c;
        tree.assign(rows + 1, vector<long long>(cols + 1, 0));
    }
    
    void update(int row, int col, long long delta) {
        for (int i = row; i <= rows; i += lowBit(i)) {
            for (int j = col; j <= cols; j += lowBit(j)) {
                tree[i][j] += delta;
            }
        }
    }
    
    long long query(int row, int col) {
        long long sum = 0;
        for (int i = row; i > 0; i -= lowBit(i)) {
            for (int j = col; j > 0; j -= lowBit(j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
    
    long long rangeQuery(int r1, int c1, int r2, int c2) {
        return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
    }
};

/**
 * Difference Array with Fenwick Tree for range updates
 */
class RangeUpdateFenwick {
private:
    FenwickTree diff;
    
public:
    RangeUpdateFenwick(int n) : diff(n) {}
    
    /**
     * Add delta to range [left, right] (1-indexed)
     */
    void rangeUpdate(int left, int right, long long delta) {
        diff.update(left, delta);
        diff.update(right + 1, -delta);
    }
    
    /**
     * Get value at position idx (1-indexed)
     */
    long long pointQuery(int idx) {
        return diff.query(idx);
    }
};

// ==================== TEST FUNCTIONS ====================

void testBasicOperations() {
    cout << "\n=== Basic Fenwick Tree Operations ===\n";
    
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(arr);
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    ft.display();
    
    // Test prefix queries
    cout << "\nPrefix sum queries:\n";
    for (int i = 1; i <= 6; i++) {
        cout << "Sum[1.." << i << "] = " << ft.query(i) << endl;
    }
    
    // Test range queries
    cout << "\nRange sum queries:\n";
    cout << "Sum[2..4] = " << ft.rangeQuery(2, 4) << endl;  // 3 + 5 + 7 = 15
    cout << "Sum[3..6] = " << ft.rangeQuery(3, 6) << endl;  // 5 + 7 + 9 + 11 = 32
    
    // Test updates
    cout << "\nUpdating index 3 by +10\n";
    ft.update(3, 10);  // arr[2] becomes 15
    ft.display();
    
    cout << "Sum[1..6] after update = " << ft.query(6) << endl;
    cout << "Sum[2..4] after update = " << ft.rangeQuery(2, 4) << endl;
}

void testRangeUpdates() {
    cout << "\n=== Range Update Operations ===\n";
    
    RangeUpdateFenwick ruft(6);
    
    cout << "Initial array (all zeros)\n";
    for (int i = 1; i <= 6; i++) {
        cout << "arr[" << i << "] = " << ruft.pointQuery(i) << endl;
    }
    
    // Range updates
    cout << "\nApplying range updates:\n";
    ruft.rangeUpdate(2, 4, 5);  // Add 5 to range [2, 4]
    cout << "Added 5 to range [2, 4]\n";
    
    ruft.rangeUpdate(1, 3, 3);  // Add 3 to range [1, 3]
    cout << "Added 3 to range [1, 3]\n";
    
    ruft.rangeUpdate(5, 6, -2); // Add -2 to range [5, 6]
    cout << "Added -2 to range [5, 6]\n";
    
    cout << "\nFinal array values:\n";
    for (int i = 1; i <= 6; i++) {
        cout << "arr[" << i << "] = " << ruft.pointQuery(i) << endl;
    }
}

void test2DFenwick() {
    cout << "\n=== 2D Fenwick Tree Operations ===\n";
    
    FenwickTree2D ft2d(4, 4);
    
    // Update some positions
    ft2d.update(1, 1, 1);
    ft2d.update(2, 2, 2);
    ft2d.update(3, 3, 3);
    ft2d.update(4, 4, 4);
    ft2d.update(2, 3, 5);
    
    cout << "Updated positions:\n";
    cout << "(1,1) += 1, (2,2) += 2, (3,3) += 3, (4,4) += 4, (2,3) += 5\n";
    
    // Test 2D range queries
    cout << "\n2D Range queries:\n";
    cout << "Sum in rectangle (1,1) to (2,2) = " << ft2d.rangeQuery(1, 1, 2, 2) << endl;
    cout << "Sum in rectangle (2,2) to (3,3) = " << ft2d.rangeQuery(2, 2, 3, 3) << endl;
    cout << "Sum in rectangle (1,1) to (4,4) = " << ft2d.rangeQuery(1, 1, 4, 4) << endl;
}

void performanceBenchmark() {
    cout << "\n=== Performance Benchmark ===\n";
    
    const int n = 100000;
    const int operations = 50000;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    
    // Benchmark Fenwick Tree construction
    auto start = high_resolution_clock::now();
    FenwickTree ft(arr);
    auto end = high_resolution_clock::now();
    
    auto construction_time = duration_cast<microseconds>(end - start);
    cout << "Construction time for " << n << " elements: " << construction_time.count() << " microseconds\n";
    
    // Benchmark queries
    start = high_resolution_clock::now();
    long long sum = 0;
    for (int i = 0; i < operations; i++) {
        sum += ft.query(rand() % n + 1);
    }
    end = high_resolution_clock::now();
    
    auto query_time = duration_cast<microseconds>(end - start);
    cout << "Time for " << operations << " queries: " << query_time.count() << " microseconds\n";
    cout << "Average query time: " << (double)query_time.count() / operations << " microseconds\n";
    
    // Benchmark updates
    start = high_resolution_clock::now();
    for (int i = 0; i < operations; i++) {
        ft.update(rand() % n + 1, rand() % 100);
    }
    end = high_resolution_clock::now();
    
    auto update_time = duration_cast<microseconds>(end - start);
    cout << "Time for " << operations << " updates: " << update_time.count() << " microseconds\n";
    cout << "Average update time: " << (double)update_time.count() / operations << " microseconds\n";
}

int main() {
    cout << "🌟 Fenwick Tree (Binary Indexed Tree) Implementation 🌟\n";
    cout << "=======================================================\n";
    
    srand(time(nullptr));
    
    testBasicOperations();
    testRangeUpdates();
    test2DFenwick();
    performanceBenchmark();
    
    cout << "\n✨ All Fenwick Tree operations completed successfully! ✨\n";
    
    return 0;
}