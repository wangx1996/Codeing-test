#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <ctime>
#include<random>

using namespace std;

class Sort{


public:
	Sort(){
		cout<<"initial"<<endl;	
	}

	~Sort(){
		cout<<"delete"<<endl;
	}


	void swap(vector<int>& vt, int i,int j){
		int temp = vt[i];
		vt[i] = vt[j];
    		vt[j] = temp;
	}

	/*@冒泡排序*/
	void BubbleSort(vector<int>& vt){
		for(int i=0;i<vt.size(); ++i){
			for(int j=vt.size()-1; j>i; --j){
				if(vt[j-1]>vt[j]){
					swap(vt,j-1,j);
				}
			}
		}			
		
	}

	/*@冒泡排序pro*/
	void BubbleSortPro(vector<int>& vt){
		bool flag = true;
		for(int i=0; i<vt.size()&& flag; ++i){
			flag = false;//初始化为false
			for(int j=vt.size()-1; j>i; --j){
				if(vt[j-1]>vt[j]){
					swap(vt,j-1,j);
					flag = true;//只有当发生交换的时候改为true
				}
			}
		}
	}

	/*@简单排序*/
	void SimpleSort(vector<int>& vt){
		for(int i=0; i<vt.size(); ++i){
			int min = vt[i];
			int index = i;			
			for(int j=i+1; j<vt.size(); ++j){
				if(vt[j]<min){
					min = vt[j];
					index =j;
				}
          		}
			vt[index] = vt[i];
			vt[i] = min;
		}
	}

	/*@插入排序*/
	void InsertSort(vector<int>& vt){
	   for(int i=1; i<vt.size(); ++i){
		if(vt[i-1]>vt[i]){
			int dummy=vt[i];//哨兵点
			int j= i-1;
			for(; vt[j]>dummy && j>=0; --j){
				vt[j+1] = vt[j];
			}
			vt[j+1] = dummy;
		}
           }
	}


	/*@堆排序*/
	void HeapMake(vector<int>& vt){ //大顶堆
		int son_index = vt.size()/2;//先获得最低端的父节点
		for(int i= son_index; i>=1; --i){
                        int j = i*2-1; 
		    for( ; j<vt.size(); j=j*2){
			if(j < vt.size()-1 && vt[j] < vt[j+1])
				j++;
			if(vt[i-1]>vt[j])
				break;
			swap(vt,i-1,j);	
		    }
		}
	}


	void HeapSort(vector<int>& vt){
		vector<int> tempv = vt;
		for(int i=0; i<vt.size(); ++i){	
			HeapMake(tempv);
			vt[vt.size()-1-i] = tempv[0];
			tempv.erase(tempv.begin());
		}
	}


	/*@希尔排序*/
	void ShellSort(vector<int> &vt){
		int k = vt.size();
		while(k>=1){
			k = k/2;
			for(int i=k;i<vt.size();++i){
				if(vt[i-k]>vt[i]){
					int dummy = vt[i];
					int j = i-k;
					for(; vt[j]>dummy && j>0; j=j-k){
						vt[j+k] = vt[j];
					}
					vt[j+k] = dummy;
				}
			}
		}
	}		
		

	/*@快速排序*/
	void QuikSort(vector<int>& vt, int start,int end){

		if(start>=end)
			return;
		int pivot = Partition(vt,start,end);
		QuikSort(vt, start, pivot-1);
		QuikSort(vt,pivot+1, end);
	}
			 
	int Partition(vector<int>& vt, int start, int end){
		int left = start;
		int right = end;
    		std::default_random_engine random(time(NULL));
    		std::uniform_int_distribution<int> dis1(left, right);
		int pivot = dis1(random);
		//cout<<"pivot " <<pivot<<endl;

		int dummy = vt[pivot];
		int hole = pivot;
		while(left<right){
			while(hole<right && vt[right] > dummy){
				right--;
			}
			//swap(vt,hole,right);
			vt[hole] = vt[right];
			hole = right;
			/*cout<<"right"<<endl;
			for(int i=0; i<vt.size(); ++i){
				cout<<vt[i]<<" ";
			}
			cout<<'\n'<<endl;*/
			while(left<hole && vt[left] < dummy){
				left++;
			}
			//swap(vt,left,hole);//指针法与挖坑法本质都是一样的，没什么区别，只不过一个是在不断交换元素而一个是赋值
			vt[hole] = vt[left];
			hole = left;
			/*cout<<"left"<<endl;
			for(int i=0; i<vt.size(); ++i){
				cout<<vt[i]<<" ";
			}
			cout<<'\n'<<endl;*/

		}
		vt[left] = dummy;
		return left;	
	}

};

int main(){
	int n=0;
    	cin>>n;
	vector<int> vt(n,0);
	for(int i=0; i<n;++i){
		cin>>vt[i];
	}

	Sort sort;
	//sort.BubbleSort(vt);
	//sort.SimpleSort(vt);
        //sort.InsertSort(vt);
	//sort.HeapSort(vt);
	//sort.ShellSort(vt);
	sort.QuikSort(vt,0,vt.size()-1);
	for(int i=0; i<n; ++i){
		cout<<vt[i]<<" ";
	}
	cout<<'\n'<<endl;

	return 0;
}



