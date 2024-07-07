class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, int src, unordered_map<int, bool> &visited)
    {
        visited[src] = 1;

        int n = isConnected[src].size();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                // koi node khudse connected ka bhi 1 ayega but we dont want to count that
                if (src != i && isConnected[src][i] == 1)
                {
                    dfs(isConnected, i, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_map<int, bool> visited;
        int count = 0;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};