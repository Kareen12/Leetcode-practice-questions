class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            int currDist = front.first;
            int x = front.second.first;
            int y = front.second.second;

            if (x == heights.size() - 1 && y == heights[0].size() - 1)
                return dist[x][y];

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < heights.size() && newX >= 0 && newY >= 0 && newY < heights[0].size())
                {
                    int currDistt = abs(heights[x][y] - heights[newX][newY]);
                    int maxx = max(currDistt, currDist);
                    if (maxx < dist[newX][newY])
                    {
                        dist[newX][newY] = maxx;
                        pq.push({maxx, {newX, newY}});
                    }
                    // dist[newX][newY] = min(dist[newX][newY], maxx);
                }
            }
        }
        return 0;
    }
};