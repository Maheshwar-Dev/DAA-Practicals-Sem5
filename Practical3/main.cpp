class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> data;
        if (root == nullptr) return data;

        stack<TreeNode*> myStack;
        stack<TreeNode*> out;
        myStack.push(root);

        while (!myStack.empty()) {
            TreeNode* curr = myStack.top();
            myStack.pop();
            out.push(curr);

            if (curr->left) myStack.push(curr->left);
            if (curr->right) myStack.push(curr->right);
        }

        while (!out.empty()) {
            data.push_back(out.top()->val);
            out.pop();
        }

        return data;
    }
};
