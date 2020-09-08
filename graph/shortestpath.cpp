/* 2020.8.30
 * 图部分的代码练习，来自大话数据结构
 * 如何生成图的邻接矩阵以及邻接表
 */

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<limits.h>
#include <Eigen/Dense>
using namespace std;

void Dijkstra(const vector<vector<int>>& d){
     vector<int>  path(d.size(),0);//最短路径
     vector<int>  visited(d.size(),0); //表示改点是否已经加入最短路径

     vector<int>  weight(d.size(),0); //从v0到各点的权值

     for(int i=0; i<d.size(); ++i){
         weight[i] = d[0][i];
     }//初始化权值

     visited[0]=1;
     int k=0;
     for(int i=1; i<d.size(); ++i){
	int min = INT_MAX;

        for(int j=0; j<d.size(); ++j){

           if(visited[j]!=1 && min>weight[j]){
                k =j;//找离起点最近距离的点
                min = weight[j];//当前最小距离
	   }
        }
        visited[k]=1;
        for(int w=0; w<d.size(); ++w){//更新当前最小距离点邻接点的距离
		if(visited[w]!=1 && weight[w]>(min+d[k][w]) && d[k][w]!= INT_MAX){
			weight[w] = min+d[k][w];
                        path[w]= k;//前驱点

                }
        }
     }

     for(int i=0; i<9; ++i){
	cout<<" "<<weight[i];
     }

     cout<<'\n'<<endl;

     for(int i=0; i<9; ++i){
	cout<<" "<<path[i];
     }
     cout<<'\n'<<endl;
}

void FLoyd(vector<vector<int>>& d,Eigen::MatrixXd &C){
     cout<<"FLoyd"<<endl;

     Eigen::MatrixXd P =  Eigen::MatrixXd::Constant(d.size(), d.size(), 0); 
     vector<vector<int>>  path(d.size(),vector<int>(d.size(),0));//路径 
     vector<vector<int>>  weight = d;
     for(int i=0; i<d.size(); ++i){
	for(int j=0; j<d.size(); ++j){
	     path[i][j] = j;
	     P(i,j) = j;
        }
     }

     for(int k=0; k<d.size(); ++k){//过k点
	for(int i=0; i<d.size(); ++i){
		for(int j=0; j<d.size(); ++j){
			if(weight[i][j]>(weight[i][k]+weight[k][j]) && weight[i][k]!= INT_MAX && weight[k][j]!= INT_MAX){
				weight[i][j] =weight[i][k]+weight[k][j];
				path[i][j] = path[i][k];
                                C(i,j) =weight[i][k]+weight[k][j];
	                        P(i,j) = path[i][k];
                        }
                 }
       }
    }
 
    cout<<C<<endl;
    cout<<'\n'<<endl;
    cout<<P<<endl;

}


int main(){
    vector<vector<int>> d(9,vector<int>(9,0));
    Eigen::MatrixXd C = Eigen::MatrixXd::Constant(9, 9, 0);        // 创建3*3的值全为1.2的矩阵

    for(int i=0; i<9; ++i){
	for(int j=0; j<9; ++j){
	    if(i==j){
		d[i][j]=0;
                C(i,j)=0;
	    }else{
		d[i][j]=INT_MAX;
                C(i,j)= -1; 
            } 
        }
     }

    d[0][1]=1;
    d[0][2]=5;
    d[1][2]=3;
    d[1][4]=5;
    d[1][3]=7;
    d[2][4]=1;
    d[2][5]=7;
    d[3][4]=2;
    d[3][6]=3;
    d[4][7]=9;
    d[4][6]=6;
    d[4][5]=3;
    d[5][7]=5;
    d[6][7]=2;
    d[6][8]=7;
    d[7][8]=4; //构建图



    d[1][0]=1;
    d[2][0]=5;
    d[2][1]=3;
    d[4][1]=5;
    d[3][1]=7;
    d[4][2]=1;
    d[5][2]=7;
    d[4][3]=2;
    d[6][3]=3;
    d[7][4]=9;
    d[6][4]=6;
    d[5][4]=3;
    d[7][5]=5;
    d[7][6]=2;
    d[8][6]=7;
    d[8][7]=4; //构建图

    C(0,1)=1;
    C(0,2)=5;
    C(1,2)=3;
    C(1,4)=5;
    C(1,3)=7;
    C(2,4)=1;
    C(2,5)=7;
    C(3,4)=2;
    C(3,6)=3;
    C(4,7)=9;
    C(4,6)=6;
    C(4,5)=3;
    C(5,7)=5;
    C(6,7)=2;
    C(6,8)=7;
    C(7,8)=4; //构建图



    C(1,0)=1;
    C(2,0)=5;
    C(2,1)=3;
    C(4,1)=5;
    C(3,1)=7;
    C(4,2)=1;
    C(5,2)=7;
    C(4,3)=2;
    C(6,3)=3;
    C(7,4)=9;
    C(6,4)=6;
    C(5,4)=3;
    C(7,5)=5;
    C(7,6)=2;
    C(8,6)=7;
    C(8,7)=4; //构建图

    cout<<C<<endl;
    Dijkstra(d);
    FLoyd(d,C);
return 0;
}
