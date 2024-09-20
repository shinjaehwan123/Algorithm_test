//내 코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,deleteNode;
void DFS(int node);
vector<int> parent;
vector<vector<int>> graph;
vector<bool> visited;
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N,false);
    parent.resize(N);
    graph.resize(N);
    int root;

    for(int i=0; i< N; i++){
        int parent_node;

        cin >> parent_node;

        if(parent_node == -1){
            root = i;
            continue;
        }

        graph[i].push_back(parent_node);
        graph[parent_node].push_back(i);
    }

    cin >> deleteNode;

    if(deleteNode == root){
        cout << 0 << endl;
    }
    else{
        //이제 DFS를 수행한다.
        DFS(root);
        cout << result << endl;
    }

   

    return 0;
}

void DFS(int node){
    visited[node] = true;
    int cnt =0;
    for(int childNode : graph[node]){
        if(!visited[childNode]){
            if(childNode != deleteNode){
                visited[childNode] = true;
                cnt++;
                DFS(childNode);
            }
        }
    }
    if(cnt ==0){
        result++;
    }
}



//강의 코드
#include <iostream>
#include <vector>
#inlcude <queue>

using namespace std;

static int N;
static vector<vector<int>> tree;
static int answer = 0;
static int deleteNode = 0;
static vector<bool> visited;
void DFS(int number);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N);
    tree.resize(N);
    int root=0;

    for(int i=0; i<N; i++){
        int parent;
        cin >> parent;

        if(parent != -1){
            tree[i].push_back(parent);
            tree[parent].push_back(i);
        }
        else{
            root = i;
        }
    }

    cin >> deleteNode;

    if(deleteNode == root){
        cout << 0 << endl;
    }
    else{
        DFS(root);
        cout << answer << endl;
    }

    return 0;
}

void DFS(int number){
    visited[number] = true;
    int cNode = 0;

    for(int i:tree[number]){
        if(visited[i] == false && i != deleteNode){
            cNode++;
            DFS(i);
        }
    }

    if(cNode==0){
        answer++;
    }
}

