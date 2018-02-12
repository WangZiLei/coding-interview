#include <iostream>
#include <vector>
using namespace std;

//方法一
int getCounts1(int n){

	int counts = 0;
	unsigned int flag = 1;
	while(flag){
		if(flag & n)
			counts++;
		flag = flag<<1;
	}
	return counts;
}

//方法二
//12-1=11 即1100b - 1b = 1011b
//1100b & 1011b = 1000b
int getCounts2(int n){

	int counts = 0;
	unsigned int flag = 1;
	while(n){
		n = n&(n-1);
		counts++;
	}
	return counts;
}

void test(){
	vector<int> n = {-1,-8,0xFFFFFFFF,0x80000000,-5,0,1,2,4,7,0x7FFFFFFF};
	for(auto i:n){
		cout<<i<<"的二进制中1的个数为："<<getCounts1(i)<<endl;
	}
}

int main(){
	test();
	return 0;
}
