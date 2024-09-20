//여행계획세우기 내 코드

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> graph;
//처음 parnet를 설정해줌.
vector<int> parent;
vector<int> route;
int map[201][201];

int find(int node); //연결된 최상단 노드를 찾음
void union_function(int a, int b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    parent.resize(N+1);
    graph.resize(N+1);
    route.resize(M+1);

    for(int i=1; i<=N;i++){
        parent[i] = i;
    }

    //union 수행
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];

            //1이면 연결되었음.
            if(map[i][j] == 1){
                union_function(i,j);
            }
        }
    }

    //이제 여행할 도시 개수를 구한다. 즉 M을 구한다.
    bool flag = false;

    cin >> route[1];
    int index =find(route[1]);
    for(int i=2; i<=M; i++){
        cin >> route[i];

        //모든 루트를 비교해준다.
        if( ( find(route[i]) != find(route[i-1]) ) ){
              //cout << find(route[i])<<" "<<find(route[i-1]) << endl;
              cout << "NO" << endl;
              flag = true;
              break;
        }     
    }

    if(!flag){
        cout << "YES" << endl;
    }
  

   return 0; 
}

void union_function(int a, int b){
    int root_a = find(a);
    int root_b = find(b);

    if(root_a != root_b){
        parent[root_b] =root_a;//연결시킨다.
    }
}

int find(int node){
    if(parent[node] == node){
        return node;
    }

    else{
        return parent[node] = find(parent[node]);
    }
}





























#if 0
#include <iostream>
#include <vector>
using namespace std;

vector<int>parent;
void unionfunc(int a, int b);
int find(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    int graph[201][201];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N;j++){
            cin >> graph[i][j];
        }
    }

    int route[M+1];

    for(int i=1; i<=M; i++){
        cin >> route[i];
    }

    parent.resize(N+1);

    for(int i=1; i<=N; i++){ //부모 노드를 자기로 초기화 해준다.
        parent[i] = i;
    }

    //인접 행렬 탐색에서 도시가 연결되어 있으면 대표노드로 유니온 함.
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(graph[i][j]==1){
                unionfunc(i,j);
            }
        }
    }


    //여행 계획 도시가 하나의 대표 도시로 연결되는지 확인
    int index = find(route[1]);
    bool connect = true;

    for(int i=2; i<=M; i++){
        if(index != find(route[i])){ //연결되어 있지 않으면
            cout << "NO" << endl;
            connect = false;
            break;
        }
    }

    if(connect){
        cout << "YES" << endl;
    }


    return 0;
}

void unionfunc(int a, int b){
    //대표 노드 추출
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b] = a;
    }

}

int find(int a){
    //부모 노드를 넣어줌
    if(a==parent[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}
#endif