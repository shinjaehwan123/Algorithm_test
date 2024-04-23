#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>

//우선순위 queue로 구현해야할듯
using namespace std;

int n,m;
int max_ans=0;
int graph[21][21];
pair<int,int> student[2];
bool visited[21][21]={false,};
int cnt=0;

//위, 오른쪽, 아래, 왼쪽
int dx[4]={-1,0,1,0};
int dy[4] = {0,1,0,-1};



int main(void){
    
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }
    int start, end;
    for(int i=0; i<m; i++){
        cin >> start >> end;
        student[i].first = start;
        student[i].second = end;
    }

    BFS(student[0].first, student[0].second);

    cout << endl;

    return 0;
}




//우선 순위 queue를 가지고 구현함. 함께하는 효도
#if 0
#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>

//우선순위 queue로 구현해야할듯
using namespace std;


int n,m;
int max_ans=0;
int graph[21][21];
pair<int,int> student[2];
bool visited[21][21]={false,};
int cnt=0;

//위, 오른쪽, 아래, 왼쪽
int dx[4]={-1,0,1,0};
int dy[4] = {0,1,0,-1};


struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(graph[a.first][a.second] < graph[b.first][b.second]){
            return true;
        }
        else{
            return false;
        }
    }
};

void BFS(int i, int j){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> myqueue;
    myqueue.push(make_pair(i,j));
    visited[i][j]=true;

    int ans=graph[i][j];
    graph[i][j]=0;

    //greedy로 가면 안될것같음.
    while(!myqueue.empty()){
      
        int x = myqueue.top().first;
        int y = myqueue.top().second;
        myqueue.pop();

        cout << graph[x][y] << endl;

        for(int i=0; i <4; i++){
            int now[2];
            now[0] = x + dx[i];
            now[1] = y + dy[i];


            //방문하지 않았고, 수확량이 0이 아니라면 
            if(!visited[now[0]][now[1]] && !graph[now[0]][now[1]]){
                //벽에 걸리지 않으면
                if(now[0] >=1 && now[0]<=n && now[1]>=1 && now[1]<=m){
                    //점수를 더하고
                    ans +=graph[now[0]][now[1]];
                    //방문했따고 표시
                    visited[now[0]][now[1]]=true;
                    //열매를 수확했으니까 0으로 초기화
                    //graph[now[0]][now[1]]=0;
                    //push 해줌
                    myqueue.push(make_pair(now[0], now[1]));
                }
            }  
           
            
        }
        
    }

    
}

int main(void){
    
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }
    int start, end;
    for(int i=0; i<m; i++){
        cin >> start >> end;
        student[i].first = start;
        student[i].second = end;
    }

    BFS(student[0].first, student[0].second);

    cout << endl;

    return 0;
}
#endif


#if 0
//난로의 반지름의 길이가 반지름으 길이의 배수인 집에서만 연탄 사용가능
//최대 공배수를 만드는 문제이다.


int radius[101];
int do_it(int a, int b);

int main(void){
    
    int n;
    cin >> n;
    int Max = 0;

    for(int i=1; i<=n;i++){
        cin >> radius[i]; 
    }
    int ans = 0;

    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    if(n == 2){
        if(do_it(radius[1],radius[2])!=1){
            cout << 2 << '\n';
            return 0;
        }
        else{
            cout << 1 << '\n';
            return 0;
        }
    }
    //3개 이상인 경우

    int cnt=n;
    int tmp = do_it(radius[1],radius[2]);


    if(tmp == 1){
        tmp = radius[1];
        cnt--;
    }
    for(int i=3; i <= n; i++){
        int tmp2 = do_it(tmp, radius[i]);

        if(tmp2 == 1){
            tmp2 = tmp;
            cnt--; 
        }
        tmp = tmp2;
    }
    cout << cnt <<'\n';
    return 0;
}

//최대 공배수 구하는 code
int do_it(int a, int b){
    if(b==0){
        return a;
    }

    return do_it(b,a%b);
}
#endif