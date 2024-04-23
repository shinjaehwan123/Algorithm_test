#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//우선순위큐 //priority queue Fifo //priority queue는 들어간 순서와 상관없이 sorting해서 나온다
//따라서 우선순위 큐는 fifo의 성질을 가지지 않는다
//heap --->complete binary tree 왼쪽부터 채워준다
//max heap-->부모가 자식보다 크면 max heap따라서 mea heap에서 가장 큰 숫자는 root에 있다
//min heap -->부모가 자식보다 작음
//heap --> complete binary tree 왼쪽부터 채워준다.
//full binary tree --> 다 채워져 있어야된다.
//full binary tree ->  다 채워져 있어야된다.
//complete binary tree --> 다 안채워져도 되지만 왼쪽자식은 채워줘있어야된다.
//구현 배열로 구현(할 수만 있다면 배열로 구현하면 좋다)
//어떻게 자식 찾냐 -->왼쪽 자식은 곱하기 2 오른쪽 자식은 곱하기 2+1 ==> complete binary tree이기 때문에 가능ㅎ다
//부모 어떻게 찾냐 자기 인덱스에 나누기 2를 하면 부모를 찾을 수 있다
//배열 사이즈 100이라고 하면 배열의[0]번은 버려지고 [1]번부터 사용가능해서 총 99개를 사용할 수 있다

//구현
//heap_size : 현재 maxheap에 들어있는 데이터 개수  heap size : 현재 maxheap에 들어있는 데이터 개수
//데이터새로들어오면 부모랑 비교해주면 된다. 데이터새로 들어오면 부모랑 부교해 주면 된다.
//내가 부모보다 작으면 끝 or 내가 1번 자리까지 올라올때가지 하면 된다. 내가 부모보다 작으면 끝 or 내가 1번 자리까지 올라올때까지 하면 된다.
//enqueue
//dequeue ==> root 즉 1번 값을 dequeue한다
//root빼면 트리 붕괴, 모양 맞춰주기위해 끝에꺼 root자리로 올린다. 그 이후 자식 중 큰 애랑 비교한다


#if 0
#define heap_len 20
int my_heap[heap_len];
int heap_size = 0; //==>들어가 있는게 아무것도 없다 따라서 0이다.

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void enqueue(int _data) {
	if (heap_size == heap_len - 1) {
		printf("priority queue full\n");
		return;
	}
	//새식구 만들어 주기
	heap_size++; //인덱스 0번은 사용하지 않음
	my_heap[heap_size] = _data;

	//자기 자리 찾아가기
	int me = heap_size;
	int parent = me / 2;

	while (1) {
		if (me == 1) {
			return;
		}
		//내가 부모보다 작으니 여기가 내자리이다.
		if (my_heap[me] < my_heap[parent]) {
			return; //부모보다 작으면 자리 찾은거니까 thank you case
		}
		else {//알고보니 부모가 아니엇다. 자리를 바꿔줘야한다
			swap(my_heap[parent], my_heap[me]);
			me = parent;
			parent = me/2;
		}
	}
	

}

//자식 중 큰 값을 가진 자식의 index를 반환해준다
//만약 자식이 없으면 0을 반환 왜나하면 인덱스 0번은 사용하지 않는 공간이기 대문이다
int findReplace(int _me) {
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

int dequeue(void) {
	if (heap_size == 0) {
		printf("우선순위큐가 비었음\n");
		return -999;
	}
	//첫번째 node가 0이되면 나누기 2를 해도 0이기때문에 1부터 시작을 한다
	int res = my_heap[1]; //큐에서 꺼내느 값
	//max heap을 복구해준다.
	//1. 모양복구
	my_heap[1] = my_heap[heap_size]; // 맨 끝에 있는 애를 올려준다. 올려준 애 안지운다
	//따라서 heap size를 안지운은게 중욯다
	heap_size--;

	//2. 집안 전통 복구한다
	int me = 1;

	while (1) {
		//자식 중 큰 값을 가진 자식의 index를 반환해준다
		//만약 자식이 없으면 0을 반환해준다
		int replacer = findReplace(me);
		//자식이 없으면 여기가 내자리
		if (replacer == 0) {
			return res;
		}

		//내가 자식보다 크다
		if (my_heap[me] >= my_heap[replacer]) {
			return res;
		}

		//자리를 비켜주자
		swap(my_heap[me], my_heap[replacer]);
		me = replacer;
	}

}

int main(void) {
	enqueue(10);
	enqueue(20);
	enqueue(5);
	enqueue(100);
	
	for (int i = 0; i < 4; i++) {
		printf("%d\n", dequeue());
	}

	return 0;
}
#endif


struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node{
	int data;
	struct node*left;
	struct node*right;
}

struct node* root = 0;

void addBST(int n){
    struct node* temp = root;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->left = 0;
    newnode->right = 0;
    

    if(root ==0){
        root = newnode;
        return;
    }

    while(1){
        if(newnode->data > temp->data){
            if(temp->right == 0){
                temp->right = newnode;
                break;
            }
            else{
                temp = temp->right;
            }
        }
        else if(newnode->data < temp->data){
            if(temp->left == 0){
                temp -> left = newnode;
                break;
            }
            else{
                temp = temp->left;
            }
        }
    }
}

void delFRomBSt(struct node *_r, int data){
	struct node *t = _r;
	struct node *t_p = 0;

	while(1){

		if(t == 0){
			return;
		}	

		if(t->data = n){
			//삭제할때 영향을 받지 않는다
			if(t->right ==0 && t->left ==0){
				if(t==root){
					root =0;
					return;
				}
				if(t_p ->left ==t){
					t_p->left =0;
				}
				else if(t_p->right ==t){
					t_p->right =0;
				}
				free(t);
				return;

			}


			//삭제할때 하나의 영향을 받는다
			if(t->right !=0 && t->left ==0){
				if(t==root){
					root = t->right;
					free(t);
					return;
				}

				if(t_p->left == t){
					t_p->left = t->right;
					free(t);
					return;
					
				}
				else if(t_p->right == t){
					t_p->right  = t->right;
					free(t);
					return;
				}
			}

			else if(t->right ==0 && t->left !=0){
				if(t_p->left == t){
					t_p->left = t->left;
					free(t);
					return;
				}

				else if(t_p->left == t){
					t_p->left = t->left;
					free(t);
					return;
				}

			}


			//삭제할때 2개의 영향을 받는다.
			else if(t->right != 0 && t->left !=0){
				if(t == root){
					root = t->right;
					

				}
			}

		}
		else{
			t_p = t;

			if(t->data > n){
				t = t->left;
			}
			else if(t->data < n){
				t = t->right;
			}
		}

	}




}

void inorder(struct node* _r){
    struct node* temp = _r;
    if(temp == 0){
        return;
    }
    inorder(_r->left);
    printf("%d ", _r->data);
    inorder(_r->right);
    
}

int main(void){
    addBST(100);
    addBST(1500);
    addBST(50);

    inorder(root);

    return 0;
}