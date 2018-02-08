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
		if(in.empty())
			return false;
		int element;
		while(!in.empty()){
			element = in.top();
			in.pop();
			out.push(element);
		}
	}
	n = out.top();
	out.pop();
	return true;
}

void test(){
	int element = 5;
	MyQueue queue;
    if(queue.del(element)){
		cout<<"�ն���ɾ��Ԫ�أ������棨ɾ���ɹ�����element="<<element<<endl;
    }else{
    	cout<<"�ն���ɾ��Ԫ�أ����ؼ٣�ɾ��ʧ�ܣ���element="<<element<<endl;
    }

    queue.add(1);
    queue.add(2);
    queue.add(3);
    element = 5;
    if(queue.del(element)){
		cout<<"����ɾ��Ԫ�أ������棨ɾ���ɹ�������ɾ����element="<<element<<endl;
    }else{
    	cout<<"����ɾ��Ԫ�أ����ؼ٣�ɾ��ʧ�ܣ�����ɾ����element="<<element<<endl;
    }

    int n;
    MyQueue x;
    x.add(164);
    x.add(23);
    x.add(38);
    cout<<"��������:";
    while(x.del(n)){
		cout<<n<<" ";
    }
    cout<<endl;

}



int main(){
	test();
	return 0;
}
