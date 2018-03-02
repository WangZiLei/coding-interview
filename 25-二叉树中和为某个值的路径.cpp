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
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)
            return vector<vector<int>>{};

		return FindPath(root,expectNumber,0);
    }

    vector<vector<int>> FindPath(TreeNode* root,int expectNumber,int currentSum){
        currentSum += root->val;
        if(root->left==NULL && root->right==NULL){
			//���rootΪҶ�ӽڵ�
			if(currentSum == expectNumber)
				return vector<vector<int>>{{root->val}};
			else
				return vector<vector<int>>{};
        }else{
        	vector<vector<int>> pathRight,pathLeft;
        	if(root->right != NULL)
				pathRight = FindPath(root->right,expectNumber,currentSum);
			if(root->left != NULL)
				pathLeft = FindPath(root->left,expectNumber,currentSum);

			//�ϲ�����������·��
			vector<vector<int>> path;
            if(pathLeft.size() != 0)
				for(auto item:pathLeft){
					path.push_back(item);
				}
            if(pathRight.size() != 0)
				for(auto item:pathRight){
					path.push_back(item);
				}

			//��ÿ��·�����ϵ�ǰ�Ľڵ�
            if(path.size() != 0){
				for(int i=0;i<path.size();i++)
					path[i].insert(path[i].begin(),root->val);
            }
            return path;
        }
    }
};
