class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data;
        if (root == nullptr) return data;

        stack<TreeNode*> myStack;
        myStack.push(root);

        while (!myStack.empty()) {
            TreeNode* curr = myStack.top();
            myStack.pop();
            data.push_back(curr->val);

            if (curr->right) myStack.push(curr->right);
            if (curr->left) myStack.push(curr->left);
        }

        return data;
    }
};
