//softeer 우물 안의 개구리
// https://softeer.ai/practice/6289
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//BFS 문제이다.
int N,M;

vector<int> parent;
vector<int> weight;
int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}

void union_function(int node1, int node2){
    int a = find(node1);
    int b = find(node2);
    
    if(a == b){
        return;
    }
    else{
        parent[b] = a;
    }
}

vector<vector<int>> graph;
int answer = 0;
void BFS(int i);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    parent.resize(N+1);
    graph.resize(N+1);
    
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    

    //이제 무게를 입력받는다.
    weight.resize(N+1);

    for(int i=1; i<=N; i++){
        int person_weight;
        cin >> person_weight;
        weight[i] = person_weight;
    }

    for(int i=0; i<M; i++){
        int start , end;
        cin >>start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
      
    }

    //이제 1부터 N까지 BFS를 실시해주다.
    for(int i=1; i<=N ;i++ ){
        BFS(i);
    }

    cout << answer << endl;

    return 0;
    
}

void BFS(int i){
    int flag = false;
    for(int node : graph[i]){
        if(weight[i] <= weight[node]){
            flag = true;
        }
    }

    if(flag == false){
        answer++;
    }
}
