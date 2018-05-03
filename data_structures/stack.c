#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdint.h>


int top, n, *stk;

int stack_init(int *stk, int *top);
void push(int *stk, int x);
int pop(int *stk);
int seek(int *stk);
void stack_display(int *stk, int n);
int stack_empty(int *stk, int n);
int stack_full(int *stk);


int main() {
	
	int choice, x;

	n = stack_init(stk , &top);

	stk = (int *)malloc(sizeof(int) * n);

	while(1) {
		printf("\nOptions: ");
		printf("\n0. Push a number ");
		printf("\n1. Pop the stack ");
		printf("\n2. Seek the stack(Get the top element) ");
		printf("\n3. Display stack ");
		printf("\n4. Clear Screen ");
		printf("\n5. Exit \n");

		scanf("%d", &choice);

		switch(choice) {
			case 0:
				if(stack_full(stk) == 0) {
					printf("\nEnter the number to push: ");
					scanf("%d", &x);
					push(stk, x);
				}
				else 
					printf("\nStack full. Overflow Condition\n");
				break;
			case 1:
				x = pop(stk);
				if(x != INT_MAX)
					printf("\nThe poped number = %d\n", x);
				break;
			case 2:
				x = seek(stk);
				if(x != INT_MAX)
					printf("\nThe element at the top of the stack = %d\n", x);
				break;
			case 3:
				stack_display(stk, n);
				break;
			case 4:
				system("clear");
				break;
			case 5:
				exit(1);
			default:
				printf("\nInvalid option entered.\n");
		}
	}
}

int stack_init(int *stk, int *top) {
	int n;
	printf("Enter the size of stack: ");
	scanf("%d", &n);

	*top = n;

	return n;
}

void push(int *stk, int x) {
	
	if(stack_full(stk) == 1) {
		printf("\nStack full. Overflow condition.\n");
		return;
	}
	
	top--;
	stk[top] = x;
}

int pop(int *stk) {
	
	int x;
	
	if(stack_empty(stk, n) == 1) {
		printf("\nStack empty. Underflow condition.\n");
		return INT_MAX;
	}

	x = stk[top];
	top++;
		
	return x;
}

int seek(int *stk) {
	
	if(stack_empty(stk, n) == 1) {
		printf("\nStack  empty. No elements.\n");
		return INT_MAX;
	}
	else 
		return stk[top];
}

void stack_display(int *stk, int n) {
	printf("\nTOP \n");
	for(int i = top; i < n; i++) {
		printf("%d\n", stk[i]);
	}
}
	



int stack_empty(int *stk, int n) {
	
	if(top == n)
		return 1;
	else 
		return 0;
}

int stack_full(int *stk) {
	if(top == 0) 
		return 1;
	else
		return 0;
}











