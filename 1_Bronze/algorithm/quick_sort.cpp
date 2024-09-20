//quick sort C++ 구현
#include <iostream>
#include <queue>

void quick_sort(int data[], int start, int end){
	int pivot = start;
	int low = start+1;
	int high = end;
	if(start >=end){
		return;
	}
	while(low <= high){
		while(data[low] < data[pivot] && low <= end){
			low++;
		}
		while(data[high] >= data[pivot] && high >=start +1){
			high--;
		}
		if(low < high){
			swap(data, low, high);
		}
	}
	swap(data,high, pivot);
	quick_sort(data, start, high-1);
	quick_sort(data, high+1,end);
}

int main(void){
	int data[] = {23,32,34,100,87,76,23,65,2,90,21,1,3};
	int sz = sizeof(data)/sizeof(data[0]);
	quick_sort(data,0,sz-1);
	
	return 0;
}

//bubble sort
#if 0
int do_bubble_sort(int data[], int sz){
	int i,j, temp;
	int cnt=0;
	for(int i=0; i<sz-1; i++){
		for(int j=0; j< sz-1-i; j++){
			if(data[j] > data[j+1]){
				temp =data[j];
				data[j] = data[j+1];
				data[j+1]=temp;

			}
		}
	}
}


#endif

//insert_sort

void do_insertion_sort(int data[], int sz){
	int i,j,temp;

	for(i=1; i<=sz; i++){
		int me =data[i];
		for(int j=i-1; j>=0; j--){
			if(data[j]>me){
				data[j+1] = data[j];
			}
		}
	}
}





#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void show(int data[], int sz) {
	int i;
	for (i = 0; i < sz; i++) {
		printf("%d--->", data[i]);
	}
	printf("\n");
}
void swap(int data[], int idxa, int idxb) {
	int temp = 0;
	temp = data[idxa];
	data[idxa] = data[idxb];
	data[idxb] = temp;
}
int pivot_signal = 0;
void print_neighbor(int data[], int idx,int real_size) {
	pivot_signal = 1;
	if (idx - 1 >= 0) {
		printf("%d ", data[idx - 1]);
	}
	else {
		printf("-999");
	}

	if (idx + 1 < real_size) {
		printf("%d\n", data[idx + 1]);
	}
	else {
		printf("-999\n");
	}
}

void quick_sort(int data[], int start, int end,int real_size,int num) {
	int pivot = start;
	int low = start + 1;
	int high = end;
	if (start >= end) {
		return;
	}
	while (low <= high) {
		while (data[low] <= data[pivot] && low <= end) {
			low++;
		}
		while (data[high] >= data[pivot] && high >= start + 1) {
			high--;
		}
		if (low < high) {
			swap(data, low, high);
		}
	}
	swap(data, high, pivot);
	//show(data, real_size);
	if (data[high] == num) {
		print_neighbor(data, high,real_size);
	}

	quick_sort(data, start, high - 1,real_size,num);
	quick_sort(data, high + 1, end,real_size,num);
}



int main(void) {
	int data[] = {23,32,34,100,87,76,23,65,2,90,21,1,3};
	int sz = sizeof(data) / sizeof(data[0]);
	int num = 32;
	int data_size = sz; 
	quick_sort(data, 0, sz - 1,sz,num);
	//show(data, sz);
	if (pivot_signal != 1) {
		printf("-999");
	}
	return 0;
}
#endif