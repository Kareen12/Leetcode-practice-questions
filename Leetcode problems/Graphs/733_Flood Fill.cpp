class Solution
{
public:
    void dfs(int srr, int src, int oldColor, int newColor, map<pair<int, int>, bool> &visited, vector<vector<int>> &ans)
    {
        visited[{srr, src}] = 1;
        ans[srr][src] = newColor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = srr + dx[i];
            int newY = src + dy[i];

            if (newX >= 0 && newX < ans.size() && newY >= 0 && newY < ans[0].size() && !visited[{newX, newY}] && ans[newX][newY] == oldColor)
            {

                dfs(newX, newY, oldColor, newColor, visited, ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        map<pair<int, int>, bool> visited;

        int oldColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, oldColor, color, visited, ans);
        return ans;
    }
};