#include <iostream>
#include <malloc.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	TreeNode *prior;
	TreeNode *head;
    TreeNode* Convert(TreeNode* root){
    	prior = NULL;
    	//��Ϊţ����������ƽ̨�Ƚ�ɵ�����뷵��ת��֮��ĵ�һ���ڵ�
    	//���ʹ��head����¼����ڵ�
    	head = NULL;
		func(root);
		return head;
    }

    void func(TreeNode *root){
    	if(root == NULL)
			return;
		//���������˼��
		func(root->left);
		if(prior == NULL){
			head = root;
			root->left = prior;
			prior = root;
		}else{
			prior->right = root;
			root->left = prior;
			prior = root;
		}
		func(root->right);
    }

    //for testing
    void travel(TreeNode *begin,TreeNode *end){
        TreeNode *p;
        cout<<endl<<"����";

        p = begin;
        if(begin != NULL){
			while(p != NULL){
				cout<<p->val<<" ";
				p = p->right;
			}
        }
        cout<<endl<<"����";

        p = end;
        if(end != NULL){
			while(p != NULL){
				cout<<p->val<<" ";
				p = p->left;
			}
        }
        cout<<endl;
    }

};



int main(){
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode)*7);

	p[0].left = NULL;
	p[0].val = 4;
	p[0].right = NULL;

	p[1].left = NULL;
	p[1].val = 8;
	p[1].right = NULL;

	p[2].left = NULL;
	p[2].val = 12;
	p[2].right = NULL;

	p[3].left = NULL;
	p[3].val = 16;
	p[3].right = NULL;

	p[4].left = p+0;
	p[4].val = 6;
	p[4].right = p+1;

	p[5].left = p+2;
	p[5].val = 14;
	p[5].right = p+3;

	p[6].left = p+4;
	p[6].val = 10;
	p[6].right = p+5;

	auto obj = new Solution;
	obj->Convert(&p[6]);

	obj->travel(&p[0],&p[3]);

	return 0;
}




