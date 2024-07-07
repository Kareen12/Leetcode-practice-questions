class Solution
{
public:
    bool solveUsingTopologicalSort(unordered_map<int, list<int>> &adjList, int n)
    {
        unordered_map<int, int> indegree;
        queue<int> q;

        for (auto nbr : adjList)
        {
            int src = nbr.first;
            for (auto i : nbr.second)
            {
                indegree[i]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto nbr : adjList[front])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        return ans.size() == n;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // int n = prerequisites.size();
        unordered_map<int, list<int>> adjList;

        for (auto task : prerequisites)
        {
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }

        return solveUsingTopologicalSort(adjList, numCourses);
    }
};