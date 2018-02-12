#include <iostream>
#include <vector>
using namespace std;

//return index
int getMin(vector<int> &num){
	int length = num.size();
	if(length == 0)
		return -1;
	if(length == 1)
		return 0;
	if(length == 2)
		if(num[1] > num[0])
			return 0;
		else
			return 1;

    int low=0,mid,high=length-1;

    while(low+1 < high){
		mid = (high+low)/2;
		if(num[low] < num[mid]){
			//���������1 2 3 4 5������ ֱ�ӷ���low
			if(num[high] > num[mid])
				return low;
			low = mid;
		}else if(num[low] > num[mid]){
			high = mid;
		}else{
			//���ȶ����߽��б�������
            for(int i=low;i<mid;i++)
				if(num[i] > num[i+1])
					return i+1;
			//���Ұ�߼������ϲ���
			low = mid;
		}
    }
    if(high == low+1)
		return high;

}

void test(){
	//�����Բ������{}
	vector<vector<int>> nums = {{1,2,3,4,5},{4,5,1,2,3},{1},{2,1},
								{1,1,1,1,1},{1,1,1,1,1,3},{1,1,1,4,1},
								{3,3,3,3,1,3,3},{3,3,3,3,5,3,3,3},{5,3,3,3,3,3,3}};

	for(int i=0;i<nums.size();i++){
		//output the array
		for(auto obj:nums[i])
			cout<<obj<<" ";
		cout<<"  ��С����Ϊ��"<<nums[i][getMin(nums[i])]<<endl;

	}
}

int main(){
	test();
	return 0;
}
