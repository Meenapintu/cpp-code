#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
	int value;
	Node* next;
	
	
	};


bool linear(Node* head, int value){
	while(head !=nullptr){
		if(head->value == value) return true;
		else head = head->next;
	}
	return false;
	}


bool binary(vector<int>* vect, int value){
	
	size_t size = vect->size();
	int l =0,r=size-1;
	int mid = (l+r)/2;
	while(l<r){
			if(vect->at(mid) == value)return true;
			
			else if(vect->at(mid) < value)
			{
				l = mid+1;
				mid = (l+r)/2;
			}else
			{
				r = mid;
				mid = (l+r)/2;
			}
			
	}
	return false;
}



int main(){
	
	vector<int> vec;
	Node* list = nullptr,*tlist;
	int n,t;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>t;
		vec.push_back(t);
		tlist = new Node();
		
		tlist->value = t;
		tlist->next = list;
		list = tlist;
		
	}
	
	cin>>t;
	
	if(binary(&vec,t)){
		cout<<"Binary found "<<t<<'\n';
	}else cout<<"Binary Not found "<<t<<'\n';
	
	if(linear(list,t)){
		cout<<"Linear found "<<t<<'\n';
	}else cout<<"Linear Not found "<<t<<'\n';

return 0;
	}
