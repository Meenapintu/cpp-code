struct node{
	int value;
	node* left;
	node *right;
	int height;
	
	node(int value){
		this.value = value;
		this.left = nullptr;
		this.right=nullptr;
		this.height =0;
	}
};




int hdiff(node* n){
	return n->left->height - n->right->height;
	}




insert(int value,node *tree){
	if(tree==nullptr)tree = new node(value);
	else if(t->value >value){
		insert(value,t->left);
		//rotation management
		if(hdiff(tree) ==2)
		{
			if(value< t->left.value)
				rotatewithleftchild(tree);
			else 
				doublewithleftchild(tree);
			
			
		}
	}
	else if(t->value < value)
		{
			insert(value,t->right);
					//rotation management
		if(hdiff(tree) ==-2)
		{
			if(value > t->right.value)
				rotatewithrightchild(tree);
			else 
				doublewithrightchild(tree);
			
			
		}
		}
		
	else{
		t->height = max(t->left->height,t->right->height)+1;
	}
	
}
