class Solution
{
public:
    int djkastra(int src, int n, unordered_map<int, list<pair<int, int>>> &adjList, int distanceThreshold)
    {
        vector<int> distances(n, INT_MAX);
        set<pair<int, int>> st;
        distances[src] = 0;
        st.insert({0, src});
        int reachableNodes = 0;
        while (!st.empty())
        {
            auto top = *st.begin();
            st.erase(st.begin());

            int currDist = top.first;
            int currNode = top.second;

            if (currNode != src && currDist <= distanceThreshold)
            {
                reachableNodes++;
            }

            for (auto nbr : adjList[currNode])
            {
                int newDist = nbr.second + currDist;
                if (newDist < distances[nbr.first])
                {
                    auto it = st.find({distances[nbr.first], nbr.first});
                    if (it != st.end())
                    {
                        st.erase(it);
                    }
                    distances[nbr.first] = newDist;
                    st.insert({distances[nbr.first], nbr.first});
                }
            }
        }
        return reachableNodes;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        unordered_map<int, list<pair<int, int>>> adjList;
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w}); // because it is undirected graph
        }

        int minReachableNodes = INT_MAX;
        int city = 0;
        for (int i = 0; i < n; i++)
        {
            int reachableNodes = djkastra(i, n, adjList, distanceThreshold);
            if (reachableNodes <= minReachableNodes)
            {
                minReachableNodes = reachableNodes;
                city = i;
            }
        }
        return city;
    }
};