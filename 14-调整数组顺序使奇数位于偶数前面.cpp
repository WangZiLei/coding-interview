#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void adjust(vector<int> &num){
    int len = num.size();
    if(len < 2)
		return;
    int i=0,j=len-1;
    while(1){
    	//一直迭代，直到碰到了偶数
        while(num[i]%2!=0 && i<len)
			i++;
		//一直迭代，直到碰到了奇数
		while(num[j]%2==0 && j>=0)
			j--;
		if(i>=j)
			break;
		//swap
		int tmp;
		tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
    }
}


void test(){
	vector<vector<int>> num = {{},{1},{2,1},{2,2,2},{1,9,8,7,4,9}};
    for(auto i:num){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
		adjust(i);
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl<<endl;;

    }


}



int main(){
	test();
	return 0;
}
