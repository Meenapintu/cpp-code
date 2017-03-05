#include <iostream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
	
	Node(int value)
	{
		this->value = value;
		this->left=nullptr;
		this->right=nullptr;
	}
	~Node(){
		
	}
		
	};
	
class AvlTree{
	
	 Node *rootsave;
	public:
	AvlTree(){
	
		rootsave =nullptr;
		}
	~AvlTree(){;}
	
	void insert(Node* root,int value)
	{
		while(root!=nullptr )
		{
			if(root->value < value && root->right!=nullptr)
			root = root->right;
			else if(root->value < value)
			  break; // add right chlild 
			
			else if(root->value >= value && root->left!=nullptr)
			root = root->left;
			else break ;//add left child //if(root->value > value)
		}
		if(root ==nullptr)
		{
			root = new Node(value);
			rootsave = root;
		}
		else if(root->value < value)
		{
			root->right = new Node(value);
			
		}
		else {
			root->left = new Node(value);
		}
		
	}
	
	int search(Node* root,int value)
	{	
		
		while(root!=nullptr)
		{
			if(root->value < value )
			root = root->right;
			
			else if(root->value > value)
			root = root->left;
			else break; // value found 
		}
		if(root!=nullptr) 
		{
			return root->value;
		}
		else {
			cout<<"requested key not found \n" ;
			return -1;  // assuming keys are >0 else we have to do something about it 
		}
	}
	
	Node* _search(Node* root,int value)
	{	
		if(root == nullptr)return nullptr;
		
		while(root->left!=nullptr || root->right !=nullptr)
		{
			if(root->value < value )
				if(root->right!=nullptr)
					if(root->right->value == value)return root;
					else root = root->right;
				else root = root->right;
			
			else if(root->value > value)
				if(root->left!=nullptr)
					if(root->left->value == value)return root;
					else root = root->left;
				else root = root->left;
		
		}
		{
			cout<<"requested key not found \n" ;
			return nullptr;  // assuming keys are >0 else we have to do something about it 
		}
	}
	
	
	void remove_help(Node* parent, Node* node,bool left){
		
		if(node->left==nullptr && node->right ==nullptr)
			{
			// delete root;
				if(left)
				parent->left = nullptr;
				else 
				parent->right = nullptr;
				 
				cout<<" called out\n";
				return;
			}
			else if(node->right !=nullptr && node->left ==nullptr)
			{
				cout<<left<<"right present\n";
				//if(root->right!=nullptr)
				node->value = node->right->value;
				node->left=node->right->left;
				node->right = node->right->right;
				return;
			}
		 
			
			else if(node->left !=nullptr && node->right ==nullptr)
			{
				cout<<left<<"left present\n";
				node->value = node->left->value;
				cout<<left<<"left present\n";
				
				node->left=node->left->left;
				cout<<left<<"---left present\n";
				
				node->right=node->left->right;
				
				cout<<left<<"left present\n";
				return;
				//root->left;
			}
			else
			{
				//both child present 
				
				cout<<"both present\n";
				
				if(node->right->left == nullptr && node->right->right == nullptr)
				{
					node->value = node->right->value;
					node->right = nullptr;
					return;
				}
				else if(node->right->left == nullptr && node->right->right != nullptr)
				{
					node->value = node->right->value;
					node->right = node->right->right;
					return;
				}
				else
				{
					Node* tempnam = find_smallest(node->right);  //already have ->left->left=nullptr
					node->value = tempnam->left->value;
					//tempnam->value = value;
					if(tempnam->left->right == nullptr)
					{
						tempnam->left = nullptr;
						cout<<"setnull\n";
					}
					else
					{
						tempnam->left->value = tempnam->left->right->value;
						tempnam->left->left=tempnam->left->right->left;
						tempnam->left->right = tempnam->left->right->right;
					}
					
				}
				//remove(tempnam,value);
				//tempnam = tempnam->right;
			}
			
	}
	void remove(Node* root,int value)
	{
			if(root == nullptr) return;
			
			if(root->value == value)
			{
				cout<<"  root\n";
				if(root->left==nullptr && root->right==nullptr)
				{
					root = nullptr;
					rootsave = nullptr;
				}
				else {
					remove_help(root,root,true);
				}
				return;
			}
			
			cout<<" Not root\n";
			// single value root h=1;
			Node* temp = _search(root,value);
			
			if(temp == nullptr){
				cout<<"Nothing to remove\n";
				return;
			}
			
			if(temp->left !=nullptr)
			{
				cout<<(temp->value)<< (temp->left->value)<<" Not root remove operation\n";
				if(temp->left->value == value)
				{
					remove_help(temp,temp->left,true);
				}
				else remove_help(temp,temp->right,false);
			}
			else
			{  //right child
				remove_help(temp,temp->right,false);
				
			}
		}
			/**
			
			
			if(ro == nullptr)break;
			else if(root->value < value )
			root = root->right;
			
			else if(root->value > value)
			{
				root = root->left;
			}
			else break; // value found 
		}
		if(root==nullptr)
		{
			cout<<"requested key not found \n" ;
			return ;  // assuming keys are >0 else we have to do something about it 
		}
		else
		{
			if(root->left==nullptr && root->right==nullptr)
			{
			// delete root;
				cout<<" called out\n";
				root = nullptr;
				return;
			}
			else if(root->left==nullptr)
			{
				//if(root->right!=nullptr)
				root->value = root->right->value;
				root->left=root->right->left;
				root->right = root->right->right;
				return;
			}
		 
			
			else if(root->right==nullptr)
			{
				root->value = root->left->value;
				root->left=root->left->left;
				root->right = root->left->right;
				return;
				//root->left;
			}
			else
			{
				//both child present 
				
				
				if(root->right->left == nullptr && root->right->right == nullptr)
				{
					root->value = root->right->value;
					root->right = nullptr;
					return;
				}
				else
				{
					Node* tempnam = find_smallest(root->right);  //already have ->left->left=nullptr
					root->value = tempnam->left->value;
					tempnam->value = value;
					if(tempnam->left->right == nullptr)
					{
						tempnam->left = nullptr;
						cout<<"setnull\n";
					}
					else
					{
						tempnam->value = tempnam->left->right->value;
						tempnam->left=tempnam->left->right->left;
						tempnam->right = tempnam->left->right->right;
					}
					
				}
				//remove(tempnam,value);
				//tempnam = tempnam->right;
			}
		}
		
	}
	* 
	* */
	
	Node* find_smallest(Node *node)
	{
		
		while(node->left->left!=nullptr)
		{

			 //if(root->value > value)
			node = node->left;
			//else break; // value found 
		}
		return node;
		//root left is null so we can replace root with 
	}
	
	Node *getTree(){return rootsave;}
	
	void preorder(Node *root=nullptr)
	{
		
		if(root == nullptr) return;
		else
		{
			preorder(root->left);
			cout<< root->value<< " ";
			preorder(root->right);
		}
	}
		
};
