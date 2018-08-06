#include<bits/stdc++.h>
using namespace std;

int *stk, *top_ptr, stk_size;

void stack_init();
void push(int x);
void pop();
int top();
void display_stack();

int main() {

	stack_init();
	int choice, x;

	system("clear");

	while(1) {

		cout<<"Options: "<<endl;
		cout<<"0. Push a value"<<endl;
		cout<<"1. Pop the stack"<<endl;
		cout<<"2. Top of stack"<<endl;
		cout<<"3. Display stack"<<endl;
		cout<<"4. Clear Screen"<<endl;
		cout<<"5. Exit"<<endl;

		cin>>choice;

		switch(choice) {

			case 0:
				cout<<"Enter value to be pushed onto stack: ";
				cin>>x;
				push(x);
				display_stack();
				break;

			case 1:
				pop();
				display_stack();
				break;

			case 2:
				x = top();
				cout<<"Top of stack = "<<x<<endl;
				break;

			case 3:
				display_stack();
				break;

			case 4:
				system("clear");
				break;

			case 5:
				return 0;
			
			default:
				cout<<"Invalid choice"<<endl;
		}

	}

	return 0;
}


void stack_init() {

	cout<<"Enter max size of stack: ";
	cin>>stk_size;

	if(stk_size <= 0 || stk_size >= INT_MAX) {
		cout<<"Invalid stack size"<<endl;
		stack_init();
	}
	
	stk = new int[stk_size];
	top_ptr = NULL;

	return;
}

bool stack_empty() {

	if(top_ptr == NULL)
		return true;
	else
		return false;
}


bool stack_full() {

	if(top_ptr == &stk[stk_size - 1])
		return true;
	else
		return false;
}


void push(int x) {

	if(stack_full() == true) {
		cout<<"Error: Stack full. Push operation discarded"<<endl;
		return;
	}

	if(stack_empty() == true) 
		top_ptr = &stk[0];
	else
		top_ptr++;

	*top_ptr = x;
	
	return;
}


void pop() {

	if(stack_empty() == true) {
		cout<<"Error: Stack empty. pop() operation discarded"<<endl;
		return;
	}
	else if(top_ptr == &stk[0]) {
		top_ptr = NULL;
	}
	else
		top_ptr--;
}

int top() {

	return *top_ptr;
}


void display_stack() {

	if(stack_empty() == true) {
		cout<<"Stack Empty => Nothing to print"<<endl;
		return;
	}

	cout<<"\nTOP"<<endl;
	for(int *ptr = top_ptr; ptr >= stk; ptr--)
		cout<<ptr<<" , "<<*ptr<<endl;

	return;
}































































