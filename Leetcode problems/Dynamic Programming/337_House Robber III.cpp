// MEMOISATION
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int solve(TreeNode *root, unordered_map<TreeNode *, int> &dpMap)
    {
        if (!root)
            return 0;

        int robThisHouse = 0, dontRobThisHouse = 0;

        if (dpMap.find(root) != dpMap.end())
            return dpMap[root];

        robThisHouse += root->val;
        if (root->left)
        {
            robThisHouse += solve(root->left->left, dpMap) + solve(root->left->right, dpMap);
        }
        if (root->right)
        {
            robThisHouse += solve(root->right->left, dpMap) + solve(root->right->right, dpMap);
        }

        dontRobThisHouse = solve(root->left, dpMap) + solve(root->right, dpMap);

        dpMap[root] = max(robThisHouse, dontRobThisHouse);
        return dpMap[root];
    }
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> dpMap;
        return solve(root, dpMap);
    }
};