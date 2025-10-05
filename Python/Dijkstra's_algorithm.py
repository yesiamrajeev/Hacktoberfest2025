import heapq

def dijkstra(graph, start):
    """
    Dijkstra's algorithm to find the shortest paths from start node to all other nodes.
    
    :param graph: dict, adjacency list representation of graph
                  Example: {'A': [('B', 1), ('C', 4)], 'B': [('C', 2), ('D', 5)], ...}
    :param start: starting node
    :return: dict of shortest distances to all nodes
    """
    # Initialize distances to infinity
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    
    # Priority queue: (distance, node)
    priority_queue = [(0, start)]
    
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        # Skip if we already found a better path
        if current_distance > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            # If a shorter path is found
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances


# Example usage
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('C', 2), ('D', 5)],
    'C': [('D', 1)],
    'D': []
}

start_node = 'A'
shortest_distances = dijkstra(graph, start_node)
print(f"Shortest distances from {start_node}: {shortest_distances}")
