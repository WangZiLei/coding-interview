/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root == NULL)
            return res;
        que.push(root);
        while(!que.empty()){
            auto elem = que.front();
            que.pop();
            res.push_back(elem->val);
            if(elem->left != NULL){
                que.push(elem->left);
            }
            if(elem->right != NULL){
                que.push(elem->right);
            }
        }
        return res;
    }
};
