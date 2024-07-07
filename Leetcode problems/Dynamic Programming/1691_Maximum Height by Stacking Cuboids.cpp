class Solution
{
public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &v : cuboids)
        {
            sort(v.begin(), v.end());
        }

        sort(cuboids.begin(), cuboids.end());

        vector<int> ans(cuboids.size());
        for (int i = 0; i < cuboids.size(); i++)
        {
            ans[i] = cuboids[i][2];
        }

        for (int i = cuboids.size() - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2])
                {
                    ans[j] = max(ans[j], ans[i] + cuboids[j][2]);
                }
            }
        }
        int res = INT_MIN;
        for (int i : ans)
        {
            res = max(res, i);
        }
        return res;
    }
};