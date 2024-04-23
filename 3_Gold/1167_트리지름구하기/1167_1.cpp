#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> node_distance;
void BFS(int start_vertex);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin>>v;

    graph.resize(v+1);
    visited.resize(v+1, false);

    for(int i=0; i < v; i++){
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

    node_distance.resize(v+1, 0);
    //시작을 1번 node에서 한다고 가정
    BFS(1);
    
    int Max =1;

    for(int i =2; i<= v; i++){
        if(node_distance[Max] < node_distance[i]){
            Max = i;
        }
    }

    fill(node_distance.begin(), node_distance.end(), 0);
    fill(visited.begin(), visited.end(),0);
    BFS(Max);

    sort(node_distance.begin(), node_distance.end());


    cout << node_distance[0] << endl;
}

void BFS(int start_vertex){
    queue<int> myqueue;
    myqueue.push(start_vertex);
    visited[start_vertex] = 1;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();
        for(pair<int,int> i : graph[now_node]){
            if(!visited[i.first]){
                visited[i.first]=1;
                myqueue.push(i.first);
                node_distance[i.first] = node_distance[now_node] + i.second;
            }
        }
    }
}



// for(pair<int,int> i : graph[1]){
    //     cout << i.first;
    //     cout << i.second;
    //     cout << endl;
    // }

//--------------------------------------------------------------------------------------------------------------------------
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vecotr<vector<pair<int,int>>>A;
vector<bool> visited;
vector<int> m_distnace;

void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N+1);

    for(int i=0; i<N; i++){
        int S;
        cin >>S;
        while(true){
            int E,V;
            cin >> E;
            if(E==-1){
                break;
            }
            cin >>V;
            A[S].push_back(make_pair(E,V));
        }
    }

    m_distance = vector<int>(N+1,0);
    visited = vector<bool>(N+1, false);
    BFS(1);
    int Max = 1;

    for(int i=2; i<=N; i++){
        if(m_distance[Max] < m_distance[i]){
            Max = i;
        }
    }

    fill(m_distance.begin(), m_distance.end(),0); //Max값을 찾았으면 0으로 초기화 함.
    fill(visited.begin(), visited.end(), false); // 방문 배열을 초기화함
    BFS(Max);
    sort(m_distance.begin(), m_distance.end());
    cout << m_distance[N] << "\n";
}

void BFS(int index){
    queue<int> myqueue;
    myqueue.push(index);
    visited[index]= true;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();
        for(pair<int,int> i : A[now_node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                myqueue.push(i.first);
                //거리배열을 update한다.
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}

#endif


#if 0
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int A[101][101];
bool visited[101][101] = {false,};
int N, M;
void BFS(int i, int j);

int main(void){
    //list.resize(N,vector<int>(M,0));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N>>M;

    for(int)



    
}




#endif

