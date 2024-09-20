#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//내 코드 
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
                    t_p->right = t->left;
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
				//이경우는 왼쪽에 하나밖에 없는 경우를 나타낸다.
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

//여기에서는 BST의 부가 기능을 넣겠다.
//BST의 height를 구하는 코드 구현
int MeasureHeightOfBST(struct node*_r){
	int right_height =0;
	int left_height =0;

	if(_r==0){
		return 0;
	}

	right_height = MeasureHeightOfBST(_r->right);
	left_height = MeasureHeightOfBST(_r->left);

	return 1+((right_height > left_height) ? right_height : left_height); 
}

//원하는 노드가 있는지 찾는다.
struct node* findNode(int _data){
	struct node*cur = root;

	if(cur ==0){
		return 0;
	}

	if(cur->data == _data){
		return cur;
	}
	else if(cur->data > _data){
		cur = cur->left;
	}
	else if(cur->data <= _data){
		cur = cur->right;
	}
}

//이제 BST 안에 있는 노드의 전체 개수를 구한다.
int cntBSTNodes(struct node *_r){
	if(_r==0){
		return 0;
	}
	return 1 + cntBSTNodes(_r->left) + cntBSTNodes(_r->right);
}

//BST에 포함된 terminal node의 개수를 구하는 함수
int cntTerminalNodes(struct node * _r){

	if(_r==0){
		return 0;
	}

	//내가 terminal node이면 1을 반환한다.
	if(_r->left ==0 && _r->right ==0){
		return 1;
	}
	//내가 Terminal node가 아니라면 왼쪽 node, 오른쪽 node 값을 더해서 반환한다.
	else{
		return cntTerminalNodes(_r->right) + cntTerminalNodes(_r->left);
	}

}



//traversal 구현  
//pre-order : 나 - L - R
//post-order : L - R - 나
//in-order : L - 나 - R
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
	addToData(45);
	addToData(2000);
	delFromBST(40,root);
	inorder(root);

	printf("\n");

	printf("Height : %d\n", MeasureHeightOfBST(root));

	printf("Nodes 개수 : %d\n ", cntBSTNodes(root));

	printf("Terminal Nodes 개수 : %d\n ", cntTerminalNodes(root));
	

}





#if 0
struct node {
	int data;
	struct node* right;
	struct node* left;
};
struct node* root = 0;

void addToData(int n) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	struct node* temp = root;
	newnode->left = newnode->right = 0;
	newnode->data = n;
	if (root == 0) {
		root = newnode;
		return;
	}
	while (1) {
		if (temp->data > n) {
			if (temp->left == 0) {
				temp->left = newnode;
				return;
			}
			temp = temp->left;
		}
		else if (temp->data < n) {
			if (temp->right == 0) {
				temp->right = newnode;
				return;
			}
			temp = temp->right;
		}
	}
	return;
}

void delFromBST(int _data, struct node* _r) {
	struct node* t = _r;
	struct node* t_p = 0;
	
	while (1) {
		if (t == 0) {
			return;
		}
		else if (t->data == _data) {
			if (t->left == 0 && t->right == 0) {//무자식일 경우
				if (t == root) {
					root = 0;
					free(t);
					return;
				}

				if (t_p->left == t) {
					t_p->left = 0;
				}
				else {
					t_p->right = 0;
				}
				free(t);
				return;
			}
			else if (t->left != 0 && t->right == 0) {//왼자식일때
				if (t == root) {
					root = t->left;
					free(t);
					return;
				}
				if (t_p->left == t) {
					t_p->left = t->left;
					free(t);
					return;
				}
				else if (t_p->right == t) {
					t_p->right = t->left;
					free(t);
					return;
				}
			}
			else if (t->left == 0 && t->right != 0) {
				if (t == root) {
					root = t->right;
					free(t);
					return;
				}
				if (t_p->left == t) {
					t_p->left = t->right;
					free(t);
					return;
				}
				else {
					t_p->right = t->right;
					free(t);
					return;
				}
			}
			else {//쌍자식인 경우 
				/*struct node* r = t->right; //오른쪽 끼어넣는 경우
				struct node* r_p = t;
				while (r->left != 0) {
					r_p = r;
					r = r->left;
				}
				t->data = r->data;

				if (r_p->left == r) {
					r_p->left = r->right;
				}
				else {
					r_p->right = r->right;
				}
				free(r);
				return;
			}
			*/
				struct node* r = t->left;
				struct node* r_p = t;
				while (r->right != 0) {
					r_p = r;
					r = r->right;
				}
				t->data = r->data;

				if (r_p->right == r) {
					r_p->right = r->left;
				}
				else {
					r_p->left = r->left;
				}
				free(r);
				return;

			}
		}
		else {
			t_p = t;
			if (t->data > _data) {
				t = t->left;
			}
			else {
				t = t->right;
			}
		}
	}
}

void inorder(struct node* _r) {
	if (_r == 0) {
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