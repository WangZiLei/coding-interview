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
	int getFromEndToBegin(int k);
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
	//如果第一个节点是要删除的节点
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
	cout<<"遍历链表：";
    while(x->next != NULL){
        cout<<x->value<<" ";
        x = x->next;
    }
    //打印最后一个节点的值
    cout<<x->value<<endl;

}

int LinkList::getFromEndToBegin(int k){
	Node *i,*j;
	i = this->p;
	j = this->p;

	if(k < 1)
		throw std::exception();
	if(j == NULL)
		throw std::exception();
	if(j->next == NULL){
		if(k == 1){
			return this->p->value;
		}else{
			throw std::exception();
		}
	}

	while(j->next != NULL){
        j = j->next;
        if(k == 1){
			i = i->next;
        }else{
        	k--;
        }
	}
	//比较k和链表长度
	if(k == 1){
		return i->value;
	}else{
		throw std::exception();
	}
}



void test(){
	LinkList a;

	a.addNode(1);
	cout<<"倒数第1个节点是："<<a.getFromEndToBegin(1)<<endl;
	a.addNode(2);
	cout<<"倒数第2个节点是："<<a.getFromEndToBegin(2)<<endl;
	a.addNode(3);
	a.addNode(4);
	a.addNode(5);
	a.travel();
	cout<<"倒数第3个节点是："<<a.getFromEndToBegin(3)<<endl;
	cout<<"倒数第5个节点是："<<a.getFromEndToBegin(5)<<endl;
	cout<<"倒数第6个节点是："<<a.getFromEndToBegin(6)<<endl;

	LinkList b;
	b.getFromEndToBegin(1);

	a.travel();

}



int main(){
	test();
	return 0;
}
