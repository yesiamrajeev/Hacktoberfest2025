/**
 * Dijkstra's Shortest Path Algorithm Implementation in C
 * 
 * Dijkstra's algorithm is used to find the shortest path between nodes in a graph,
 * which may represent, for example, road networks. It was conceived by computer
 * scientist Edsger W. Dijkstra in 1956.
 * 
 * Time Complexity: O((V + E) log V) with priority queue
 * Space Complexity: O(V)
 * 
 * @author Hacktoberfest2025 Contributor
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Structure to represent a graph edge
typedef struct {
    int dest;
    int weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Structure for priority queue node
typedef struct {
    int vertex;
    int distance;
} PQNode;

// Structure for priority queue
typedef struct {
    PQNode nodes[MAX_VERTICES];
    int size;
} PriorityQueue;

/**
 * Initialize graph with given number of vertices
 */
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    // Initialize adjacency matrix with infinity
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0;  // Distance from vertex to itself is 0
            } else {
                graph->adjMatrix[i][j] = INF;  // No direct edge initially
            }
        }
    }
    
    return graph;
}

/**
 * Add an edge to the graph
 */
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    // For undirected graph, uncomment the next line
    // graph->adjMatrix[dest][src] = weight;
}

/**
 * Initialize priority queue
 */
void initPQ(PriorityQueue* pq) {
    pq->size = 0;
}

/**
 * Check if priority queue is empty
 */
bool isPQEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

/**
 * Insert element into priority queue
 */
void insertPQ(PriorityQueue* pq, int vertex, int distance) {
    int i = pq->size++;
    
    // Insert at the end and bubble up
    while (i > 0 && pq->nodes[(i-1)/2].distance > distance) {
        pq->nodes[i] = pq->nodes[(i-1)/2];
        i = (i-1)/2;
    }
    
    pq->nodes[i].vertex = vertex;
    pq->nodes[i].distance = distance;
}

/**
 * Extract minimum element from priority queue
 */
PQNode extractMin(PriorityQueue* pq) {
    PQNode min = pq->nodes[0];
    PQNode last = pq->nodes[--pq->size];
    
    int i = 0;
    while (2*i + 1 < pq->size) {
        int child = 2*i + 1;
        
        // Find smaller child
        if (child + 1 < pq->size && 
            pq->nodes[child + 1].distance < pq->nodes[child].distance) {
            child++;
        }
        
        if (last.distance <= pq->nodes[child].distance) {
            break;
        }
        
        pq->nodes[i] = pq->nodes[child];
        i = child;
    }
    
    pq->nodes[i] = last;
    return min;
}

/**
 * Find minimum distance vertex that hasn't been visited
 */
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INF, min_index = -1;
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

/**
 * Dijkstra's algorithm implementation using adjacency matrix
 */
void dijkstra(Graph* graph, int src) {
    int vertices = graph->vertices;
    int dist[MAX_VERTICES];     // Distance from source to each vertex
    bool visited[MAX_VERTICES]; // Track visited vertices
    int parent[MAX_VERTICES];   // Store shortest path tree
    
    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    // Distance from source to itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick minimum distance vertex from unvisited vertices
        int u = minDistance(dist, visited, vertices);
        
        if (u == -1) break;  // No more reachable vertices
        
        // Mark the picked vertex as visited
        visited[u] = true;
        
        // Update distance value of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            // Update dist[v] if not visited, there's an edge from u to v,
            // and total weight of path from src to v through u is smaller
            if (!visited[v] && graph->adjMatrix[u][v] != INF && 
                dist[u] != INF && dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print the shortest distances
    printf("\n=== Dijkstra's Shortest Path Results ===\n");
    printf("Vertex\tDistance from Source (%d)\tPath\n", src);
    printf("------\t------------------------\t----\n");
    
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\t\t\t\tNo path\n", i);
        } else {
            printf("%d\t%d\t\t\t\t", i, dist[i]);
            
            // Print path
            int path[MAX_VERTICES];
            int pathLength = 0;
            int current = i;
            
            // Build path from destination to source
            while (current != -1) {
                path[pathLength++] = current;
                current = parent[current];
            }
            
            // Print path from source to destination
            for (int j = pathLength - 1; j >= 0; j--) {
                printf("%d", path[j]);
                if (j > 0) printf(" -> ");
            }
            printf("\n");
        }
    }
}

/**
 * Dijkstra's algorithm using priority queue (more efficient)
 */
void dijkstraPQ(Graph* graph, int src) {
    int vertices = graph->vertices;
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    PriorityQueue pq;
    
    // Initialize
    initPQ(&pq);
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    
    dist[src] = 0;
    insertPQ(&pq, src, 0);
    
    while (!isPQEmpty(&pq)) {
        PQNode current = extractMin(&pq);
        int u = current.vertex;
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (int v = 0; v < vertices; v++) {
            if (graph->adjMatrix[u][v] != INF && !visited[v]) {
                int newDist = dist[u] + graph->adjMatrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    insertPQ(&pq, v, newDist);
                }
            }
        }
    }
    
    // Print results
    printf("\n=== Dijkstra's Algorithm (Priority Queue) ===\n");
    printf("Vertex\tDistance from Source (%d)\n", src);
    printf("------\t------------------------\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

/**
 * Display the graph's adjacency matrix
 */
void displayGraph(Graph* graph) {
    printf("\n=== Graph Adjacency Matrix ===\n");
    printf("   ");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == INF) {
                printf(" INF");
            } else {
                printf("%4d", graph->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * Main function to demonstrate Dijkstra's algorithm
 */
int main() {
    printf("🚀 Dijkstra's Shortest Path Algorithm 🚀\n");
    printf("=========================================\n");
    
    // Create a sample graph
    Graph* graph = createGraph(6);
    
    // Add edges (directed graph)
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 2, 4, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 5, 3);
    
    // Display the graph
    displayGraph(graph);
    
    // Run Dijkstra's algorithm from vertex 0
    dijkstra(graph, 0);
    
    // Run optimized version with priority queue
    dijkstraPQ(graph, 0);
    
    // Test with different source
    printf("\n" "=" * 50 "\n");
    dijkstra(graph, 2);
    
    // Cleanup
    free(graph);
    
    printf("\n✨ Dijkstra's algorithm demonstration completed! ✨\n");
    
    return 0;
}