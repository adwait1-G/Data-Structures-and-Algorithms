/*
 * Question: Given a binary tree, check whether it is a BST (Binary Search Tree) or not.
 */



#include<bits/stdc++.h>
using namespace std;

//"node" sructure of the binary tree.
typedef struct binary_tree_node {
    
    int key;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} node;

node *root;
int node_count = 0;
node *temp;

//Used in display_binary_tree();
node *current;
bool isbst;

//Functions required to build a Binary Tree and check if it is a Binary Search Tree or not.

void binary_tree_add_node();
bool check_bt_is_bst(node *root_node);
void create_binary_tree_node(node *ptr, bool left);

//Error handling rountine.
void err_exit(const char *err_string) {
    cerr<<err_string<<endl;
    exit(1);
}


int main() {
    
    int choice;
    while(1) {
        
        cout<<"Choices: "<<endl;
        cout<<"0. Add node"<<endl;
        cout<<"1. Check if the tree is a BST or not"<<endl;
	cout<<"2. Clear Screen"<<endl;
	cout<<"3. Exit"<<endl;
        
        cin>>choice;
        
        switch(choice) {
            
            case 0: {
                binary_tree_add_node();
                break;
            }
            case 1: {
                if(check_bt_is_bst(root) == true) {
                    cout<<"This binary tree is a BST"<<endl;
                }
                else {
                    cout<<"This binary tree is not a BST"<<endl;
                }
                break;
            }
	    case 2:
		    system("clear");
		    break;
	    case 3:
		    exit(1);

        }
        
    }
}

//Creates a new node and attaches it to the main binary tree.
void create_binary_tree_node(node *ptr, bool left) {
    
    temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    
    cout<<"Enter the new node's key: ";
    cin>>temp->key;
    
    if(left == true) {
        ptr->left = temp;
    }
    else {
        ptr->right = temp;
    }
}

//Algorithm to add a new node to binary tree.
void binary_tree_add_node() {
    
    //Creation of the root node.
    if(node_count == 0) {
        
        cout<<"This is the root node"<<endl;
        
        if((root = (node *)malloc(sizeof(node))) == NULL) {
            err_exit("Error: Not able to allocate memory for the root node");
        }
        
        root->left = NULL;
        root->right = NULL;
        
        cout<<"Enter key of root node: ";
        cin>>root->key;
        node_count++;
    }
    //For all the other nodes.
    else {
        
        bool choice;
        node *current = root;
 	       
        while(1) {      //Seems like an infinite loop, but breaks after creation of the node.
    
	    cout<<"Root: "<<current->key<<endl;

            cout<<"Left(0) / Right(1): ";
            cin>>choice;
            
            //To navigate left.
            if(choice == 0) {

		if(current->left == NULL) {
                    
                    cout<<"Adding node at this position."<<endl;
                    create_binary_tree_node(current, true);
                    node_count++;
                    break;
                }
                else {
                    
                    current = current->left;
                }
            }
            //To navigate right.
            else if(choice == 1) {
                
                if(current->right == NULL) {
                    
                    cout<<"Adding node at this position."<<endl;
                    create_binary_tree_node(current, false);
                    node_count++;
                    break;
                }
                else {
                    
                    current = current->right;
                }
            }
            else {
                cout<<"Invalid choice!"<<endl;
            }
            
        }
   }
}


//The main algorithm: Checking if a binary tree is a bst or not.

bool check_bt_is_bst(node *root_node) {
    
    //Return true if there are no nodes.
    if(root_node == NULL) {
        
        return true;
    }
    //If key of left node > key of root node, then return false.
    if(root_node->left != NULL && root_node->key < root_node->left->key) {
        
        return false;
    }
    //If key of right node < key of root node, then return false.
    if(root_node->right != NULL && root_node->key > root_node->right->key) {
        
        return false;
    }
    //Check recursively if left subtree and right subtree are bsts.
    return check_bt_is_bst(root_node->left) && check_bt_is_bst(root_node->right) ;
	
}



