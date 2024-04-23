#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>>graph;
vector<bool>visited;
static vector <int> Ndistance;
void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    graph.resize(N+1);

    for(int i=0; i< N; i++){
        int start;
        cin >> start;
        while(1){
            int end, weight;
            cin >> end;
            if(end == -1){
                break;
            }
            cin >> weight;
            graph[start].push_back(make_pair(end, weight));
        }
    }

    Ndistance.resize(N+1,0); //각 노드의 distance를 저장할 컨테이너, 초기값 0
    visited = vector<bool>(N+1, false);
    BFS(1); //1번 node부터 출발할 것임
    int max_distance = 1; //가장 큰 지름을 저장할 변수

    for(int i=2; i<=N;i++){ //위에서 BFS(1)을 했기 때문에 2부터시작
        if(distance[max_distance] < distance[i]){
            max_distance = i;
        }
    }

    fill(distance.begin(), distance.end(),0); //각 노드별 distnace을 초기화 시킴
    fill(visited.begin(), visited.end(),0); //방문 기록을 초기화 시킴
    BFS(max_distance); //가장 지름이 큰 출발 노드로 부터 지름을 구함
    sort(distance.begin(), distance.end());
    cout << distance[N]<< endl;
}

void BFS(int index){ //BFS구현
    queue<int> Myqueue;
    Myqueue.push(index);
    visited[index] = 1;

    while(!Myqueue.empty()){
        int current = Myqueue.front();
        Myqueue.pop();
        for(auto i : graph[current]){
            if(!visited[i.first]){
                visited[i.first] = true;
                Myqueue.push(i.first);
                //거리 배열 update
                distance[i.first] = distance[current] + i.second;
            }
        }
    }

}