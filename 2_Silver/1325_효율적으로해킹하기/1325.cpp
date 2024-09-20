//내코드 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//A가 B를 신뢰한다. B를 해킹하면 A도 해킹할 수 있음.
vector<vector<int>> graph;
vector<bool> visited;
int N, M;
void DFS(int node);
vector<int> answer;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    //1번부터 N번까지 번호가 부여됨.
    graph.resize(N+1);
    visited.resize(N+1,false);
    answer.resize(N+1,0);

    //이제 신뢰관계를 넣어준다.
    for(int i=0; i<M; i++){
        int start, end;

        cin >> start >> end;
        //start가 end를 신뢰한다.
        graph[start].push_back(end);
    }

    //이제 하나씩 해킹하면서 찾아본다.

    for(int i=1; i<=N; i++){
        DFS(i);
        fill(visited.begin(), visited.end(), false);
    }

    int min =0;

    // for(int i=1; i< answer.size(); i++){
    //     cout << answer[i] << " ";

    // }
    // cout << endl;

    for(int i=1; i<=N; i++){
        if(answer[i] > min){
            min = answer[i];
        }
    }
    // cout << min << endl;
    
    vector<int> compare;

    for(int i=1; i<=N; i++){
        if(answer[i] == min){
            compare.push_back(i);
        }
    }

    sort(compare.begin(), compare.end());

    //이제 compare 값을 출력한다.
    for(int i=0; i < compare.size(); i++){
        cout << compare[i] << " ";
    }

    return 0;
    
}

void DFS(int node){
    visited[node] = true;

    for(int collection : graph[node]){
        if(!visited[collection]){
            //이건 선택이다.
            visited[collection] = true;
            //visited 여기서 해도 되고 안해도 되고
            answer[collection]++;
            DFS(collection);
        }
    }

}


//==============================================================================================


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