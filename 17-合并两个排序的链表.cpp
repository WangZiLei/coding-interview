#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int value;
	Node *next;
};

class LinkList{
public:
	Node *p = NULL;
	stack<int> sta;
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
    while(x != NULL){
        cout<<x->value<<" ";
        x = x->next;
    }
    cout<<endl;
}

void LinkList::reverse(){
	if(this->p == NULL)
		return;
	if(this->p->next == NULL)
		return;
	Node *prev=NULL,*cur=this->p,*next=cur->next;
	while(cur != NULL){
        cur->next = prev;
        prev = cur;
        cur = next;
        if(next != NULL)
			next = next->next;
	}
	this->p = prev;
}

Node *mergeLinklist(Node *a,Node *b){
	if(a==NULL && b==NULL)
		return NULL;

	//注意头节点
	Node *res = new Node();
	res->next = NULL;
	res->value = 666;
	Node *p = res;
	//true:merge left,false:merge right
	bool sign;
	while(a!=NULL || b!=NULL){
		if(a==NULL){
			sign = false;
		}else if(b==NULL){
			sign = true;
		}else{
			if(a->value > b->value){
				sign = false;
			}else{
				sign = true;
			}
		}
		if(sign){
			p->next = new Node();
            p->next->next = NULL;
            p->next->value = a->value;
            a = a->next;
            p = p->next;
		}else{
			p->next = new Node();
            p->next->next = NULL;
            p->next->value = b->value;
            b = b->next;
            p = p->next;
		}
	}
	p = res->next;
	delete res;
	return p;

}



void test(){
	//{NULL,NULL}{}{}{}{}
	LinkList a,b,c;

	a.addNode(1);
	a.addNode(4);
	a.addNode(9);
	b.addNode(4);
	b.addNode(5);
	b.addNode(9);
	b.addNode(11);
	a.travel();
	b.travel();
	c.p = mergeLinklist(a.p,b.p);
	c.travel();

}



int main(){
	test();
	return 0;
}
