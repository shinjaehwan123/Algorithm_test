#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N,M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

int executeLCA(int a, int b);

void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    tree.resize(N+1); //초기화값 0이 나옴.
    depth.resize(N+1);

    // for(int i=0; i<=N; i++){
    //     cout << depth[i] << " ";
    // }
    parent.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<N-1 ; i++){
        int s,e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1); //BFS를 이용해서 깊이를 구한다.
    cin >> M;

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >>b;
        int LCA = executeLCA(a,b);
        cout << LCA << endl;
    }
}

//조상 부모를 구하는 LCA알고리즘을 구현한다.
int executeLCA(int a, int b){
    //a가 depth가 더 깊은 것
    if(depth[a] < depth[b]){
        int temp =a;
        a = b;
        b = temp;
    }

    //a에 b의 parent를 할당해 깊이를 줄인다. 
    while(depth[a]!= depth[b]){
        a = parent[a];
    }

    while(a!=b){ //만약 같은 위치에 올라왔는데 다르다면 같을때까지 해준다.
        a = parent[a];
        b = parent[b];
    }

    return a;
}


//이제 각노드의 깊이를 구하는 알고리즘을 구현한다.
void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    depth[1] = 0;

    int level =1;
    int now_size = 1;
    int count =0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(int next : tree[now_node]){
            if(!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                parent[next] = now_node;
                depth[next] = level;
            }
        }

        //깊이와 parent를 구햇음
        count++;
        if(count == now_size){
            count =0;
            now_size = myqueue.size();
            level++;
        }
    }
}