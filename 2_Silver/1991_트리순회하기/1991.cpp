// 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다.
// 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
// 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 
// 자식 노드가 없는 경우에는 .으로 표현한다.

// 출력
// 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다.
// 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.


#include <iostream>
using namespace std;

static int n;
static int tree[26][2];
void preorder(int now);
void inorder(int now);
void postorder(int now);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i<n ; i++){
        char node_char, left, right;
        cin >> node_char >> left >> right;
        int node = node_char - 'A';

        if(left == '.'){
            tree[node][0] = -1;
        }
        else{
            tree[node][0] = left -'A';
        }

        if(right == '.'){
            tree[node][1] = -1;
        }
        else{
            tree[node][1] = right - 'A';
        }
    }
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;
}

void preorder(int now){
    if(now == -1){
        return;
    }
    cout << (char)(now + 'A');
    preorder(tree[now][0]);
    preorder(tree[now][1]);
}

void inorder(int now){
    if(now == -1){
        return;
    }
    inorder(tree[now][0]);
    cout << (char)(now + 'A');
    inorder(tree[now][1]);
}

void postorder(int now){
    if(now == -1){
        return;
    }
    postorder(tree[now][0]);
    postorder(tree[now][1]);
    cout<< (char)(now + 'A');
}