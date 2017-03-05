#include <iostream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

// for max heap
//#define HTYPE <

// for min heap 
#define HTYPE >
	
class heap{
	//this is a minheap
	vector<int>vec;
	
	public:
		heap()
		{
			;
		}
		~heap(){;}
		int parent(int child)
		{
			return child>0?(child-1)/2:-1;
		}
		int left(int parent)
		{
			return 2*parent+1;
		}
		int right(int parent)
		{
			return 2*parent+2;
		}
		
		
 void insert(int value)
	{
		vec.push_back(value);
		insert_balance(vec.size()-1);
	
	};
 void insert_balance(int node)
	{
		int p = parent(node);
		if(p>=0&& vec.at(p) HTYPE vec.at(node))
		{
			int temp = vec.at(node);
			vec.at(node) = vec.at(p);
			vec.at(p) = temp;
			insert_balance(p);
		}
	}
int get_root()
	{
		if(vec.size() ==0) return -1;
		else return vec.front();
	}
void delete_root()
	{
		if(vec.size() ==0)
		{
			cout<< "Empty heap\n";
		}
		
		else
		{
			vec.front() = vec.back();
			vec.pop_back();
			delete_balance(0);
		}
	}
 void delete_balance(int node)
	{
		int l = left(node);
		int r = right(node);
		int child = l;
		
		if(l<vec.size() && r<vec.size() && vec.at(l) HTYPE vec.at(r))
		{
			child = r;
		}
		if(child <vec.size()&&vec.at(node) HTYPE vec.at(child))
		{
			int temp = vec.at(child);
			vec.at(child) = vec.at(node);
			vec.at(node) = temp;
			delete_balance(child);
		}
	}
	
void print_heap(){
	
	print(&vec);
}
};
