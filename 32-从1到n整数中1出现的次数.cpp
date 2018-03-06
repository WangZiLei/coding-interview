#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


//方法一
int getCountsOf1Test(int num){
	int counts = 0;
    for(int i=1;i<=num;i++){
		int n = i;
		while(n){
			if(n%10 == 1)
				counts++;
			n = n/10;
		}
    }
    return counts;
}


int string2int(string num){
	int res = 0;
	for(char ch:num)
		res = res*10+(ch-'0');
	return res;
}

int getCounts(string num){
	int length = num.length();
	if(length == 0)
		return 0;
	char highBit = num[0];
	//去掉最高位
	num.erase(0,1);
	length--;

	//1的个数
	int counts;
	if(highBit == '0'){
		counts = 0;
	}else if(highBit == '1'){
		counts = string2int(num)+1+length*pow(10,length-1);
	}else{
		counts = length*pow(10,length-1)*(highBit-'0')+pow(10,length);
	}
	return counts+getCounts(num);
}

//方法二
int getCountsOf1(int num){
	string str = "";
	if(num < 1)
		return 0;
	while(num){
		char ch = (num%10)+'0';
		str.insert(0,string(1,ch));
		num = num/10;
	}
	return getCounts(str);
}


void test(){
	vector<int> n = {-1,0,1,6,11,65,139,725,99,999,9999,99999};
	for(auto i:n){
		cout<<"1-"<<i<<"中1出现的次数为："<<getCountsOf1Test(i)<<endl;
		cout<<"1-"<<i<<"中1出现的次数为："<<getCountsOf1(i)<<endl<<endl;
	}

}

int main(){
	test();
	return 0;
}
