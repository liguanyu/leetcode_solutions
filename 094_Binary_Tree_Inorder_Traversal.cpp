class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        TreeNode* node;
        stack<TreeNode*> stk;
        node = root;
        
        while(node != NULL || !stk.empty()){
            while(node != NULL){
                stk.push(node);
                node = node->left;
            }
            
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
            node = node->right;
        }
        
        return result;
    }
    
};