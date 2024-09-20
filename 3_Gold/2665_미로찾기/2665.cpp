//내 코드 다른 풀이 2
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
int MAP[51][51] = {0,};
int visited[51][51]={0,};
int mdistance[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int,pair<int,int>> &b){
        //오름 차순으로 정렬을 해준다.
        if(a.first > b.first){
            return true;
        }
        else{
            return false;
        }
    }
};

priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pd;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j=1; j<=s.size(); j++){
            MAP[i][j] = s[j-1]-'0';

            if(MAP[i][j] == 1){
                MAP[i][j] = 0;
            }
            else{
                MAP[i][j] =1;
            }
        }
    }

    for(int i=1; i<=N; i++){
        fill(mdistance[i], mdistance[i]+N+1, INT_MAX);
    }

    mdistance[1][1] =0;

    pd.push(make_pair(0,make_pair(1,1)));

    while(!pd.empty()){
        pair<int,pair<int,int>> now_node = pd.top();
        int distance_node = now_node.first;
        int now_x = now_node.second.first;
        int now_y = now_node.second.second;
        pd.pop();

        //다익스트라는 최소 거리 노드만 체크해주므로 for 문안에서 visited을 true로 만들지 않음
        if(visited[now_x][now_y] == true){
            continue;
        }

        visited[now_x][now_y] = true;

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            

            //범위를 넘어서면
            if(next_x <=0 ||  next_x > N || next_y <=0 ||  next_y > N){
                continue;
            }

            
            if(mdistance[next_x][next_y] > mdistance[now_x][now_y] + MAP[next_x][next_y]){
                mdistance[next_x][next_y] = mdistance[now_x][now_y] + MAP[next_x][next_y];
                pd.push(make_pair(mdistance[next_x][next_y], make_pair(next_x, next_y)));
            }
        }
    }

    cout << mdistance[N][N] <<endl;
  
}






//내 코드 최종

#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
int MAP[51][51]={0,};
int visited[51][51]= {false,};
int dist[51][51];

int dx[]={0,-1,0,1};
int dy[] = {-1,0,1,0};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int,pair<int,int>> &b){
        //오름 차순을 우선순위로 놓아야 된느거 아닌가?
        return a.first > b.first; //오름차순 정렬임.
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //미로사이즈를 입력한다.
    string a;

    //0은 검은방, 흰 방은 1로 나타낸다. 여기서 검은 방의 개수를 count할려면 
    //검은 방을 1로 바꿔야지 쉽다.
    for(int i=0; i<N; i++){
        cin >> a;

        for(int j=0; j<N; j++){
            MAP[i][j] = a[j] -'0';
            if(MAP[i][j]==1){
                MAP[i][j]=0;
            }
            else if(MAP[i][j]==0){
                MAP[i][j]=1;
            }
        }
    }

    //각 거리를 무한대로 초기화시킨다.
    for(int i=0; i<N; i++){
        fill(dist[i], dist[i]+N, INT_MAX);
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pd;
    
    //시작 가중치는 0이고 (0,0)에서 시작을 한다.
    pd.push(make_pair(0,make_pair(0,0)));

    dist[0][0] =0;

    while(!pd.empty()){
        pair<int,int> now = pd.top().second;
        int distance = pd.top().first;
        pd.pop();

        if(visited[now.first][now.second]==1){
            continue;
        }

        //방문한 좌표는 이제 True로 반환을 해준다.
        visited[now.first][now.second] == true;

        for(int i=0; i<4; i++){
            //이제 좌표를 나타낸다.
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            //범위를 넘어가면 continue를 해준다.
            if(nx <0 || nx >=N || ny <0 || ny >=N){
                continue;
            }

            //원래 보다 크면 넣어준다. 흰색이 0, 검은색이 1이다. 즉 최소값을 구하는 것
            if(dist[now.first][now.second] + MAP[nx][ny] < dist[nx][ny]){
                dist[nx][ny] = dist[now.first][now.second] + MAP[nx][ny];
                pd.push(make_pair(dist[nx][ny], make_pair(nx,ny)));
            }
        }
    }

    cout << dist[N-1][N-1] << endl;
    return 0;
    

}
#endif



//풀이 4 my code
#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct compare{
    bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> & b){
        return a.first > b.second; //오름차순정렬을 한다.
    }
};

int cnt =0;

int map[51][51];
int visited[51][51];
int mdistance[51][51];
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> myqueue;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        string str;
        cin >> str;

        for(int j=1; j<=N; j++){
            map[i][j] = str[j]='0';
        }
    }

    myqueue.push(make_pair(map[1][1], make_pair(1,1)));

    //myqueue.top().first가 1이라면 cnt 감소하지 않고
    

}
#endif

//풀이 3 //내코드
#if 0
#include <iostream>
#include <queue>



//미로찾기, 다익스트라를 이용한다. //내 코드
#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
int MAP[51][51]={0,};
int visited[51][51]={false,};
int dist[51][51];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int, pair<int,int>>& b){
        return a.first > b.first; //오름차순이다. priority queue에서는
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //미로 사이즈를 입력한다.
    string a;
    for(int i=0; i<N; i++){
        cin >>a;

        for(int j=0;j<N;j++){
            MAP[i][j] = a[j] - '0';
            MAP[i][j] ^=1;
        }
    }

    for(int i=0; i<N; i++){
        fill(dist[i], dist[i]+N,INT_MAX );
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,compare> pd;

    pd.push({0,make_pair(0,0)}); //처음 0은 cost를 뜻한다. -를 취해서 cost가 작은거를 구한다.

    dist[0][0] = 0; //벽의 개수
    
    while(!pd.empty()){
        int cost = pd.top().first;
        pair<int,int> cur = pd.top().second;
        pd.pop();

        if(visited[cur.first][cur.second] == true){
            continue;
        }

        visited[cur.first][cur.second] == true;

        for(int i=0; i<4; i++){
            //좌표를 나타낸다.
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //범위를 넘어가면 continue
            if(nx < 0 || nx >=N || ny <0 || ny >=N){
                continue;
            }

            //원래 보다 크면 넣어준다.
            if(dist[cur.first][cur.second] + MAP[nx][ny] < dist[nx][ny]){
                dist[nx][ny] = dist[cur.first][cur.second] + MAP[nx][ny];
                pd.push( {dist[nx][ny], make_pair(nx,ny)} );
            }

        }
    }

    cout << dist[N-1][N-1]<<endl;
    return 0;
}
#end if

//방법 2
//미로찾기, 다익스트라를 이용한다. //내 코
#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
int MAP[51][51]={0,};
int visited[51][51]={false,};
int dist[51][51];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int, pair<int,int>>& b){
        return a.first < b.first; //오차순이다. priority queue에서는
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //미로 사이즈를 입력한다.
    string a;
    for(int i=0; i<N; i++){
        cin >>a;

        for(int j=0;j<N;j++){
            MAP[i][j] = a[j] - '0';
            MAP[i][j] ^=1;
        }
    }

    for(int i=0; i<N; i++){
        fill(dist[i], dist[i]+N,INT_MAX );
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,compare> pd;

    pd.push({0,make_pair(0,0)}); //처음 0은 cost를 뜻한다. -를 취해서 cost가 작은거를 구한다.

    dist[0][0] = 0; //벽의 개수
    
    while(!pd.empty()){
        int cost = pd.top().first;
        pair<int,int> cur = pd.top().second;
        pd.pop();

        if(visited[cur.first][cur.second] == true){
            continue;
        }

        visited[cur.first][cur.second] == true;

        for(int i=0; i<4; i++){
            //좌표를 나타낸다.
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //범위를 넘어가면 continue
            if(nx < 0 || nx >=N || ny <0 || ny >=N){
                continue;
            }

            //원래 보다 크면 넣어준다.
            if(dist[cur.first][cur.second] + MAP[nx][ny] < dist[nx][ny]){
                dist[nx][ny] = dist[cur.first][cur.second] + MAP[nx][ny];
                pd.push( {dist[nx][ny], make_pair(nx,ny)} );
            }

        }
    }

    cout << dist[N-1][N-1]<<endl;
    return 0;
}
#end if

