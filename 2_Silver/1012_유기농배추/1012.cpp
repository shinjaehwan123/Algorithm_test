#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51]={0,};
int visited[51][51]={0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void DFS(int i, int j);

int M,N,K;//M은 가로길이, N은 세로길이, K는 배추가 심어져있는 개수

//solution 1 내풀이

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T; //case경우가 주어짐
   
    cin >> T; //case 입력

    for(int i=1; i<=T; i++){
        cin >> M >> N;

        cin >>K;

        //배추가 심어져 있는 case를 입력함
        for(int i=0; i<K; i++){
            int w,h; //가로 세로입력
            cin >>w>>h;
            arr[h][w]=1;
        }

        int cnt=0;

        for(int i=0; i<N;i++){
            for(int j=0; j< M; j++){
                if(arr[i][j]==1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;

        for(int i=0; i<N;i++){
            fill(arr[i], arr[i]+M, 0);
            fill(visited[i], visited[i]+M,false);
        }
    }
    return 0;
}

void DFS(int i, int j){
    if(visited[i][j]==1){
        return;
    }

    visited[i][j] = true;
    arr[i][j] = 0;

    for(int r=0; r<4;r++){
        int width = j + dx[r];
        int height = i + dy[r];

         if(width >=0 && height >=0 && width < M && height <N){
            if((visited[height][width]==0) && arr[height][width]==1){
                DFS(height, width);
            }
         }
    }

}




























//-------------------------------------------------------------------------------------------------------------------------
//solution 2
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool visited[51][51]= {false,};

int arr[51][51]={0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int cnt=0;
int result=0;
int m, n, k; //m은 가로길이, n은 세로길이

void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T){
        cin >> m >> n; //배추를 심은 땅의 면적을 나타냄.
        cin >> k;
        
        for(int i=0; i<k; i++){ //배추의 위치를 말함.
            int w,h;
            cin >>w>>h;
            arr[h][w] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j <m; j++){
                if(arr[i][j]==1){
                    BFS(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt<<endl;

        for(int i=0; i<n; i++){
            fill(arr[i], arr[i]+m,0);
            fill(visited[i], visited[i]+m,false);
        }
        --T;
    }
}

void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int now[2];
        now[0] = myqueue.front().first;
        now[1]=  myqueue.front().second;
        myqueue.pop();
        visited[now[0]][now[1]] = true;

        for(int i=0; i<4; i++){
            int x = now[0] + dx[i];
            int y = now[1] + dy[i];

            if(x>=0 && y>=0 && x<n&& y < m){
                if(arr[x][y] !=0 && !visited[x][y]){
                    visited[x][y]= true;
                    
                    arr[x][y] = 0;
                    myqueue.push(make_pair(x,y));
                }
            }
        }
    }
}





#endif



//-------------------------------------------------------------------------------------------------------------------------
//Solutione3
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool visited[51][51]= {false,};
int height[2501]={0,};
int width[2501]={0,};
int arr[51][51]={0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int cnt=0;
int result=0;
int m, n, k; //m은 가로길이, n은 세로길이

void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T){
        cin >> m >> n; //배추를 심은 땅의 면적을 나타냄.
        cin >> k;
        
        for(int i=0; i<k; i++){ //배추의 위치를 말함.
            int w,h;
            cin >>w>>h;
            width[i] = w;
            height[i] = h;
            arr[h][w] = 1;
        }

        for(int i=0; i<k; i++){
            if(arr[height[i]][width[i]]==1){
                BFS(height[i],width[i]);
                cnt++;
            }
        }

        cout << cnt<<endl;

        for(int i=0; i<n; i++){
            fill(arr[i], arr[i]+m,0);
            fill(visited[i], visited[i]+m,false);
        }

        
        --T;
    }
}

void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int now[2];
        now[0] = myqueue.front().first;
        now[1]=  myqueue.front().second;
        myqueue.pop();
        visited[now[0]][now[1]] = true;

        for(int i=0; i<4; i++){
            int x = now[0] + dx[i];
            int y = now[1] + dy[i];

            if(x>=0 && y>=0 && x<n&& y < m){
                if(arr[x][y] !=0 && !visited[x][y]){
                    visited[x][y]= true;
                    
                    arr[x][y] = 0;
                    myqueue.push(make_pair(x,y));
                }
            }
        }
    }
}
#endif