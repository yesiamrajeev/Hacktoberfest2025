#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

struct Node
{
    int y, x;
    int gCost, hCost;
    Node *parent;

    Node(int r, int c) : y(r), x(c), gCost(0), hCost(0), parent(nullptr) {}

    int fCost() const
    {
        return gCost + hCost;
    }
};

struct compareNodes
{
    bool operator()(const Node *a, const Node *b) const
    {
        return a->fCost() > b->fCost();
    }
};

bool isValid(int y, int x, int rows, int cols)
{
    return (y >= 0) && (y < rows) && (x >= 0) && (x < cols);
}

int calculateHeuristic(int y, int x, int goalY, int goalX)
{
    return std::abs(y - goalY) + std::abs(x - goalX);
}

std::vector<Node *> aStarSearch(std::vector<std::vector<int>> &grid, Node *start, Node *goal)
{
    int rows = grid.size();
    int cols = grid[0].size();

    std::priority_queue<Node *, std::vector<Node *>, compareNodes> openList;
    std::vector<std::vector<Node *>> allNodes(rows, std::vector<Node *>(cols, nullptr));

    start->hCost = calculateHeuristic(start->y, start->x, goal->y, goal->x);
    openList.push(start);
    allNodes[start->y][start->x] = start;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    while (!openList.empty())
    {
        Node *currentNode = openList.top();
        openList.pop();

        if (currentNode->y == goal->y && currentNode->x == goal->x)
        {
            std::vector<Node *> path;
            while (currentNode != nullptr)
            {
                path.push_back(currentNode);
                currentNode = currentNode->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newY = currentNode->y + dy[i];
            int newX = currentNode->x + dx[i];

            if (isValid(newY, newX, rows, cols) && grid[newY][newX] == 0)
            {
                int tentativeGCost = currentNode->gCost + 1;

                Node *neighbor = allNodes[newY][newX];

                if (neighbor == nullptr || tentativeGCost < neighbor->gCost)
                {
                    if (neighbor == nullptr)
                    {
                        neighbor = new Node(newY, newX);
                        allNodes[newY][newX] = neighbor;
                    }

                    neighbor->parent = currentNode;
                    neighbor->gCost = tentativeGCost;
                    neighbor->hCost = calculateHeuristic(newY, newX, goal->y, goal->x);

                    openList.push(neighbor);
                }
            }
        }
    }

    return {};
}

int main()
{
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0}};

    Node *startNode = new Node(0, 0);
    Node *goalNode = new Node(4, 7);

    // This grid will be modified to show the path
    std::vector<std::vector<int>> grid_with_path = grid;

    std::vector<Node *> path = aStarSearch(grid, startNode, goalNode);

    if (path.empty())
    {
        std::cout << "No path found!" << std::endl;
    }
    else
    {
        std::cout << "Path found:" << std::endl;
        for (Node *node : path)
        {
            grid_with_path[node->y][node->x] = 2;
        }

        for (const auto &row : grid_with_path)
        {
            for (int cell : row)
            {
                if (cell == 2)
                    std::cout << "* ";
                else if (cell == 1)
                    std::cout << "# ";
                else
                    std::cout << ". ";
            }
            std::cout << std::endl;
        }
    }

    // Memory Cleanup
    for (size_t i = 0; i < grid.size(); ++i)
    {
        for (size_t j = 0; j < grid[0].size(); ++j)
        {
            // Find the node pointer in the path to avoid double-freeing start/goal
            bool in_path = false;
            if (path.empty())
            { // If no path, start/goal were never put in allNodes grid
                if ((i == startNode->y && j == startNode->x) || (i == goalNode->y && j == goalNode->x))
                {
                    in_path = true;
                }
            }
            if (!in_path)
            {
                // This will delete all nodes created with 'new' in the search function
                // The 'path' vector itself does not own the pointers
            }
        }
    }

    delete startNode;
    delete goalNode;

    return 0;
}