#include <iostream>
#include <string>
#include <vector>

#include "utils.cpp"

using namespace std;

void swap(vector<int>* vect,int i,int j){
	
		int t = vect->at(i);
		vect->at(i) = vect->at(j);
		vect->at(j)=t;
		
		return;
}

/** 
 * time complexity BigO(n^2)
 * 
 * */

void bubble(vector<int>*vect){
	
	size_t size = vect->size();
	
	for(int i=0;i<size;++i)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(vect->at(j) > vect->at(j+1))
			{
				swap(vect,j,j+1);
			}
		}
	}
	
	return;
	}


/**
 * time complexity BigO(n^2)
 * 
 * */
 
void selection(vector<int>*vect){
	
	size_t size = vect->size();
	int min;
	for(int i=0;i<size;++i)
	{
		min = i;
		
		for(int j=i+1;j<size;j++)
		{
			if(vect->at(j) < vect->at(min))
				min = j;
		}
		
		swap(vect,i,min);
	}
	
	return;
	}
	
/**
 * time BigO(end-begin) = BigO(n)
 * space O(n)
 * */
void merge(vector<int>*vect,int begin,int mid,int end){
	
	int n = mid-begin+1;
	
	vector<int>temp_vect = *(new vector<int>);
	 
	int temp_begin=0;
	int tmid = mid+1;
	
	for(int i=0;i<n;++i){
		temp_vect.push_back(vect->at(begin+i));
	}
	print(&temp_vect);
	
	while(mid<end && temp_begin<n)
	{
			if(temp_vect[temp_begin]< vect->at(mid+1)){
			vect->at(begin) = temp_vect[temp_begin];
			begin++;
			temp_begin++;
		}
		else{
			vect->at(begin) = vect->at(mid+1);
			begin++;
			mid++;
		}
	}
	
	while(temp_begin<n){
		vect->at(begin) = temp_vect[temp_begin];
			begin++;
			temp_begin++;
	}

	return;
	}
	
	/**
	 * time O(nlong)
	 * */
	 
void merge_sort(vector<int>*vect,int begin, int end){
	
	if(begin<end)
	{
		int mid = (begin+end)/2;
		merge_sort(vect,begin,mid);
		merge_sort(vect,mid+1,end);
		
		merge(vect,begin,mid,end);
	}
	
	return;
	}
	

int partition(vector<int>*vect,int begin,int end){
	int temp_pivot = vect->at(begin);
	int tempnam = begin;
	
	for(int i=begin+1;i<= end;++i)
	{
		if(vect->at(i) <= temp_pivot)
		{
			swap(vect,i,tempnam);
			swap(vect,i,++tempnam);	
		}
	}
	return tempnam;
}
	
void quick_sort(vector<int>*vect,int begin,int end){
	
	if(begin<end){
		int pivot = partition(vect,begin,end);
		quick_sort(vect,begin,pivot);
		quick_sort(vect,pivot+1,end);
	}
	
	return;
	}


int main(){
	
	vector<int>vect;
	int n,t;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>t;
		vect.push_back(t);
	}
	
	//bubble(&vect);
	
	//selection(&vect);
	//merge_sort(&vect,0,vect.size()-1);
	
	quick_sort(&vect,0,vect.size()-1);
	
	print(&vect);
	
	
	return 0;
	}
