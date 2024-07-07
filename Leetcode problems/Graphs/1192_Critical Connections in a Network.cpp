class Solution
{
public:
    vector<vector<int>> ans;
    // Function to find if the given edge is a bridge in graph.
    void solve(int src, int parent, int &timer, vector<int> &tin,
               vector<int> &low, vector<int> connections[], unordered_map<int, bool> &visited)
    {
        visited[src] = 1;
        low[src] = tin[src] = timer;
        timer++;

        for (auto nbr : connections[src])
        {
            if (nbr == parent)
                continue;

            if (!visited[nbr])
            {
                solve(nbr, src, timer, tin, low, connections, visited);
                // agar  nbr ka timer ow ho to
                low[src] = min(low[src], low[nbr]);
                if (low[nbr] > tin[src])
                {
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else
            {
                low[src] = min(low[nbr], low[src]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto edge : connections)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, bool> visited;
        int timer = 0;
        vector<int> tin(n);
        vector<int> low(n);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                solve(i, -1, timer, tin, low, adj, visited);
            }
        }
        return ans;
    }
};