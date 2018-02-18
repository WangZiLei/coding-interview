#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class BigNumber{
public:
	BigNumber(int n);
	//成功返回真，不能加则返回假
	bool increase();
	void print();
private:
	int len;
	vector<char> num;
};

BigNumber::BigNumber(int n){
	if(n < 1){
		throw std::exception();
		return;
	}
    len = n+1;
    num.clear();
	num.resize(len,'0');
}

void BigNumber::print(){
	bool start_print = false;
	for(auto iter=num.begin();iter!=num.end();iter++){
		//前面的0不打印
		if(!start_print && *iter != '0')
			start_print = true;
		if(start_print)
			cout<<*iter<<"";
	}
}

bool BigNumber::increase(){
	//存在绕回现象，即类似于999->0->1
    if(num[0] == '1')
		return false;
	int pos = len-1;
	while(pos > 0){
		if(num[pos] == '9'){
			num[pos] = '0';
			pos--;
		}else{
			num[pos]++;
			return true;
		}
	}
	return false;
}


void test(){
	vector<int> len = {1,4,-2,-1,0};
	for(auto item:len){
        cout<<"接下来打印的是"<<item<<"位数"<<endl;
        auto num = BigNumber(item);
        while(num.increase()){
			num.print();
			cout<<" ";
        }
        cout<<endl<<endl;
	}

}


int main(){
	test();
	return 0;
}
