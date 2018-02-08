#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int value;
	Node *next;
};

class LinkList{
private:
	Node *p = NULL;
	stack<int> sta;
public:
	void addNode(int val);
	bool delNode(int val);
	void travel();
	void reverse();
};

void LinkList::addNode(int val){
	Node *node = new Node();
	if(node == NULL)
		return;
	node->value = val;
	node->next = NULL;
	if(this->p == NULL){
		this->p = node;
	}else{
		Node *x = this->p;
        while(x->next != NULL){
            x = x->next;
        }
        x->next = node;
	}
}

bool LinkList::delNode(int val){
	if(this->p == NULL)
		return false;

	Node *x = this->p;
	//�����һ���ڵ���Ҫɾ���Ľڵ�
	if(x->value == val){
		this->p = x->next;
		delete x;
		return true;
	}
	while(x->next != NULL){
        if(x->next->value == val){
			Node *tmp = x->next;
			x->next = x->next->next;
			delete tmp;
			return true;
        }
        x = x->next;
	}
	return false;
}

void LinkList::travel(){
	if(this->p == NULL)
		return;
	Node *x = this->p;
	cout<<"��������";
    while(x->next != NULL){
        cout<<x->value<<" ";
        x = x->next;
    }
    //��ӡ���һ���ڵ��ֵ
    cout<<x->value<<endl;

}

void LinkList::reverse(){
	if(this->p == NULL)
		return;
	Node *x = this->p;
    while(x->next != NULL){
		this->sta.push(x->value);
        x = x->next;
    }
    this->sta.push(x->value);
    cout<<"�����������";
	while(!this->sta.empty()){
        cout<<this->sta.top()<<" ";
        this->sta.pop();
	}
	cout<<endl;
}


void test(){
	LinkList a;
	if(a.delNode(6)){
		cout<<"ɾ���ڵ�ɹ�"<<endl;
	}else{
		cout<<"ɾ���ڵ�ʧ��"<<endl;
	}

	a.addNode(1);
	a.addNode(2);
	a.addNode(3);
	a.addNode(4);
	a.addNode(5);
	a.travel();
	a.reverse();
	if(a.delNode(1)){
		cout<<"ɾ���ڵ�1�ɹ�"<<endl;
	}else{
		cout<<"ɾ���ڵ�1ʧ��"<<endl;
	}
	if(a.delNode(5)){
		cout<<"ɾ���ڵ�5�ɹ�"<<endl;
	}else{
		cout<<"ɾ���ڵ�5ʧ��"<<endl;
	}
	if(a.delNode(50)){
		cout<<"ɾ���ڵ�50�ɹ�"<<endl;
	}else{
		cout<<"ɾ���ڵ�50ʧ��"<<endl;
	}
	a.travel();

}



int main(){
	test();
	return 0;
}
