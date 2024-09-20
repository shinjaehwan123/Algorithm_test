//BFS로 구현을 한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void BFS(int v);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    A.resize(N+1);
    visited.resize(N+1,false);


    for(int i=0; i<M; i++){
        int start ,end;
        cin >> start >> end;
        A[start].push_back(end);
        A[end].push_back(start);
    }

    int cnt =0;

    for(int i=1; i<=N; i++){
        if(visited[i] == false){
            cnt++;
            BFS(i);
        }
    }

    cout << cnt <<endl;
}

void BFS(int v){
    queue<int> myqueue;
    myqueue.push(v);

    while(!myqueue.empty()){
        int node = myqueue.front();
        visited[node] = true;

        myqueue.pop();

        for(int next : A[node]){
            if(!visited[next]){
                visited[next] = true;
                myqueue.push(next);
            }
        }
    }
}



//DFS로 구현
#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int v);
 int cnt=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >>M;
    A.resize(N+1);
    visited.resize(N+1,false);

    for(int i=0; i<M; i++){
        int s,e;
        cin >>s >>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

   

    for(int i=1; i<=N; i++){
        if(visited[i]==0){
            cnt++;
            DFS(i);
           
        }
    }

    cout << cnt << endl;
    
    return 0;
}

void DFS(int i){
    // if(visited[i]==1){
    //     return;
    // }
    visited[i]=true;

    for(int i : A[i]){
        if(visited[i]==0){
            DFS(i);
        }
    }
}
#endif


