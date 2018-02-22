#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPopOrder(vector<int> inSequence,vector<int> outSequence){
    int length = inSequence.size();
    if(length != outSequence.size())
		return false;

	stack<int> sta;
	int i = 0,j = 0;
    while(i < length){
		if(inSequence[i] != outSequence[j]){
			sta.push(inSequence[i]);
			i++;
		}else{
			i++;
			j++;
		}
    }
    if(i == j)
		return true;

	while(j < length){
		auto elem = sta.top();
		if(elem == outSequence[j]){
			sta.pop();
			j++;
		}else{
			return false;
		}
	}
	return true;

}

void test(){
	vector<vector<vector<int>>> seqs = {
		{{},{}},
		{{1},{}},
		{{1},{1}},
		{{1},{1,2}},
		{{1},{3,7}},
		{{1,2,3},{1,2,3}},
		{{1,2,3},{1,3,2}},
		{{1,2,3},{3,2,1}},
		{{1,2,3,4,5},{4,5,3,2,1}},
		{{1,2,3,4,5},{4,5,3,1,2}},
		{{},{}},
	};

	for(auto item:seqs){
		string res = "";
		if(isPopOrder(item[0],item[1]))
			res = "==";
		else
			res = "!=";
		for(auto iter:item[0])
			cout<<iter<<" ";
		cout<<res<<" ";
		for(auto iter:item[1])
			cout<<iter<<" ";
		cout<<endl;
	}

}


int main(){
	test();
	return 0;
}
