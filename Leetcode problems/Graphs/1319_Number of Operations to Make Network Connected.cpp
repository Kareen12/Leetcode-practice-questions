class Solution
{
public:
    int findParent(int u, vector<int> &parent)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (rank[u] > rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int extraEdges = 0;
        for (auto i : connections)
        {
            int u = i[0];
            int v = i[1];

            u = findParent(u, parent);
            v = findParent(v, parent);

            if (u != v)
            {
                unionSet(u, v, parent, rank);
            }
            else
            {
                extraEdges++;
            }
        }
        int noOFConnectedComponents = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                noOFConnectedComponents++;
        }
        int noOFRequiredEdges = noOFConnectedComponents - 1;
        return extraEdges >= noOFRequiredEdges ? noOFRequiredEdges : -1;
    }
};