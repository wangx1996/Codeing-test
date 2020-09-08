#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <ctime>
#include<random>
#include <algorithm>

using namespace std;

//左右均为闭区间，查找第一次找到的那个target的位置
bool Binary_search(vector<int>& vt, int target, int& index){
	int left=0;
	int right = vt.size()-1;
	while(left<=right){
		int mid = left+(right-left)/2;
		if(vt[mid] == target){
			index = mid;
			return true;
			break;
		}
		if(vt[mid]<target){
			left = mid+1;
		}else if(vt[mid]>target){
			right = mid-1;
		}
	}
	return false;
}

//左开右闭，查找第一个小于target的位置，或者说是target前有多少个元素.
int Lower_bound(vector<int>& vt, int target){
	int left = 0;
	int right =vt.size();
	while(left<right){
		int mid = left+(right-left)/2;
		if(vt[mid] == target){
			right = mid;
		}else if(vt[mid]<target){
			left = mid+1;
		}else if(vt[mid]>target){
			right = mid;
		}
	}

	return vt[left]==target? left:-1;
}



int End_bound(vector<int>& vt, int target){
	int left = 0;
	int right =vt.size();
	while(left<right){
		int mid = left+(right-left)/2;
		if(vt[mid] == target){
			cout<<mid<<endl;
			left = mid+1;
		}else if(vt[mid]<target){
			left = mid+1;
		}else if(vt[mid]>target){
			right = mid;
		}
	}
	cout<<left-1<<endl;
	return vt[left-1]==target? left-1:-1;
}



int main(){
	int n=0, target;
    	cin>>n>>target;
	vector<int> vt(n,0);
	for(int i=0; i<n;++i){
		cin>>vt[i];
	}	

	int index;
	if(Binary_search(vt, target,index))
		cout<<index<<endl;


	cout<<	Lower_bound(vt,target)<<endl;

	cout<<	End_bound(vt,target)<<endl;
	return 0;
}
