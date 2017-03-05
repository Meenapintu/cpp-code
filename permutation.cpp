#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;


/*
 * Permutation of a string , 
 * 
 * comment line 34 ...//for unique permutation .   to get all repeated permutation 
 * 
 * time complexity  BigO(factorial(n))
 * 
 */

string swap(string str,int i,int j){
		char c = str.at(i);
		str.at(i) = str.at(j);
		str.at(j)=c;
		return str;
	}

void get_permutation( const string& str,int pos,size_t size,string tree=""){
	
	if(pos >=size) return;
	
	
	if(pos ==size-1)cout<<tree<<str<<endl;
	
	tree.append("-");    //just debugging flag to get tree structure 
	
	get_permutation(str,pos+1,size,tree);
	 
	for(int i=pos+1;i<size;++i){
		if(str.at(pos)==str.at(i))continue;    // for unique permutation . 
		
		else get_permutation(swap(str,pos,i),pos+1,size,tree);
	}
	
	return;
	}


int main(){
	string str;
	cin>>str;
	
	size_t size = str.length();
	
	get_permutation(str,0,size);
	
	return 0;
	}
