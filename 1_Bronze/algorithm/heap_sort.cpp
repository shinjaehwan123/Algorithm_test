#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define heap_len 20
int my_heap[heap_len];
int heap_size =0;

void swap(int my_heap[], int me, int parent){
    int temp = my_heap[me];
    my_heap[me] = my_heap[parent];
    my_heap[parent] = temp;
}

void enqueue(int _data){
    if(heap_size == heap_len-1){
        return;
    }
    heap_size++;
    
    my_heap[heap_size] = _data;
    
    int me = heap_size;
    int parent = me/2;

    while(1){
        if(me==1){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] <= my_heap[parent]){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] > my_heap[parent]){
            swap(my_heap, me, parent);
            me = parent;
            parent = me/2;
        }

    }
}

int find_index(int _me) {
	int left_child = _me * 2;
	int right_child = left_child + 1;

	//무자식
	if (left_child > heap_size) {
		return 0;
	}
	//홑자식 하나
	if (right_child > heap_size) {
		return left_child;
	}
	//쌍자식 두명의 자식
	if (my_heap[left_child] < my_heap[right_child]) {
		return right_child;
	}
	else {
		return left_child;
	}
}

void dequeue(void){
    if(heap_size==0){
        cout << "heap이 비어있습니다."<<endl;
        return;
    }
    if(heap_size==1){
        cout << my_heap[1]<<endl;
        heap_size--;
        return;
    }
    int res = my_heap[1];
    cout << res << " ";
    swap(my_heap,1, heap_size);
    heap_size--;
     int me = 1;
    int find = find_index(me);
   

    while(1){
        if(find ==0){
            return;
        }
        else if(my_heap[find] > my_heap[me]){
            swap(my_heap, me, find);
            me = find;
            find = find_index(me);
        }
        else if(my_heap[find] < my_heap[me]){
            return;
        }
    }
}

void show(int my_heap[], int heap_size){
    for(int i=1; i<=heap_size;i++){
        cout << my_heap[i] <<" ";
    }
    cout << endl;
}

int main(void){

    enqueue(10);
    enqueue(100);
    enqueue(5);
    enqueue(1000);
    enqueue(20323);

    show(my_heap, heap_size);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    cout << endl;
    return 0;
}