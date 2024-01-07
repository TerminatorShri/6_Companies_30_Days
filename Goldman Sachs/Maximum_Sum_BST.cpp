#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Hard
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    struct Info
    {
        bool is_bst;
        int mini, maxi, sum;
        Info(bool a, int b, int c, int d)
        {
            is_bst = a;
            mini = b;
            maxi = c;
            sum = d;
        }
    };
    Info *solve(TreeNode *root, int &ans)
    {
        if (!root)
            return new Info(true, INT_MAX, INT_MIN, 0);
        Info *left = solve(root->left, ans);
        Info *right = solve(root->right, ans);
        // If left and right sub-tree are BST and inorder predecessor is less than root and inorder successor is greater than root then current sub-tree is BST
        bool isBST = (left->is_bst) && (right->is_bst) &&
                     (root->val > left->maxi) && (root->val < right->mini);
        int sum = left->sum + right->sum + root->val;
        if (isBST)
            ans = max(ans, sum);
        int minii = min(root->val, min(left->mini, right->mini));
        int maxii = max(root->val, max(left->maxi, right->maxi));
        return new Info(isBST, minii, maxii, sum);
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

int main()
{
    return 0;
}