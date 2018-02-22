#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

//最后一个元素为树根
//[begin,end]
bool judgeBST(vector<int> sequence,int begin,int end){
	//如果要判断的元素只有1个或者1个以下
	if(begin >= end)
		return true;

	//用来记录index是否从左子树到了右子树
	//在二叉搜索树中，hasChange顶多变化1次
	//因此如果hasChange有多于1次的变化，就可判断这个树不是二叉搜索树
	bool hasChange = false;
	//值为1或者-1，用来判断正负
	int sign = -1;

	//用来记录左右子树的分界位置(左子树的后一个位置)
	int index = end;
	for(int i=begin;i<end;i++){
        if((sequence[i]-sequence[end])*sign < 0){
            if(hasChange == true){
				return false;
            }else{
				hasChange = true;
				sign = sign*(-1);
				index = i;
			}
        }
	}
	return judgeBST(sequence,begin,index-1) && judgeBST(sequence,index,end-1);
}

bool VerifySquenceOfBST(vector<int> sequence){
	int length = sequence.size();
	if(length == 0)
		return false;
	if(length==1)
		return true;
	return judgeBST(sequence,0,length-1);
}


void test(){
	vector<vector<int>> seqs = {
		{},
		{1},
		{1,2},
		{2,1},
		{1,2,3},
		{2,3,1},
		{7,6,9,11,10,8},
		{5,6,9,10,8},
		{7,6,11,10,8},
		{5,7,6,9,8},
		{5,7,6,8},
		{9,10,11,8},
		{5,7,6,9,11,10,8},
		{7,4,6,5}, //not
	};

	for(auto i:seqs){
        for(auto j:i)
			cout<<j<<" ";
		if(VerifySquenceOfBST(i)){
			cout<<"为后序遍历序列"<<endl;
		}else{
			cout<<"不为后序遍历序列"<<endl;
		}
	}
}


int main(){
	test();
	return 0;
}
