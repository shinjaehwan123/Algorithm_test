#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N,M;
vector<bool> visited;
vector<vector<int>> graph;
vector<int> mdistance;
int Min_distance = INT_MAX;
int BFS(int i);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(N+1);
    visited.resize(N+1,false);
    mdistance.resize(N+1,0);

    for(int i=0; i<M; i++){
        int start,end;

        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int index = 1;
    
    //모든 관계를 고려해야줘야함 그 중 최소값을 반환해야함. index를 반환해야
    for(int i=1; i<=N; i++){
        int min_distance = BFS(i);
        
        if(Min_distance > min_distance){
            Min_distance = min_distance;
            index = i;
        }
         else if (Min_distance == min_distance) {
            index = min(index, i);
        }

        fill(visited.begin(), visited.end(), false);
        fill(mdistance.begin(), mdistance.end(), 0);
    }


    cout << index << <<endl;
    
}

int BFS(int i){
    queue<int> myqueue;
    //우선 자기 자신을 push해준다.
    myqueue.push(i);
    

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        visited[i] = true;
        myqueue.pop();

        for(int node : graph[now_node]){
            if(!visited[node]){
                visited[node]= true;
                mdistance[node] = mdistance[now_node] + 1;
                myqueue.push(node);
            }
        }
    }

    int total =0;

    for(int i=1; i<=N; i++){
        total += mdistance[i];
    }

    return total;
    
}



#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

//한번 BFS로 구현을 해보자
//관계 중 가장 작은 숫자를 구하여라

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
vector<int> mdistance;

int MIN;
int cnt=0;
int BFS(int i);
int V,E;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    MIN = INT_MAX;

    cin >> V >> E;

    visited.resize(V+1,false);
    graph.resize(V+1);
    mdistance.resize(V+1,0);

    for(int i=0; i<E; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int index =1;
    for(int i=1; i<=V; i++){
        int k = BFS(i);
        if(MIN >= k){
            //만약 MIN이랑 같으면 숫자가 index가 작은 사람을 출력한다.
            if(MIN == k){
                if(index> i){
                    index = i;
                }
            }
            else{
                MIN = k;
                index = i;
            }
             
        }
        //visited을 초기화한다.
        fill(visited.begin(),visited.end(),false);
        fill(mdistance.begin(), mdistance.end(),0);
    }

    cout << index << endl;

    return 0;
}


//BFS를 수행한다.
int BFS(int i){
    queue<int> myqueue;
    myqueue.push(i);

    while(!myqueue.empty()){
        int start = myqueue.front();
        //처음 pop()을 해준다.
        myqueue.pop();
        visited[start] = true;

        //연결되어 있는 모든 속성을 나열한다.
        for(int node : graph[start]){
            if(visited[node] == false){
                myqueue.push(node);
                visited[node] = true;
                mdistance[node] = mdistance[start] + 1;   
            }
        }
    }

    int total =0;

    for(int i=1; i<=V; i++){
        total +=mdistance[i];
    }

    //cout << total<<endl;

    return total;

}
#endif








#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int>> graph;
int BFS(int startNode, int V);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    graph.resize(V + 1);

    for(int i = 0; i < E; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int minKevinBacon = INT_MAX;
    int person = -1;

    for(int i = 1; i <= V; i++){
        int kevinBaconNumber = BFS(i, V);
        if(kevinBaconNumber < minKevinBacon){
            minKevinBacon = kevinBaconNumber;
            person = i;
        }
    }

    cout << person << endl;

    return 0;
}

// BFS를 수행하여 startNode에서 모든 다른 노드까지의 최단 거리를 합산한다.
int BFS(int startNode, int V){
    vector<int> distance(V + 1, -1);
    queue<int> myqueue;
    myqueue.push(startNode);
    distance[startNode] = 0;

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();

        for(int neighbor : graph[current]){
            if(distance[neighbor] == -1){
                distance[neighbor] = distance[current] + 1;
                myqueue.push(neighbor);
            }
        }
    }

    int kevinBaconSum = 0;
    for(int i = 1; i <= V; i++){
        kevinBaconSum += distance[i];
    }

    return kevinBaconSum;
}
#endif