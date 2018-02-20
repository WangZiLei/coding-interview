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
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if(pRoot1==NULL || pRoot2==NULL)
			return false;
		//�����ǰ�ڵ㲻���غ�
		//��ô�ͻ���������
        if(compareTree(pRoot1,pRoot2))
			return true;
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }

    //pRoot2�Ƿ�����pRoot1����pRoot1Ϊ���ڵ㣩�غ�
    bool compareTree(TreeNode* pRoot1, TreeNode* pRoot2){
		//�����������pRoot2��Ҷ�ӽڵ����һ��ڵ㣨NULL�ڵ㣩
		//��ô����Ľڵ�϶����ǿ����غϵ�
		if(pRoot2==NULL)
			return true;
		//����ڶ�Ӧ��λ�ã�pRoot1ΪNULL��pRoot2��ΪNULL
		//����ĳ�������ϣ�pRoot2������ȫ���ǵ�pRoot1
		//�ο���ָoffer�и��ķ������������Ϳ�������
		if(pRoot1==NULL)
			return false;
		//���㶼�����غϣ���ô�������϶������غ�
        if(pRoot1->val != pRoot2->val)
			return false;
		//��������غϣ�Ȼ�����������ܲ����غ�
		return compareTree(pRoot1->left,pRoot2->left) && compareTree(pRoot1->right,pRoot2->right);
    }
};
