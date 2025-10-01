/**
 * Advanced Graph Algorithms Implementation in C
 * 
 * This file contains implementations of several important graph algorithms:
 * 1. Bellman-Ford Algorithm (Shortest Path with Negative Weights)
 * 2. Floyd-Warshall Algorithm (All-Pairs Shortest Path)
 * 3. Topological Sort using DFS
 * 4. Strongly Connected Components (Kosaraju's Algorithm)
 * 5. Minimum Spanning Tree (Kruskal's Algorithm)
 * 
 * These algorithms form the foundation of many real-world applications
 * including network routing, social network analysis, and optimization problems.
 * 
 * @author Hacktoberfest2025 Advanced Contributor
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define INF INT_MAX

// Edge structure for various algorithms
typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

// Graph structure using adjacency list
typedef struct GraphNode {
    int vertex;
    int weight;
    struct GraphNode* next;
} GraphNode;

typedef struct {
    int vertices;
    int edges;
    GraphNode* adjList[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int finishTime[MAX_VERTICES];
    int time;
} Graph;

// Union-Find structure for Kruskal's algorithm
typedef struct {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} UnionFind;

// ==================== UTILITY FUNCTIONS ====================

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = 0;
    graph->time = 0;
    
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
        graph->finishTime[i] = 0;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    graph->edges++;
}

void addUndirectedEdge(Graph* graph, int src, int dest, int weight) {
    addEdge(graph, src, dest, weight);
    addEdge(graph, dest, src, weight);
    graph->edges--; // Adjust count since we count each edge once
}

void resetGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        graph->visited[i] = false;
        graph->finishTime[i] = 0;
    }
    graph->time = 0;
}

// ==================== BELLMAN-FORD ALGORITHM ====================

/**
 * Bellman-Ford Algorithm for shortest paths with negative weights
 * Time Complexity: O(V * E)
 * Space Complexity: O(V)
 * 
 * Returns true if no negative cycles exist, false otherwise
 */
bool bellmanFord(Graph* graph, int source, int dist[], int parent[]) {
    int V = graph->vertices;
    
    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
    
    // Create edge list from adjacency list
    Edge edges[MAX_EDGES];
    int edgeCount = 0;
    
    for (int u = 0; u < V; u++) {
        GraphNode* current = graph->adjList[u];
        while (current != NULL) {
            edges[edgeCount].source = u;
            edges[edgeCount].destination = current->vertex;
            edges[edgeCount].weight = current->weight;
            edgeCount++;
            current = current->next;
        }
    }
    
    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    
    // Check for negative cycles
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int weight = edges[j].weight;
        
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            return false; // Negative cycle detected
        }
    }
    
    return true;
}

// ==================== FLOYD-WARSHALL ALGORITHM ====================

/**
 * Floyd-Warshall Algorithm for all-pairs shortest paths
 * Time Complexity: O(V³)
 * Space Complexity: O(V²)
 */
void floydWarshall(int adjMatrix[][MAX_VERTICES], int V, 
                   int dist[][MAX_VERTICES], int next[][MAX_VERTICES]) {
    
    // Initialize distance and next matrices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = adjMatrix[i][j];
            if (i != j && adjMatrix[i][j] != INF) {
                next[i][j] = j;
            } else {
                next[i][j] = -1;
            }
        }
    }
    
    // Floyd-Warshall main algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int next[][MAX_VERTICES], int start, int end) {
    if (next[start][end] == -1) {
        printf("No path");
        return;
    }
    
    printf("%d", start);
    while (start != end) {
        start = next[start][end];
        printf(" -> %d", start);
    }
}

// ==================== TOPOLOGICAL SORT ====================

void topologicalSortDFS(Graph* graph, int v, int* stack, int* top) {
    graph->visited[v] = true;
    
    GraphNode* current = graph->adjList[v];
    while (current != NULL) {
        if (!graph->visited[current->vertex]) {
            topologicalSortDFS(graph, current->vertex, stack, top);
        }
        current = current->next;
    }
    
    stack[++(*top)] = v;
}

/**
 * Topological Sort using DFS
 * Time Complexity: O(V + E)
 * Works only on Directed Acyclic Graphs (DAG)
 */
void topologicalSort(Graph* graph, int result[]) {
    resetGraph(graph);
    int stack[MAX_VERTICES];
    int top = -1;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (!graph->visited[i]) {
            topologicalSortDFS(graph, i, stack, &top);
        }
    }
    
    // Copy result in reverse order
    for (int i = 0; i <= top; i++) {
        result[i] = stack[top - i];
    }
}

// ==================== STRONGLY CONNECTED COMPONENTS ====================

void fillOrder(Graph* graph, int v, int* stack, int* top) {
    graph->visited[v] = true;
    
    GraphNode* current = graph->adjList[v];
    while (current != NULL) {
        if (!graph->visited[current->vertex]) {
            fillOrder(graph, current->vertex, stack, top);
        }
        current = current->next;
    }
    
    stack[++(*top)] = v;
}

void dfsUtil(Graph* graph, int v, int component[], int compNum) {
    graph->visited[v] = true;
    component[v] = compNum;
    
    GraphNode* current = graph->adjList[v];
    while (current != NULL) {
        if (!graph->visited[current->vertex]) {
            dfsUtil(graph, current->vertex, component, compNum);
        }
        current = current->next;
    }
}

Graph* getTranspose(Graph* graph) {
    Graph* transpose = createGraph(graph->vertices);
    
    for (int v = 0; v < graph->vertices; v++) {
        GraphNode* current = graph->adjList[v];
        while (current != NULL) {
            addEdge(transpose, current->vertex, v, current->weight);
            current = current->next;
        }
    }
    
    return transpose;
}

/**
 * Kosaraju's Algorithm for finding Strongly Connected Components
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
int stronglyConnectedComponents(Graph* graph, int component[]) {
    int stack[MAX_VERTICES];
    int top = -1;
    
    // Step 1: Fill vertices in stack according to their finishing times
    resetGraph(graph);
    for (int i = 0; i < graph->vertices; i++) {
        if (!graph->visited[i]) {
            fillOrder(graph, i, stack, &top);
        }
    }
    
    // Step 2: Create transpose graph
    Graph* transpose = getTranspose(graph);
    
    // Step 3: Process all vertices in order defined by stack
    resetGraph(transpose);
    int componentCount = 0;
    
    while (top >= 0) {
        int v = stack[top--];
        if (!transpose->visited[v]) {
            dfsUtil(transpose, v, component, componentCount);
            componentCount++;
        }
    }
    
    free(transpose);
    return componentCount;
}

// ==================== MINIMUM SPANNING TREE (KRUSKAL) ====================

void initUnionFind(UnionFind* uf, int n) {
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

int findSet(UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = findSet(uf, uf->parent[x]); // Path compression
    }
    return uf->parent[x];
}

bool unionSets(UnionFind* uf, int x, int y) {
    int rootX = findSet(uf, x);
    int rootY = findSet(uf, y);
    
    if (rootX == rootY) return false; // Already in same set
    
    // Union by rank
    if (uf->rank[rootX] < uf->rank[rootY]) {
        uf->parent[rootX] = rootY;
    } else if (uf->rank[rootX] > uf->rank[rootY]) {
        uf->parent[rootY] = rootX;
    } else {
        uf->parent[rootY] = rootX;
        uf->rank[rootX]++;
    }
    
    return true;
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

/**
 * Kruskal's Algorithm for Minimum Spanning Tree
 * Time Complexity: O(E log E)
 * Space Complexity: O(V)
 */
int kruskalMST(Graph* graph, Edge mst[], int* mstWeight) {
    Edge edges[MAX_EDGES];
    int edgeCount = 0;
    
    // Extract all edges
    for (int u = 0; u < graph->vertices; u++) {
        GraphNode* current = graph->adjList[u];
        while (current != NULL) {
            if (u < current->vertex) { // Avoid duplicate edges in undirected graph
                edges[edgeCount].source = u;
                edges[edgeCount].destination = current->vertex;
                edges[edgeCount].weight = current->weight;
                edgeCount++;
            }
            current = current->next;
        }
    }
    
    // Sort edges by weight
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
    
    UnionFind uf;
    initUnionFind(&uf, graph->vertices);
    
    int mstEdges = 0;
    *mstWeight = 0;
    
    for (int i = 0; i < edgeCount && mstEdges < graph->vertices - 1; i++) {
        if (unionSets(&uf, edges[i].source, edges[i].destination)) {
            mst[mstEdges++] = edges[i];
            *mstWeight += edges[i].weight;
        }
    }
    
    return mstEdges;
}

// ==================== DEMONSTRATION FUNCTIONS ====================

void demonstrateBellmanFord() {
    printf("\n=== Bellman-Ford Algorithm Demo ===\n");
    
    Graph* graph = createGraph(5);
    
    // Add edges (some with negative weights)
    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);
    
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    
    if (bellmanFord(graph, 0, dist, parent)) {
        printf("No negative cycle detected.\n");
        printf("Shortest distances from vertex 0:\n");
        for (int i = 0; i < graph->vertices; i++) {
            if (dist[i] == INF) {
                printf("Vertex %d: INF\n", i);
            } else {
                printf("Vertex %d: %d\n", i, dist[i]);
            }
        }
    } else {
        printf("Negative cycle detected!\n");
    }
    
    free(graph);
}

void demonstrateFloydWarshall() {
    printf("\n=== Floyd-Warshall Algorithm Demo ===\n");
    
    int V = 4;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    
    int dist[MAX_VERTICES][MAX_VERTICES];
    int next[MAX_VERTICES][MAX_VERTICES];
    
    floydWarshall(adjMatrix, V, dist, next);
    
    printf("All-pairs shortest distances:\n");
    printf("     ");
    for (int j = 0; j < V; j++) {
        printf("%8d", j);
    }
    printf("\n");
    
    for (int i = 0; i < V; i++) {
        printf("%4d ", i);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("     INF");
            } else {
                printf("%8d", dist[i][j]);
            }
        }
        printf("\n");
    }
    
    printf("\nSample paths:\n");
    printf("Path 0->3: ");
    printPath(next, 0, 3);
    printf("\nPath 1->0: ");
    printPath(next, 1, 0);
    printf("\n");
}

void demonstrateTopologicalSort() {
    printf("\n=== Topological Sort Demo ===\n");
    
    Graph* graph = createGraph(6);
    
    // Create a DAG
    addEdge(graph, 5, 2, 1);
    addEdge(graph, 5, 0, 1);
    addEdge(graph, 4, 0, 1);
    addEdge(graph, 4, 1, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 1, 1);
    
    int result[MAX_VERTICES];
    topologicalSort(graph, result);
    
    printf("Topological ordering: ");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(graph);
}

void demonstrateSCC() {
    printf("\n=== Strongly Connected Components Demo ===\n");
    
    Graph* graph = createGraph(5);
    
    addEdge(graph, 1, 0, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 2, 1, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 3, 4, 1);
    
    int component[MAX_VERTICES];
    int numComponents = stronglyConnectedComponents(graph, component);
    
    printf("Number of strongly connected components: %d\n", numComponents);
    printf("Component assignments:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: Component %d\n", i, component[i]);
    }
    
    free(graph);
}

void demonstrateMST() {
    printf("\n=== Minimum Spanning Tree (Kruskal) Demo ===\n");
    
    Graph* graph = createGraph(4);
    
    // Create undirected weighted graph
    addUndirectedEdge(graph, 0, 1, 10);
    addUndirectedEdge(graph, 0, 2, 6);
    addUndirectedEdge(graph, 0, 3, 5);
    addUndirectedEdge(graph, 1, 3, 15);
    addUndirectedEdge(graph, 2, 3, 4);
    
    Edge mst[MAX_VERTICES];
    int mstWeight;
    int edgeCount = kruskalMST(graph, mst, &mstWeight);
    
    printf("Minimum Spanning Tree edges:\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("Edge (%d, %d) with weight %d\n", 
               mst[i].source, mst[i].destination, mst[i].weight);
    }
    printf("Total MST weight: %d\n", mstWeight);
    
    free(graph);
}

int main() {
    printf("🚀 Advanced Graph Algorithms Implementation 🚀\n");
    printf("==============================================\n");
    
    demonstrateBellmanFord();
    demonstrateFloydWarshall();
    demonstrateTopologicalSort();
    demonstrateSCC();
    demonstrateMST();
    
    printf("\n✨ All graph algorithms demonstrated successfully! ✨\n");
    
    return 0;
}