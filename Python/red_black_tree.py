"""
Red-Black Tree Implementation in Python
A Red-Black Tree is a self-balancing binary search tree with additional color properties.

Properties of Red-Black Trees:
1. Every node is either red or black
2. The root is always black
3. All leaves (NIL nodes) are black
4. Red nodes cannot have red children (no two red nodes can be adjacent)
5. Every path from root to leaf contains the same number of black nodes

Time Complexities:
- Search: O(log n)
- Insert: O(log n) 
- Delete: O(log n)

@author Hacktoberfest2025 Contributor - Advanced Implementation
"""

from enum import Enum

class Color(Enum):
    RED = 1
    BLACK = 2

class RBNode:
    def __init__(self, data=None, color=Color.RED, parent=None, left=None, right=None):
        self.data = data
        self.color = color
        self.parent = parent
        self.left = left
        self.right = right

class RedBlackTree:
    def __init__(self):
        # Create NIL node (sentinel)
        self.NIL = RBNode(color=Color.BLACK)
        self.root = self.NIL
    
    def insert(self, data):
        """Insert a new node with given data"""
        new_node = RBNode(data, Color.RED, self.NIL, self.NIL, self.NIL)
        
        parent = self.NIL
        current = self.root
        
        # Find the correct position
        while current != self.NIL:
            parent = current
            if new_node.data < current.data:
                current = current.left
            else:
                current = current.right
        
        new_node.parent = parent
        
        if parent == self.NIL:
            self.root = new_node
        elif new_node.data < parent.data:
            parent.left = new_node
        else:
            parent.right = new_node
        
        # Fix any violations
        self._fix_insert(new_node)
    
    def _fix_insert(self, node):
        """Fix Red-Black Tree violations after insertion"""
        while node.parent.color == Color.RED:
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right
                
                if uncle.color == Color.RED:
                    # Case 1: Uncle is red
                    node.parent.color = Color.BLACK
                    uncle.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        # Case 2: Node is right child
                        node = node.parent
                        self._left_rotate(node)
                    
                    # Case 3: Node is left child
                    node.parent.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    self._right_rotate(node.parent.parent)
            else:
                uncle = node.parent.parent.left
                
                if uncle.color == Color.RED:
                    node.parent.color = Color.BLACK
                    uncle.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self._right_rotate(node)
                    
                    node.parent.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    self._left_rotate(node.parent.parent)
        
        self.root.color = Color.BLACK
    
    def _left_rotate(self, x):
        """Perform left rotation"""
        y = x.right
        x.right = y.left
        
        if y.left != self.NIL:
            y.left.parent = x
        
        y.parent = x.parent
        
        if x.parent == self.NIL:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        
        y.left = x
        x.parent = y
    
    def _right_rotate(self, x):
        """Perform right rotation"""
        y = x.left
        x.left = y.right
        
        if y.right != self.NIL:
            y.right.parent = x
        
        y.parent = x.parent
        
        if x.parent == self.NIL:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        
        y.right = x
        x.parent = y
    
    def search(self, data):
        """Search for a node with given data"""
        return self._search_helper(self.root, data)
    
    def _search_helper(self, node, data):
        if node == self.NIL or data == node.data:
            return node
        
        if data < node.data:
            return self._search_helper(node.left, data)
        return self._search_helper(node.right, data)
    
    def inorder_traversal(self):
        """Perform inorder traversal"""
        result = []
        self._inorder_helper(self.root, result)
        return result
    
    def _inorder_helper(self, node, result):
        if node != self.NIL:
            self._inorder_helper(node.left, result)
            result.append((node.data, node.color.name))
            self._inorder_helper(node.right, result)
    
    def get_black_height(self, node=None):
        """Calculate black height of the tree"""
        if node is None:
            node = self.root
        
        if node == self.NIL:
            return 0
        
        left_black_height = self.get_black_height(node.left)
        right_black_height = self.get_black_height(node.right)
        
        # Add 1 if current node is black
        add_black = 1 if node.color == Color.BLACK else 0
        
        return max(left_black_height, right_black_height) + add_black
    
    def validate_rb_properties(self):
        """Validate Red-Black Tree properties"""
        def validate_helper(node, black_count, expected_black_count):
            if node == self.NIL:
                return black_count == expected_black_count
            
            # Check property 4: Red node cannot have red children
            if node.color == Color.RED:
                if node.left.color == Color.RED or node.right.color == Color.RED:
                    return False
            
            # Update black count
            if node.color == Color.BLACK:
                black_count += 1
            
            # Recursively check both subtrees
            return (validate_helper(node.left, black_count, expected_black_count) and
                    validate_helper(node.right, black_count, expected_black_count))
        
        if self.root == self.NIL:
            return True
        
        # Property 2: Root is black
        if self.root.color != Color.BLACK:
            return False
        
        # Property 5: All paths have same number of black nodes
        expected_black_count = self.get_black_height()
        return validate_helper(self.root, 0, expected_black_count)

# Demo and test functions
def demonstrate_red_black_tree():
    print("=== Red-Black Tree Implementation ===")
    
    rb_tree = RedBlackTree()
    
    # Insert test data
    test_data = [20, 15, 25, 10, 5, 1, 17, 4, 34, 30]
    print("Inserting values:", test_data)
    
    for value in test_data:
        rb_tree.insert(value)
        print(f"Inserted {value}, Tree valid: {rb_tree.validate_rb_properties()}")
    
    # Display tree structure
    print("\nInorder traversal (value, color):")
    traversal_result = rb_tree.inorder_traversal()
    for data, color in traversal_result:
        print(f"{data}({color})", end=" ")
    print()
    
    # Search operations
    print(f"\nBlack height: {rb_tree.get_black_height()}")
    print(f"Tree properties valid: {rb_tree.validate_rb_properties()}")
    
    # Search tests
    search_values = [15, 25, 100]
    for val in search_values:
        found = rb_tree.search(val)
        if found != rb_tree.NIL:
            print(f"Found {val}: Yes")
        else:
            print(f"Found {val}: No")

if __name__ == "__main__":
    demonstrate_red_black_tree()
    print("\n✨ Red-Black Tree implementation completed! ✨")