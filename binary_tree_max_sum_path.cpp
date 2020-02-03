/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findsum(TreeNode* root, int &maxsum){
            if(root == NULL)
                return 0;

            int l = findsum(root->left, maxsum);
            int r = findsum(root->right, maxsum);

            int sum1 = max(root->val, max(l,r)+root->val);
            int sum2 = max(sum1, l+r+root->val);
            maxsum = max(maxsum, sum2);

            return sum1;
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;

        int result = findsum(root, maxsum);
        return maxsum;
    }
};
