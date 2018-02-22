#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

//���һ��Ԫ��Ϊ����
//[begin,end]
bool judgeBST(vector<int> sequence,int begin,int end){
	//���Ҫ�жϵ�Ԫ��ֻ��1������1������
	if(begin >= end)
		return true;

	//������¼index�Ƿ������������������
	//�ڶ����������У�hasChange����仯1��
	//������hasChange�ж���1�εı仯���Ϳ��ж���������Ƕ���������
	bool hasChange = false;
	//ֵΪ1����-1�������ж�����
	int sign = -1;

	//������¼���������ķֽ�λ��(�������ĺ�һ��λ��)
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
			cout<<"Ϊ�����������"<<endl;
		}else{
			cout<<"��Ϊ�����������"<<endl;
		}
	}
}


int main(){
	test();
	return 0;
}
