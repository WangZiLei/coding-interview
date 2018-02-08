#include <iostream>
#include <vector>
using namespace std;

char *replaceSpace(char *str,int length){
	if(str == NULL)
		return "";
	if(length == 0)
		return "";
	//统计0的个数
	int zero_counts = 0;
	for(int i=0;i<length;i++)
		if(str[i] == ' ')
			zero_counts++;

	int length_new = length+2*zero_counts;
	//包括'\0'的长度
    char *p = new char[length_new+1];
    //'\0'也直接拷贝下来
    int i = length;
    int j = length_new;
	while(i>=0 && j>=0){
		p[j] = str[i];
        if(str[i] == ' '){
			p[j] = '0';
            p[--j] = '2';
            p[--j] = '%';
        }
        j--;
        i--;
	}
	return p;
}

void test(){
	char str_array[][100] = {""," ","  ","  a","a  ","aa  aa","\0"};
	for(auto str:str_array){
        cout<<str<<endl;
        cout<<replaceSpace(str,string(str).size())<<endl;
        cout<<endl;
	}
	char *p = NULL;
	cout<<"NULL字符指针"<<endl;
	cout<<replaceSpace(p,0)<<endl;
	cout<<endl;
}

int main(){
	test();
	return 0;
}
