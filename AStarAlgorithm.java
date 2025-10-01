import java.util.*;

class Node implements Comparable<Node> {
    int x, y;       // coordinates (for grid)
    int g, h;       // g = cost from start, h = heuristic
    Node parent;    // for path reconstruction

    public Node(int x, int y, int g, int h, Node parent) {
        this.x = x;
        this.y = y;
        this.g = g;
        this.h = h;
        this.parent = parent;
    }

    public int f() {
        return g + h;
    }

    @Override
    public int compareTo(Node other) {
        return this.f() - other.f();
    }
}

public class AStarAlgorithm {

    // Manhattan Distance heuristic
    private static int heuristic(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public static List<Node> aStarSearch(int[][] grid, int[] start, int[] goal) {
        int rows = grid.length, cols = grid[0].length;

        PriorityQueue<Node> open = new PriorityQueue<>();
        boolean[][] closed = new boolean[rows][cols];

        Node startNode = new Node(start[0], start[1], 0,
                heuristic(start[0], start[1], goal[0], goal[1]), null);

        open.add(startNode);

        while (!open.isEmpty()) {
            Node current = open.poll();

            // reached goal
            if (current.x == goal[0] && current.y == goal[1]) {
                return reconstructPath(current);
            }

            closed[current.x][current.y] = true;

            // neighbors (4 directions)
            int[][] directions = {{1,0},{-1,0},{0,1},{0,-1}};
            for (int[] d : directions) {
                int nx = current.x + d[0];
                int ny = current.y + d[1];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    grid[nx][ny] == 0 && !closed[nx][ny]) {

                    int g = current.g + 1;
                    int h = heuristic(nx, ny, goal[0], goal[1]);
                    Node neighbor = new Node(nx, ny, g, h, current);

                    open.add(neighbor);
                }
            }
        }

        return new ArrayList<>(); // no path found
    }

    private static List<Node> reconstructPath(Node node) {
        List<Node> path = new ArrayList<>();
        while (node != null) {
            path.add(node);
            node = node.parent;
        }
        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        // 0 = free cell, 1 = blocked
        int[][] grid = {
                {0, 0, 0, 0, 0},
                {1, 1, 0, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1},
                {0, 0, 0, 0, 0}
        };

        int[] start = {0, 0};
        int[] goal = {4, 4};

        List<Node> path = aStarSearch(grid, start, goal);

        if (!path.isEmpty()) {
            System.out.println("Shortest Path:");
            for (Node n : path) {
                System.out.print("(" + n.x + "," + n.y + ") ");
            }
        } else {
            System.out.println("No path found!");
        }
    }
}
