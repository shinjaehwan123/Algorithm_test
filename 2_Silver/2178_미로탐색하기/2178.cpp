#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int graph[100][100];
bool visited[100][100] = {0,};
int N, M;
void BFS(int i, int j);


int main(void){

    cin >> N >> M;
    for(int i=0; i< N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            graph[i][j] = s[j] - '0';
        }
    }

    //(0,0)에서 시작함.
    BFS(0,0); 
    
   
    cout << graph[N-1][M-1] << endl;

    
}

//queue 구현, BFS 탐색
void BFS(int i, int j){
     queue<pair<int,int>>Myqueue;
     Myqueue.push(make_pair(i,j));

     while(Myqueue.empty()!=0){
        int current[2];
        current[0] = Myqueue.front().first;
        current[1] = Myqueue.front().second;
        visited[current[0]][current[1]]=1;
        
        Myqueue.pop();

        int x,y;
        //상,하,좌,우 탐색
        for(int i=0; i<4; i++){
            x = current[0] + dx[i];
            y = current[1] + dy[i];

            if(x>=0 && y>=0 && x < N && y < M){ //칸을 초과하는지 검사
                if(graph[x][y]!=0 && visited[x][y]==0){ // 1만 이동할 수 있기 때문에
                    Myqueue.push(make_pair(x,y));
                    graph[x][y] = graph[current[0]][current[1]] + 1;
                    visited[x][y] = 1;
                }
            }
        }
     }
}


#if 0
void BFS(int n){
    queue<int>A;
    A.push_back(n);

    

    visited[now] =1;
    
    while(A.empty() !=0){
        int now = A.front();
        A.pop();
        for(int i : A[now]){
            if(visited[i]!=0){
                A.push_back(i);
                visited[i]=1;
            }
            
        }
    }    
}
#endif