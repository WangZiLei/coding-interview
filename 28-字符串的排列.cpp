#include <iostream>
#include <vector>
using namespace std;

void permutation(string &str,int index){
	if(index < 0)
		throw exception();
	if(index == str.size()-1){
		cout<<str<<endl;
		return;
	}

	char tmp;
	for(int i=index;i<str.size();i++){
		tmp = str[i];
		str[i] = str[index];
		str[index] = tmp;

		permutation(str,index+1);

		tmp = str[i];
		str[i] = str[index];
		str[index] = tmp;

	}
}

void permutation(string str){
	if(str.size() <= 0)
		return;
    permutation(str,0);
}


void test(){
	vector<string> strs = {"a","b","aaa","ab","abc",""};
	for(auto item:strs){
		cout<<item<<"的全排列为："<<endl;
		permutation(item);
		cout<<endl<<endl;
	}

}

int main(){
	test();
	return 0;
}
