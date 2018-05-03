#include<stdio.h>
#include<stdlib.h>

void fill_array(int arr[], int n);
void access_element(int arr[], int n);
void search_element(int arr[], int n);


void display_array(int arr[], int n);

int main() {
	
	int n, *arr, choice, index, key;
	printf("Enter the size of array: ");
	scanf("%d", &n);

	
	arr = (int *)malloc(n * sizeof(int));
	fill_array(arr, n);
	while(1) {
		printf("Options: ");
		printf("\n0. Access an element by it's index ");
		printf("\n1. Search for an element ");
		printf("\n2. Insert an element ");
		printf("\n3. Delete an element ");
		printf("\n4. Display the array ");
		printf("\n5. Exit ");

		scanf("%d", &choice);

		switch(choice) {
			case 0:
				access_element(arr, n);
				break;
			case 1:
				search_element(arr, n);
				break;
			case 2:
//				insert_element(arr, &n);
				break;
			case 3:
//				delete_element(arr, &n);
				break;
			case 4:
				display_array(arr, n);
				break;
			case 5:
				return 1;
			default:
				fprintf(stderr, "\nWrong option\n");
		}

	}

}


void fill_array(int arr[], int n) {
	printf("Enter the elements of the array: ");
	for(int i = 0 ; i < n; i++) {
		printf("\nElement %d: ", i);
		scanf("%d", arr + i);
	}	
}

void access_element(int arr[], int n) {
	int index;
	printf("\nEnter the index of the element to be accessed: ");
	scanf("%d",&index);
	if(index < 0) {
		fprintf(stderr, "\nError: Index entered is negative. \n");
		return;
	}
	else if(index >= n) {
		fprintf(stderr, "\nError: Index >= n.\n");
		return;
	}
	else {
		printf("Element at index %d = %d\n", index, arr[index]);
		return;
	}
}

void search_element(int arr[], int n) {
	int key, count = 0;
	printf("\nEnter the key to be searched: ");
	scanf("%d", &key);
	
	printf("\n");
	for(int i = 0; i < n; i++) {
		if(key == arr[i]) {
			printf("%d, ", i);
			count++;
		}
	}

	if(count == 0) {
		printf("\nThe key entered is not present in the array\n");
		return;
	}
	else {
		printf("\nThe key is present in the above %d indices\n", count);
		return;
	}
}


void display_array(int arr[], int n) {
	for(int i = 0 ; i < n; i++) {
		printf("--");
	}

	printf("\n|");
	
	for(int i = 0 ; i < n; i++) 
		printf("%d |", arr[i]);
	

	for(int i = 0 ; i < n; i++) {
		printf("--");
	}
}















