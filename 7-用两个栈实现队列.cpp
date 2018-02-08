#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
private:
	stack<int> out;
	stack<int> in;
public:
	bool add(int n);
	bool del(int &n);
};

bool MyQueue::add(int n){
    in.push(n);
	return true;
}

bool MyQueue::del(int &n){
	if(out.empty()){
		int element;
		while(!in.empty()){
			element = in.top();
			in.pop();
			out.push(element);
		}
	}
	if(out.empty())
		return false;
	n = out.top();
	out.pop();
	return true;
}

void test(){
	int element = 5;
	MyQueue queue;
    if(queue.del(element)){
		cout<<"空队列删除元素，返回真，element="<<element<<endl;
    }else{
    	cout<<"空队列删除元素，返回假，element="<<element<<endl;
    }

    queue.add(1);
    queue.add(2);
    queue.add(3);
    element = 5;
    if(queue.del(element)){
		cout<<"队列删除元素，返回真，被删除的element="<<element<<endl;
    }else{
    	cout<<"队列删除元素，返回假，被删除的element="<<element<<endl;
    }

    int n;
    MyQueue x;
    x.add(164);
    x.add(23);
    x.add(38);
    cout<<"遍历队列:";
    while(x.del(n)){
		cout<<n<<" ";
    }
    cout<<endl;

}



int main(){
	test();
	return 0;
}
