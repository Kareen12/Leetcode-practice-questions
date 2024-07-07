class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> arr = grid;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    pair<int, int> coordinates = make_pair(i, j);
                    q.push({coordinates, 0});
                }
            }
        }

        int minutes = 0;
        while (!q.empty())
        {
            auto frontt = q.front();
            q.pop();

            int x = frontt.first.first;
            int y = frontt.first.second;
            int time = frontt.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() &&
                    arr[newX][newY] == 1)
                {
                    pair<int, int> newCoordinates = make_pair(newX, newY);
                    minutes = max(minutes, time + 1);
                    q.push({newCoordinates, time + 1});
                    arr[newX][newY] = 2;
                }
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                if (arr[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return minutes;
    }
};