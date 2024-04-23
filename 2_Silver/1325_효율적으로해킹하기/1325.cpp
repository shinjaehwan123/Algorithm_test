//silver 1 효율적으로 해킹하기
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>graph;
vector<bool>visited;
vector<int> answer;

void SEARCH_NODE(int start_vertex);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; //N은 노드, M은 관계

    cin >> N >>M;

    graph.resize(N+1);
    answer.resize(N+1);
    //visited.resize(N+1,0); //각 노드가 해킹할 수 있는 컴퓨터 수를 나타냄.
    visited.resize(N+1,false);

    

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end); //역으로 저장한다.
    }

    for(int i=0; i<=N; i++){
        fill(visited.begin(), visited.end(), false);
        SEARCH_NODE(i);
    }
    
    int maxVal =0;

    for(int i=1; i<=N; i++){
        maxVal = max(maxVal, answer[i]);
    }

    for(int i=1; i<=N; i++){
        //answer 배열에서 maxVal와 같은 값을 가진 index을 정답으로 출력
        if(answer[i] == maxVal){
            cout << i << " ";
        }
    }


}

void SEARCH_NODE(int start_vertex){
    queue<int> myqueue;

    //단방향이고 특정 current가 비어 있다면?
     //처음 부터 비어 있으면 1을 증가하면서 맞는 노드를 찾음
    //if(graph[start_vertex].empty()){
    //    start_vertex = start_vertex +1;
    //}

    visited[start_vertex]=true;

    myqueue.push(start_vertex);

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();
        for(int i : graph[current]){
            if(visited[i]==false){
                visited[i]= true; //증요!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                answer[i]++; //신큐노드 인덱스의 정답 배열값 증가시키기 
                myqueue.push(i);

            }

        }     
    }
}
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool>visited;
vector<int> answer;
vector<int>answer_2;

bool compare(int &a , int & b);

void BFS(int start_vertex);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N,M; //N은 Node개수 M은 연결관계
    cin >> N >> M;

    graph.resize(N+1);
    visited.resize(N+1, false);
    answer.resize(N+1,0);

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    for(int i=0; i<=N; i++){
        BFS(i);
        fill(visited.begin(), visited.end(),false);
    }

    int Max = -1;

    for(int i=1; i<=N; i++){
        if(Max <= answer[i]){
            Max = answer[i];
        }
    }

    for(int i=1; i<=N; i++){
        if(Max == answer[i]){
            answer_2.push_back(i);
        }
    }
    
    sort(answer_2.begin(), answer_2.end(),compare);
    
    for(int i : answer_2){
        cout << i << " ";
    }

}

bool compare(int &a, int &b){
    if(a < b){
        return true; //오름차순 ?
    }
    else{
        return false;
    }
}

void BFS(int start_vertex){
    queue<int> myqueue;
    visited[start_vertex]=true;
    myqueue.push(start_vertex);

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();
        visited[current] = true;

        for(int i : graph[current]){
            if(visited[i] == 0){
                visited[i] = true;
                answer[i] = answer[i] + 1;
                myqueue.push(i);
            }
        }
    }
}