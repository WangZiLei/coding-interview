#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void travel(vector<int> matrix,int m,int n){
	if(matrix.size() == 0)
		return;
    if(m==1 || n==1){
		for(int i=0;i<matrix.size();i++)
			cout<<matrix[i]<<" ";
		return;
    }

	int layerCounts = (min(m,n)+1)/2;
	for(int layer=0;layer<layerCounts;layer++){
		//对于 奇数*奇数 的矩阵，最后会剩下一条数没有遍历
		//此时就不能使用常规方法，需要特殊对待
		if(layer==layerCounts-1 && m%2 && n%2){
			if(m>n){
				for(int j=0;j<m-n+1;j++)
					cout<<matrix[(layer+j)*n+layer]<<" ";
			}else{
				for(int j=0;j<n-m+1;j++)
					cout<<matrix[layer*n+j+layer]<<" ";
			}
			break;
		}
		//上横
		for(int j=0;j<n-1-layer*2;j++){
            cout<<matrix[layer*n+j+layer]<<" ";
		}
		//右竖
		for(int j=0;j<m-1-layer*2;j++){
            cout<<matrix[(layer+j)*n+n-layer-1]<<" ";
		}
		//下横
		for(int j=0;j<n-1-layer*2;j++){
            cout<<matrix[(m-1-layer)*n+n-layer-1-j]<<" ";
		}
		//左竖
		for(int j=0;j<m-1-layer*2;j++){
            cout<<matrix[(m-1-layer-j)*n+layer]<<" ";
		}
	}
}

void test(){
	vector<vector<vector<int>>> matrixs = {
		{{},{0,0}},
		{{1},{1,1}},
		{{1,2,3},{1,3}},
		{{1,2,3},{3,1}},
		{{1,2,3,6,5,4},{2,3}},
		{{1,2,3,12,13,4,11,14,5,10,15,6,9,8,7},{5,3}},
		{{1,2,3,4,5,12,13,14,15,6,11,10,9,8,7},{3,5}},
		{{1,2,3,4,12,13,14,5,11,16,15,6,10,9,8,7},{4,4}}
	};

	for(int i=0;i<matrixs.size();i++){
		travel(matrixs[i][0],matrixs[i][1][0],matrixs[i][1][1]);
		cout<<endl;
	}

}


int main(){
	test();
	return 0;
}
