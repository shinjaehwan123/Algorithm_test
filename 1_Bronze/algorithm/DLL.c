#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head = 0;
void addToData(int n) {
	struct node* temp = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = newnode->prev = 0;
	newnode->data = n;
	if (head == 0) {
		head = newnode;
		return;
	}
	else {
		while (temp->next != 0) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
	return;
}


void deldata(int n) {
	struct node* temp = head;
	while (temp != 0) {
		if (temp->data == n) {
			break;
		}
		temp = temp->next;
	}
	if (temp == 0) {
		return;
	}
	if (head == temp) {
		head = head->next;
		if (head != 0) {
			head->prev = 0;
		}
		free(temp);
		return;
	}
	if (temp->next != 0) {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
		return;
	}
	else {
		temp->prev->next = 0;
		free(temp);
		return;
	}
}

void insert(int n, int m) {//n뒤에 m을 삽입한다
	struct node* temp = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->prev = newnode->next = 0;
	newnode->data = m;
	while (temp != 0) {
		if (temp->data == n) {
			break;
		}
		temp = temp->next;
	}
	if (temp == 0) {
		return;
	}
	if (temp == head) {
		if (head->next == 0) {
			newnode->prev = head;
			newnode->next = 0;
			head->next = newnode;
			return;
		}
	}

	if (temp->next != 0) {
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next = newnode;
		newnode->next->prev = newnode;
		return;
	}
	else {
		newnode->prev = temp;
		newnode->next = 0;
		temp->next = temp;
		return;
	}
}

void insert2(int n, int m) { // n앞에 m을 삽입한다
	struct node* temp = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->prev = newnode->next = 0;
	newnode->data = m;
	while (temp != 0) {
		if (temp->data == n) {
			break;
		}
		temp = temp->next;
	}
	if (temp == 0) {
		return;
	}
	if (temp == head) {
		newnode->next = head;
		head->prev = newnode;
		newnode->prev = 0;
		head = newnode;
		return;
	}
	else {
		newnode->next = temp;
		newnode->prev = temp->prev;
		temp->prev = newnode;
		newnode->prev->next = newnode;
	}

}




void show(void) {
	struct node* temp = head;
	while (temp != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(void) {
	int i, a;
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		int data;
		scanf("%d", &data);
		addToData(data);
	}
	int j, k;
	scanf("%d %d", &j, &k);
	insert2(j, k);
	deldata(20);
	show();
}