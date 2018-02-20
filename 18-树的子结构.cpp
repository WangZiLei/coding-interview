/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if(pRoot1==NULL || pRoot2==NULL)
			return false;
		//如果当前节点不能重合
		//那么就换左右子树
        if(compareTree(pRoot1,pRoot2))
			return true;
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }

    //pRoot2是否能与pRoot1（以pRoot1为根节点）重合
    bool compareTree(TreeNode* pRoot1, TreeNode* pRoot2){
		//如果都遍历到pRoot2的叶子节点的下一层节点（NULL节点）
		//那么上面的节点肯定都是可以重合的
		if(pRoot2==NULL)
			return true;
		//如果在对应的位置，pRoot1为NULL而pRoot2不为NULL
		//即在某个子树上，pRoot2可以完全覆盖掉pRoot1
		//参考剑指offer中给的范例的两个树就可以明白
		if(pRoot1==NULL)
			return false;
		//顶点都不能重合，那么整个树肯定不能重合
        if(pRoot1->val != pRoot2->val)
			return false;
		//顶点可以重合，然后看左右子树能不能重合
		return compareTree(pRoot1->left,pRoot2->left) && compareTree(pRoot1->right,pRoot2->right);
    }
};
