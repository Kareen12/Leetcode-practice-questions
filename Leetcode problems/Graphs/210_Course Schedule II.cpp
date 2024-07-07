class Solution
{
public:
    vector<int> solve(unordered_map<int, list<int>> &adjList, int numCourses, vector<int> &ans)
    {
        unordered_map<int, int> indegree;

        for (auto i : adjList)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

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

        if (ans.size() == numCourses)
            return ans;
        else
        {
            ans.clear();
            return ans;
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;

        unordered_map<int, list<int>> adjList;

        for (auto task : prerequisites)
        {
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }

        return solve(adjList, numCourses, ans);
    }
};