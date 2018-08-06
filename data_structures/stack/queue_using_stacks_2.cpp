#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void enqueue(int x);
int dequeue();
void dequeue(int *x);
void display_queue();

int main() {

	int choice, x;
	while(1) {

		cout<<"Options: "<<endl;
		cout<<"0. Enqueue a number"<<endl;
		cout<<"1. Dequeue "<<endl;
		cout<<"2. Clear Screen"<<endl;
		cout<<"3. Exit"<<endl;

		cin>>choice;

		switch(choice) {

			case 0:
				cout<<"\nEnter number to enqueue: ";
				cin>>x;
				enqueue(x);
				break;
			
			case 1:
				x = dequeue();
				cout<<"Number dequeued = "<<x<<endl;
				break;

			case 2:
				system("clear");
				break;

			case 3:
				return 0;

			default:
				cout<<"Invalid Choice"<<endl;
		}

	}

	return 0;
}


void enqueue(int x) {

	s.push(x);
	return;
}


int dequeue() {

	if(s.empty() == true) {
		cout<<"Queue empty. Dequeue operation discarded"<<endl;
		return INT_MAX;
	}

	int x;
	dequeue(&x);
	return x;
}

void dequeue(int *x) {

	int y;

	y = s.top();
	s.pop();
	if(s.empty() == true) {
		*x = y;
		return;
	}
	else {
		dequeue(x);
		s.push(y);
	}

	return;
}


