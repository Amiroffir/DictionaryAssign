#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable : 4996)
void add(int key, int val);
void printDictionary();
struct item* search(int key);
void removed(int key);
typedef struct item {
	int val;
	int key;
	struct item* next;
	struct item* prev;
}item;
struct item* head;
struct item* tail;
int ID_COUNTER = 1;

int main() {
	char ind = 'x';
	int val1, val2;
	while (ind != 'E')
	{
		printf("*********MENU*********\ntype charachter for execution\n'I'.add item to list\n'R'.remove item from list\n'L'.print\n'P'.peek to item value\n'E' for exit: ");
		ind = getch();
		printf("\n\n");
		switch (ind)
		{
		case 'I':
			printf("Please enter item's key and value:\n");
			scanf("%d %d", &val1, &val2);
			add(val1,val2);
			printf("\n\n");
			break;
		case 'R':
			printf("Please enter item to remove key number :\n");
			scanf("%d", &val1);
			removed(val1);
			printf("\n\n");
			break;
		case 'L':
			printDictionary();
			printf("\n\n");
			break;
		case 'E':
			printf("done!");
			printf("\n\n");
			break;
		case 'P':
			printf("Please enter item to peek key number :\n");
			scanf("%d", &val1);
			struct item* temp = search(val1);
			if (temp != NULL)
				printf("item's value is: %d\n", temp->val);
			else
				printf("item not found\n");
			printf("\n\n");
			break;
		default:
			printf("invalid char");
			printf("\n\n");
			break;
		}
	}
}


void add(int key, int val) {
	struct item* curr = malloc(sizeof(struct item));
	curr->key = key;
	curr->val = val;
	curr->next = head;
	curr->prev = NULL;
	if (head != NULL) {
		head->prev = curr;
	}
	head = curr;
	if (tail == NULL) {
		tail = curr;
	}
	ID_COUNTER++;
}

void printDictionary() {
	struct item* curr = head;
	while (curr != NULL) {
		printf("Key: %d, Val: %d\n", curr->key, curr->val);
		curr = curr->next;
	}
}

struct item* search(int key) {
	struct item* curr = head;
	while (head != NULL) {
		if (curr->key == key) {
			//printf(" Val: %d", curr->val);
			return curr;
		}
		head = head->next;
	}
			printf("item isn't found");
			return NULL;
}
void removed(int key) {
	struct item* curr = search(key);
	if (curr != NULL) {
		if (curr->prev != NULL) {
			curr->prev->next = curr->next;
		}
		else {
			head = curr->next;
		}
		if (curr->next != NULL) {
			curr->next->prev = curr->prev;
		}
		else {
			tail = curr->prev;
		}
		free(curr);
		
	}
}
