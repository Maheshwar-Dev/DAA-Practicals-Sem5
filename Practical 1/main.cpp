class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> data;

        stack<TreeNode*> myStack;

        TreeNode* curr = root;

        while (curr != nullptr || !myStack.empty()) {
            while (curr != nullptr) {
                myStack.push(curr);
                curr = curr->left;
            }
            curr = myStack.top();
            myStack.pop();
            data.push_back(curr->val);
            curr = curr->right;
        }

        return data;
    }
};
