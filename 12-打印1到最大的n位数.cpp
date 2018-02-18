#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class BigNumber{
public:
	BigNumber(int n);
	//�ɹ������棬���ܼ��򷵻ؼ�
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
		//ǰ���0����ӡ
		if(!start_print && *iter != '0')
			start_print = true;
		if(start_print)
			cout<<*iter<<"";
	}
}

bool BigNumber::increase(){
	//�����ƻ����󣬼�������999->0->1
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
        cout<<"��������ӡ����"<<item<<"λ��"<<endl;
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
