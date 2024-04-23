//특정거리 도시 찾기
//내 코드 왜 틀렸는지 모르겠음. long을 안써서 틀린건가 ?
#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

long N,M,K,X;
vector<vector<long>>graph;
vector<bool> visited; //cycle이 허용되서 visited 필요없을 수도....
//but 최단 거리니까 필요함
vector<long> order;
bool flag = false;


void BFS(long start_vertex, long purpose);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>N>>M>>K>>X;

    graph.resize(N+1);
    visited.resize(N+1,0);

    for(long i=0; i<M; i++){
        long start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    BFS(X,0);

    if(order.empty()){
        cout << -1 << "\n";
    }
    else{
        sort(order.begin(), order.end());
        for(long i : order){
            cout << i << "\n";
        }
    }
}

void BFS(long start_vertex, long purpose){
    queue<long> myqueue;
    myqueue.push(start_vertex);
    visited[start_vertex]=1;

    while(!myqueue.empty()){
        flag =0;
        long current = myqueue.front();
        myqueue.pop();

        for(long i : graph[current]){
            if(!visited[i]){
    
                if(purpose+1 == K){
                    order.push_back(i);
                }

                visited[i] = 1;
                flag =1;
                myqueue.push(i);
            } 
        }
        if(flag){
            purpose +=1;
        }
    }
}
#endif



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int node);
vector<vector<int>> A;
vector<int> answer;
vector<int> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N,M,K,X;
    cin >> N>>M>>K>>X;
    A.resize(N+1);

    for(int i=0; i<M;i++){
        int S,E;
        cin >> S >> E;
        A[S].push_back(E);
    }
    visited.resize(N+1);

    for(int i=0; i<=N; i++){
        visited[i]= -1;
    }

    BFS(X);

    for(int i=0; i<=N;i++){
        if(visited[i] == K){
            answer.push_back(i);
        }
    }
    if(answer.empty()){
        cout << -1 << endl;
    }
    else{
        sort(answer.begin(), answer.end());
            for(int temp:answer){
                cout << temp<< endl;
            }
        }
    }


void BFS(int node){
    queue<int> queue;
    queue.push(node);
    visited[node]++;

    while(!queue.empty()){
        int now_node = queue.front();
        queue.pop();
        for(int i: A[now_node]){
            if(visited[i]== -1){
                visited[i] = visited[now_node]+1;
                queue.push(i);
            }
        }
    }
}

