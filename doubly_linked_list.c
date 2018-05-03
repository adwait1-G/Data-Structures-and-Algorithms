#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	
	int key;
	struct node *next;
	struct node *prev;
} list_node;



list_node *list_head, *new_node, *to_delete_node, *temp;

unsigned int list_length;


void list_init();
void insert_node();
void delete_node();
void list_search();
void list_sort();
void update_node();
void list_reverse();
void list_display();

int main() {
	
	int choice, key;
	list_init();

	while(1) {
		printf("\nOptions: ");
		printf("\n0. Insert a node ");
		printf("\n1. Delete a node ");
		printf("\n2. Search for a key ");
		printf("\n3. Sort the list ");
		printf("\n4. Update a node's key ");
		printf("\n5. Reverse the list ");
		printf("\n6. Display list ");	
		printf("\n7. Clear screen \n");
		scanf("%d", &choice);

		switch(choice) {
			case 0:
				insert_node();
				break;
			case 1:
				delete_node();
				break;
			case 2:
				list_search();
				break;
			case 3:
//				list_sort();
				break;
			case 4:
				update_node();
				break;
			case 5:
				list_reverse();
				break;
			case 6:
				list_display();
				break;
			case 7:
				system("clear");
				break;
			default: 
				fprintf(stderr, "\nInvalid option\n");
		}

	}

	return 0;
}


void list_init() {
	list_head = (list_node *)malloc(sizeof(list_node));
	list_head->prev = NULL;
	list_head->next = NULL;
	list_head->key = 0;

	list_length = 0;
}

void insert_node() {
	int index, flag, i;
	list_node *current;

	new_node = (list_node *)malloc(sizeof(list_node));

	printf("Enter the key: ");
	scanf("%d", &new_node->key);

	
	if(list_head->next == NULL) {
		printf("\nThis is the first node.");
		
		new_node->prev = list_head;
		new_node->next = list_head->next;		//Essentially, new_node->next = NULL;	
		list_head->next = new_node;	
	}
	else {
		printf("\n***Note: Indexing starts from 0***\n");
		printf("\nEnter the position to insert: ");
		scanf("%d", &index);

		if(index < 0 || index > list_length) {
			fprintf(stderr, "\nError: Invalid position entered\n");
			return;
		}
		current = list_head;
		i = 0;
		while( i < index) {
			current = current->next;
			i++;
		}

		new_node->next = current->next;
		new_node->prev = current;
		current->next = new_node;		
		current->next->prev = new_node;
	}
	
	list_length += 1;
	list_display();
}

void delete_node() {
	int index, i;
	list_node *current;

	if(list_length == 0) {
		fprintf(stderr, "\nNew List. No nodes to delete\n");
		return;
	}
	
	printf("\nEnter the index of node to be deleted: ");
	scanf("%d", &index);

	if(index < 0 || index >= list_length) {
		fprintf(stderr, "\nError: Invalid index entered\n");
		return;
	}

	current = list_head;

	for(i = 0 ; i < index; i++) {
		current = current->next;
	}

	to_delete_node = current->next;
	
	if(to_delete_node->next != NULL) 
		current->next->next->prev = current;

	current->next = current->next->next;
	
	free(to_delete_node);
	list_length -= 1;

	return;
}

void list_search() {
	
	int value, index, choice, flag = 0, i;
	list_node *current;
	printf("\nOptions: ");
	printf("\n0. Search by key ");
	printf("\n1. Retrive key by Index \n");
	scanf("%d", &choice);

	if(choice == 0) {
		printf("Enter the key: ");
		scanf("%d", &value);
		
		current = list_head;
		i = -1;
		while(current->next != NULL) {
			i += 1;
			if(current != list_head) {
				if(current->key == value) {
					flag = 1;
					printf("Index of the key: %d\n", i - 1);
					return;
				}
			}
			current = current->next;
		}

		if(flag == 0) {
			printf("\nKey not found \n");
		}
	}
	else if(choice == 1) {
		int i;
		list_node *current;
		
		printf("\nEnter the Index (0-indexed list): ");
		scanf("%d", &index);
		
		if(index < 0 || index >= list_length) {
			fprintf(stderr, "Error: Invalid index entered\n");
			return;
		}

		current = list_head;
		i = -1;
		while(i < index) {
			i += 1;
			current = current->next;
		}

		printf("Key at Index %d = %d\n", index, current->key);
	}
	
	return;
}

void update_node() {
	int index, value, i;
	list_node *current;
	
	printf("\nPresent: \n");
	list_display();
	
	printf("\nEnter the index of node whose key is to be updated: ");
	scanf("%d", &index);

	if(index < 0 || index >= list_length) {
		fprintf(stderr, "\nError: Invalid Index entered\n");
		return;
	}

	printf("Enter the new key: ");
	scanf("%d", &value);

	current = list_head;
	
	for(i = 0 ; i <= index; i++) {
		current = current->next;
	}

	current->key = value;

	printf("\nUpdated: \n");
	list_display();

	return;
}

void list_reverse() {
	
	list_node *prev_node, *cur_node, *next_node;
	
	list_display();
	if(list_length == 0) {
		printf("\nNo nodes in the list.\n");
	}
	else if(list_length == 1) {
		printf("\n1 node in the list.\n");
	}
	else if(list_length == 2) {
		prev_node = list_head->next;
		current = list_head->next->next;
		
		list_head->next = current;

		current->next = prev_node;
		current->prev = list_head;

		prev_node->next = NULL;
		prev_node->prev = current;
		
		list_display();
	}
	else {
		}
}





void list_display() {
	list_node *current;
	current = list_head;
	printf("\nList: Head --> ");
	while(1) {
		if(current == NULL) {
			printf("NULL\n");
			break;
		}
		else if(current != list_head) {
			printf("%d --> ", current->key);
		}
		
		current = current->next;
	}

	return;
}



























