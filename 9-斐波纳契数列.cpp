#include <iostream>
#include <vector>
using namespace std;


long long Fibonacci(int n){
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;

    long long a=0,b=1;
    while(n!=2){
		b = b+a;
		a = b-a;
		n--;
    }
    return a+b;

}

void test(){
	vector<int> n = {-1,0,1,2,3,4,5,6,100};
	for(auto i:n){
		cout<<"f("<<i<<")="<<Fibonacci(i)<<endl;
	}
}

int main(){
	test();
	return 0;
}
