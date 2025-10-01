/**
 * Advanced Data Structures and Algorithms Implementation in JavaScript
 * 
 * This file contains implementations of various DSA concepts including:
 * - Binary Search Tree with advanced operations
 * - Graph algorithms (BFS, DFS, Dijkstra)
 * - Dynamic Programming solutions
 * - Sorting algorithms with visualizations
 * 
 * @author Hacktoberfest2025 Contributor
 */

// ==================== BINARY SEARCH TREE ====================
class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }

    // Insert a value into the BST
    insert(val) {
        this.root = this.insertRec(this.root, val);
    }

    insertRec(root, val) {
        if (root === null) {
            return new TreeNode(val);
        }

        if (val < root.val) {
            root.left = this.insertRec(root.left, val);
        } else if (val > root.val) {
            root.right = this.insertRec(root.right, val);
        }

        return root;
    }

    // Search for a value in the BST
    search(val) {
        return this.searchRec(this.root, val);
    }

    searchRec(root, val) {
        if (root === null || root.val === val) {
            return root;
        }

        if (val < root.val) {
            return this.searchRec(root.left, val);
        }

        return this.searchRec(root.right, val);
    }

    // Inorder traversal (sorted order)
    inorder() {
        const result = [];
        this.inorderRec(this.root, result);
        return result;
    }

    inorderRec(root, result) {
        if (root !== null) {
            this.inorderRec(root.left, result);
            result.push(root.val);
            this.inorderRec(root.right, result);
        }
    }

    // Find minimum value node
    findMin(root = this.root) {
        while (root.left !== null) {
            root = root.left;
        }
        return root;
    }

    // Delete a node
    delete(val) {
        this.root = this.deleteRec(this.root, val);
    }

    deleteRec(root, val) {
        if (root === null) return root;

        if (val < root.val) {
            root.left = this.deleteRec(root.left, val);
        } else if (val > root.val) {
            root.right = this.deleteRec(root.right, val);
        } else {
            // Node to be deleted found
            if (root.left === null) return root.right;
            if (root.right === null) return root.left;

            // Node with two children
            const minNode = this.findMin(root.right);
            root.val = minNode.val;
            root.right = this.deleteRec(root.right, minNode.val);
        }

        return root;
    }
}

// ==================== GRAPH ALGORITHMS ====================
class Graph {
    constructor() {
        this.adjacencyList = {};
    }

    // Add vertex to the graph
    addVertex(vertex) {
        if (!this.adjacencyList[vertex]) {
            this.adjacencyList[vertex] = [];
        }
    }

    // Add edge between two vertices
    addEdge(v1, v2, weight = 1) {
        this.addVertex(v1);
        this.addVertex(v2);
        this.adjacencyList[v1].push({ node: v2, weight });
        this.adjacencyList[v2].push({ node: v1, weight }); // For undirected graph
    }

    // Breadth-First Search
    bfs(start) {
        const queue = [start];
        const result = [];
        const visited = {};
        visited[start] = true;

        while (queue.length) {
            const vertex = queue.shift();
            result.push(vertex);

            this.adjacencyList[vertex].forEach(neighbor => {
                if (!visited[neighbor.node]) {
                    visited[neighbor.node] = true;
                    queue.push(neighbor.node);
                }
            });
        }

        return result;
    }

    // Depth-First Search (Iterative)
    dfs(start) {
        const stack = [start];
        const result = [];
        const visited = {};
        visited[start] = true;

        while (stack.length) {
            const vertex = stack.pop();
            result.push(vertex);

            this.adjacencyList[vertex].forEach(neighbor => {
                if (!visited[neighbor.node]) {
                    visited[neighbor.node] = true;
                    stack.push(neighbor.node);
                }
            });
        }

        return result;
    }

    // Dijkstra's Shortest Path Algorithm
    dijkstra(start, finish) {
        const nodes = new PriorityQueue();
        const distances = {};
        const previous = {};
        const path = [];
        let smallest;

        // Build initial state
        for (let vertex in this.adjacencyList) {
            if (vertex === start) {
                distances[vertex] = 0;
                nodes.enqueue(vertex, 0);
            } else {
                distances[vertex] = Infinity;
                nodes.enqueue(vertex, Infinity);
            }
            previous[vertex] = null;
        }

        // As long as there is something to visit
        while (nodes.values.length) {
            smallest = nodes.dequeue().val;

            if (smallest === finish) {
                // Build path to return
                while (previous[smallest]) {
                    path.push(smallest);
                    smallest = previous[smallest];
                }
                break;
            }

            if (smallest || distances[smallest] !== Infinity) {
                for (let neighbor of this.adjacencyList[smallest]) {
                    // Calculate distance to neighboring node
                    let candidate = distances[smallest] + neighbor.weight;
                    let nextNeighbor = neighbor.node;

                    if (candidate < distances[nextNeighbor]) {
                        // Update smallest distance
                        distances[nextNeighbor] = candidate;
                        // Update previous
                        previous[nextNeighbor] = smallest;
                        // Enqueue with new priority
                        nodes.enqueue(nextNeighbor, candidate);
                    }
                }
            }
        }

        return path.concat(smallest).reverse();
    }
}

// Priority Queue for Dijkstra's algorithm
class PriorityQueue {
    constructor() {
        this.values = [];
    }

    enqueue(val, priority) {
        this.values.push({ val, priority });
        this.sort();
    }

    dequeue() {
        return this.values.shift();
    }

    sort() {
        this.values.sort((a, b) => a.priority - b.priority);
    }
}

// ==================== DYNAMIC PROGRAMMING ====================
class DynamicProgramming {
    // Fibonacci with memoization
    static fibMemo(n, memo = {}) {
        if (n in memo) return memo[n];
        if (n <= 2) return 1;
        
        memo[n] = this.fibMemo(n - 1, memo) + this.fibMemo(n - 2, memo);
        return memo[n];
    }

    // 0/1 Knapsack Problem
    static knapsack(weights, values, capacity) {
        const n = weights.length;
        const dp = Array(n + 1).fill().map(() => Array(capacity + 1).fill(0));

        for (let i = 1; i <= n; i++) {
            for (let w = 1; w <= capacity; w++) {
                if (weights[i - 1] <= w) {
                    dp[i][w] = Math.max(
                        values[i - 1] + dp[i - 1][w - weights[i - 1]],
                        dp[i - 1][w]
                    );
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][capacity];
    }

    // Longest Common Subsequence
    static longestCommonSubsequence(str1, str2) {
        const m = str1.length;
        const n = str2.length;
        const dp = Array(m + 1).fill().map(() => Array(n + 1).fill(0));

        for (let i = 1; i <= m; i++) {
            for (let j = 1; j <= n; j++) {
                if (str1[i - 1] === str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    // Coin Change Problem
    static coinChange(coins, amount) {
        const dp = Array(amount + 1).fill(Infinity);
        dp[0] = 0;

        for (let coin of coins) {
            for (let i = coin; i <= amount; i++) {
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] === Infinity ? -1 : dp[amount];
    }
}

// ==================== SORTING ALGORITHMS ====================
class SortingAlgorithms {
    // Quick Sort
    static quickSort(arr) {
        if (arr.length <= 1) return arr;

        const pivot = arr[Math.floor(arr.length / 2)];
        const left = arr.filter(x => x < pivot);
        const middle = arr.filter(x => x === pivot);
        const right = arr.filter(x => x > pivot);

        return [
            ...this.quickSort(left),
            ...middle,
            ...this.quickSort(right)
        ];
    }

    // Merge Sort
    static mergeSort(arr) {
        if (arr.length <= 1) return arr;

        const mid = Math.floor(arr.length / 2);
        const left = arr.slice(0, mid);
        const right = arr.slice(mid);

        return this.merge(this.mergeSort(left), this.mergeSort(right));
    }

    static merge(left, right) {
        const result = [];
        let leftIndex = 0;
        let rightIndex = 0;

        while (leftIndex < left.length && rightIndex < right.length) {
            if (left[leftIndex] < right[rightIndex]) {
                result.push(left[leftIndex]);
                leftIndex++;
            } else {
                result.push(right[rightIndex]);
                rightIndex++;
            }
        }

        return result
            .concat(left.slice(leftIndex))
            .concat(right.slice(rightIndex));
    }

    // Heap Sort
    static heapSort(arr) {
        const n = arr.length;

        // Build heap
        for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
            this.heapify(arr, n, i);
        }

        // Extract elements from heap
        for (let i = n - 1; i > 0; i--) {
            [arr[0], arr[i]] = [arr[i], arr[0]];
            this.heapify(arr, i, 0);
        }

        return arr;
    }

    static heapify(arr, n, i) {
        let largest = i;
        let left = 2 * i + 1;
        let right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest !== i) {
            [arr[i], arr[largest]] = [arr[largest], arr[i]];
            this.heapify(arr, n, largest);
        }
    }
}

// ==================== DEMONSTRATION FUNCTIONS ====================
function demonstrateBST() {
    console.log("\n=== Binary Search Tree Demo ===");
    
    const bst = new BinarySearchTree();
    const values = [50, 30, 70, 20, 40, 60, 80];
    
    console.log("Inserting values:", values);
    values.forEach(val => bst.insert(val));
    
    console.log("Inorder traversal (sorted):", bst.inorder());
    
    console.log("Searching for 40:", bst.search(40) !== null);
    console.log("Searching for 25:", bst.search(25) !== null);
    
    console.log("Deleting 30...");
    bst.delete(30);
    console.log("Inorder after deletion:", bst.inorder());
}

function demonstrateGraph() {
    console.log("\n=== Graph Algorithms Demo ===");
    
    const graph = new Graph();
    
    // Add vertices and edges
    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "C", 2);
    graph.addEdge("B", "E", 3);
    graph.addEdge("C", "D", 2);
    graph.addEdge("C", "F", 4);
    graph.addEdge("D", "E", 3);
    graph.addEdge("D", "F", 1);
    graph.addEdge("E", "F", 1);
    
    console.log("BFS from A:", graph.bfs("A"));
    console.log("DFS from A:", graph.dfs("A"));
    console.log("Shortest path A to E:", graph.dijkstra("A", "E"));
}

function demonstrateDP() {
    console.log("\n=== Dynamic Programming Demo ===");
    
    console.log("Fibonacci(10):", DynamicProgramming.fibMemo(10));
    
    const weights = [1, 3, 4, 5];
    const values = [1, 4, 5, 7];
    const capacity = 7;
    console.log("Knapsack problem result:", DynamicProgramming.knapsack(weights, values, capacity));
    
    console.log("LCS of 'ABCDGH' and 'AEDFHR':", 
        DynamicProgramming.longestCommonSubsequence("ABCDGH", "AEDFHR"));
    
    const coins = [1, 3, 4];
    const amount = 6;
    console.log(`Minimum coins for amount ${amount}:`, 
        DynamicProgramming.coinChange(coins, amount));
}

function demonstrateSorting() {
    console.log("\n=== Sorting Algorithms Demo ===");
    
    const unsortedArray = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array:", unsortedArray);
    
    console.log("Quick Sort:", SortingAlgorithms.quickSort([...unsortedArray]));
    console.log("Merge Sort:", SortingAlgorithms.mergeSort([...unsortedArray]));
    
    const heapArray = [...unsortedArray];
    SortingAlgorithms.heapSort(heapArray);
    console.log("Heap Sort:", heapArray);
}

// ==================== MAIN EXECUTION ====================
function main() {
    console.log("🚀 Advanced Data Structures & Algorithms in JavaScript 🚀");
    console.log("=========================================================");
    
    demonstrateBST();
    demonstrateGraph();
    demonstrateDP();
    demonstrateSorting();
    
    console.log("\n✨ All demonstrations completed successfully! ✨");
}

// Run the demonstrations
main();

// Export for use in other modules (if using Node.js)
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        BinarySearchTree,
        Graph,
        DynamicProgramming,
        SortingAlgorithms,
        PriorityQueue
    };
}