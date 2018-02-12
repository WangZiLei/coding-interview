#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;


double power(double base,int exponent){
	if(fabs(base-0.0) < 1e-8)
		return 0;
	if(fabs(base-1.0) < 1e-8)
		return 1;

	bool positive;
	if(exponent > 0){
		positive = true;
	}else if(exponent < 0){
		positive = false;
		exponent = exponent*(-1);
	}else{
		return 1;
	}

	double res = 1.0;
	//这里可以用一个更简单的办法来求乘方
	//使得复杂度降低为logN,N为指数
	for(int i=0;i<exponent;i++){
		res *= base;
	}

	if(positive == false){
		return 1.0/res;
	}else{
		return res;
	}

}

void test(){
	vector<vector<int>> n = {{0,0},{0,-2},{1,9},{-0.0,5},{-2,7},{2,-5},{3,4}};
	for(auto i:n){
		cout<<"power("<<i[0]<<","<<i[1]<<")="<<power(i[0],i[1])<<endl;
	}
}

int main(){
	test();
	return 0;
}
