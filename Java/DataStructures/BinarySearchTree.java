public class BinarySearchTree<T extends Comparable<T>> {
    private Node<T> root;
    
    private static class Node<T> {
        T data;
        Node<T> left, right;
        
        Node(T data) {
            this.data = data;
            left = right = null;
        }
    }
    
    public BinarySearchTree() {
        root = null;
    }
    
    public void insert(T data) {
        root = insertRec(root, data);
    }
    
    private Node<T> insertRec(Node<T> root, T data) {
        if (root == null) {
            root = new Node<>(data);
            return root;
        }
        if (data.compareTo(root.data) < 0) {
            root.left = insertRec(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            root.right = insertRec(root.right, data);
        }
        return root;
    }
    
    public boolean search(T data) {
        return searchRec(root, data);
    }
    
    private boolean searchRec(Node<T> root, T data) {
        if (root == null) {
            return false;
        }
        if (data.equals(root.data)) {
            return true;
        }
        return data.compareTo(root.data) < 0 
            ? searchRec(root.left, data) 
            : searchRec(root.right, data);
    }
    
    public void delete(T data) {
        root = deleteRec(root, data);
    }
    
    private Node<T> deleteRec(Node<T> root, T data) {
        if (root == null) {
            return root;
        }
        if (data.compareTo(root.data) < 0) {
            root.left = deleteRec(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            root.right = deleteRec(root.right, data);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            root.data = minValue(root.right);
            root.right = deleteRec(root.right, root.data);
        }
        return root;
    }
    
    private T minValue(Node<T> root) {
        T minv = root.data;
        while (root.left != null) {
            minv = root.left.data;
            root = root.left;
        }
        return minv;
    }
    
    public void inorder() {
        inorderRec(root);
        System.out.println();
    }
    
    private void inorderRec(Node<T> root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }
    
    public void preorder() {
        preorderRec(root);
        System.out.println();
    }
    
    private void preorderRec(Node<T> root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }
    
    public void postorder() {
        postorderRec(root);
        System.out.println();
    }
    
    private void postorderRec(Node<T> root) {
        if (root != null) {
            postorderRec(root.left);
            postorderRec(root.right);
            System.out.print(root.data + " ");
        }
    }
    
    public int height() {
        return heightRec(root);
    }
    
    private int heightRec(Node<T> root) {
        if (root == null) {
            return -1;
        }
        return 1 + Math.max(heightRec(root.left), heightRec(root.right));
    }
    
    public boolean isEmpty() {
        return root == null;
    }
}