#include <iostream>
#include <vector>
using namespace std;

int getSubArrayMaxSum(vector<int> nums){
	if(nums.size() <= 0)
		throw exception();

    int maxSum = nums[0];
    int currentSum = 0;
    for(auto num:nums){
		currentSum += num;
		if(currentSum > maxSum)
			maxSum = currentSum;
		if(currentSum < 0)
			currentSum = 0;
    }
	return maxSum;
}


void test(){
	vector<vector<int>> nums = {
		{1,-2,3,10,-4,7,2,-5},
		{-2,1,3,10,-4,7,2,-5},
		{1,1,3},
		{-3,-1,-2,-2},
		{-1,-1,-2,-2},
		{-3},
		{},
	};
	for(auto item:nums){
		cout<<"子数组最大和为："<<getSubArrayMaxSum(item)<<endl;
	}

}

int main(){
	test();
	return 0;
}
