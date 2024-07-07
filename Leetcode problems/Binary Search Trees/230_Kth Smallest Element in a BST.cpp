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
    int kthSmallest(TreeNode *root, int &k)
    {
        if (!root)
            return -1;

        int leftAns = kthSmallest(root->left, k);
        // Agar left se hi pura ans aa rha h to return kardo right me mat jao
        if (leftAns != -1)
        {
            return leftAns;
        }

        k--;
        if (k == 0)
        {
            return root->val;
        }

        // Agar right se hi pura ans aa rha h to return kardo left me mat jao ab
        int rightAns = kthSmallest(root->right, k);
        // return rightAns;
        if (rightAns != -1)
        {
            return rightAns;
        }
        return -1;
    }
};

// ANOTHER APPROACH

class Solution
{
    void solve(TreeNode *root, int &k, int &ans)
    {
        // we will do inorder traversal here -> LNR
        if (!root)
            return;

        // go left
        solve(root->left, k, ans);

        // for node decrease value of k
        k--;

        if (k == 0)
        {
            ans = root->val;
            return;
        }

        // go right
        solve(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode *root, int &k)
    {
        int ans = 0;
        // int count = 0;
        // solve(root, k, count, ans);
        solve(root, k, ans);
        return ans;
    }
};