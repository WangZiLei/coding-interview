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
	Node *addNode(int val);
	bool delNode(Node *p);
	void travel();

};

Node *LinkList::addNode(int val){
	Node *node = new Node();
	if(node == NULL)
		return NULL;
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
	return node;
}

bool LinkList::delNode(Node *p){
	if(this->p == NULL)
		return false;
    //如果链表中只有一个元素
    if(this->p == p){
		p = p->next;
		delete this->p;
		this->p = p;
		return true;
    }
    //如果p是最后一个节点
    if(p->next == NULL){
		//遍历链表 找到前面一个元素，然后删除
		auto tmp = this->p;
		while(tmp->next != p){
			tmp = tmp->next;
		}
		tmp->next = p->next;
		delete p;
		return true;
    }
    auto tmp = p;
    tmp->value = p->next->value;
    tmp->next = p->next->next;
    delete p->next;
	return true;
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



void test(){
	auto linklist = LinkList();

	linklist.addNode(1);
	linklist.addNode(2);
	linklist.addNode(3);
	linklist.addNode(4);

	auto p = linklist.addNode(5);

	linklist.delNode(p);

	linklist.travel();

}



int main(){
	test();
	return 0;
}
