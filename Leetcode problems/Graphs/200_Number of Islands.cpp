class Solution
{
public:
    void bfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &visited)
    {
        visited[{i, j}] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int x = front.first;
            int y = front.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                    grid[newX][newY] == '1' && !visited[{newX, newY}])
                {
                    q.push({newX, newY});
                    visited[{newX, newY}] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        map<pair<int, int>, bool> visited;

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int n = grid[i].size();
            for (int j = 0; j < n; j++)
            {
                if (!visited[{i, j}] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};