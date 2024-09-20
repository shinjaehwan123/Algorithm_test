#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* head = 0;

void addToSLL(int n) {
	struct node* temp = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = 0;
	newnode->data = n;
	if (head == 0) {
		head = newnode;
		return;
	}
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = newnode;
	return;
}

void showSLL(void) {
	struct node* temp = head;
	if (temp == 0) {
		return;
	}
	while (temp != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	return;
}

void destroySLL(void) {
	struct node* temp = head;
	if (temp == 0) {
		return;
	}
	while (head != 0) {
		head = head->next;
		free(temp);
		temp = head;

	}
}

void deleteFromSLL(int n) {
	struct node* temp = head;
	struct node* prev = head;
	while (temp != 0) {
		if (temp->data == n) {
			break;
		}
		temp = temp->next;
	}
	while (prev->next != 0) {
		if (prev->next == temp) {
			break;
		}
		prev = prev->next;
	}
	if (temp == 0) {
		return;
	}
	if (head == temp) {
		head = head->next;
		free(temp);
		return;
	}
	else {
		prev->next = temp->next;
		free(temp);
		return;
	}
}

void insertIntoSLL(int n, int m) {//n앞에 m을 삽입한다
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	struct node* temp = head;
	struct node* prev = head;
	newnode->next = 0;
	newnode->data = m;
	while (temp != 0) {
		if (temp->data == n) {
			break;
		}
		temp = temp->next;
	}
	while (prev->next != 0) {
		if (prev->next == temp) {
			break;
		}
		prev = prev->next;
	}
	if (temp == 0) {
		return;
	}

	if (temp == head) {
		newnode->next = head;
		head = newnode;
		return;
	}

	newnode->next = temp;
	prev->next = newnode;
	return;

}

void insert2(int n, int m) { //n뒤에 m을 삽입한다
	struct node* temp = head;
	struct node* prev = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = 0;
	newnode->data = m;
	while (temp != 0) {
		if (temp->data == n) {
			break;
		}
		temp = temp->next;
	}
	while (prev->next != 0) {
		if (prev->next == temp) {
			break;
		}
		prev = prev->next;
	}
	if (temp->next != 0) {
		newnode->next = temp->next;
		temp->next = newnode;
		return;
	}
	else {
		temp->next = newnode;
		newnode->next = 0;
		return;
	}
}




int main(void) {
	printf("==============\n");
	addToSLL(1);
	addToSLL(2);
	addToSLL(3);
	showSLL(); // 1 2 3
	printf("\n==============\n");

	insertIntoSLL(1, 10);
	insertIntoSLL(2, 20);
	insertIntoSLL(3, 30);
	insertIntoSLL(4, 40);
	showSLL(); // 1 10 2 20 3 30
	printf("\n==============\n");

	deleteFromSLL(1);
	showSLL(); // 10 2 20 3 30
	printf("\n==============\n");

	deleteFromSLL(20);
	showSLL(); // 10 2 3 30
	printf("\n==============\n");

	deleteFromSLL(30);
	showSLL(); // 10 2 3
	printf("\n==============\n");

	destroySLL();
	showSLL(); // Nothing to show.
	printf("====finish====\n");

}