//문제
//루트 없는 트리가 주어진다. 이때 트리의 루트를 1이라고 정했을때,
//각 노드의 부모를 구하는 프로그램을 작성하시오
//입력
//첫째 줄에 노드의 개수 N(2<<=N<=100,000)이 주어 진다. 둘째 줄부터 N-1개의 줄
//에 트리 상에서 연결된 두 정점이 주어진다.
//출력
//첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

//핵심!! 1번이 부모 노드이다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
void DFS(int node);
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    graph.resize(N+1);
    visited.resize(N+1,false);
    parent.resize(N+1, 0);

    for(int i=0; i<N-1; i++){
        int start, end;

        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    //이제 노드를 다 넣어주었으니 1부터 다시 출력을 한다.
    DFS(1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << endl;
    }

    return 0;
}

void DFS(int node){
    visited[node] = true;

    //1먼 노드는 출력안해도된다.
    for(int i : graph[node]){
        if(!visited[i]){
            parent[i]=  node;
            visited[i] = true;
            DFS(i);
        }
    }
}