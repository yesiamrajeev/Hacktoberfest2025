/**
 * B+ Tree Implementation in Java
 * 
 * B+ Tree is a self-balancing tree data structure that maintains sorted data 
 * and allows searches, sequential access, insertions, and deletions in logarithmic time.
 * 
 * Key Features:
 * - All values are stored in leaf nodes
 * - Internal nodes store only keys for navigation
 * - Leaf nodes are linked for efficient range queries
 * - Optimal for database indexing and file systems
 * 
 * Time Complexities:
 * - Search: O(log n)
 * - Insert: O(log n)
 * - Delete: O(log n)
 * - Range Query: O(log n + k) where k is number of results
 * 
 * @author Hacktoberfest2025 Advanced Contributor
 */

import java.util.*;

/**
 * B+ Tree node interface
 */
abstract class BPlusNode {
    protected List<Integer> keys;
    protected BPlusNode parent;
    protected boolean isLeaf;
    
    public BPlusNode(boolean isLeaf) {
        this.keys = new ArrayList<>();
        this.parent = null;
        this.isLeaf = isLeaf;
    }
    
    public abstract boolean isFull(int order);
    public abstract BPlusNode split(int order);
    public abstract boolean isUnderflow(int order);
}

/**
 * Internal node class for B+ Tree
 */
class InternalNode extends BPlusNode {
    private List<BPlusNode> children;
    
    public InternalNode() {
        super(false);
        this.children = new ArrayList<>();
    }
    
    @Override
    public boolean isFull(int order) {
        return keys.size() >= order - 1;
    }
    
    @Override
    public boolean isUnderflow(int order) {
        return keys.size() < (order - 1) / 2;
    }
    
    @Override
    public BPlusNode split(int order) {
        int midIndex = keys.size() / 2;
        
        InternalNode newNode = new InternalNode();
        
        // Move half the keys to new node
        for (int i = midIndex + 1; i < keys.size(); i++) {
            newNode.keys.add(keys.get(i));
        }
        
        // Move half the children to new node
        for (int i = midIndex + 1; i < children.size(); i++) {
            newNode.children.add(children.get(i));
            children.get(i).parent = newNode;
        }
        
        // Remove moved elements from current node
        keys.subList(midIndex + 1, keys.size()).clear();
        children.subList(midIndex + 1, children.size()).clear();
        
        return newNode;
    }
    
    public void addChild(BPlusNode child) {
        children.add(child);
        child.parent = this;
    }
    
    public void insertChild(int index, BPlusNode child) {
        children.add(index, child);
        child.parent = this;
    }
    
    public List<BPlusNode> getChildren() {
        return children;
    }
    
    public BPlusNode getChild(int index) {
        return children.get(index);
    }
    
    public void removeChild(int index) {
        if (index < children.size()) {
            children.remove(index);
        }
    }
}

/**
 * Leaf node class for B+ Tree
 */
class LeafNode extends BPlusNode {
    private List<String> values;
    private LeafNode next; // For linked list of leaf nodes
    private LeafNode prev; // For doubly linked list
    
    public LeafNode() {
        super(true);
        this.values = new ArrayList<>();
        this.next = null;
        this.prev = null;
    }
    
    @Override
    public boolean isFull(int order) {
        return keys.size() >= order - 1;
    }
    
    @Override
    public boolean isUnderflow(int order) {
        return keys.size() < (order - 1) / 2;
    }
    
    @Override
    public BPlusNode split(int order) {
        int midIndex = keys.size() / 2;
        
        LeafNode newLeaf = new LeafNode();
        
        // Move half the keys and values to new leaf
        for (int i = midIndex; i < keys.size(); i++) {
            newLeaf.keys.add(keys.get(i));
            newLeaf.values.add(values.get(i));
        }
        
        // Remove moved elements from current leaf
        keys.subList(midIndex, keys.size()).clear();
        values.subList(midIndex, values.size()).clear();
        
        // Update linked list pointers
        newLeaf.next = this.next;
        if (this.next != null) {
            this.next.prev = newLeaf;
        }
        this.next = newLeaf;
        newLeaf.prev = this;
        
        return newLeaf;
    }
    
    public void insert(int key, String value) {
        int index = Collections.binarySearch(keys, key);
        if (index < 0) {
            index = -(index + 1);
        }
        
        keys.add(index, key);
        values.add(index, value);
    }
    
    public String search(int key) {
        int index = Collections.binarySearch(keys, key);
        if (index >= 0) {
            return values.get(index);
        }
        return null;
    }
    
    public List<String> rangeSearch(int startKey, int endKey) {
        List<String> result = new ArrayList<>();
        
        LeafNode current = this;
        while (current != null) {
            for (int i = 0; i < current.keys.size(); i++) {
                int key = current.keys.get(i);
                if (key >= startKey && key <= endKey) {
                    result.add(current.values.get(i));
                } else if (key > endKey) {
                    return result;
                }
            }
            current = current.next;
        }
        
        return result;
    }
    
    public List<String> getValues() {
        return values;
    }
    
    public LeafNode getNext() {
        return next;
    }
    
    public void setNext(LeafNode next) {
        this.next = next;
    }
    
    public LeafNode getPrev() {
        return prev;
    }
    
    public void setPrev(LeafNode prev) {
        this.prev = prev;
    }
}

/**
 * Main B+ Tree implementation
 */
public class BPlusTree {
    private BPlusNode root;
    private int order;
    
    public BPlusTree(int order) {
        this.order = order;
        this.root = new LeafNode();
    }
    
    /**
     * Insert a key-value pair into the B+ Tree
     */
    public void insert(int key, String value) {
        LeafNode leaf = findLeaf(key);
        leaf.insert(key, value);
        
        if (leaf.isFull(order)) {
            splitLeaf(leaf);
        }
    }
    
    /**
     * Find the leaf node where a key should be inserted or exists
     */
    private LeafNode findLeaf(int key) {
        BPlusNode current = root;
        
        while (!current.isLeaf) {
            InternalNode internal = (InternalNode) current;
            int childIndex = 0;
            
            for (int i = 0; i < internal.keys.size(); i++) {
                if (key < internal.keys.get(i)) {
                    break;
                }
                childIndex++;
            }
            
            current = internal.getChild(childIndex);
        }
        
        return (LeafNode) current;
    }
    
    /**
     * Split a full leaf node
     */
    private void splitLeaf(LeafNode leaf) {
        LeafNode newLeaf = (LeafNode) leaf.split(order);
        int promotedKey = newLeaf.keys.get(0);
        
        if (leaf.parent == null) {
            // Create new root
            InternalNode newRoot = new InternalNode();
            newRoot.keys.add(promotedKey);
            newRoot.addChild(leaf);
            newRoot.addChild(newLeaf);
            leaf.parent = newRoot;
            newLeaf.parent = newRoot;
            root = newRoot;
        } else {
            insertIntoParent(leaf, promotedKey, newLeaf);
        }
    }
    
    /**
     * Insert a key and child into parent node
     */
    private void insertIntoParent(BPlusNode left, int key, BPlusNode right) {
        InternalNode parent = (InternalNode) left.parent;
        
        // Find insertion point
        int index = 0;
        for (int i = 0; i < parent.keys.size(); i++) {
            if (key < parent.keys.get(i)) {
                break;
            }
            index++;
        }
        
        parent.keys.add(index, key);
        parent.insertChild(index + 1, right);
        
        if (parent.isFull(order)) {
            splitInternal(parent);
        }
    }
    
    /**
     * Split a full internal node
     */
    private void splitInternal(InternalNode internal) {
        int midIndex = internal.keys.size() / 2;
        int promotedKey = internal.keys.get(midIndex);
        
        InternalNode newInternal = (InternalNode) internal.split(order);
        
        // Remove the promoted key from the left node
        internal.keys.remove(midIndex);
        
        if (internal.parent == null) {
            // Create new root
            InternalNode newRoot = new InternalNode();
            newRoot.keys.add(promotedKey);
            newRoot.addChild(internal);
            newRoot.addChild(newInternal);
            internal.parent = newRoot;
            newInternal.parent = newRoot;
            root = newRoot;
        } else {
            insertIntoParent(internal, promotedKey, newInternal);
        }
    }
    
    /**
     * Search for a value by key
     */
    public String search(int key) {
        LeafNode leaf = findLeaf(key);
        return leaf.search(key);
    }
    
    /**
     * Range search - find all values between startKey and endKey (inclusive)
     */
    public List<String> rangeSearch(int startKey, int endKey) {
        LeafNode startLeaf = findLeaf(startKey);
        return startLeaf.rangeSearch(startKey, endKey);
    }
    
    /**
     * Display the tree structure
     */
    public void display() {
        if (root != null) {
            displayNode(root, 0);
        }
    }
    
    private void displayNode(BPlusNode node, int level) {
        String indent = "  ".repeat(level);
        
        if (node.isLeaf) {
            LeafNode leaf = (LeafNode) node;
            System.out.print(indent + "Leaf: ");
            for (int i = 0; i < leaf.keys.size(); i++) {
                System.out.print("(" + leaf.keys.get(i) + ":" + leaf.getValues().get(i) + ") ");
            }
            System.out.println();
        } else {
            InternalNode internal = (InternalNode) node;
            System.out.println(indent + "Internal: " + internal.keys);
            
            for (BPlusNode child : internal.getChildren()) {
                displayNode(child, level + 1);
            }
        }
    }
    
    /**
     * Get all leaf values in sorted order
     */
    public List<String> getAllValues() {
        List<String> result = new ArrayList<>();
        LeafNode current = getFirstLeaf();
        
        while (current != null) {
            result.addAll(current.getValues());
            current = current.getNext();
        }
        
        return result;
    }
    
    /**
     * Find the first (leftmost) leaf node
     */
    private LeafNode getFirstLeaf() {
        BPlusNode current = root;
        
        while (!current.isLeaf) {
            InternalNode internal = (InternalNode) current;
            current = internal.getChild(0);
        }
        
        return (LeafNode) current;
    }
    
    /**
     * Main method for testing B+ Tree
     */
    public static void main(String[] args) {
        System.out.println("🌟 B+ Tree Implementation 🌟");
        System.out.println("==============================");
        
        // Create B+ Tree with order 4
        BPlusTree bPlusTree = new BPlusTree(4);
        
        // Test data insertion
        System.out.println("\n=== Inserting Data ===");
        String[][] testData = {
            {"10", "Alice"}, {"20", "Bob"}, {"5", "Charlie"}, {"6", "Diana"},
            {"12", "Eve"}, {"30", "Frank"}, {"7", "Grace"}, {"17", "Henry"},
            {"15", "Ivy"}, {"25", "Jack"}, {"35", "Kate"}, {"40", "Liam"}
        };
        
        for (String[] data : testData) {
            int key = Integer.parseInt(data[0]);
            String value = data[1];
            bPlusTree.insert(key, value);
            System.out.println("Inserted (" + key + ", " + value + ")");
        }
        
        // Display tree structure
        System.out.println("\n=== Tree Structure ===");
        bPlusTree.display();
        
        // Test searches
        System.out.println("\n=== Search Operations ===");
        int[] searchKeys = {10, 25, 100, 5};
        for (int key : searchKeys) {
            String result = bPlusTree.search(key);
            System.out.println("Search " + key + ": " + (result != null ? result : "Not found"));
        }
        
        // Test range queries
        System.out.println("\n=== Range Query Operations ===");
        System.out.println("Range [10, 25]: " + bPlusTree.rangeSearch(10, 25));
        System.out.println("Range [5, 15]: " + bPlusTree.rangeSearch(5, 15));
        System.out.println("Range [30, 50]: " + bPlusTree.rangeSearch(30, 50));
        
        // Display all values in sorted order
        System.out.println("\n=== All Values (Sorted) ===");
        System.out.println(bPlusTree.getAllValues());
        
        System.out.println("\n✨ B+ Tree operations completed successfully! ✨");
    }
}