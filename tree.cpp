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
	~Node()
	{
		
	}
	
		
	};
	
class BinaryTree{
	
	 Node *rootsave;
	 
	public:
	
	BinaryTree()
	{
		rootsave =nullptr;
	}
	
	~BinaryTree(){;}
	
	Node *getTree(){return rootsave;}
	
	void setTree(Node* root){rootsave = root;}
	
	void cleanTree(Node *root)
	{
		cleanTree(node->left);
		cleanTree(node->right);
		delete root;
	}
		
		
	
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
			else break ;//add left child //if(root->value == value) if duplicate is not allowed remove first = from line 50 and replace break with return in this line
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
	
	Node* _search(Node* root,int value)  //instead of value return node pointer
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
			return root;
		}
		else {
			cout<<"requested key not found \n" ;
			return nullptr;  // assuming keys are >0 else we have to do something about it 
		}
	}
	

	void  remove(Node* root,int value)
	{
		root= _remove(root,value);
	}
	
	Node* _remove(Node* root,int value)
	{
		if(root ==nullptr)return nullptr;
		
		if(root->value ==value)
		{
			if(root->left == nullptr && root->right==nullptr)
			return nullptr;
			
			if(root->left == nullptr && root->right!=nullptr){
				root->value = root->right->value;
				root->left = root->right->left;
				root->right = root->right->right;
				
			}
			else if(root->left != nullptr && root->right ==nullptr){
				root->value = root->left->value;
				root->left = root->left->left;
				root->right = root->left->right;
				
			}
			else{
				
				if(root->right->left == nullptr)
				{
					root->value = root->right->value;
					root->right = root->right->right;
				}
				else
				{
					Node* tempnam = find_smallest(root->right);
					root->value = tempnam->left->value;
					root->right = tempnam->left->right;
				}
			}
		}
		else if(root->value < value)
		{
			root = _remove(root->right,value);
		}
		else //if(root->value > value)
		{
			root = _remove(root->left,value);
		}
		return root;
	}
			
			
		
	
	Node* find_smallest(Node *node)
	{
		while(node->left->left!=nullptr)
		{
			node = node->left;
		}
		return node;
	}
	
	
	
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
