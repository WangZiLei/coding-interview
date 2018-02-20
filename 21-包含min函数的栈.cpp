#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class MinStack{
private:
	stack<int> minElem;
	stack<int> elems;
public:
	void push(int n);
	void pop();
	int getMin();
};

void MinStack::push(int n){
	elems.push(n);
	if(minElem.empty()){
		minElem.push(n);
	}else{
		int num = minElem.top();
		if(n < num){
			minElem.push(n);
		}else{
			minElem.push(num);
		}
	}
}

void MinStack::pop(){
	if(elems.empty())
		throw exception();
	elems.pop();
	minElem.pop();
}

int MinStack::getMin(){
	if(minElem.empty())
		throw exception();
	return minElem.top();
}

void test(){
	auto a = new MinStack();
	a->push(3);
	a->push(2);
	a->push(3);
	a->push(6);
	a->push(1);
	a->pop();
	cout<<"a当前的最小值是："<<a->getMin()<<endl;

	auto b = new MinStack();
	cout<<"b当前的最小值是："<<b->getMin()<<endl;


}


int main(){
	test();
	return 0;
}
