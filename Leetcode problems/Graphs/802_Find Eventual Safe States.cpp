class Solution
{
public:
    bool dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, vector<vector<int>> &graph, int safeNodes[])
    {
        visited[node] = 1;
        safeNodes[node] = 0;
        dfsVisited[node] = 1;

        for (auto nbr : graph[node])
        {
            if (!visited[nbr])
            {
                bool ans = dfs(nbr, visited, dfsVisited, graph, safeNodes);
                if (ans)
                {
                    return true;
                }
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }

        dfsVisited[node] = 0;
        safeNodes[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        int n = graph.size();
        int safeNodes[n];
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, dfsVisited, graph, safeNodes);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (safeNodes[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};