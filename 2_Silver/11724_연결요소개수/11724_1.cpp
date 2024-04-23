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


