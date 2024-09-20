#include <stdio.h>
#include <stdlib.h>

#if 0
struct node{
    int data;
    struct node* next;
};
struct node* head =0;

void addToSLL(int n){
    struct node* temp = head;
    struct node* newnode = (struct node*)malloc(struct node);
    
    ndwnode->next = 0;
    newnode->data = n;
    if(head==0){
        head = newnode;
        return;
    }

    //만약 더 이상 갈곳이 없으면 정보의 마지막 부분에서 멈춘다.
    while(temp->next !=0){
        temp = temp->next;
    }
    temp->next = newnode;
    
    return;
}

void showSLL(void){
    struct node * temp = head;
    if(temp==0){
        return;
    }

    while(temp!=0){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return;
}

void deleteFromSLL(int n){
    struct node*temp = head;
    struct node* prev = head;

    //먼저 지워야할 노드로 이동을 한다.
    while(temp!=0){
        if(temp->data == n){
            break;
        }
        temp = temp->next;
    }

    while(pre->next !=0){
        if(prev->next == temp){
            break;
        }
        else{
            prev = prev->next;
        }
    }

    //찾은 것이 없다면
    if(temp==0){
        return;
    }

    //만약 첫번째 정보를 지워야한다면
    if(head == temp){
        head = head->next;
        free(temp);
        return;
    }
    
    else{
        prev->next = temp->next;
        free(temp);
        return;
    }
    
}

void insertIntoSLL(int n, int m){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    struct node*temp = head;
    struct node*prev = head;

    newnode->next =0;
    newnode->data = m;

    while(temp!=0){
        if(temp->data == n){
            break;
        }
        else{
            temp= temp->next;
        }
    }

    while(pre->next !=0){
        if(prev->next == temp){
            break;
        }
        prev = prev->next;
    }

    if(temp ==0){
        return;
    }

    if(temp == head){
        newnode->next = head;
        head = newnode;
        return;
    }

    newnode->next = temp;
    prev->next = newnode;
    return;
}
#endif

#if 0
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head =0;

void addToData(int n){
    struct node*temp = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = newnode->prev =0;
    newnode->data = n;

    if(head ==0){
        head = newnode;
        return;
    }
    else{
        while(temp->next !=0){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return;
}


void delete(int n){
    struct node* temp = head;

    while(temp!=0){
        if(temp->data == n){
            break;
        }
        temp = temp->next;
    }

    //찾는 데이터가 없기 때문에 return을 해준다.
    if(temp==0){
        return;
    }
    if(head == temp){
        head = head->next;
        if(head!=0){
            head->prev =0;
        }
        free(temp);
        return;
    }
    if(temp->next!=0){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        
        return;
    }
    else if(temp->next ==0){
        temp->prev->next =0;
        free(temp);
        return;
    }
}

void insert(int n, int m){//n뒤에 m을 삽인한다.
    struct node*temp = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = newnode->next =0;
    newnode->data = m;

    while(temp!=0){
        if(temp->data == n){
            break;
        }
        temp = temp->next;
    }
    if(temp ==0){
        printf("찾는 데이터가 없습니다.");
        return;
    }
    
    if(temp == head){
        if(head->next ==0){
            newnode->prev = head;
            newnode->next =0;
            head->next = newnode;
            return;
        }
        else{
            newnode->prev = head;
            newnode->next = head->next;
            head->next = newnode;
            newnode->next->prev =newnode;
            
            return;
        }
    }

    if(temp->next !=0){
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
        
        return;
    }

    else if(temp->next ==0){
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next = temp;
        return;
    }

}

void show(void){
    struct node* temp = head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void){
    int i,a;
    scanf("%d", &a);

    for(i=0; i<a; i++){
        int data;
        scanf("%d", &data);
        addToData(data);
    }

    int j,k;

    scanf("%d %d", &j, &k);
    insert(j,k);
    show();
    delete(20);
    show();
}
#endif

#if 0
struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node*root =0;

void addToData(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = root;
    newnode->left = newnode->right =0;
    newnode->data =n;

    if(root ==0){
        root = newnode;
        return;
    }

    while(1){
        if(temp->data > n){
            if(temp->left ==0){
                //작은 값은 왼쪽 가지에 배치를 한다.
                temp->left = newnode;
                return;
            }
            else{
                //만약 해당 노드에 값이 존재하면
                temp= temp->left; //작은 쪽으로 이동한다.
            }
        }
        
        else if(temp->data <=n){
            if(temp->right ==0){
                temp->right = newnode;
                return;
            }
            else{
                temp = temp->right;
            }
        }
    }

    return;
}

void delFromBST(int _data, struct node* _r){
    struct node *t = _r;
    struct node *t_p = 0;

    while(1){
        //만약에 지울 데이터가 BST에 없을때에는 그냥 return을 해준다.
        if(t==0){
            return;
        }

        //데이터를 찾았으면
        else if(t->data == _data){
            //Case1 찾은 노드에 자식이 없을때를 고려해준다. 
            if(t->left ==0 && t->right ==0){
                //삭제할 노드가 root일 경우가 있음. root하나만 있으면 그냥 날리면됨
                if(t==root){
                    root=0;
                    free(t);
                    return;
                }

                //날리는 쪽이 부모 노드의 왼자식 이었을때는
                if(t_p->left ==t){
                    t_p->left =0;
                }
                else if(t_p->right == t){
                    t_p->right =0;
                }
                free(t);
                return;
            }

            //이제 삭제할 노드에 왼자식이 있을 경우를 고려해준다.
            else if(t->left !=0 && t->right ==0){
                //삭제할 노드가 head인 경우를 고려해줘야한다.
                if(t==root){
                    //이제 root에 왼자식이 들어가야한다.
                    root = t->left;
                    free(t);
                    return;
                }
                
                //지우려는 노드가 부모 노드의 왼자식일 때는
                if(t_p->left == t){
                    t_p->left = t->left;
                    free(t);
                    return;
                }
                //지우려는 노드가 부모 노드의 오른쪽 자식일 때는
                else if(t_p->right == t){
                    t_p->right = t->right;
                    free(t);
                    return;
                }
            }

            //이제 지우려는 노드에 오른자식만 있어야할 할 case를 말해줌
            else if(t->left==0 && t->right !=0){
                //만약 지워야할 노드가 root이면
                if(t==root){
                    root = t->right;
                    free(t);
                    return;
                }
                
                //만약 지워야할 노드가 부모 노드의 왼자식 이었으면
                if(t_p->left ==t){
                    t_p->left = t->right;
                    free(t);
                    return;
                }
                
                //만약 지워야할 노드가 부모 노드의 오른쪽 자식이었으면
                else if(t_p->right == t){
                    t_p->right = t->right;
                    free(t);
                    return;
                }
            }

            //이제 지울 노드 양쪽에 자식이 있을 경우를 고려해준다.
            else if(t->left !=0 && t->right != 0){
                //왼쪽 자식을 고려해준다.
                struct node* r = t->left;
                struct node* r_p =t;

                while(r->right !=0){
                    r_p = r;
                    //제일 큰거를 찾아야된다.
                    r = r->right;
                }
                //제일 큰거를 찾았으면 이제 바꿔준다.
                t->data = r->data;

                //만약 parnet node가 r이라면
                if(r_p->right == r){
                    r_p->right = r->left; 
                }
                else{
                    r_p->left = r->left;
                }
                free(r);
                return;
            }
        }

        else{
            t_p = t;
            if(t->data > _data){
                t = t->left;
            }
            else if(t->data <=_data){
                t = t->right;
            }
        }
    }
}

void inorder(struct node* _r){
    if(_r==0){
        return;
    }

    inorder(_r->left);
    printf("%d\n", _r->data);
    inorder(_r->right);
}


int main(void) {
	addToData(100);
	addToData(200);
	addToData(50);
	addToData(10);
	addToData(40);
	addToData(2000);
	delFromBST(40,root);
	inorder(root);

}
#endif

#if 0
void swap(int *data, int a, int b){
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

int do_selection_sort(int _data[], int _sz){
    int temp;
    int i;
    int least =0; // 가장작은 값을 가지는 index이다.
    int cnt = 0;

    for(int k=0; k<_sz-1; k++){ //마지막은 비교해줄 필요없음 
        least = k;

        for(i = k+1; i<_sz; i++){
            if(_data[least] > _data[i]){
                least = i;
            }
        }
        //이제 최소값을 뽑았음 
        swap(_data, least, k);
    }
}

void do_insertion_sort(int _data[], int _sz){
    int i,j,temp;

    for(i = 1; i<_sz; i++){
        int me = _data[i];
        
        for(j = i-1; j>=0 ; j--){
            if(me < _data[j]){
                _data[j+1] = _data[j];
            }
            else if(me >= _data[i]){
                break;
            }
        }
        _data[j+1] = me;
    }
}

int main(void){
    int data[] = {1,100,99,20,99,20};
    int sz = sizeof(data)/sizeof(data[0]);
    
    do_insertion_sort(data,sz);

    for(int i=0; i< sz; i++){
        printf("%d ",data[i]);
    }
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node * left;
};

struct node*root =0;

void addToData(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node*temp = head;
    newnode->data = n;

    if(root ==0){
        newnode = root;
        return;
    }

    while(1){
        if(temp->data > n){
            if(temp->left ==0){
                temp->left = newnode;
                return;
            }
            else{
                //만약 해당 노드에 값이 존재한다면
                temp = temp->left;

            }
        }
        
        else if(temp->data <=n){
            if(temp->right ==0){
                temp->right = newnode;
                return;
            }
            else{
                temp = temp->right;
            }
        }
    }
    return;
}

void delFromBST(int _data, struct node* r){
    struct node*t = _r;
    struct node*t_p = 0;

    while(1){
        //만약에 지울 데이터가 BST에 없을때에는 그냥 return을 gownsek.
        if(t == 0){
            printf("찾는 node가 없습니다.");
            return;
        }

        //만약 데이터를 찾았따면
        else if(t->data  == _data){
            if(t->left ==0 && t->right ==0){
                if(t == root){
                    root =0;
                    free(t);
                    return;
                }

                //root가 아니라면
                if(t_p->left == t){
                    t_p->left =0;    
                }
                else if(t_p->right == t){
                    t_p->right =0;
                }
                free(t);
                return;
            }
            ///////////////////////////////////////////
            else if(t->left !=0 && t->right ==0){
                if(t == root){
                    root = t->left;
                    free(t);
                    return;
                }

                if(t_p->left == t){
                    t_p->left = t->left;
                    free(t);
                    return;
                }
                else if(t_p->right == t){
                    t_p->right = t->left;
                    free(t);
                    return;
                }
            }
            ////////////////////////////////////////////
            else if(t->left ==0 && t->right !=0){
                if(root == t){
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
                    t_p->right = t->right;
                    free(t);
                    return;
                }
            }
            /////////////////////////////////////////////
            else if(t->left !=0 && t->right !=0){
                struct node* r = t->left;
                struct node * r_p = t;

                //제일 큰거를 찾아야함
                while(r->right!=0){
                    r_p = r;
                    r = r->right;
                }
                //이제 제일 큰거를 찾았음
                t->data = r->data;

                //만약 parent node가 rdlfkaus

                if(r_p->right == r){
                    r_p->right = r->left;
                }
                else{
                    r_p->left = r->left;
                }
                free(r);
                return;
            }
        }
        else{
            t_p = t;
            if(data > t->data){
                t = t->right;
            }
            else{
                t = t->left;
            }
        }
    }
}

//BST의 높이를 찾는다.
int MeasureHeight(struct node*_r){
    int right_height =0;
    int left_height =0;

    if(_r==0){
        return 0;
    }

    right_height = MeasureHeight(r->right);
    left_height = MeasureHeight(r->left);

    return 1+((right_height > left_height) ? right_height : left_height);
}

int cntBST(struct node *r){
    if(r==0){
        return;
    }
    return 1+ cntBST(r->left) + cntBST(r->right);
}

int cntTerminalNodes(struct node *r){
    if(r==0){
        return;
    }

    //내가 terminal node이면 1을 반환한다.
    if(r->left ==0 && r->right ==0){
        return 1;
    }

    //내가 Terminal node가 아니라면 왼쪽 ndoe , 오른쪽 node 값을 더해서 반환한다.
    else{
        return cntTerminalNodes(r->right) + cntTerminalNodes(r->left);
    }
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node*root =0;

void addToData(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = root;
    newnode->left = newnode->right =0;
    newnode->data = n;

    if(root==0){
        root = newnode;
        return;
    }

    while(1){
        if(temp->data > n){
            if(temp->left ==0){
                temp->left = newnode;
                return;
            }
            else{
                //만약 해당 노드값에 값이 존재하면 
                temp = temp->left;
            }
        }
        else if(temp->data <= n){
            if(temp->right ==0){
                temp->right = newnode;
                return;
            }
            else{
                temp = temp->right;
            }
        }
    }

    //void 니까 자동적으로 return이 되낟.
    
}


void delFromBST(int _data, struct node* r){
    struct node *t = r;
    struct node *t_p = 0;

    while(1){
        //만약 지울 데이터가 BST에 없을때 그냥 return을 해준다.
        if(t==0){
            return;
        }
        else if(t->data == data){
            //case1 찾은 노드에 자식이 없을때를 고렿나다.
            ////////////////////////////////////////////////
            if(t->left ==0 && t->right ==0){
                //자식이 없을때
                if(t==root){
                    root =0;
                    free(t);
                    return;
                }

                //날리는 쪽이 부모 노드의 왼자식일 때를 고려한다.
                if(t_p->left == t){
                    t_p->left =0;
                }
                else if(t_p->right == t){
                    t_p->right =0;
                }
                free(t);
                return;
            }

            //이제 삭제할 노드가 왼자식일 때를 고려한다.
            else if(t->left !=0 && t->right ==0){
                if(t==root){
                    root=0;
                    root = t->elft;
                    free(t);
                    return;
                }

                //지우려는 노드가 부모 노드의 왼족일 때를 고려한다.
                if(t_p->elft == t){
                    t_p->left = t->left;
                    fee(t);
                    return;
                }
                //지우려는 노드가 부모 노드의 오른쪽에 위치를 한다면
                else if(t_p->right == t){
                    t_p->right = t->left;
                    free(t);
                    return;
                }
            }

            else if(t->left ==0 && t->right !=0){
                if(t==root){
                    root = t->right;
                    root =0;
                    return;
                }
                
                else if(t_p->right == t){
                    t_p->right = t->right;
                    free(t);
                    return;
                }

                else if(t_p->left == t){
                    t_p->left  = t->rightl
                    free(t);
                    return;
                }
            }

            //이제 지울 노드에 양쪽에 노드가 있을 경우를 고려함
            else if(t->elft !=0 && t->right !=0){
                struct node*r = t->left;
                struct node *r_p = t;

                while(r->right !=0){
                    r_p = r;
                    r = r->right;
                }
                //제일 큰거를 찾았으면 이제 바꿔준다.
                t->data = r->data;

                if(r_p->right == r){
                    r_p->right = r->left;
                }

                else(r_p->left == r){
                    r_p->left = r->elft;
                }
                //모두 끝냈으면 이제 t를 날려준다.
                free(r);
                returnl
            }
        }
        else{
            //이제 t_p가 이동을 한다.
            t_p = r;
            if(t->data > _data){
                t = t->left;
            }
            
            else if(t->data <= _data){
                t = t->right;
            }
            
        }
    }
}

//이제 BST의 height를 측정하겠다.
int MeasureHeight(struct node *_r){
    int right_height =0;
    int left_height =0;

    //탈출 조건을 설정한다.
    if(_r==0){
        return 0;
    }

    right_height = MeasureHeight(_r->right);
    left_height = MeasureHeight(_r->left);

    return 1 + (right_height > left_height) ? right_height : left_height;
}

int cntBSTNodes(struct node *_r){
    if(_r==0){
        return 0;
    }
    return 1 + cntBSTNode(_r->left) + cntBSTNodes(_r->right);
}

//BST에 포함된 terminal node의 개수를 구하는 함수
int cntTerminal(struct node *r){
    if(_r==0){
        return 0;
    }
    if(_r->left ==0 && _r->right ==0){
        return 1;
    }
    else{
        return cntTerminal(_r->right) + cntTerminal(_r->left);
    }
}

void inorder(strcut node *_r){
    if(_r==0){
        return;
    }

    inorder(_r->left);
    printf("%d\n", _r->data);
    inorder(_r->right);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head =0;

void addToData(int n){
    struct node* temp = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = newnode->prev =0;
    newnode->data = n;
    if(head ==0){
        head = newnode;
        return;
    }
    else{
        while(temp->next !=0){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return;
}

void deldata(int n){
    struct node*temp = head;
    while(temp!=0){
        if(temp->data == n){
            break;
        }
        temp = temp->next;
    }

    if(temp == 0){
        return;
    }
    if(head == temp){
        head = head->next;
        if(head !=0){
            head->prev =0;
        }
        free(temp);
        return;
    }
    if(temp->next !=0){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
    else{
        temp->prev->next =0;
        free(temp);
        return;
    }
}

void insert(int n, int m){
    struct node* temp = head;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = newnode->next =0;
    newnode->data = m;
    while(temp!=0){
        if(temp->data == n){
            break;
        }
        temp = temp->next;
    }

    if(temp ==0){
        return;
    }
    if(temp==head){
        if(head->next ==0){
            newnode->prev = head;
            newnode->next =0;
            head->next = newnode;
            return;
        }
    }

    if(temp->next !=0){
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
    else{
        newnode->prev = temp;
        newndoe->next = 0;
        temp->next = temp;
    }

}
#endif

