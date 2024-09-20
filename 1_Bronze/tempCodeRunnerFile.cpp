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

    for(int i=0; i< N; i++){
        int parent_node;

        cin >> parent_node;

        if(parent_node == -1){
            continue;
        }

        graph[i].push_back(parent_node);
        graph[parent_node].push_back(i);
    }

    cin >> deleteNode;

    if(deleteNode == 0){
        cout << "0" << endl;
        return 0;
    }

    //이제 DFS를 수행한다.
    DFS(0);

    cout << result << endl;

    return 0;
}

void DFS(int node){
    visited[node] = true;
    int cnt =0;
    for(int childNode : graph[node]){
        if(!visited[childNode]){
            if(childNode != deleteNode){
                cnt++;
                DFS(childNode);
            }
        }
    }
    if(cnt ==0){
        result++;
    }
}