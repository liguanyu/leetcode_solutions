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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* node = root;
        stack<TreeNode*> stk;
        
        while(node!=NULL || !stk.empty()){
            if(node != NULL){
                stk.push(node);
            }
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
            
            if(node->right != NULL){
                stk.push(node->right);
            }
            node = node->left;
        }
        
        return result;
    }
};