#include<bits/stdc++.h>
using namespace std;

stack<int> s1, s2;

void enqueue(int x);
int dequeue();
void display_queue();

int main() {

	int choice, x;
	while(1) {

		cout<<"Options: "<<endl;
		cout<<"0. Enqueue a number"<<endl;
		cout<<"1. Dequeue "<<endl;
		cout<<"2. Display the queue"<<endl;
		cout<<"3. Clear Screen"<<endl;
		cout<<"4. Exit"<<endl;

		cin>>choice;

		switch(choice) {

			case 0:
				cout<<"\nEnter number to enqueue: ";
				cin>>x;
				enqueue(x);
				display_queue();
				break;
			
			case 1:
				x = dequeue();
				cout<<"Number dequeued = "<<x<<endl;
				display_queue();
				break;

			case 2:
				display_queue();
				break;

			case 3:
				system("clear");
				break;

			case 4:
				return 0;

			default:
				cout<<"Invalid Choice"<<endl;
		}

	}

	return 0;
}


void enqueue(int x) {

	if(s1.empty() == true && s2.empty() == true) {
		s2.push(x);
		return;
	}
	else if(s1.empty() == true && s2.empty() == false) {
	
		while(s2.empty() == false) {
			s1.push(s2.top());
			s2.pop();
		}

		s1.push(x);

		while(s1.empty() == false) {
			s2.push(s1.top());
			s1.pop();
		}
		
		return;
	}
}

int dequeue() {

	if(s2.empty() == true) {
		cout<<"No elements in queue"<<endl;
		return INT_MIN;
	}

	int x = s2.top();
	s2.pop();

	return x;
}

void display_queue() {

	int x;
	
	cout<<"FRONT"<<endl;
	while(s2.empty() == false) {
		
		x = s2.top();
		cout<<x<<endl;
		s1.push(x);
		s2.pop();
	}

	while(s1.empty() == false) {

		s2.push(s1.top());
		s1.pop();
	}

	return;
}














