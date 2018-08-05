#include<bits/stdc++.h>
using namespace std;

class node {

	public: 
		int data;
		struct node *next;
		static int list_len;
		static struct node *last_ptr;
};

class node *head, *temp, *last_ptr;

int list_len;


void list_init();
void insert_node(int pos, int x);
int delete_node(int index);
int delete_node(struct node *ptr);
void reverse_list(struct node *ptr, struct node *current);
int middle_of_list();
void display_list();
void remove_duplicates_sorted();
void remove_duplicates_unsorted();
void swap_nodes(int index1, int index2);
void print_reverse_list(struct node *ptr);

int main() {
	
	list_init();

	int choice, index, x;
	while(1) {

		cout<<"Options: "<<endl;
		cout<<"0. Insert node"<<endl;
		cout<<"1. Delete node"<<endl;
		cout<<"2. Display List"<<endl;
		cout<<"3. Remove Duplicates(From a sorted list)"<<endl;
		cout<<"4. Reverse List"<<endl;
		cout<<"5. Find Middle of List"<<endl;
		cout<<"6. Remove duplicates(From an unsorted list)"<<endl;
		cout<<"7. Swap 2 nodes"<<endl;
		cout<<"8. Print List in Reverse order"<<endl;
		cout<<"9. Clear"<<endl;
		cout<<"10. Exit"<<endl;
		cin>>choice;

		switch(choice) {

			case 0:
				cout<<"\nEnter index and node value: ";
				cin>>index>>x;
				insert_node(index, x);
				display_list();
				break;
			
			case 1:
				cout<<"\nEnter index of node to delete: ";
				cin>>index;
				delete_node(index);
				display_list();
				break;
			
			case 2:
				display_list();
				break;
			
			case 3:
				remove_duplicates_sorted();
				display_list();
				break;

			case 4:
				reverse_list(NULL, head->next);
				display_list();
				break;
			
			case 5:
				x = middle_of_list();
				cout<<"Middle of list = "<<x<<endl;
				break;

			case 6:
				remove_duplicates_unsorted();
				display_list();
				break;

			case 7:
				int index1, index2;
				cout<<"Enter indices of 2 nodes to be swapped: ";
				cin>>index1>>index2;
				swap_nodes(index1, index2);
				display_list();

			case 8:
				print_reverse_list(head->next);
				break;
			case 9:
				system("clear");
				break;

			case 10:
				return 0;
			
			default:
				cout<<"\nInvalid choice"<<endl;
		}
	}

	return 0;
}
	

//Initializing head.
void list_init() {

	//Initializing head.
	head = new node;
	head->data = 0;
	head->next = NULL;

	//List length = 0
	list_len = 0;

	last_ptr = NULL;

	system("clear");
	cout<<"THIS IS A 0-INDEXED LINKED LIST"<<endl;

	return;

}


void insert_node(int pos, int x) {

	if(pos > list_len || pos < 0) {

		cout<<"\nInsert_node: Invalid Position"<<endl;
		return ;
	}

	struct node *current;
	current = head;

	for(int i = 0; i < pos; i++) {
		current = current->next;
	}

	temp = new node;

	temp->data = x;
	temp->next = current->next;
	current->next = temp;

	if(pos == list_len) {
		last_ptr = temp;
	}

	list_len++;

	return;
}

void display_list() {

	if(list_len == 0) {
		cout<<"Display_list: No Elements in the list"<<endl;
		return;
	}

	struct node *current = head->next;
	
	cout<<"\nLIST: \nHEAD-->";
	while(current != NULL) {
		cout<<current->data<<"-->";
		current = current->next;
	}
	
	cout<<"NULL\n"<<endl;

	current = head->next;
	cout<<"HEAD-->";
	while(current != NULL) {
		cout<<current<<"-->";
		current = current->next;
	}

	cout<<"NULL\n"<<endl;

	return;
}


int delete_node(int index) {

	if(index < 0 || index >= list_len) {
		cout<<"\nDelete_node: Invalid Position"<<endl;
		return INT_MIN;
	}

	struct node *current = head;
	int x;

	for(int i = 0; i < index; i++) {
		current = current->next;
	}

	temp = current->next;
	x = temp->data;

	current->next = temp->next;
	delete temp;

	if(index == list_len - 1) {
		last_ptr = current;
	}

	list_len--;

	return x;
}

int delete_node(struct node *ptr) {

	int x;
	temp = ptr->next;
	x = temp->data;

	ptr->next = temp->next;
	free(temp);

	return x;
}

void remove_duplicates_sorted() {

	//No nodes case.
	if(head->next == NULL) {
		cout<<"No elements in the list"<<endl;
		return;
	}

	struct node *ptr = head->next;
	
	if(ptr->next == NULL) 
		return;

	while(ptr->next != NULL) {

		if(ptr->data == ptr->next->data) 
			//Deleting ptr->next. Passing ptr as argument.
			delete_node(ptr);
		else
			ptr = ptr->next;
	}

	return;
}


void reverse_list(struct node *ptr, struct node *current) {

	if(current == NULL) {
		head->next = ptr;
		return;
	}

	temp = current->next;
	current->next = ptr;
	reverse_list(current, temp);
}


int middle_of_list() {

	if(list_len == 0) {
		cout<<"\nmiddle_of_list: No elements in the list"<<endl;
		return INT_MIN;
	}

	struct node *ptr1, *ptr2;

	ptr1 = head->next;
	ptr2 = head->next;
	
	while(1) {

		if(ptr2->next == NULL)
			return ptr1->data;
		
		else if(ptr2->next->next == NULL)
			return (ptr1->data + ptr1->next->data) / 2;

		ptr2 = ptr2->next->next;
		ptr1 = ptr1->next;

	}

}
		

void remove_duplicates_unsorted() {

	unordered_map<int, int> freq;
	struct node *current;
	int x;

	if(head->next == NULL) {
		cout<<"No elements in the list"<<endl;
		return;
	}
	
	current = head;
	while(current->next != NULL) {
		
		x = current->next->data;

		freq[x]++;
		
		if(freq[x] > 1) {
			delete_node(current);
			freq[x]--;
		}

		current = current->next;
	}
	
	return;
}

void swap_nodes(int index1, int index2) {

	if(index1 < 0 || index1 >= list_len) {
		cout<<"Invalid index1"<<endl;
		return;
	}

	if(index2 < 0 || index2 >= list_len) {
		cout<<"Invalid index2"<<endl;
		return;
	}
	
	struct node *ptr_to_one, *ptr_to_two, *one_to_next, *two_to_next, *ptr1, *ptr2;
	int i;

	i = 0;
	ptr_to_one = head;
	ptr_to_two = head;
	while(i < index1) {
		i++;
		ptr_to_one = ptr_to_one->next;
	}

	i = 0;
	while(i < index2) {
		i++;
		ptr_to_two = ptr_to_two->next;
	}

	ptr1 = ptr_to_one->next;
	ptr2 = ptr_to_two->next;

	one_to_next = ptr1->next;
	two_to_next = ptr2->next;

	//Swapping!
	ptr_to_one->next = ptr2;
	ptr2->next = one_to_next;

	ptr_to_two->next = ptr1;
	ptr1->next = two_to_next;

	return;
}


void print_reverse_list(struct node *ptr) {

	if(ptr == NULL)
		return;

	print_reverse_list(ptr->next);
	cout<<ptr->data<<endl;

	return;
}






























		
		












