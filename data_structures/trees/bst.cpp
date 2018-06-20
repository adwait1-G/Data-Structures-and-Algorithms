//Implementing a bst - search, max, min, insert, delete.

#include<bits/stdc++.h>
using namespace std;

struct bst_node {

	float key;
	struct bst_node *parent;
	struct bst_node *left;
	struct bst_node *right;

	int height;
};

typedef struct bst_node node;

node *root, *temp;
unsigned bst_node_count = 0;

//Functions set 1
void insert_bst_node(float x);
void delete_bst_node();
float find_max_element();
float find_min_element();
bool search_an_element(float x);
void display_bst_wrapper(node *ptr);
void display_bst(node *bst_node_ptr);



// Functions and constants required for AVL operations.
node* find_first_unbalanced_node(node *ptr);


const int LL = 1, LR = 2, RR = 3, RL = 4;	//Encoding the 4 cases.
int which_case;

//Error handling function
void err_exit(const char *err_msg);


int main() {

	system("clear");

	unsigned choice;
	float x;

	while(1) {

		cout<<"Choose an option: "<<endl;
		cout<<"1. Insert node"<<endl;
		cout<<"2. Delete node"<<endl;
		cout<<"3. Find maximum element"<<endl;
		cout<<"4. Find minimum element"<<endl;
		cout<<"5. Search an element"<<endl;
		cout<<"6. Display bst"<<endl;
		cout<<"7. Clear Screen"<<endl;
		cout<<"8. Exit"<<endl;

		cin>>choice;

		switch(choice) {

			case 1: {	cout<<"Enter node key : ";
					cin>>x;
					insert_bst_node(x);
					display_bst_wrapper(root);
					break;
			}

			case 2:
				delete_bst_node();
				break;

			case 3:{
					x = find_max_element();
					cout<<"Max element = "<<x<<"\n"<<endl;
					break;
			}

			case 4:{
					x = find_min_element();
					cout<<"Min element = "<<x<<"\n"<<endl;
					break;
			}

			case 5:{	cout<<"Enter search key: ";
				       	cin>>x;
					search_an_element(x);
					break;
			}
			case 6:
				display_bst_wrapper(root);
				break;
			case 7:
				system("clear");
				break;
			case 8:
				return 0;
			default:
				cout<<"Invalid choice!"<<endl;
		}

	}

	return 0;
}

//Function 0: Error handling function.
void err_exit(const char *err_msg) {
	
	cout<<err_msg<<endl;
	exit(1);
}

//Function 1
void insert_bst_node(float x) {


	//If node is root(first node)
	if(bst_node_count == 0) {
		
		root = new node;
		if(root == NULL)
			err_exit("Error: Cannot allocate memory for root node");


		//Updating root's details.
		root->parent = NULL;
		root->left = NULL;
		root->right = NULL;
		root->height = 0;	//Height of root = 0.

		//Updating root's key.
		root->key = x;

		cout<<"Height of new node = "<<root->height<<endl;

	}

	else {

		//Getting all details about node.
		temp = new node;
		if(temp == NULL)
			err_exit("Error: Cannot allocate memory for a node");
	
		//Updating kid's key.
		temp->key = x;

                //Updating kid's kids as NULL.
                temp->right = NULL;
                temp->left = NULL;

		//Initialization.
		temp->height = 0;

		//Inserting node at the right place.
		node *current = root;
		while(1) {		//Seems like an infinite loop, but is not.

			temp->height++;		//When loop terminates, temp->height will have it's correct value.

			//Go right edge case
			if(temp->key > current->key && current->right == NULL) {		

				temp->parent = current;
				
				//Edge from parent to new right kid.	
				current->right = temp;

				break;
			}
			
			//Go left edge case
			else if(temp->key < current->key && current->left == NULL) {

				temp->parent = current;

				//Edge from parent to new left kid.
				current->left = temp;

				break;
			}
			
			//Go right case
			else if(temp->key > current->key) {

				current = current->right;
			}
			
			//Go left case
			else if(temp->key < current->key) {
				current = current->left;
			}

		}

		cout<<"\nHeight of new node: "<<temp->height<<endl;

		node *ptr = find_first_unbalanced_node(temp);
		if(ptr == NULL)
			cout<<"No unbalanced nodes found!"<<endl;
		else
			cout<<"Key of unbalanced node: "<<ptr->key<<endl;
	}

	bst_node_count += 1;

	return ;
}

//Function 2
void delete_bst_node() { 

	//Idea is to traverse the way user wants and delete the node he asks to delete.
	
	cout<<"Still under construction :P"<<endl;
}
	
		
//Function 3
float find_max_element() {

	node *current = root;
	
	while(current->right != NULL) {

		current = current->right;
	}

	return current->key;
}


//Function 4
float find_min_element() {

	node *current = root;

	while(current->left != NULL) {

		current = current->left;
	}

	return current->key;
}



//Function 5
bool search_an_element(float x) {

	//Getting key to be searched.
	float search_key;
	cout<<"Enter key to be searched: ";
	cin>>search_key;

	bool key_present = false;
	node *current = root;

	while(1) {

		//Loop Termination condition 1 - Key found!
		if(search_key == current->key) {

			key_present = true;
			break;
		}


		//Loop Termination condition 2 - Key not found!
		if(current->left == NULL && current->right == NULL) {
			key_present = false;
			break;
		}

		if(search_key < current->key) {

			current = current->left;
		}
		else if(search_key > current->key) {

			current = current->right;
		}
	}

	return key_present;
}

//Function 6a 
void display_bst_wrapper(node *ptr) {

	cout<<"\nBST: "<<endl;
	display_bst(ptr);
	cout<<"\n"<<endl;
}


//Function 6b 
void display_bst(node* bst_node_ptr) {
	


	cout<<bst_node_ptr->key;

	//If node is a leaf.
	if(bst_node_ptr->left == NULL && bst_node_ptr->right == NULL) {

		return;
	}
	
	//No right sub-tree
	else if(bst_node_ptr->left != NULL && bst_node_ptr->right == NULL) {

		cout<<"(";
		display_bst(bst_node_ptr->left);
		cout<<",X)";
	}
	
	//No left sub-tree
	else if(bst_node_ptr->left == NULL && bst_node_ptr->right != NULL) {

		cout<<"(X,";
		display_bst(bst_node_ptr->right);
		cout<<")";
	}

	//Both sub-trees are present. 
	else {
		cout<<"(";
		display_bst(bst_node_ptr->left);
		cout<<",";
		display_bst(bst_node_ptr->right);
		cout<<")";
	}
	
}

node* find_first_unbalanced_node(node *ptr) {

	node *first_unbal_node = NULL, *current = ptr;

	while(1) {

		if(current == root )
			break;
		
		
		if(abs(current->parent->left->height - current->parent->right->height) > 1) {

			first_unbal_node = current->parent;
			break;
		}

		else if(abs(current->parent->left->height - current->parent->right->height) <= 1) {

			current = current->parent;
		}
	}

	cout<<"\nKey of first unbalanced node: "<<first_unbal_node->key<<endl;
	return first_unbal_node;
}











	
	
