/**
 * AVL Tree Implementation in Java
 * 
 * AVL Tree is a self-balancing Binary Search Tree where the difference between 
 * heights of left and right subtrees cannot be more than one for all nodes.
 * 
 * Time Complexities:
 * - Search: O(log n)
 * - Insert: O(log n) 
 * - Delete: O(log n)
 * 
 * @author Hacktoberfest2025 Contributor
 */

class AVLTree {
    
    // Node class for AVL Tree
    class Node {
        int key;
        Node left, right;
        int height;

        Node(int key) {
            this.key = key;
            this.height = 1;
        }
    }

    private Node root;

    // Get height of the node
    private int height(Node node) {
        if (node == null)
            return 0;
        return node.height;
    }

    // Get balance factor of node
    private int getBalance(Node node) {
        if (node == null)
            return 0;
        return height(node.left) - height(node.right);
    }

    // Right rotate
    private Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = T2;

        // Update heights
        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1;

        // Return new root
        return x;
    }

    // Left rotate
    private Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = T2;

        // Update heights
        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;

        // Return new root
        return y;
    }

    // Insert a key into AVL tree
    public void insert(int key) {
        root = insertRec(root, key);
    }

    private Node insertRec(Node node, int key) {
        // Step 1: Perform normal BST insertion
        if (node == null)
            return new Node(key);

        if (key < node.key)
            node.left = insertRec(node.left, key);
        else if (key > node.key)
            node.right = insertRec(node.right, key);
        else // Equal keys not allowed
            return node;

        // Step 2: Update height of this ancestor node
        node.height = 1 + Math.max(height(node.left), height(node.right));

        // Step 3: Get the balance factor
        int balance = getBalance(node);

        // Step 4: If node becomes unbalanced, there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node.left.key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node.right.key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Find minimum value node
    private Node minValueNode(Node node) {
        Node current = node;
        while (current.left != null)
            current = current.left;
        return current;
    }

    // Delete a key from AVL tree
    public void delete(int key) {
        root = deleteRec(root, key);
    }

    private Node deleteRec(Node root, int key) {
        // Step 1: Perform standard BST delete
        if (root == null)
            return root;

        if (key < root.key)
            root.left = deleteRec(root.left, key);
        else if (key > root.key)
            root.right = deleteRec(root.right, key);
        else {
            // Node with only one child or no child
            if ((root.left == null) || (root.right == null)) {
                Node temp = null;
                if (temp == root.left)
                    temp = root.right;
                else
                    temp = root.left;

                // No child case
                if (temp == null) {
                    temp = root;
                    root = null;
                } else // One child case
                    root = temp; // Copy the contents of non-empty child
            } else {
                // Node with two children
                Node temp = minValueNode(root.right);
                root.key = temp.key;
                root.right = deleteRec(root.right, temp.key);
            }
        }

        // If the tree had only one node then return
        if (root == null)
            return root;

        // Step 2: Update height of current node
        root.height = Math.max(height(root.left), height(root.right)) + 1;

        // Step 3: Get the balance factor
        int balance = getBalance(root);

        // Step 4: If node becomes unbalanced, there are 4 cases

        // Left Left Case
        if (balance > 1 && getBalance(root.left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root.left) < 0) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root.right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root.right) > 0) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }

        return root;
    }

    // Search for a key in AVL tree
    public boolean search(int key) {
        return searchRec(root, key);
    }

    private boolean searchRec(Node root, int key) {
        if (root == null)
            return false;
        
        if (key == root.key)
            return true;
        
        if (key < root.key)
            return searchRec(root.left, key);
        
        return searchRec(root.right, key);
    }

    // Preorder traversal of AVL tree
    public void preOrder() {
        System.out.print("Preorder traversal: ");
        preOrderRec(root);
        System.out.println();
    }

    private void preOrderRec(Node node) {
        if (node != null) {
            System.out.print(node.key + " ");
            preOrderRec(node.left);
            preOrderRec(node.right);
        }
    }

    // Inorder traversal of AVL tree (gives sorted order)
    public void inOrder() {
        System.out.print("Inorder traversal: ");
        inOrderRec(root);
        System.out.println();
    }

    private void inOrderRec(Node node) {
        if (node != null) {
            inOrderRec(node.left);
            System.out.print(node.key + " ");
            inOrderRec(node.right);
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        AVLTree tree = new AVLTree();

        System.out.println("=== AVL Tree Implementation ===");
        
        // Insert elements
        System.out.println("\nInserting elements: 10, 20, 30, 40, 50, 25");
        tree.insert(10);
        tree.insert(20);
        tree.insert(30);
        tree.insert(40);
        tree.insert(50);
        tree.insert(25);

        // Display tree
        tree.preOrder();
        tree.inOrder();

        // Search elements
        System.out.println("\nSearching for 30: " + tree.search(30));
        System.out.println("Searching for 35: " + tree.search(35));

        // Delete element
        System.out.println("\nDeleting 30...");
        tree.delete(30);
        tree.preOrder();
        tree.inOrder();

        System.out.println("\n✨ AVL Tree operations completed successfully! ✨");
    }
}