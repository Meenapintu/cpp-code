#include "tree.cpp"

//heap test 
int main(){
	
	BinaryTree h ;
	char t='a';
	int value;
	while(t!='e'){
		
		cin>>t;
		
		
		switch(t)
		{
			case 'd':
				cin>>value;
				h.remove(h.getTree(),value);
				cout<<"removed\n";
				break;
			case 'i':
				cin>>value;
				h.insert(h.getTree(),value);
				cout<<"inserted\n";
				break;
			case 'm':
				cin>>value;
				cout<< (h.search(h.getTree(),value))<<endl;
				cout<<"searched \n";
			break;
			
			default:
				h.preorder(h.getTree());
				cout<<"printed\n";
				break;
		}
	}
	return 0;
	}

