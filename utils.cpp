#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int>*vect){
	
	size_t size = vect->size();
	
	for(int i=0;i<size;++i)
	cout<<vect->at(i)<<" ";
	
	cout<<endl;
	
	return;
	}
