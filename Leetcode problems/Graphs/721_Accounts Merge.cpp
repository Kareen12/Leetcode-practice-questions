class Solution
{
public:
    int findParent(int node, vector<int> parent)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mp;
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string s = accounts[i][j];
                if (mp.find(s) == mp.end())
                {
                    mp[s] = i;
                }
                else
                {
                    unionSet(i, mp[s], parent, rank);
                }
            }
        }

        unordered_map<int, set<string>> preAns;
        for (auto it : mp)
        {
            string s = it.first;
            int number = it.second;

            number = findParent(number, parent);
            preAns[number].insert(s);
        }

        vector<vector<string>> ans;
        for (auto j : preAns)
        {
            int fst = j.first;
            auto sec = j.second;
            string name = accounts[fst][0];
            vector<string> v;
            v.push_back(name);
            for (auto st : sec)
            {
                v.push_back(st);
            }
            ans.push_back(v);
        }
        return ans;
    }
};