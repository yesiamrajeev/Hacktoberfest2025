import java.util.*;

/**
 * Comprehensive Graph Traversal Algorithms Implementation in Java
 * 
 * This class provides fundamental graph algorithms including:
 * 1. Graph representation using adjacency list
 * 2. Breadth-First Search (BFS) traversal
 * 3. Depth-First Search (DFS) traversal (recursive and iterative)
 * 4. Connected components detection
 * 5. Path finding between vertices
 * 6. Cycle detection in undirected graphs
 * 
 * @author Sourav Saha (yashsaha555)
 */
public class GraphTraversal {
    
    /**
     * Graph class using adjacency list representation
     * Supports both directed and undirected graphs
     */
    static class Graph {
        private final Map<Integer, List<Integer>> adjacencyList;
        private final boolean isDirected;
        private final Set<Integer> vertices;
        
        /**
         * Constructor to create a graph
         * @param isDirected true for directed graph, false for undirected
         */
        public Graph(boolean isDirected) {
            this.adjacencyList = new HashMap<>();
            this.isDirected = isDirected;
            this.vertices = new HashSet<>();
        }
        
        /**
         * Add an edge between two vertices
         * Time Complexity: O(1)
         * @param from source vertex
         * @param to destination vertex
         */
        public void addEdge(int from, int to) {
            // Add vertices to the set
            vertices.add(from);
            vertices.add(to);
            
            // Add edge from -> to
            adjacencyList.computeIfAbsent(from, k -> new ArrayList<>()).add(to);
            
            // For undirected graph, add edge to -> from as well
            if (!isDirected) {
                adjacencyList.computeIfAbsent(to, k -> new ArrayList<>()).add(from);
            }
        }
        
        /**
         * Get neighbors of a vertex
         * @param vertex the vertex to get neighbors for
         * @return list of neighboring vertices
         */
        public List<Integer> getNeighbors(int vertex) {
            return adjacencyList.getOrDefault(vertex, new ArrayList<>());
        }
        
        /**
         * Get all vertices in the graph
         * @return set of all vertices
         */
        public Set<Integer> getVertices() {
            return new HashSet<>(vertices);
        }
        
        /**
         * Display the graph structure
         */
        public void displayGraph() {
            System.out.println("\n=== Graph Structure ===");
            System.out.println("Type: " + (isDirected ? "Directed" : "Undirected"));
            
            for (int vertex : vertices) {
                System.out.print(vertex + " -> ");
                List<Integer> neighbors = getNeighbors(vertex);
                if (neighbors.isEmpty()) {
                    System.out.println("[]");
                } else {
                    System.out.println(neighbors);
                }
            }
            System.out.println("========================\n");
        }
    }
    
    // ======================== BFS IMPLEMENTATION ========================
    
    /**
     * Breadth-First Search (BFS) Traversal
     * 
     * Algorithm:
     * 1. Start from source vertex, mark as visited
     * 2. Use a queue to maintain vertices to visit
     * 3. For each vertex, visit all unvisited neighbors
     * 4. Add neighbors to queue for future processing
     * 
     * Time Complexity: O(V + E) where V = vertices, E = edges
     * Space Complexity: O(V) for visited array and queue
     * 
     * @param graph the graph to traverse
     * @param startVertex starting vertex for BFS
     * @return list of vertices in BFS order
     */
    public static List<Integer> bfsTraversal(Graph graph, int startVertex) {
        List<Integer> bfsOrder = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        
        // Start BFS from the given vertex
        queue.offer(startVertex);
        visited.add(startVertex);
        
        System.out.println("BFS Traversal starting from vertex " + startVertex + ":");
        
        while (!queue.isEmpty()) {
            int currentVertex = queue.poll();
            bfsOrder.add(currentVertex);
            System.out.print(currentVertex + " ");
            
            // Visit all unvisited neighbors
            for (int neighbor : graph.getNeighbors(currentVertex)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.offer(neighbor);
                }
            }
        }
        
        System.out.println("\n");
        return bfsOrder;
    }
    
    /**
     * BFS to find shortest path in unweighted graph
     * 
     * @param graph the graph to search
     * @param start starting vertex
     * @param target target vertex
     * @return list representing the shortest path, empty if no path exists
     */
    public static List<Integer> bfsShortestPath(Graph graph, int start, int target) {
        Map<Integer, Integer> parent = new HashMap<>();
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        
        queue.offer(start);
        visited.add(start);
        parent.put(start, -1); // Start has no parent
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            
            if (current == target) {
                // Reconstruct path
                List<Integer> path = new ArrayList<>();
                int vertex = target;
                while (vertex != -1) {
                    path.add(0, vertex); // Add to beginning
                    vertex = parent.get(vertex);
                }
                return path;
            }
            
            for (int neighbor : graph.getNeighbors(current)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    parent.put(neighbor, current);
                    queue.offer(neighbor);
                }
            }
        }
        
        return new ArrayList<>(); // No path found
    }
    
    // ======================== DFS IMPLEMENTATION ========================
    
    /**
     * Depth-First Search (DFS) Traversal - Recursive Implementation
     * 
     * Algorithm:
     * 1. Start from source vertex, mark as visited
     * 2. Recursively visit all unvisited neighbors
     * 3. Backtrack when no unvisited neighbors remain
     * 
     * Time Complexity: O(V + E)
     * Space Complexity: O(V) for visited set + O(V) for recursion stack
     * 
     * @param graph the graph to traverse
     * @param startVertex starting vertex for DFS
     * @return list of vertices in DFS order
     */
    public static List<Integer> dfsTraversalRecursive(Graph graph, int startVertex) {
        List<Integer> dfsOrder = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        
        System.out.println("DFS Traversal (Recursive) starting from vertex " + startVertex + ":");
        dfsRecursiveHelper(graph, startVertex, visited, dfsOrder);
        System.out.println("\n");
        
        return dfsOrder;
    }
    
    /**
     * Helper method for recursive DFS
     */
    private static void dfsRecursiveHelper(Graph graph, int vertex, Set<Integer> visited, List<Integer> dfsOrder) {
        visited.add(vertex);
        dfsOrder.add(vertex);
        System.out.print(vertex + " ");
        
        // Recursively visit all unvisited neighbors
        for (int neighbor : graph.getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                dfsRecursiveHelper(graph, neighbor, visited, dfsOrder);
            }
        }
    }
    
    /**
     * Depth-First Search (DFS) Traversal - Iterative Implementation
     * 
     * Algorithm:
     * 1. Use a stack instead of recursion
     * 2. Push starting vertex onto stack
     * 3. Pop vertex, mark as visited, push unvisited neighbors
     * 
     * Time Complexity: O(V + E)
     * Space Complexity: O(V) for visited set and stack
     * 
     * @param graph the graph to traverse
     * @param startVertex starting vertex for DFS
     * @return list of vertices in DFS order
     */
    public static List<Integer> dfsTraversalIterative(Graph graph, int startVertex) {
        List<Integer> dfsOrder = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        
        stack.push(startVertex);
        
        System.out.println("DFS Traversal (Iterative) starting from vertex " + startVertex + ":");
        
        while (!stack.isEmpty()) {
            int current = stack.pop();
            
            if (!visited.contains(current)) {
                visited.add(current);
                dfsOrder.add(current);
                System.out.print(current + " ");
                
                // Add neighbors to stack (in reverse order to maintain left-to-right traversal)
                List<Integer> neighbors = graph.getNeighbors(current);
                for (int i = neighbors.size() - 1; i >= 0; i--) {
                    int neighbor = neighbors.get(i);
                    if (!visited.contains(neighbor)) {
                        stack.push(neighbor);
                    }
                }
            }
        }
        
        System.out.println("\n");
        return dfsOrder;
    }
    
    // ======================== ADVANCED GRAPH ALGORITHMS ========================
    
    /**
     * Find all connected components in an undirected graph
     * 
     * @param graph the undirected graph
     * @return list of connected components (each component is a list of vertices)
     */
    public static List<List<Integer>> findConnectedComponents(Graph graph) {
        List<List<Integer>> components = new ArrayList<>();
        Set<Integer> globalVisited = new HashSet<>();
        
        for (int vertex : graph.getVertices()) {
            if (!globalVisited.contains(vertex)) {
                List<Integer> component = new ArrayList<>();
                Set<Integer> componentVisited = new HashSet<>();
                
                // DFS to find all vertices in this component
                dfsComponentHelper(graph, vertex, componentVisited, component);
                globalVisited.addAll(componentVisited);
                components.add(component);
            }
        }
        
        return components;
    }
    
    /**
     * Helper method for finding connected components
     */
    private static void dfsComponentHelper(Graph graph, int vertex, Set<Integer> visited, List<Integer> component) {
        visited.add(vertex);
        component.add(vertex);
        
        for (int neighbor : graph.getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                dfsComponentHelper(graph, neighbor, visited, component);
            }
        }
    }
    
    /**
     * Detect cycle in undirected graph using DFS
     * 
     * @param graph the undirected graph
     * @return true if cycle exists, false otherwise
     */
    public static boolean hasCycleUndirected(Graph graph) {
        Set<Integer> visited = new HashSet<>();
        
        for (int vertex : graph.getVertices()) {
            if (!visited.contains(vertex)) {
                if (hasCycleDFS(graph, vertex, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    /**
     * Helper method for cycle detection using DFS
     */
    private static boolean hasCycleDFS(Graph graph, int vertex, int parent, Set<Integer> visited) {
        visited.add(vertex);
        
        for (int neighbor : graph.getNeighbors(vertex)) {
            if (!visited.contains(neighbor)) {
                if (hasCycleDFS(graph, neighbor, vertex, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true; // Back edge found, cycle detected
            }
        }
        return false;
    }
    
    // ======================== DEMONSTRATION METHODS ========================
    
    /**
     * Create a sample undirected graph for demonstration
     */
    public static Graph createSampleUndirectedGraph() {
        Graph graph = new Graph(false); // Undirected graph
        
        // Create a graph with the following structure:
        //     0
        //    / \
        //   1   2
        //  /   / \
        // 3   4   5
        //      \ /
        //       6
        
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 4);
        graph.addEdge(2, 5);
        graph.addEdge(4, 6);
        graph.addEdge(5, 6);
        
        return graph;
    }
    
    /**
     * Create a sample directed graph for demonstration
     */
    public static Graph createSampleDirectedGraph() {
        Graph graph = new Graph(true); // Directed graph
        
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 5);
        
        return graph;
    }
    
    /**
     * Demonstrate all graph traversal algorithms
     */
    public static void demonstrateTraversals() {
        System.out.println("🚀 Graph Traversal Algorithms Demonstration");
        System.out.println("=".repeat(50));
        
        // Create and display undirected graph
        Graph undirectedGraph = createSampleUndirectedGraph();
        undirectedGraph.displayGraph();
        
        // BFS Demonstration
        System.out.println("📊 BREADTH-FIRST SEARCH (BFS)");
        System.out.println("-".repeat(30));
        List<Integer> bfsResult = bfsTraversal(undirectedGraph, 0);
        System.out.println("BFS Result: " + bfsResult);
        
        // Shortest Path using BFS
        List<Integer> shortestPath = bfsShortestPath(undirectedGraph, 0, 6);
        System.out.println("Shortest path from 0 to 6: " + shortestPath);
        System.out.println();
        
        // DFS Demonstrations
        System.out.println("🔍 DEPTH-FIRST SEARCH (DFS)");
        System.out.println("-".repeat(30));
        List<Integer> dfsRecursive = dfsTraversalRecursive(undirectedGraph, 0);
        System.out.println("DFS Recursive Result: " + dfsRecursive);
        
        List<Integer> dfsIterative = dfsTraversalIterative(undirectedGraph, 0);
        System.out.println("DFS Iterative Result: " + dfsIterative);
        System.out.println();
        
        // Connected Components
        System.out.println("🔗 CONNECTED COMPONENTS");
        System.out.println("-".repeat(30));
        List<List<Integer>> components = findConnectedComponents(undirectedGraph);
        System.out.println("Connected Components: " + components);
        System.out.println();
        
        // Cycle Detection
        System.out.println("🔄 CYCLE DETECTION");
        System.out.println("-".repeat(30));
        boolean hasCycle = hasCycleUndirected(undirectedGraph);
        System.out.println("Graph has cycle: " + hasCycle);
        System.out.println();
        
        // Directed Graph Example
        System.out.println("➡️  DIRECTED GRAPH EXAMPLE");
        System.out.println("-".repeat(30));
        Graph directedGraph = createSampleDirectedGraph();
        directedGraph.displayGraph();
        bfsTraversal(directedGraph, 0);
        dfsTraversalRecursive(directedGraph, 0);
    }
    
    /**
     * Interactive graph creation method
     */
    public static void interactiveGraphDemo() {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("\n🎮 Interactive Graph Creation");
        System.out.println("=".repeat(30));
        
        System.out.print("Create directed graph? (y/n): ");
        boolean isDirected = scanner.next().toLowerCase().startsWith("y");
        
        Graph graph = new Graph(isDirected);
        
        System.out.println("Enter edges (format: 'from to', enter -1 -1 to stop):");
        
        while (true) {
            System.out.print("Edge: ");
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            
            if (from == -1 && to == -1) break;
            
            graph.addEdge(from, to);
            System.out.println("Added edge: " + from + " -> " + to);
        }
        
        graph.displayGraph();
        
        System.out.print("Enter starting vertex for traversal: ");
        int startVertex = scanner.nextInt();
        
        System.out.println("\nChoose traversal type:");
        System.out.println("1. BFS");
        System.out.println("2. DFS (Recursive)");
        System.out.println("3. DFS (Iterative)");
        System.out.print("Choice: ");
        
        int choice = scanner.nextInt();
        
        switch (choice) {
            case 1:
                bfsTraversal(graph, startVertex);
                break;
            case 2:
                dfsTraversalRecursive(graph, startVertex);
                break;
            case 3:
                dfsTraversalIterative(graph, startVertex);
                break;
            default:
                System.out.println("Invalid choice!");
        }
    }
    
    // ======================== MAIN METHOD ========================
    
    /**
     * Main method to demonstrate all graph traversal algorithms
     * Perfect for learning and interview preparation!
     */
    public static void main(String[] args) {
        try {
            // Run predefined demonstrations
            demonstrateTraversals();
            
            // Optional: Interactive demo
            Scanner scanner = new Scanner(System.in);
            System.out.print("Run interactive demo? (y/n): ");
            
            if (scanner.next().toLowerCase().startsWith("y")) {
                interactiveGraphDemo();
            }
            
            System.out.println("\n✅ Graph Traversal Demonstration Complete!");
            System.out.println("📚 Perfect for interview preparation and learning!");
            
        } catch (Exception e) {
            System.err.println("Error during demonstration: " + e.getMessage());
            e.printStackTrace();
        }
    }
}