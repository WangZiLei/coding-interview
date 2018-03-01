#include <iostream>
#include <vector>
using namespace std;

int checkMoreThanHalf(vector<int> nums){
    if(nums.size() <= 0)
		throw exception();
	if(nums.size() == 1)
		return nums[0];

	//某个数字的出现次数
    int counts = 0;
    int num = nums[0];
    for(auto item:nums){
		if(item == num){
			counts++;
		}else{
			if(counts == 0){
				counts = 1;
				num = item;
			}else{
				counts--;
			}
		}
    }

    //check
    counts = 0;
    for(auto item:nums){
		if(item == num)
			counts++;
    }
    if(counts*2 <= nums.size())
		throw exception();

	return num;
}


void test(){
	vector<vector<int>> nums = {
		{1},
		//{1,2},
		{1,1,3},
		//1,1,2,2},
		{5,5,5,2,3},
		//{},
	};
	for(auto item:nums){
		cout<<"数目超过一半的元素为："<<checkMoreThanHalf(item)<<endl;
	}

}

int main(){
	test();
	return 0;
}
