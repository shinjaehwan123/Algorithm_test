#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



template <typename T1, typename T2>
void BFS(T1 num1, T2 num2);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A(10,0);

    for(int i=0; i<10; i++){
        cout << A[i]<<" ";
    }
}
#endif

#if 0
struct cmp{
    bool operator()(int a, int b){
        return a>b; //오름차순
    }
};

int main(){
    priority_queue<int,vector<int>, less<int>> pd;

    pd.push(5);
    pd.push(3);
    pd.push(6);
    pd.push(7);

    while(!pd.empty()) {
        int temp = pd.top();
        cout << temp;
        pd.pop();
    }   
    
    return 0;
}
#endif

//-------------------------------------------------------------------
#if 0

#include<iostream>
#include <vector>


using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    vector<int> A(n,0);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int shortcut=  A[1] - A[0];

    for(int i=1; i<n-1;i++){
        if(shortcut > A[i+1] - A[i]){
            shortcut = A[i+1]- A[i];
        }
    }
    
    int cnt=0;
    
    for(int i=0; i<n-1;i++){
        if(shortcut == (A[i+1]- A[i])){
            cnt++;
        }
    }

    cout << cnt << endl;

   return 0;
}
#endif
//-------------------------------------------------------------------

#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >>N;

    vector<pair<int,int>>A;
    vector<pair<int,int>>B(1,{0,0});

    for(int i=0; i<N; i++){
        int s,e;
        cin >> s>>e;
        A.push(make_pair(s,e));
    }

    //오름차순 정렬이 됨. second에 대해 정렬하려면 새로운 함수 선언이 필요
    sort(A.begin(), A.end(), commpare);

    int count =0;
    int end =-1;

    for(int i=0; i<N; i++){
        if(A[i].first >= end){
            end = A[i].second; //중료시간이 짧은 것을 선택함
            count++;
        }
    }

    cout<< count << endl;
}

bool compare(const practice<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first; //오름차순으로 정렬함
    }
    return a.second < b.second; //오름차순으로 정렬함
}
#endif

//유기농 배치 연습

#if 0

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51]={0,};
int visited[51][51]={0,};
int dx = {0,-1,0,1};
int dy = {1,0,-1,0};

void DFS(int i, int j);

int M, N, K; //M은 가로길이, N은 세로길이, K는 배추가 심엊있는 개수

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; //case경우가 주어짐

    cin >> T; //case입력

    for(int i=1; i<=T;i++){

        for(int i=0; i<K; i++){
            int w,h;
            cin >>w>>h;
            arr[w][h] = 1;
        }

        int cnt=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M;j++){
                if(arr[i][j]==1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;

        for(int i=0; i<N; i++){
            fill(arr[i], arr[i]+M, 0);
            fill(visited[i], visited[i]+M, false);
        }
    }

    return 0;
    
}

void DFS(int i, int j){
    if(visited[i][j]==1){
        return;
    }

    visited[i][j] = true;
    arr[i][j]=0;

    for(int r=0; r<4;r++){
        int width = j + dx[r];
        int height = i + dy[r];

        if(width >=0 && height >=0 && width < M && height < N){
            if(visited[height][widht]==0 && arr[height][width]==1){
                DFS(height, width);
            }
        }
    }
}


#endif

//----------------------------------------------------------------

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <math>

using namespace std;

vector<bool> visited;
bool isPrime(int n);
void DFS(int number, int num_size);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N,false);
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);

    return 0;
}

void DFS(int number, int num_size){
    if(num_size > N){
        return;
    } 

    if(num_size == N){
        cout << number << endl;
    }

    //1. logic : 0 or 짝수는 고래해 줄 필요없음.
    //2. logic : 총 자리수 만큼 for문을 돌리면 됨.
    for(int i=1; i<=9 ; i++){
        if(i%2==0){
            continue;
        }
        else if(isPrime(numver *10 + i){
            DFS(number*10 + i, num_size + 1);
        }
    }
}

bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

#endif
//----------------------------------------------------------------

#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <math>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
}




#endif

//----------------------------------------------------------------
#if 0
#include <iostrema>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    int start =0;
    int end =0;

    for(int i=0; i< N; i++){
        cin >> A[i];
        if(start < A[i]){
            start = A[i];
        }

        end = end + A[i];
    }

    while(start <= end){
        int middle = (start + end)/2;
        int sum =0;
        int count =0;

        //middle값으로 모든 레슨을 저장할 수 있는지 확인
        for(int i=0; i< N; i++){
            if(sum+A[i]>middle){
                count++;
                sum =0;
            }
            sum = sum + A[i];
        }

        if(sum !=0){
            count++;
        }
        if(count > M){
            start = middle+1;
        }
        elseif(count < M){
            end = middle-1;
        }

        cout << start << endl;
    }


}


#endif



//----------------------------------------------------------------
#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<par<int,int>>> graph;
vector<bool> visited;
vector<int> node_distance;
void BFS(int start_vertex);

int main(void){
    int v;
    cin >> v;

    graph.resize(v+1);
    visited.resize(v+1,fasle);

    for(int i=0; i<v; i++){
        int start;
        cin >> start;

        while(1){
            int end, weigth;
            cin >> end;
            if(end == -1){
                break;
            }
            cin >> weight;
            graph[start].push_back(maek_pair(end, weight);
        }
    }

    node_distance.resize(v+1,0);

    //시작을 1번 node에서 한다고 가정
    BFS(1);

    int Max =1;

    for(int i=2; i<=v; i++){
        if(node_distance[Max] < node_distance[i]){
            Max = i;
        }
    }

    fill(node_distance.begin(), node_distance.end());
    fill(visted.begin(), visited.end(),0);
    BFS(Max);

    sort(node_distnace.begin(), node_distance.end());

    cout << node_distance[0]<< endl;
    
}


void BFS(int start_vertex){
    queue<int> myqueue;
    myqueue.push(start_vertex);
    visited[start_vertex]=1;

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

#endif




//----------------------------------------------------------------
#if 0
//유기농배추문제
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[50][50]={0,};
bool visited[50][50] = {false,};
int dx[4]={0,-1,0,1};
int dy[4]= {1,0,-1,0};

void DFS(int i, int j);
int M, N ,K;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >>T;

    for(int i=0; i<T; i++){
        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            int width, height;
            cin >> width >> height;
            arr[height][width] = 1;
        }

        int count =0;

        for(int i=0; i<N; i++){
            for(int j=0; j< M; j++){
                if(arr[i][j]==0){
                    continue;
                }
                count++;
                DFS(i,j);
            }
        }

        cout<< count << endl;
        
        for(int i=0; i<50 ; i++){
            fill(arr[i], arr[i]+50, 0);
            fill(visited[i], visited[i]+50, 0);
        }

    }

    return 0;
}

void DFS(int i, int j){

    if(visited[i][j] == 1){
        return;
    }

    visited[i][j]= true;

    for(int r=0; r<4 ; r++){
        int y = i + dy[r];
        int x = j + dx[r]; 
    
        if(visited[y][x]==0 && y < N && x < M && y>=0 && x>=0){
            if(arr[y][x]==1){
                arr[i][j]=0;
                //visited[y][x]=1;
                DFS(y,x);
            }
        }
    }
}
#endif





//----------------------------------------------------------------

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> visited;
vector<int> node_distance;
void BFS(int start_vector);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin >> v;

    graph.resize(v+1);
    visited.resize(v+1, false);

    for(int i=0; i< v; i++){
        int start;
        cin >> start;

        while(1){
            int end, weight;
            cin >> end;
            if(end == -1){
                break;
            }
            cin >> weight;
            graph[start].push_back(make_pair(end, wegiht));
        }
    }

    node_distance.resize(v+1,0);
    //시작을 1번 node에서 한다고 가정한다.
    BFS(1);

    int Max = 1;

    for(int i=2; i<=v ; i++){
        if(node_distance[Ma] < node_distance[i]){
            Max = i;
        }
    }

    fill(node_distance.begin(), node_distance.end(),0);
    fill(visited.begin(), visited.end(),0);
    BFS(width);

    sort(node_distance.begin(), node_distance.end());

    cout << node_distance[0] << endl;
}

void BFS(int start_vertex){
    queue<int> myqueue;
    myqueue.push(start_vertex);
    visited[start_vertex] =1;

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
#endif

#if 0
//미로탐색

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
    ios::sync_with_stdio(fasle);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M ; j++){
            graph[i][j] = s[j] -'0';
        }
    }

    //(0,0)에서 시작한다.
    BFS(0,0);

    cout << graph[N-1][M-1] << endl;
}

//queue 구현, BFS(탐색)
void BFS(int i, int j){
    queue<pair<int,int>> Myqueue;
    Myqueue.push(make_pair(i,j));

    while(Mhyqueue.empty()!=0){
        int current[2];
        current[0] = Myqueue.front().first;
        current[1] = Myqueue.front().second;
        visited[current[0]][current[1]] = 1;

        Myqueue.pop();

        int x,y;
        //상하좌우로 탐색한다.
        for(int i=0; i<4; i++){
            x= current[0] + dx[i];
            y = current[1] + dy[i];

            if(x>=0 && y>=0 && x < N && y < M){ //칸을 초과하는지 검사한다.
                if(graph[x][y]!=0 && visited[x][y]==0){ // 1만 이동할 수 있기 때문에
                    Myqueue.push(make_pair(x,y));
                    graph[x][y] = graph[current[0]][current[1]] + 1;
                    visited[x][y] =1;
                }
            }
        }
    }
}
#endif


#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int start =0;
    int end =0;

    for(int i=0; i<N; i++){
        cin >> A[i];
        if(start < A[i]){
            start = A[i];
        }
        end = end + A[i];
    }

    while(start <= end){
        int middle = (start + end)/2;
        int sum=0;
        int count =0;

        //middle값으로 모든 레슨을 저장할 수 있는지 확인한다.
        for(int i=0; i<N; i++){
            if(sum + A[i] > middle){
                count++;
                sum =0;
            }
            sum = sum + A[i];
        }

        if(sum !=0){
            count++;
        }
        if(count > M){
            start = middle + 1;
        }
        else{
            end = middle-1;
        }
    }

    cout << start <<endl;
}
#endif


#if 0
#include <iostream>
#include <queue>

using namespace std;

static int dx[]= {0,1,0,-1};
static int dy[]= {1,0,-1,0};

static int A[101][101];
static bool visited[101][101]={false,};
static int N, M;
void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

//N은 row 행, M은 column 행
    for(int i=0; i<N ; i++){
        string s;
        cin >> s;
        for(int j=0; j< M; ㅓ++){
            A[i][j]=s[j] - '0';
        }
    }

    BFS(0,0);
    cout << A[N-1][M-1]<<endl;
}

void BFS(int i, int j){
    queue<pair<int,int >> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int current[2];
        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;

        myqueue.pop();

        visited[i][j] = true;

        for(int k=0; k<4;k++){
            int x = current[0] + dx[k];
            int y = current[1] + dy[k];

            if(x >=0 && y >= 0 && x<N && y < M){
                if(A[x][y] != 0 && !visited[x][y]){
                    visited[x][y] = true;
                    A[x][y] = A[current[0]][current[1]] + 1;
                    myqueue.push(make_pair(x,y));
                }
            }
        }
    }
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//정렬을 이용함.

using namespace std;

bool compare(const pair<int, int > & a, const pair<int,int> &b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,int>> A;
    vector<pair<int,int>> B(1,{0,0});

    //cout << B.back().first << " " << B.back().second << endl;

    for(int i=0; i<N ; i++){
        int start, end;
        cin >> start >> end;
        A.push_back(make_pair(start, end));
    }

    //second 즉 끝나는 시간에 대해 오름 차순 정렬을 해야됨.
    sort(A.begin(), A.end(), compare);

    int count =0;
    int end = -1;

    //Algorithm part
    for(int i=0; i<N ; i++){
        if(A[i].first >= end){
            end = A[i].second;
            count++;
        }
    }
}

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first; //오름차순저열
    }
    return a.second < b.second; //second에 대한 오름차순 정렬
}
#endif


//절대값 힙찾기 문제

#if 0
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        int first = int(abs(a));
        int second = int(abs(b));
        if(first == second){
            return a > b; //오름차순 정렬을 함
        }
        else if(first != second){
            return first > second; //오름차순 정렬을 함
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, compare> myqueue;

    int N;
    cin >> N;
    int current;

    for(int i=0; i<N; i++){
        cin >> current;

        if(current ==0){
            if(myqueue.empty()){
                cout << "0" << endl;
            }
            else{
                cout << myqueue.top() << endl;
                myqueue.pop();
            }
        }
        else{
            myqueue.push(current);
        }
    }
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);
static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
static bool IsEven;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<N;i++){
        int V,E;
        cin >> V >> E;
        A.resize(V+1);
        visited.resize(V+1);
        check.resize(V+1);
        IsEven = true;

        for(int i=0; i<E; i++){
            int start, end;
            cin >> start >> end;
            A[start].push_back(end);
            A[end].push_back(start);
        }

        //주어진 그래프가 하나로 연결된다는 보장이 없으므로 모든 노드에서 수행함.
        for(int i=1; i<=V; i++){
            if(IsEven){
                DFS(i);
            }
            else{
                break;
            }
        }

        if(IsEven){
            cout << "YES"<<endl;
        }
        else if(!IsEven){
            cout <<"NO"<< endl;
        }

        for(int i=0; i<=V; i++){
            A[i].clear();
        }
        fill(visited.begin(), visited.end(), false);
        fill(check.begin(), check.end(),0);
    }
}

void DFS(int node){
    visited[node]= true;

    for(int i:A[node]){
        if(!visited){
            //인접한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리
            //여기서는 0,1처리를 한다.
            check[i] = (check[node]+1)%2;
            DFS(i);
        }
        else if(check[node] == check[i]){
            //이미 방문한 노드가 현재 노드와 같은 집합이면 이분 그래프가 인접하다는 의미
            IsEven = false;
        }
    }
}
#endif

#if 0
//칵테일 만들기
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>>A[10];
long minn; //최소공배수
bool visited[10];
long D[10];

long gcd(long a, long b);
void DFS(int node);

//데이터를 저장할 때마다 비율과 관련된 수들의 최소 공배수를 업데이트해줌
//A,B의 최소 공배수는 A*B/최대공약수로 구함. 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //임시 시작점에 최소공배수 저장함.
    //임시의 시작점에서 DFS로 탐색을 수행하면서 각 노드의 값을 이전 노드의 값과 비율 계산
    //각 노드의 값을 모든 노드의 최대 공약수로 나눈 뒤 출력함.

    int N;
    cin >> N;
    minn =1;

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a>>b >>p >>q;
        A[a].push_back(make_tuple(a,b,p,q));
        A[b].push_back(make_tuple(b,a,q,p));
        //두 수의 최소공배수는 두 수의 곱을 최대 공약수로 나눈것
        minn = minn*(p*q/gcd(p,q));
    }
    D[0] = minn; //최소공배수를 저장함.
    DFS(0); //0부터 시작함
    long mgcd = D[0]; //mgcd는 D 배열에 저장된 수의 최소공배수임.

    for(int i=1; i<N; i++){
        mgcd = gcd(mgcd, D[i]); //0은 이미 위에 저장 되었으니까
        //mgcd는 최소 공배수를 구함. 
    }

    for(int i=0; i<N; i++){
        cout << D[i]/mgcd << ' ';
    }

    return 0;
}

//최대공약수를 구한다.
long gcd(long a, long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

void DFS(int node){
    visited[node] = true;

    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>i]){
            D[get<0>i]= D[node]*get<2>(i)/ get<1>(i);
            DFS(get<0>(i));
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define Max 15

using namespace std;

int N=0;
int col[Max]={0,};

bool condition(int i);
void queen_N(int i);
int result =0;

int main(void){
    cin >> N;
    queen_N(0);
    cout <<result << endl;
}

bool condition(int i){
    for(int k=0; k<i ; k++){
        if(col[k] == col[i] || abs(col[k]-col[i]) = i-k){
            return false;
        }
    }
}

void queen_N(int i){
    if(i==N){
        result++;
        return;
    }

    for(int j=0; j<N;j++){
        col[i] = j; //행이 주어지고 어떤 열에 queen이 놓이는지 알수 있음.
        //0열에는 모두 놓을 수 있음.

        //만약 중간에 걸러지면 i는 어떻게 설정해야됨?
        if(condition(i)){
            queen_N(i+1);
        }

    }
}
#endif



#if 0
//좋은 수열 문제

#include <iostream>
#include <cstring>

using namespace std;

int N;

bool isbad(string str);

void good(int a, string str);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    good(0,"");

    return 0;
}

bool isbad(string str){
    for(int i=1; i <= str.length()/2 ; i++){
        if(str.substr(str.length()-i,i) == str.substr(str.length()-2*i,i)){
            return false;
        }
    }
    return true;
}

void good(int a, string str){
    if(!isbad(str)){
        return;
    }
    if(a==N){
        cout << str << endl;
        exit(0);
    }

    good(a+1, str + "1");
    good(a+1, str + "2");
    good(a+1, str + "3");
}
#endif


#if 0

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a,b,c;

int Sender[] = {0,0,1,1,2,2};
int Receier[] = {1,2,0,2,0,1};
vector<int> answer;
bool visited[201][201] = {false};
int now[3];
bool flag = fase;

bool compare(int &a, int &b){
    if(a<b){
        return true;
    }
    else{
        return false;
    }
}

void BFS(void);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now[0] >> now[1]>> now[2];
    BFS();

    sort(answer.begin(), answer.end(), compare);

    for(int i : answer){
        cout << i << " ";
    }
    return 0;
}



void BFS(void){
    queue<pair<int,int>>myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        int A = myqueue.front().first;
        int B = myqueue.front().second;
        int C = now[2]-A-B;

        visited[A][B]=true;

        myqueue.pop();

        if(A==0){
            for(int i:answer){
                if(i == C){
                    flag = true;
                }
            }
            if(!flag){
                answer.push_back(C);
            }
            flag = false;
        }

        for(int k=0; k<6;k++){
            int next[] = {A,B,C};
            next[Receiver[k]] = next[Reciver[k]] + next[Sender[k]];
            //물병을 보내면 Sender쪽의 물의 양은 0이 되는게 원칙임
            next[Sender[k]] =0;

            if(next[Receiver[k] > now[Receiver[k]]]){
                next[Sender[k]] = next[Receiver[k]]- now[Receiver[k]];
                next[Receiver[k]] = now[Receiver[k]];
            }

            //A,B의 물의 양을 통하여 방문 배열 체크

            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]] = true;
                myqueue.push(make_pair(next[0], next[1]));
            }
        }
    }
}

#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void SEARCH_NODE(int start_vertex);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    graph.resize(N+1);
    answer.resize(N+1);
    visited.resize(N+1,fasle);

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    for(int i=0; i<=N; i++){
        fill(visited.begin(), visited.end(), false);
        SEARCH_NODE(1);
    }

    int maxVall=0;

    for(int i=1; i<=N; i++){
        maxVal = max(maxVal, anser[i]);
    }

    for(int i=1; i<=N; i++){
        //anser 배열에서 maxVal와 같은 값을 가진 index을 정답으로 출력
        if(answer[i] == maxVal){
            cout << i << " ";
        }
    }
}

void SEARCH_NODE(int start_vertex){
    queue<int>queue;

    //단방향이고 특정 current가 비어 있다면

    visited[start_vertex]= true;

    myqueue.push(start_vertex);

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();
        for(int i:graph[current]){
            if(visited[i]== false){
                visited[i] = true;
                answer[i]++;
                myqueue.push[i];
            }
        }
        
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int send[]={0,0,1,1,2,2};
int receiver[]={1,2,0,2,0,1};
int now[3];
void BFS(void);
//용량이 총 201이기 때문에 이 판단을 했음
bool visited[201][201]={false,};
vector<int> answer;

bool compare(int &a, int &b){
    if(a <b){
        return true;
    }
    else{
        return false;
    }
}

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //각각의 물병 용량을 입력받음.
    cin >> now[0] >> now[1] >> now[2];

    BFS();

    sort(answer.begin(),answer.end(), compare);

    for(int i : answer){
        cout << i << " ";
    }
    return 0;

}

void BFS(void){
    //1. queue를 만든다. 2. push함. 3. visted 처리를 함.
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    //visited[0][0] = true;

    //빌 때까지 while 문을 돌림.
    while(!myqueue.empty()){
        //1. 변수 3개를 만든다.
        int A = myqueue.front().first;
        int B = myqueue.front().second;
        int C = now[2]-A-B;

        //변수 3개를 만든 후 pop을 해줌
        myqueue.pop();

        //for에 들어가기전 다음을 나타내느 변수를 선언해줌
        for(int k=0; k<6; k++){
            int next[] = {A,B,C};
            next[receiver[k]] = next[receiver[k]] + next[send[k]];
            next[send[k]]=0;

            //만약 넘쳤을때
            if(next[receiver[k]] > now[receiver[k]]){
                next[send[k]] = next[receiver[k]]- now[receiver[k]];
                next[receiver[k]] = now[receiver[k]];
            }

            //만약 visited 였으면 push를 하지 않아됨
            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]]= true;
                myqueue.push(make_pair(next[0], next[1]));
                if(next[0]==0){
                    answer.push_back(next[2]);
                }
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

int N;
int fibo(int n);
vector<int>D;

int main(void){
    cin >> N;
    D.resize(N+1);

    for(int i=0; i<=N; i++){
        D[i]= -1;
    }
    D[0]=0;
    D[1]=1;
    fibo(N);
    cout << D[N];



}

int fibo(int n){
    if(D[n]!=-1){
        return D[n];
    }
    else{
        return D[n] = fibo(n-2)+fibo(n-1);
    }
}
#endif


#if 0
//양배추 문제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100][100]={false,};
void BFS(int a, int b);
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
graph[100][100];


int main(void){

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N;i++){
        string str;
        cin >> str;

        for(int j=0; j<M; j++){
            graph[i][j] = str[j] -'0';
        }
    }

    BFS(0,0);

    cout << graph[N-1][M-1]<<"\n";
    
}

void BFS(int a, int b){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool>visited;
vector<int>answer;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(N+1);
    visited.resize(N+1,false);

    // for (int i = 1; i <= N; ++i) {
    //     graph[i].resize(N + 1, 0); // 내부 벡터의 크기를 조절하고, 0으로 초기화합니다.
    // }

    for(int i=1; i<=M;i++){
        int start. end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    for(int i=1; i<=N; i++){
        fill(visited.begin(), visited.end(),false);
        BFS(i);
    }

    for(int i=1; i<=N; i++){

    }
}

void BFS(int i){
    queue<int> myqueue;
    myqueue.push(i);
    visited[i]= true;

    while(!myqueue.empty()){
        int x = myqueue.front();
        myqueue.pop();

        if(int i : graph[x]){
            if(visited[i]==0){
                visited[i]= true;
                answer[i]++;
                myqueue.push(i);
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;

vector<tuple<int,int,int>>A[10];
long minn;
bool visitied[10];
long D[10];

long gcd(long a, long b);
void DFS(int node);

//데이터를 저장할 때마다 비율과 관련된 수들의 최소 공배수를 업데이트해줌
//A,B의 최소공배수는 A*B/최대공약수임. 따라서 1,3,5,7의 최소 공배수는 1*3*5*7임 (최대공약수)

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //임시의 시작점에 최소공배수 값을 저장함
    //임시의 시작점에서 DFS로 탐색을 수행하면서 각 노드의 값을 이전 노드의 값과의 비율을 계산함
    //각 노드의 값은 ㅗ든 노드의 최대 공약수로 나눈 뒤 추력함

    int N;
    cin >> N;
    minn=1;

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >>a >>b>>p>>q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push.back(make_tuple(a,q,p));
        minn = minn*(p*q/gcd(p,q));
    }

    D[0]= minn; //최소공배수를 저장함.
    DFS(0); //0부터 시작함
    long mgcd = D[0]; //mgcd는 D배열에 저장된 수들의 최소공배수임.


    //모든 수의 최대 공약수를 구함
    for(int i=1; i<N; i++){
        mgcd = gcd(mgcd,D[i]);    
    }

    for(int i=0; i<N; i++){
        cout << D[i]/mgcd << ' ';
    }

    return 0;
}

long gcd(long a, long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

void DFS(int node){
    visited[node]= true;

    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)]= D[node]*get<2>(i)/get<1>(i);
            DFS(get<0>(i));
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
#include <numeric>

using namespace std;

const int MAX_N 22;
int n, m;
int graph[MAX_N][MAX_N];
bool viisted[MAX_N][MAX_N];
vector<pair<int,int>>friends;
vector<int>max_harvest_per_friend;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, int depth, int harvest, int &max_harvest){
    if(depth==3){
        max_harvest = max(max_harvest, harvest);
        return;
    }

    for(int dir =0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && !visited[nx][ny]){
            //DFS로 3개를 택함
            visited[nx][ny] = true;
            dfs(nx, ny, depth+1, harvest + graph[nx][ny], max_harvest);
            visited[nx][ny] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>n >>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    friends.resize(m);

    for(int i=0; i<m ; i++){
        cin >> friends[i].frist >> friends[i].second;
    }
    //최대 수확량
    max_ahrvest_per_friends.resize(m,0);


    for(int i=0; i<m ;i++){
        int x = friends[i].first;
        int y = frinds[i].second;

        for(int i=0; i<=n; i++){
            fill(visited[i], visited[i]+n+1,false);
        }
        visited[x][y] = true;
        dfs(x,y,0, graph[x][y], max_harvest_per_friend[i]);
    }

    int total_max_harvest=0;

    for(int i=0; i<m;i++){
        totla_max_harvest += max_harvest_per_frind[i];
    }
    cout << totla_max_ahrvest << "\n";

    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int max_n =22;
int max_depth =3;
int n, m; //n은 격자, m은 사람 수
int graph[max_n][max_n]={0,};
vector<pair<int,int>> friends;

vector<vector<vector<int,int>>>> paths;
vector<vector<pair<int,int>>> all_paths;

void dfs(int x, int y, int depth, vector<pair<int,int>> &current_path, vector<vector<int,int>>>&all_paths){
    if(depth == max_depth){
        all_path.push_back(current_path); //특정 사람이 갈 수 있는 모든 path의 경우의 수
        return;
    }

    for(int dir=0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        for(nx >=1 && nx<=n && ny >=1 && ny <=n){
            current_path.push_back(make_pair(nx,ny));
            dfs(nx,ny,depth+1, current_path, all_paths);
            current_path.pop_back();
        }
    }
}

//각 사람마다 경로 3개를 선택했으면 이제 최대 거리를 비교해준다.
void calculator_function(vector<vector<pair<int,int>>> & chosen_paths){
    int harvest=0;
    //임시 배열을 설정해준다.
    temp_graph[max_n][max_n] = {0,};

    //copy를 함
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n ; j++){
            temp_graph[i][j] = graph[i][j];
        }
    }

    for( vector<pair<int,int>> &path:chosen_paths){ //이제 각 각 고른 4개의 path를 실행시킨다.
        for(pair<int,int> & p : path){ //이제 각각의 요소를 뜯어본다.
            int x = p.first;
            int y = p.second;

            if(graph[x][y] > 0){
                //0보다 작은건 수확한거 근데 이 조건 없어도 됨.
                harvest += graph[x][y];
                //수확했으면 이제 이 칸은 0이된다.
                graph[x][y] =0;
            }

        }

    }

    return harvest;

}

void findMaxHarvest(int idx, vector<vector<pair<int,int>>> & chosen_paths, int & max_harvest){

    if(idx == m){//총 3개의 경로를 선택했으면....
        //계산을 실행함
        max_harvest = max(max_harvest, calculator_function(chosen_paths)); //
        return;

    }

    //각 친구가 선택할 수 있는 최대를 고른다.
    for(vector<pair<int,int>> & path : paths[idx]){
        chosen_paths.push_back(path); //1번 친구의 최대 path를 선택했음
        //이제 2번친구의 최대 경로를 선택해야함
        findMaxHarvest(idx+1, chosen_paths, max_harvest);
        chosen_paths.pop_back();
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >>m;

    //n*n 정사각형 격자모양임.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    //사람 수를 resizing 해줌
    friends.resize(m+1);
    paths.resize(m+1);// 각 시작점으로 부터 path를 저장함.

    for(int i=0; i<m ;i++){
        int x,y;
        cin >> x >>y;
        frind[i].first = x;
        friend[i].second = y;

        //초기화 해줌
        vector<pair<int,int>> current_path;

        //초기화해줌
        current_path.push_back(make_pair(x,y));

        //초기화해줌// 이건 초기화 안해도 될듯
        vector<vector<pair<int,int>>> all_paths;

        //모든 경우의 수를 path에 저장해 놓음.
        dfs(x,y,0, current_path, all_paths);
        
    }

    int max_harvest=0;

    vector<vector<pair<int,int>>> chosen_paths;
    findMaxHarvest(0,chosen_paths, max_harvest); //0번 친구부터 시작

    cout << max_harves << '\n';

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define Max 15

int N=0;
//column
int col[Max] = {0,};

bool condition(int i); // 주변에 놓인것이 있는지 없지지 판단한다.
void queen_N(int i); // 주변에 없으면 +1을 해줌. 이때 i는 충수임.
int result=0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    queen_N(0); //처음에는 0행부터 시작한다. 이때 행은 row이고 열은 column이 되낟.
    cout << result << endl;
    return 0;
}

//범위가 침범되는지 아닌지 판단한다. //i,k는 row이다.
bool condition(int i){
    //모든 행을 다 고려해준다.
    for(int k=0; i<i;k++){
        //만약 같은 열에 있으면 안된다. 그리고 대각선에도 있으면 안됨.
        if(col[k] == col[i] || abs(col[k] - col[i]) == i - k){
            return false;
        }
    }
}

void queen_N(int i){
    if(i==N){ //만약 까지 다 놨으면 플러스를 해준다.
        reusult++;
        return;
    }

    for(int j=0; j<N; j++){ //모든 열을 고려한다. 0행부터시작
        col[i] = j; //
    }
    //행이 row, 열이 column
    if(condition(i)){
        queen_N(i+1); //만족하면 다음 row로 넘어간다.
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namesapce std;

int arr[51][51]={0,};
int visited[51][51] = {0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int M,N,K; //M로 가로길이, N은 세로길이, K는 배추가 심어진 개수

//solution 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int i=1; i<=T; i++){
        cin >> M >> N;

        //배추가 심어져 있는 case를 입력함
        for(int i=0; i<K; i++){
            int w,h; //가로, 세로입력
            cin >> w>>h;
            arr[h][w] = 1;
        }

        int cnt=0;

        //모든 것을 탐색한다.
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]==1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }
         cout << cnt << endl;

         for(int i=0; i<N ; i++){
            fill(arr[i],arr[i]+M,0);
            fill(visited[i], visited[i]+M, false);
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

    for(int r=0; r<4; r++){
        int width = j + dx[r];
        int height = i + dy[r];

        if(width >=0 && height >=0 && wdith < M && height < N){
            if((visited[height][width]==0) && arr[height][width]==1){
                DFS(height, width);
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namesapce std;

int K;
int V,E;
void DFS(int node, int r);
vector<vector<int>> graph[5];
int flag = true;
vector<int> check;

int main(void){

    cin >> k;
    int r;
    for(int r=0; r<k; r++){
        cin >> V >> E;
    }

    for(int i=1; i<=V;i++){
        DFS(i,r);
        //초기화 시켜준다.
    }

    fill(visited.begin(), visited.end(),0);
    fill(check.begin(), check.end(),0);
}

void DFS(int node, int r){
    visited[node]= true;

    for(int i : graph[r][node]){
        if(visited[i]==false){
            visited[i]=true;
            check[i] = (check[node]+1)%2;
            DFS(i,r);
        }
        else if(visited[i]== true){
            if(check[i] == check[node]){
                flag = false;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    vector<int>A;
    A.resize(N,0);
    int start =0;
    int end =0;

    for(int i=0; i<N; i++){
        cin >> A[i];
        if(start < A[i]){
            start = A[i];
        }
        end +=A[i];
    }

    while(start <=end){
        int middle = (start + end)/2;
        int sum=0;
        int count =0;

        //middle값으로 모든 레슨을 저장할 수 있을까 ?
        for(int i=0; i<N; i++){
            if(sum+A[i] > middle){
                count++;
                sum=0;
            }
            sum = sum + A[i];
        }
    
        if(sum!=0){
            count++;
        }
        if(count > M){
            start = middle+1;
        }
        else{
            end = middle-1;
        }
    }

    cout << start <<endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>>A[10];
long minn; //최소공배수 저장
bool visited[10];
long D[10]; //최소가 되는 재료량을 저장한다

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn=1;

    //input을 입력한다
    for(int i=0; i<N-1;i++){
        int a,b,p,q;
        cin>>a>>b>>p>>q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        //a*b의 최소공배수는 a*b/최대공약수
        minn = minn*(p*q)/gcd(p,q);
    }
    //0번 재료부터 순서대로 공백으로 구분해서 출력해야 하기 때문에
    D[0] = minn;
    //cout << minn <<endl;
    DFS(0); //연결되어 있는 정보

    //이제 최소공배수를 곱한다.
    for(int i=1; i<N; i++){
        minn = gcd(minn, D[i]);
    }

    for(int i=0; i<N; i++){
        D[i]= D[i]/minn;
        cout << D[i] <<" ";
    }
    return 0;
}

//모든 비율을 맞춰줌
void DFS(int node){
    visited[node] = true;
    for(tuple<int,int,int> i : A[node]){
        if(!(visited[get<0>(i)])){
            D[get<0>(i)] = D[node]*(get<2>(i))/(get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));  
        }
    }
}

long gcd(long a, long b){
    if(b==0){
        return a;
    }
    return gcd(b,(a%b));
}
#endif

#if 0
#include <iostream>
#include <vector>
using namesapce std;

vector<int> parent;
void unionfunc(int a, int b);
int find(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int graph[201][201];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> graph[i][j];
        }
    }

    int route[1001];

    for(int i=1; i<=M; i++){
        cin >> route[i];
    }

    parent.resize(N+1);

    for(int i=1; i<=N;i++){
        for(int j=1; j<=N; j++){
            if(graph[i][j]==1){
                unionfunc(i,j);
            }
        }
    }

    //여행 계획 도시가 하나의 대표 도시로 연결되는지 확인
    int index = find(route[1]);
    bool connect = true;

    for(int i=2; i<=M;i++){
        if(index != find(route[i])){
            cout << "NO" << endl;
            connect = false;
            break;
        }
    }

    return 0;
}

void unionfunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parnet[b]=a;
    }
}


int find(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return parnet[a] = find(parent[a]);
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> D,T,P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    D.resize(N+2,0);
    T.resize(N+1);
    P.resize(N+1);

    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }
    for(int i=N; i>0 ; i--){
        if(i+T[i]-1 > N){ //N+1 이상이면
            D[i] = D[i+1]; //전의 값을 가져온다.
        }
        else{
            D[i] = max(D[i+1], D[i+T[i]] + P[i]);
        }
    }
    cout << D[1];

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> & b){
        return a.first > b.first; //오름차순으로 정렬함. 
    }
};

vector<bool>visited;
vector<long>mdistance;

vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; //N개의 도시, M개의 버스가 있음.
    cin >> N;
    cin >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    //M은 버스노선의 개수 즉 edge 개수이다.
    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >>w;
        mlist[u].push_back(make_pair(v,w));
    }

    int start, end;
    cin >> start >> end;

    mdistance[start] =0;

    myqueue.push(make_pair(0,start)); //가중치, 노드

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node] = true;

        for(pair<int,int> i : mlist[now_node]){
            int next_node = i.first;
            int next_value = i.second;

            if(mdistance[next_node] > mdistance[now_node] + next_value){
                mdistance[next_node] = mdistance[now_node] + next_value;

                myqueue.push(make_pair(mdistance[next_node], next_node));
            }
        }
    }

     if(visited[end] == true){
        cout << mdistance[end] << endl;
    } 


}
#endif


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>

using namesapce std;

int MAX_N = 22;
int n, m;
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int,int>> friend;
vector<int> max_harvest_per_freind;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, int depth, int harvest, int & max_harvest){
    if(depth == 3){
        max_harvest = max(max_harvest, harvest);
        return;
    }

    for(int dir =0;dir <4 ; dir++){
        int nx = x +dx[dir];
        int ny = y + dy[dir];

        if(nx>=1 && nx <=n && ny >=1 && ny <= n && !visited[nx][ny]){
            //DFS로 3개 택함
            //3개의 조합을 선택한다.
            visited[nx][ny] = true;
            dfs(nx,ny,depth+1, harvest + graph[nx][ny], max_harvest);
            visited[nx][ny] = fasle;
        }
    }
}

void dfs(int x, int y, int depth, int harvest, int & max_harvest){
    if(depth==3){
        max_harvest = max(max_harvest, harvest);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=1 && nx <=n && ny >=1 && ny <=n && !visited[nx][ny]){
            visited[nx][ny]= true;
            dfs(nx,ny,depth+1,harvest + graph[nx][ny], max_harvest);
            visited[nx][ny] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    friends.resize(m);

    for(int i=0; i<m;i++){
        int x = friends[i].first;
        int y = friends[i].second;
        
        for(int i=0; i<=n; i++){
            fill(visited[i], visited[i] + (n+1) , 0);
        }
        visited[x][y] = true;
        dfs(x,y, 0, graph[x][y], max_harvest_per_friend[i]);
    }

    int total_max_harvest =0;

    for(int i=0; i<m; i++){
        total_max_harvest +=max_harvest_per_friend[i];
    }

    cout << total_max_harvest << "\n";

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N  =22;
const int MAX_DEPTH =3;
int n,m;
int grpah[MAX_DEPTH] [MAX_N]= {0,};
vector<pair<int,int>>friend;
vector<vector<pair<int,int>>> graph;



vector<vector<vector<pair<int,int>>>> paths;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, int depth, vector<pair<int,int>> & current_path, vector<vector<pair<int,int>>> & all_path){
    if(depth == MAX_DEPTH){
        all_path.push_back(current_path);
        return;
    }

    for(int dir =0; dir <4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >=1 && nx <=n && ny>=1 && ny <=n){
            current_path.push_back(make_apir(nx,ny));
            dfs(nx, ny,depth+1), current_path, all_path);
            current_path.pop_back();
        }
    }
}

int findMAXHArvest(int idx, vector<vector<pair<int,int>>> & chosne_pahts, int max_ahrvest){
    if(idx == m) {
        max_ahrst = max(max_ahrt, calculatore (chosne_apth);
        return;)
    }

    //각각 참여자의 path 4칸을 찾음
    for( vecotr<pair<int,int>> path : path[idx]){
        //path1의 모든 path를 나타낸다.
        chosen_apth. push_back(path); 

    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N, M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N은 도시 개수, M은 경로의 개수
    int N,M;

    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);

    //출발이 1이니까 1를 0로 초기화한다.
    mdistance[1]-0;

    //시작, 도착 가중치를 넣는다.
    for(int i=1; i<=M ; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start,end, weight));
    }

    //이제 다 넣었으니 N-1만큼 반복한다.
    for(int i=1; i<N; i++){
        for(int j=0; j<edges.size(); j++){
            tuple<int,int,int> medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            //일단 방문을 했어야된다.
            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
                //작은 distance로 갱신한다.
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;

    for(int j=0; j< edges.size(); j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        for(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M, sCity, eCity;
vector<long> mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistance.end(), LONG_MIN);

    for(int i=0; i<M; i++){
        int start, end, price;
        cin >> start>>end>>price;
        edges.push_back(make_tuple(start, end, price));
    }

    for(int i=0; i<N; i++){
        cin >> cityMoney[i];
    }

    mdistance[sCity] = cityMoney[sCity];

    for(int i=0; i<=N+50; i++){
        for(int j=0; j<edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            //일단 연결은 되어 있어야지 가중치를 뽑을 수 있음.
            if(mdistance[start] == LONG_MIN){
                continue;
            }
            
            // if(mdistance[start] == LONG_MAX){
            //     continue;
            // }

            //시작 노드가 양수 사이클에 연결된 노드라면 종료하고, 아니면 mdistnace를 업데이트함.
            else if(mdistance[end] < mdistance[start] + cityMoney[end] -weight){
                mdistance[end] = mdistance[start] + cityMoney[end] - weight;

                //사이클을 충분히 돌았으면
                if(i >=N-1){
                    mdistance[end] = LONG_MAX;
                }
            }
        }
    }

    if(mdistance[eCity] == LONG_MIN){
        cout << "gg" << endl;
    }
    else if(mdistance[eCity] == LONG_MAX){
        cout << "Gee" <<endl;
    }
    else{
        cout << mdistance[eCity] << endl;
    }

}
#endif


//한번 tuple로 구현해보자
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <tuple>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> &b){
        return a.first > b.first; //우선순위queue에서는 오름차순 정령ㄹ이다.
    }
};

vector<bool>visited;
vector<long> mdistance;

vector<tuple<int,int,int>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    cin >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    //tuple로는 다익스타라 구현이 어렵나 ?
    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >>w;
        mlist.push_back(make_tuple(u,v,w));
    }

    int start, end;
    cin >>start >> end;

    //자기 출발 위치는 0이다.
    mdistance[start]=0;

    myqueue.push(make_pair(0,start)); //최소거리 start node

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node]= true;

        // for(pair<int,int> node : edges[now_node]){
        //     pair<int,int> medges = node;
        //     int end = node.first;
        //     int edge_weight = node.second;

        //     if(mdistance[end] > mdistance[now_node] + weight ){
        //         mdistance[end] = mdistance[now_node] + weight;
        //         myqueue.push(make_pair(mdistance[end], end)); //weight, star node를 넣어준다.
        //     }
           
        // }

        for(int i=0; i<mlist.size(); i++){
            int start = get<0>(mlist[i]);
            int end = get<1>(mlist[i]);
            int weight = get<2>(mlist[i]);

            if(start != now_node){
                continue;
            }

            //만약 시작 노드가 맞으면 이제 부터 비교
            if(mdistance[end] > mdistance[start] + weight){
                mdistance[end] = mdistance[start] + weight;
                myqueue.push(make_pair(mdistance[end], end));
            }
        }
    }

    //이제 다 탐색을 했음
    // if(visited[end] == true){
    //     cout << mdistance[end] << endl;
    // }
    cout << mdistance[end] << endl;
    return 0;

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namesapce std;

struct compare{
    bool operation((pair<int,int> &A, pair<int,int> &B)){
        if(A.first > B.first){ //오름차순으로 정렬한다.
            return true;
        }
        else{
            return false;
        }
    }
};

//

int N,M,K; //여기서 K는 k번째 경로를 의미한다.

vector<int>visited;
vector<vector<pair<int,int>>> graph;
vector<int> mdistance;

//작은게 우선순위에 와야한다.
priority_queue<pair<int,int>, vector<pair<int,int>>, compare1> pd;

//노드개수가 1001개니까 1001개를 만든다. 오름차순으로 정렬한다.
//왜나하면 제일 큰거를 push해줘야 하기 때문이다.
priority_queue<int,vector<int>, less<int>> disqueue[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K; //노드수, 경로, 몇번째 길인지 알려준다.
    graph.resize(N+1); //여기서는 노드의 개수를 저장한다.

    for(int i=0; i<M; i++){
        int start, end, weight;
        graph[start].push_back(make_pair(end,weight));
    }
    mdistnace.resize(N+1, INT_MAX);
    pd.push(make_pair(0,1)); //가중치가 0이고 시작노드는 1이다.
    disqueue[1].push(0); //일단 우선순위 queue에 1을 0에 넣는다.

    while(!pd.empty()){
        //제일 작은 거를 꺼낸다.
        pair<int,int> u = pd.top();
        int now = u.second;
        int distnace = u.first;

        pd.pop();

        //now에 연결된 시작노드에 end node를 다 탐색한다.
        for(pair<int,int node1 : graph[now]){
            int end = node1.first;
            int weight = node1.second;

            //저장된 경로가 k가 안됐,을 경우 그냥 추가해준다.
            if(disqueue[end].size() < K ){
                disqueue.push(distance + weight);
                pd.push(make_pair(distance + weight, end)); //가중치, 시작노드
            }

            else if(disqueue[end].size() >=k && disqueue[end].top() > distance + weight){
                disqueue[end].pop();
                disqueue[end].push(distance + weight);
                pd.push(make_pair(distance+weight, end));
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(disqueue[i].size() == K){
            cout << disqueue[i].top() << endl;
        }
        else{
            cout << -1 << endl;
        }
    }



}
#endif

#if 0
//유니온파인드 문제 !! 연결되어 있는지 확인함
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int>parent;
vector<vector<int>>graph;
vector<int>true_person;
int find(int node);
void uinio_function(int a, int b);
vector<vector<int>> party;
int flag = false;
int cnt =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; //사람의 수, 파티 수가 주어짐
    cin >> N >> M;
    parent.resize(N+1);
    party.resize(M+1);

    //사람들의 번호가 1부터 N까지 주어짐
    for(int i=1; i<N; i++){
        parent[i] = i;
    }

    int N_1; //진실을 아는 사람
    cin >> N_1;

    true_person.resize(N_1+1);

    //만약 N_1이면 진실을 아는 사람을 안 적어줘도됨
    for(int i=0; i<N_1; i++){
        cin >> true_person[i];
    }

    //이제 파티에 진실을 아는 사람있으면 그 사람을 parent해서 union_func을 진행
    for(int i=0; i<M; i++){
        int person; //파티에 오는 사람 수를 저장
        cin >> person;

        for(int u=0; u <person; u++){
            int select; //파티에 오는 사람 수 이다.
            cin >> select;
            party[i].push_back(select);

            
        }
    }
}

void union_func(int a,int b){
    int i = find(a);
    int j = find(b);

    if(i!=j){
        parnet[j]=i;
    }
}

int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
#endif


#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namesapce std;

int N, M;
vector<vector<int>> A;
vector<bool>visited;

void DFS(int vertex);
int cnt =0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N+1);
    visited.resize(N+1, false);
    
    for(int i=0; i<M; i++){
        int start,end;
        cin >> start >> end;
        A[start].push_back(end);
        A[end].push_back(start);
    }

    //각 노드별로 탐색을 한다.
    for(int i=1; i<=N; i++){
        if(visited[i] == 0){
            cnt++;
            DFS(i);
        }
    }

    cout << cnt <<endl;

    return 0;
}

void DFS(int i){
    visited[i] = true;

    for(int i : A[i]){
        if(visited[i] == 0){
            DFS(i);
        }
    }
}
#endif


#if 0
//유기농배추문제
#include <iostream>
#include <vector>
#include <queue>

using namesapce std;

int arr[51][51] = {0,};
int visited[51][51] = {0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void DFS(int i, int j);

int N,M,K; //M은 가로길이, N은 세로길이, K는 배추가 심어져있는 개수이다.

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; //case경우가 주어진다.
    cin >>T;

    for(int i=1; i<=T; i++){
        cin >> M >> N;
        cin >>k;

        //배추가 심어져 있는 case를 입력한다.
        for(int i=0; i<K; i++){
            int w,h;
            cin >> w >> h;
            arr[h][w] =1;
        }

        int cnt=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]==1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;

        for(int i=0; i<N; i++){
            fill(arr[i], arr[i]+M, false);
        }
    }

    return 0;
}

void DFS(int i, int j){
    if(visited[i][j] == 1){
        return;
    }
    visited[i][j] = true;
    arr[i][j]=0;

    for(int r=0; r<4; r++){
        int width = j + dx[r];
        int height = i + dy[r];

        if(wdith >= 0 && height >=0 && width <M && height < N){
            if(visited[height][width]==0 && arr[height][width] == 1){
                DFS(height, width);
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>

using namesapce std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,1,0};
int graph[100][100];
bool visited[100][100]={false,};
int N, M;
void BFS(int i, int j);

int main(void){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            graph[i][j] = s[j] = '0';
        }
    }

    BFS(0,0);
    cout << graph[N-1][N-1] << endl;
    return 0;
}


void BFS(int i, int j){
    queue<pair<int,int>> Myqueue;
    Myqueue.push(make_pair(i,j));

    while(Myqueue.empty()){
        int current[2];
        current[0] = Myqueue.front().first;
        current[1] = Myqueue.front().second;
        visited[current[0]][current[1]] = true;

        Myqueue.pop();

        int x,y;
        for(int i=0; i<4; i++){
            x = current[0] + dx[i];
            y = current[1] + dy[i];

            if(x>=0 && y>=0 && x <N && y < M){
                if(graph[x][y]!=0 && visited[x][y] == 0){
                    Myqueue.push(make_pair(x,y));
                    graph[x][y] = graph[current[0]][current[1]] +1;
                    visited[x][y]=1;                }
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>degree;
vector<int>setbuild;
vector<vector<int>>graph;
vector<int>goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

         //이제 우선순위 건물을 비교해줘야함.
        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                //그리고 degree 1를 증가시킨다.
                degree[i]++;
            }
        }
    }

    //이제 위상절렬이 완성됨
    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] ==0){
            //차수가 0인 노드는 우선순위가 높으므로 push해줌
            myqueue.push(i);
        }
    }

    //이제 push된 것부터 출력을 해줌. 그리고 queue가 빌때까지 출력해줌
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node : graph[now]){
            //이제 순서대로 해당 종속 노드가 나오게 된다.
            //일단 차수 하나를 낮춰준다.
            degree[node]--;

            //push해준다.
            if(degree[node]==0){
                myqueue.push(node);
            }

            //그 다음에 해당 노드 현재 상태에다 setbuild를 더해준다.
            //2개 이상의 건물이랑 종속성이 있는 경우 큰 build시간이 지난 후 지어진다.
            goal[node] = max(goal[node], (goal[now] + setbuild[now]));
        }
    }

    //이제 모든 노드에 자기 자신의 시간을 더한다.
    for(int i=1; i<=N; i++){
        goal[i] = goal[i] + setbuild[i];
        cout << goal[i] << endl;
    }

   
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namesapce std;

int K;
int V,E;
vector<bool> visited;
void DFS(int node, int r);
vector<vector<int>> graph[5];
int flag = true;
vector<int> check;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for(int r=0; i<K; i++){
        flag = true;
        cin >> V >> E;

        visited.resize(V+1,0);
        graph[r].resize(V+1);

        for(int i=0; i<=E; i++){
            int start, end;
            cin >> start >> endl;
            graph[r][start].push_back(end);
            graph[r][end].push_back(start);
        }

        //그래프가 다 연결된다는 보장은 없음
        for(int i=1; i<=V; i++){
            if(falg){
                DFS(i,r);
            }
            else{
                break;
            }
            //초기화 시켜준다.
        }
    

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

        // for(int i=0; i<=V ;i++){
        //     graph[i].clear();
        // }

        fill(visited.begin(), visited.end, false);
        fill(check.begin(), check.end(), 0);
    }

    return 0;
}

void DFS(int node, int r){
    visited[node] = true;

    for(int i: graph[r][node]){
        if(visited[i] == false){
            visited[i] = true;
            check[i] = (check[node]+1) %2;
            DFS(i,r);
        }
        //만약 방문했으면 전 노드와 같은 숫자인지 배교한다.
        else if(visited[i] == true){
            if(check[i] == check[node]){
                flag = false;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namesapce std;

int N,M;
int MinDistance= INT_MAX;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
bool visited[14] = {false,};

void calculate(void);
void do_it(int idx, int cnt);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; //N은 map 넓이, M은 치킨집개수
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];

            //집이면
            if(graph[i][j]==1){
                home.push_back(make_pair(i,j));
            }
            //치킨집이면
            else if(graph[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    //이제 치킨집 M개를 고른다.
    //고른것, depth표현
    do_it(0,0);
    cout << Mindistance << endl;
}

void calculate(void){
    int cityDistance =0;
    for(int i=0; i<home_size(); i++){
        //집에서 가장 가까운 치킨집을 찾아야함.
        int min_distance = INT_MAX;
        
        for(int j=0; j<chicken_size(); i++){
            if(visited[j] == false){
                continue;
            }
            int housDistance = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);

            if(houseDistance < min_distance){
                min_distance = houseDistance;
            }
        }
        cityDistance +=min_distance;
    }

    if(cityDistance < MinDistance){
        MinDistance = cityDistance;
    }
}

void do_it(int idx, int cnt){
    if(cnt == M){
        calculate();
        return;
    }

    for(int i=idx; i<chicken.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            do_it(i, cnt+1);
            visited[i]=false;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,N, sCity, eCity;
vector<long>mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistance.end(), LONG_MAX);

    for(int i=0; i<M; i++){
        int start, end, price; //이때 price는 교통비라고 생각한다.
        cin >> start >> end >> price;
        edges.push_back(make_pair(start, end, price));
    }

    for(int i=0; i<N; i++){
        cin >> cityMoney[i];
    }

    mdistance[sCity] = cityMoney[sCity];

    //충분한 사이클 돌 때동안 실행
    for(int i=0; i<=N+50; i++){
        //모든 edge에 대해서 탐색한다.
        for(int j=0; j<edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            //일단 연결은 되어 있어야지 가중치를 뽑을 수 있음
            if(mdistance[start] == LONG_MAX){
                continue;
            }

            else if(mdistance[start] == LONG_MAX){
                mdistance[end] = LONG_MAX;
            }

            //시작 노드가 양수 사이클에 연결된 노드라면 종료하고 아니면 mdistance
            if(mdistance[end] < mdistance[start] -weight + cityMoney[end]){
                mdistance[end] = mdistance[start]-weight + cityMoney[end];


                //만약 사이클을 충분히 돌았으면
                //이때 양수 사이클이 생기는 현상이 발생
                if(i >=N-1){
                    mdistance[end] = LONG_MAX;
                }
            }
        }

        if(mdistance[eCity] == LONG_MAX){
            cout << "gg"<<endl;
        }
        else if(mdistance[eCity] == LONG_MAX){
            cout << "Gee" << endl;
        }
        else{
            cout << mdistance[eCity]<<endl;
        }
    }
}
#endif

#if 0
//타임 머신문제
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namesapce std;

int N,M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N은 도시의 개수, M은 경로의 개수
    int N, M;
    cin >> N >> M;

    mdistance.resize(N+1,LONG_MAX);

    //출발이 1이니까 1를 0으로 초기화한다.
    mdistance[1]=0;

    //시작,도착, 가중치를 넣는다.
    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_pair(start, end, weight));
    }

    //이제 다 넣었으니 N-1만큼 반복한다.
    for(int i=1; i<N; i++){
        //모든 노드를 탐색한다.
        for(int j=0; j<M; j++){
            tuple<int,int,int> medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
                //작은 distance로 갱신한다.
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    //모든 노드를 갱신했다면 한번 더 사이클을 돌려서 가중치가 바뀌는지 본다.
    for(int j=0; j< M; j++){
        tuple<int,int,int> medges = eges[j];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start] != LONG_MA && mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }
    
    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif


#if 0
//잃어버린 괄호
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namesapce std;

vector<string> splite_minus;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    //입력 받으면 - 앞에서 문자열을 자른다.
    stringstream input_string;
    input_string.str(str);
    string type_string;

    //이제 - 기준으로 자른다.
    while(getline(input_string, type_string, '-')){
        //짤린게 string이다.
        //이제 getline 값이 나왔으면 저장한다.
        splite_minus.push_back(type_string);
    }

    int sum=0;
    //splite_minus에는 -기준으로 짤린 값이 들어가 있음
    //일단 맨 앞의 값은 더해야한다.
    stringstream front_string;
    front_string.str(splite_minus[0]);

    //맨 앞에꺼는 더해야된다.
    while(getline(front_string, type_string, '+')){
        //stirng을 int로 바군다.
        sum = sum + stoi(type_string);
    }

    //이제 맨앞의 꺼를 더했으면 뒤에 꺼를 더한다.

    for(int i=1; i<string_minus.size(); i++){
        stringstream temp_string;
        temp_string.str(string_minus[i]);
        int part_sum =0;

        while(getline(temp_string, type_string, '+')){
            part_sum = part_sum  + stoi(type_string);
        }
        sum = sum - part_sum;
    }

    cout << sum << endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

using namesapce std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    vector<int> A;
    A.resize(N+1);
    
    int start =0;
    int end =0;

    for(int i=0; i<N; i++){
        cin >> A[i];
        if(start < A[i]){
            //일단 길이가 제일 긴 동영상도 담아야하기 때문에 이렇게 설정
            start = A[i];
        }
        end = end + A[i];
    }

    //이분법을 사용해서 최적의 수를 찾는다.
    while(start <= end){
        int middle = (start + end)/2;
        int sum=0;
        int count=0;

        //middle값으로 모든 레슨을 저장할 수 있는지 확인한다.
        for(int i=0; i<N; i++){
            //만약 강의 시간이 middle수보다 크면
            if(sum + A[i] > middle){
                //블루레이를 한개늘린다. 그리고 sum을 0으로 만들어줌
                count++;
                sum =0;
            }
            //블루레이가 감당가능하면 sum에 강의 시간을 더한다.
            sum = sum + A[i];
        }

        //마지막 블루레이에서 sum!=0dlaus
        if(sum !=0){
            count++;
        }
        //count가 예상한 블루레이보다 크다면 블루레이 사이즈를 키워야한다.
        if(count > M){
            start = middle +1;
        }
        //count가 예상한 블루레이보다 작다면 블루레이 사이즈를 줄여야한다.
        //여기서 M도 포함한 이유는 최소 블루레이를 구하는 것이기 때문에 더 작은 것을 찾는다.
        else{
            end = middle-1;
        }
    }

    cout << start << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//BFS인가 DFS인가

using namespace std;

vector<vector<int>>graph;
vector<bool>viisted;
vector<int>answer;

void SEARCH_NODE(int start_vertex);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; //N은 컴퓨터 개수, M은 연결된 관계를 나타냄.

    graph.resize(N+1);
    answer.resize(N+1);
    visited.resize(N+1, false);

    for(int i=0; i<M; i++){
        int start, end; //start는 end을 신뢰한다.
        //즉 start가 신뢰하는 컴퓨터를 저장한다.
        cin >> start >> end;
        graph[start].push_back(end); //역으로 저장한다.
    }

    //놓친게 있을 수도 있기때문에 모든 노드 탐색
    for(int i=1; i<=N; i++){
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
    queue<int>myqueue; //BFS를 푼다.

    visited[start_vertex] = true;

    myqueue.push(start_vertex);

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();
        for(int i: graph[current]){
            if(visited[i] == false){
                visited[i] = true;
                answer[i]++;
                myqueue.push(i);
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

//k번째 경로를 찾자
int N,M,K;

vector<int>visitied;
//vector<tuple<int,int,int>> graph;
vector<vector<pair<int,int>>> graph;
vector<int> mdistance;

//작은게 우선순위에 와야함
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pd;

//이건 내림차순이어야함.
//노드수가 1001개 이니까 1001개로 설정
priority_queue<int, vector<int>, less<int>> disQueue[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>> N >> M >> K;

    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;

        //모든 정보를 저장한다.
        graph[start].push_back(make_pair(end,weight));
    }

    //일단 초기화는 최대로 설정한다.
    mdistance.resize(N+1, INT_MAX);

    pd.push(make_pair(0,1)); //일단 1번 노드가 시작점이다.
    //여기서 mdistance는 필요하지 않는듯?
    disQueue[1].push(0); //우선순위큐에 0을 넣어준다.

    while(!pd.empty()){
        //이제 제일 작은거를 뽑는다.
        pair<int,int> u = pd.top();
        int distance = u.first;
        int now_node = u.second;

        //한개를 빼줌
        pd.pop();

        //now에 연결된 시작노드에 end node를 다 탐색
        //tuple로 저장했으니까 start가 now_node인 것부터찾는다
        for(pair<int,int> p : graph[now_node]){
            int end = p.first;
            int weight = p.second;

            //만약 지정된 경로가 k가 안됐으면 저장함
            if(disQueue[end].size() < K){
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distance + weight, end));
            }

            //만약 저장된 개수가 현재 가장 큰 값보다 작을때만 추가
            else if(disQueue[end].size() >=K){
                //만약 더 작으면 추가해준다.
                if(disQueue[end].top() > distance + weight){
                    disQueue[end].pop();
                    disQueue[end].push(distance+weight);
                    pd.push(make_pair(distance + weight , end));
                }
            }
        }
    }
    // 다 탐색했으면
    for(int i=1; i<=N; i++){
        if(disQueue[i].size() == K){
            cout<<disQueue[i].top() << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namesapce std;

vector<int> degree;
vector<int> setbuild;
vector<vector<int>> graph;
vector<int>goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

        while(1){
            int prebuild;
            cin >> prebuild;
            
            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                degree[i]++;
            }
        }
    }

    //이제 위상정렬이 완성됨
    queue<int> myqueue;

    for(int i=1; i<=N;i++){

        if(degree[i]==0)
            myqueue.push(i);
    }

    //이제 push된 것부터 출력해 준다. 그리고 queue가 빌때까지 출력한다.
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int i : graph[now]){
            degree[i]--;
            
            if(degree[i]==0){
                myqueue.push(i);
            }

            //그 다음 해당 노드 현재 상태이다. setbuild를 더해준다.
            goal[node]=max(goal[node], goal[node] + setbuild[now]);
        }
    }

    //이제 모든 노드에 자기 자신의 setbuid를 도해준다.
    for(int i=1; i<=N; i++){
        goal[i] = goal[i] + setbuild[i];
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>>A[10];
long minn; //최소 공배수 저장
bool visited[10];
long D[10]; //최소가 되는 재료량을 저장한다.

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn=1;

    //input을 입력한다.
    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        //a*b의 최소공배수는 a*b/최대공약수이다.
        minn = minn * (p*q)/gcd(p,g);
    }

    //0번 재료부터 순서대로 공백으로 구분해서 출력해야 하기 때문에
    D[0] = minn;
    DFS(0); //이제 연결되어 있는 정보를 본다.

    //이제 최소공배수를 곱한다.
    for(int i=1; i<N; i++){
        //모든 수의 최대공약수를 구한다.
        minn = gcd(minn, D[i]);
    }

    for(int i=0; i<N; i++){
        D[i] = D[i] / minn;
        cout<< D[i] << endl;
    }


    return 0;
}

void DFS(int node){
    visited[node] = true;
    
    for(tuple<int,int,int> i : A[node]){
        if(!visited[graph<0>(i)]){
            D[get<0>(i)] = D[node] * get<2>(i) / (get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}
long gcd(long a, long b){
    if(b==0){
        return a;
    }
    return gcd(b,(a%b));
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int MAX_N = 22;
int MAX_DEPTH =3;
bool visited[MAX_N][MAX_N];
int n,m;
int graph[MAX_N][MAX_N]={0,};
vector<pair<int,int>> friends;

vector<vector<vector<pair<int,int>>>> paths;

//친구 각각에 대한 최단 경로를 구한다.
void dfs(int x, int y, int depth, vector<[pair<int,int>> & current_path, vector<vector<pair<int,int>>>& all_paths]){
    if(depth == MAX_DEPTH){
        all_paths.push_back(current_path);
        return;
    }

    for(int dir=0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx>=1 && nx <=n && ny >=1 && ny <=n && !visited[nx][ny]){
            visited[nx][ny] = true;
            current_path.push_back(make_pair(nx,ny));
            dfs(nx,ny,depth+1, current_path, all_paths);
            //depth가 4개인 것을 pop해준다. vector는 후입선출이다.
            visited[nx][ny] = false;
            //맨 앞의 요소를 pop_back 해준다.
            current_path.pop_back();
            //다 해주면 결구 모든 current_paths는 pop_back된다.
        }
    }
}



int calculate(vector<vector<pair<int,int>>> & chosen_paths){
    int harvest=0;
    int temp_graph[MAX_N][MAX_N]={0,};

    for(int i=1; i<-n ; i++){
        for(int j=1; j<=n; j++){
            temp_graph[i][j] = graph[i][j];
        }
    }

    for(vector<pair<int,int>> & path : chsoen_paths){
        for(pair<int,int> &p : path){
            int x = p.first;
            int y = p.second;
            harvest +=temp_graph[x][y];
            temp_graph[x][y] =0;
        }
    }
}


//최대 수확하는 길을 탐색한다.
void findMAxHarvest(int idx, vecotr<vecotr<pair<int,int>>> & chosen_path, int & max_harvest){
    if(idx ==m){
        max_harvest = max(max_harvest, calculateHarvest(chosen_paths));
        return;
    }

    //각각 참여자으 path인 4칸을 찾는다.
    for(vector<pair<int,int>> & path : path[idx]){
        chosen_paths.push_back(path);
        findMaxHarvest(idx+1, chosen_path, max_harvest);
        chsoen_paths.pop_back();
    }
}

int dx[4]={-1,0,1,0};
int dy[4] = {0,1,-1,0};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    friends.resize(m);
    paths.resize(m);

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        friends.push_back(make_pair(x,y));
        vector<pair<int,int>> current_path;
        current_path.push_back(make_pair(x,y));
        vector<vector<pair<int,int>>> all_paths;
        dfs(x,y,0,current_path, all_paths);
        path[i] = all_paths;
    }


    int max_harvest =0;

    vector<vector<pair<int,int>>> chosen_paths;
    findMaxharvest(0, chosen_path, max_harvest);

    cout << max_harvest << endl;

    return 0;
}
#endif

#if 0
//다익스트라
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

uisng namespace std;

int N;
int MAP[51][51]={0,};
int visited[51][51]={false,};
int dist[51][51];

int dx[4]= {0,-1,0,1};
int dy[4]={-1,0,1,0};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int, pair<int,int>> & b){
        return a.first > b.first; //오름 차순이다. 
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //미로 사이즈를 입력한다.
    string a;
    for(int i=0; i<N; i++){
        cin >> a;

        for(int j=0; j<N; j++){
            MAP[i][j] = a[j] -'0';
            MAP[i][j] ^=1;
        }
    }

    for(int i=0; i<N; i++){
        fill(dist[i], dist[i]+N, INT_MAX);
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pd;

    pd.push(make_pair(0,make_pair(0,0)));

    dist[0][0] =0; //벽의 개수를 구한다.

    while(!pd.empty()){
        int cost = pd.top().first;
        pair<int,int> cur = pd.top().second;
        pd.pop();

        if(visited[cur.first][cur.second]==true){
            continue;
        }

        visited[cur.first][cur.second]= ture;

        for(int i=0; i<4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx >=N || ny<0 || ny >=N){
                continue;
            }

            if(dist[cur.first][cur.second] + MAP[nx][ny] < dist[nx][ny]){
                dis[nx][ny] = dis[cur.first][cur.second] + MAP[nx][ny];
                pd.push(make_pair(dist[nx][ny, make_pair(nx,ny)]));
            }
        }
    }



    return 0;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
int MAP[51][51] = {0,};
int visited[51][51] = {false,};
int dist[51][51];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int,pair<int,int>> &b){
        //return a.first < b.first; //내림차순임.
        return a.first > b.first; //오름차순
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //미로 사이즈를 입력한다.
    string a;

    for(int i=0; i<N; i++){
        cin >> a;

        for(int j=0; j<N; j++){
            MAP[i][j] = a[j] -'0';
            MAP[i][j] ^=1;
        }
    }

    for(int i=0; i<N; i++){
        fill(dist[i], dist[i]+N, INT_MAX);
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>, compare> pd;
    pd.push(make_pair(0,make_pair(0,0)));

    dist[0][0]=0; //벽의 개수를 저장한다.

    while(!pd.empty()){
        int cost = pd.top().first;
        pair<int,int> cur = pd.top().second;
        pd.pop();

        if(visited[cur.first][cur.second] == true){
            continue;
        }

        for(int i=0; i<4; i++){
            //좌표를 나타낸다.
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //범위를 넘어가면 continue
            if(nx < 0 || nx >=N || ny <0 || ny >=N){
                continue;
            }

            //원래보다 크면 넣어준다.
            if(dist[cur.first][cur.second] + MAP[nx][ny] < dist[nx][ny]){
                pd.push(make_pair(dist[nx][ny],make_pair(nx,ny));)
            }
        }
    }

    cout << dist[N-1][N-1] << endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[52][52] = {0,};
int visited[52][52]= {0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void DFS(int i, int j);

int M, N, K;// M은 가로길, N은 세로길이, K는 배추가 심어져있는 개수

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int i=1; i<=T; i++){
        //가로 세로 양배추가 심어져 있는 개수를 입력한다.
        cin >> M >> N >> K;
        int cnt =0; //각 T마다 배추희지렁이 개수를 구한다.

        for(int z=0; z<K ;z++){
            int y,x;
            cin >> y >> x;
            arr[x+1][y+1] =1; //배추가 심어져 있는 개수를 구한다.
        }


        //일단 세로구하고 가로를 해주낟.
        for(int n=1; n<=N ;n++){
            for(int m=1; m<=M; m++){
                if(arr[n][m] == 1){ //만약 양상추가 있다면
                   
                    DFS(n,m);
                    cnt++; //배추 흰 지렁이 개수를 더해준다.
                }
            }
        }

        //다 구했으면 cnt 출력해준다.
        cout << cnt << endl;

        for(int i=1; i<=N ;i++){
            fill(visited[i], visited[i]+(M+1), 0);
            fill(arr[i], arr[i] + (M+1), 0);
        }
    }

}

//이제 DFS를 구현해준다.

void DFS(int i, int j){

    visited[i][j] = 1;

    arr[i][j]=0;

    for(int r=0; r<4 ;r++){
        int nx = i + dx[r];
        int ny = j + dy[r];


        if(nx <= 0 || nx > N || ny <= 0 || ny > M ){
            continue;
        }

        if(visited[nx][ny]==true){
            continue;
        }

        if(arr[nx][ny]==1){ //왜 && 써야하냐 ?
            DFS(nx,ny);
        }

    }

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pai<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K; //K는 start node이다.

    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    visited.resize(V+1,false);
    //vertext개수 만큼 resize를 해준다.
    mlist.resize(V+1);

    for(int i=0; i<E;i++){
        //인제 start, end, weight를 넣어준다.
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(u,w);
    }

    //이제 연결해준다.
    //처음 거리는 0, start node를 넣어줌.
    myqueue.push(make_pair(0,K));
    mdistnace[K]=0;

    while(!myqueue.empty()){
        pair<int,int> current;
        int distance = current.first;
        int node_number = current.second;
        myqueue.pop();

        //만약 방문한 노드였으면 continue를 해준다.
        if(visited[node_number]== true){
            continue;
        }

        visited[node_number] = true;

        for(pair<int,int> node & mlist[node_number]){
            int end = node.first;
            int node_weight = node.second;
            if(mdistance[end] > mdistance[node_number] + node_weight){
                mdistance[end] = mdistance[node_number] + node_weight;

                //아제 커진것으 push 해준다.
                myqueue.push(make_pair(mdistance[end], end));
            }
        }
    }
}
#endif

#if 0
//N-Queen 문제
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

bool condition(int i);
void queen_N(int i);
int result =0;
int col[N];

int main(void){
    cin >> N; //MAP 정보를 넘겨준다.

    queen_N(0);
    cout << result << endl;
    return 0;
}

bool condition(int i){
    for(int k=0; k<i; i++){
        if(col[i]== col[k] || i-k == abs(col[i] - col[k])){
            return false;
        }
    }
    return true;
}

//queen_N구현
void queen_N(int i){
    if(i==N){
        result++;
        return;
    }

    for(int j=0; j<N; j++){
        col[i] = j; //모든 열을 넣어줌

        //condition을 만족하면 i를 늘려줌
        if(condition(i)){
            queen_N(i+1);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//A:0, B:1, C:2
int A,B,C;
//총 3개니까 경우의 수는 6개이다.
int send[6] = {0,0,1,1,2,2};
int receive[6]={1,2,0,2,0,1};

int bottle[3]={0,};
int full_standard[3];
vector<int> answer;
//처음에는 모든 visited을 방문하지 않았기 때문에 이렇게 설정한다.
bool visited[201][201] = {false};
int MAX;

void BFS();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++){
        cin >> full_standard[i];
    }

    BFS();  

    //기본 값이 오름차순이다.
    sort(answer.begin(),answer.end(),greater<int>());

    for(int i: answer){
        cout << i <<" ";
    }

    return 0;
}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0)); //A,B의 물의 양은 처음에는 0이다.
    visited[0][0] = true;

    while(!myqueue.empty()){
        int current[3];

        //현재 남은 병의 용량을 나타낸다.
        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];

        visited[current[0]][current[1]] = true;

        //만약 a의 물병이 비었다면 c물병의 용량을 구한다.
        if(current[0]==0){
            answer.push_back(current[2]);
        }

        myqueue.pop();

        for(int i=0; i<6; i++){
            int next[3];
            next[0] = current[0];
            next[1] = current[1];
            next[2] = current[2];

            int ns = send[i];
            int nr = receive[i];

            next[nr] = current[nr] + current[ns];
            next[ns] =0;

            if(next[nr] > full_standard[nr]){
                int rest = next[nr] - full_standard[nr];
                next[ns] = rest;
                next[nr] = full_standard[nr];
            }

            if(!visited[next[0]][next[1]]){
                myqueue.push(make_pair(next[0], next[1]));
                visited[next[0]][next[1]] = true;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b);
void swap(int &a, int & b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t ; i++){
        int a,b;
        cin >> a >> b;
        int result = a*b / gcd(a,b); //최소공배수를 구하는 식임
        cout << result << endl;
    }
    return 0;
}

int gcd(int a, int b){
    int Max = a;
    int pre_result = b;
    int result = 1;

    while(1){
        if(result ==0){
            return pre_result;
        }

        if(Max < pre_result){
            swap(Max, pre_result);
        }
        result = Max % pre_result;
        
        Max = pre_result;

        if(result !=0){
            pre_result = result;
        }
    }
}

void swap(int &a, int &b){
    int tmep = a;
    a =b;
    b = temp;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limists.h>

usig namespace std;

struct compare{
    bool operation()(int &a, int &b){
        if(a<B){ //우선순위 큐에서는 내림차순이다.
            return true;
        }
        else{
            return false;
        }
    }
};

int N,M,K;

vector<int>visited;
vector<vector<pair<int,int>>> graph;
vector<int> mdistnace;

//작은게 우선순위에 와야함, default는 first 기준이다.
priority_queue<pair<int,int<, vector<pair<int,int>>, compare> pd;
//내림차순 정렬해야한다.
priority_queue<int, vector<int>, greater<int> disQueue[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    grap.resize(N+1);

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        //모든 정보를 저장한다.
        graph[start].push_back(make_pair(end,weight));
    }

    mdistance.resize(N+1, INT_MAX);

    pd.push(make_pair(0,1)); //여기선 0은 가중치이고 1은 시작 노드이다.
    disQueue[1].push(0);

    while(!pd.empty()){
        pair<int,int> u = pd.top();
        int now = u.second;
        int distance = u.first;

        pd.pop();

        //now에 연결된 시작노드에 end node를 다 탐색한다.
        for(pair<int,int> node1 : graph[now]){
            int end = node1.first;
            int weight = node1.second;

            //저장된 경로가 K개가 안됐을때 그냥 추가하기
            if(disQueue[end].size()<K){
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distnace+weight, end));
            }

            //만약 저장된 개수가 K개면
            else if(disQueue[end].size() >= K && disQueue[end].top() > distnace + weight){
                disQueue[end].pop();
                disQueue[end].push(distnace + weight);
                pd.push(make_pair(distnace+weight, end));
            }
        }

        for(int i=1; i<=N; i++){
            if(disQueue[i].size() == K){
                cout << disQueue[i].top() << endl;
            }
            else{
                cout << -1 << endl;
            }
        }

    }


}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namesapce std;

int N, M;
int MinDistance = INT_MAX;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
//선택된 치킨집을 말한다.
bool visied[14] = {false,};

void calculate(void);
void select_chicken(int idx, int cnt);

//0은 빈칸, 1 은 집, 2는 치킨집이라고 가정한다.
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];
            //집ㅇ미ㅕㄴ
            if(graph[i][j]== 1){
                home.push_back(make_pair(i,j));
            }
            //치킨집이면
            else if(graph[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    //이제 치킨집 M개를 고르면된다.
    //치킨집 M개를 고른후 집까지의 거리를 계산해준다.
    do_it(0,0);

    cout << Mindistance << endl;

    return 0;

}

void calculate(void){
    int cityDistance =0;
    ffor(int i=0; i< house.size(); i++){
        //집에서 가장 가까운 치킨집을 고른다.
        int min_Distance = int_MAX;
        for(int j=0; j<chicken.size(); j++){
            if(visited[j]== false){
                continue;
            }

            int houseDistance = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
            if(houseDistance < min_Distance){
                min_distnace = houseDistance;
            }
        }
        cityDistance +=min_distance;
    }
    if(cityDistance < MinDistance){
        MinDistance = cityDistance;
    }
}

void select_chicken(int idx, int cnt){
    //다 골랐으면
    if(cnt == M){
        //계산을 해준다.
        calculate();
        return;
    }

    //치킨 3개를 동시에 고른다.
    //중요 i를 idx로 둠
    for(int i= idx; i < chicken.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            //M개를 고르면 return된다.
            do_it(i, cnt+1);
            visited[i] = false;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namesacpe std;

struct compare{
    bool operator()(pair<int,pair<int,int>> &a , pair<int,pair<int,int>> & b){
        return a.first > b.second; //오름차순으로 정렬을 한다. priority queue 한정
    }
};

int N;
int MAP[51][51]={0,};
int visited[51][51] = {false,};
int dist[51][51];

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //미로사이즈를 입력한다.
    string a;

    for(int i=0; i<N; i++){

        cin >>a;
        
        for(int j=0; j<N; j++){
            MAP[i][j] = a[j] -'0';
            MAP[i][j] ^=1;
        }
    }

    for(int i=0; i<N; i++){
        fill(dist[i], dist[i]+N, MAX_INT);
    }
    //초기 니까 모든 거리의 거리값을 무한대로 설정한다.

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> myqueue;

    //시작점에서는 거리 0을 넣는다.왜나하면 거리가 0이기 때문이다.
    myqueue.push(make_pair(0,make_pair(0,0)));

    dist[0][0] = 0;

    while(!myqueue.empty()){
        int cost = myqueue.top().first;
        pair<int,int> cur = myqueue.top().second;
        myqueue.pop();

        if(visited[cur.first][cur.second]==true){
            continue;
        }

        visited[cur.first][cur.seoncd]=true;

        for(int i=0; i<4; i++){
            //좌표를 나태낸다.
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //범위를 넘어가면 continue를 하낟.
            if(nx <0 || nx >=N || ny <0 || ny >=N){
                continue;
            }

            //원래 보다 자긍면 넣어준다.
            if(dist[cur.first][cur.second] + MAP[nx][ny] < dist[nx][ny]) {
                dist[nx][ny] = dist[cur.first][cur.second] + MAP[nx][ny];
                myqueue.push(make_pair(dist[nx][ny] , make_pair(nx,ny)));
            }
        }
    }

    cout << dist[N-1][N-1] << endl;
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &A, pair<int,int> & B){
        if(A.first > B.first){
            //오름차순으로 정렬한다.
            rturn true;
        }
        else{
            return false;
        }
    }
};

struct compare1{
    bool operator()(int &a, int &b){
        if(A.first < B.first){ //priority queue일때 내림 차순 정렬을 한다.
            return true;
        }
        else{
            return false;
        }
    }
};

int N,M,K;

vector<int> visited;
vector<vector<pair<int,int>>> graph;
vector<int> mdistance;

//작은게 우선순위에 와야됨.
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pd;

//내림차순 정렬해야된다.
priority_queue<int,vector<int>,compare1> disQueue[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int start, end, weight;

        cin >> start >> end >> weight;

        graph[start].push_back(make_pair(end,weight));
    }

    mdistance.resize(N+1, INT_MAX);

    pd.push(make_pair(0,1)); //여기선 0은 가중치이고 1은 시작 노드이다.
    disQueue[1].push(0);

    while(!pd.empty()){
        pair<int,int> u = pd.top();
        int now = u.second;
        int distance = u.first;

        pd.pop();

        //now에 연결된 시작노드에 end node를 다 탐색한다.
        for(pair<int,int> node1 : graph[now]){
            int end = node1.first;
            int weight = node1.second;

            //저장된 경로가 K개가 안됐을때 그냥 추가하기
            if(disQeuue[end].size() < K){
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distance + weight, end));
            }

            //만약 저장된 개수가 K개일때 현재 가장 큰 값보다 작을때만 추가하기
            else if(disQueue[end].size() >=K && disQueue[end].top() > distance + weight){
                disQueue[end].pop();
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distance + weight, end));
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(disQueue[i].size() == K){
            cout << disQueue[i].top()<< endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int>parent;
vector<int>trueP;
vector<vector<int>> party;
int result;
void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >> T;
    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin >> tureP[i];
    }
    party.resize(M);

    for(int i=0; i<M;i++){
        int party_size;
        cin >> party_size;

        for(int j=0; j<party_size; j++){
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<=N ;i++){
        parent[i] = i;
    }

    //첫번째 사람을 다 넣어서 연관성을 확인해 본다.
    for(int i=0; i<M;i++){
        int firstPeople = party[i][0];
        for(int j=1; j< party[i].size(); j++){
            unionfunc(fisrtPeople, party[i][j]);
        }
    }

    //이제 유니온을 다햇으면 거짓말을 할 수 있는 파티를 확인한다.
    for(int i=0; i<M; i++){
        bool isPosible = true;
        int cur = party[i][0];
        for(int j=0; j<T; j++){
            if(find(cur) == find(tureP[i])){
                isPsoible = false;
                break;
            }
        }

        if(isPossible){
            result++;
        }
    }
    cout << result;

    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int>> party;
int result;
void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >> T;

    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin >> trueP[i];
    }

    party.resize(M);

    for(int i=0; i<M; i++){
        int party_size;
        cin >> party_size;

        for(int j=0; j<party_size; j++){
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<=N; i++){
        parent[i]=i;
    }

    for(int i=0; i<M; i++){
        int firstPeople = party[i][0];
        
        for(int j=1; j< party[i].size(); j++){
            unionfunc(firstPeople, party[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        bool isPossible = true;
        int cur = party[i][0];

        for(int j=0; j<T; j++){
            if(find(cur) == find(tureP[i])){
                isPossible = false;
                break;
            }
        }

        if(isPossibel){
            result++;
        }
    }

    cout << result;
}

void unionfunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b] = a;
    }
}

int find(int a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &a, pair<int,int>& b){
        return a.first > b.first;// 오름차순으로 정렬함 우선순위 queue 한정
    }
};

vector<bool>visited;
vector<long>mdistance;

vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin >> N >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    //M은 버스의노선의 개수 즉 edge 개수이다.
    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    int start, end;
    cin >> start >> end;

    mdistance[start] =0;

    myqueue.push(make_pair(0,start));

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now_first;
        int now_node = now.second;

        myqueue.pop();

        if(visiteid[now_node] == 1){
            continue;
        }

        visited[now_node] = true;

        for(pair<int,int> i : mlist[now_node]){
            int next_node = i.first;
            int next_value = i.second;

            if(mdistance[next_node] > mdistance[now_node] + next_value){
                mdistance[next_node] = mdistance[now_node] + next_value;

                myqueue.push(make_pair(mdistance[next_node], next_node);
            }
        }
    }

    if(visited[end] == true){
        cout << mdistance[end] << endl;
    }

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);

    mdistance[1]=0;

    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start, end, weight));
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<M; j++){
            tuple<int,int,int>medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            if(mdistance[start]!=LONG_MAX && mdistance[end] > mdistance[start]+wegiht){
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    for(int j=0; j<M; j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0>(medges);
        int end = get<1> (medges);
        int weight = get<2> (medges);

        if(mdistance[start]! = LONG_MAX && mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
        else{
            for(int i=2; i<=N ;i++){
                if(mdistance[i] == LONG_MAX){
                    cout << -1 << endl;
                }
                else{
                    cout << mdistance[i]<<endl;
                }
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
void swap_value(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_value(char *s1, char *s2){
    int len;

    len = (strlen(s1) >= strlen(s2)) ? strlen(s1) : strlen(s2);
    cout << len << endl;
    char * temp = new char[len+1];

    strcpy(temp, s1);
    strcpy(s1,s2);
    strcpy(s2, temp);
    delete[] temp;
}

int main(void){
    int x=10, y= 20;
    swap_value(x,y);
    cout << x << y << endl;

    char s1[100] = "this is a first stringaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char s2[100] = "this is a second string";
    swap_value(s1,s2);
    cout << s1 << "  " <<s2 << endl;
    return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

template <typename T>
class Box{
    T data; //T는 타입(Type)을 나타낸다.
public:
    Box(){

    }
    void set(T value){
        data = value;
    }
    T get(){
        return data;
    }
};

int main(void){
    Box<int> box;
    box.set(100);
    cout << box.get() << endl;

    Box<double> box1;
    box1.set(3.1412);
    cout << box1.get() << endl;

    return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

template <typename T1, typename T2>

class Box2{
    T1 first_data;
    T2 second_data;

    public:
        Box2(){}
        T1 get_first();
        T2 get_second();
        void set_first(T1 value);
        void set_second(T2 value);
};

template <typename T1, typename T2>
T1 Box2<T1,T2>::get_first(){
    return first_data;
}

template <typename T1, typename T2>
T2 Box2<T1,T2> ::get_second(){
    return second_data;
}

template<typename T1, typename T2>
void Box2<T1,T2> :: set_first(T1 value){
    first_data = value;
}

template<typename T1, typename T2>
void Box2<T1,T2> :: set_second(T2 value){
    second_data = value;
}

int main(void){
    Box2<int, double> b;
    b.set_first(10);
    b.set_second(3.14);
    cout << "(" << b.get_first() << ")" << endl;
    return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

class Coord2D
{
protected:
    int x;
    int y;
public:
    Coord2D(int _x, int _y):x(_x),y(_y){}
    ~Coord2D(){
        cout << "hello" << endl;
    }
    void showCoord2D();
};

void Coord2D::showCoord2D(){
    cout << x << " " << y << endl;
}

class Coord3D : public Coord2D
{
private:
    int x;
public:
    Coord3D(int _x, int _y, int _z):Coord2D(_x,_y),z(_z){}
    ~Coord3D(){
        cout << "deconstructor" << endl;
    }

    void showCoord3D();
};

void Coord3D :: showCoord3D(){
    showCoord2D();
    cout << " ," << z << endl;
}

int main(void){
    Coord3D temp(10,20,30);
    temp.showCoord3D();

    return 0;
}

#include <iostream>

using namesapce std;

template <typename T1, T2>

class Box2{
    T1 first_data;
    T2 second_data;

    public:
        Box2(){}
        T1 get_first();
        T2 get_second();
        void set_first(T1 value);
        void set_second(T2 value);
};

template <typename T1, typename T2>
T1 Box2<T1,T2>::get_first(){
    return first_data;
}

template <typename T1, typename T2>
T2 Box2<T1,T2>::get_second(){
    return second_data;
}

template<typename T1, typename T2>
void Box2<T1,T2> :: set_first(T1 value){
    first_data = value;
}

template <typename T1, typename T2>
void Box2<T1,T2> :: set_second(T2 value){
    second_data = value;
}

int main(void){
    Box<int, double> b;
    b.set_first(10);
    b.set_second(3.14);
    cout << "(" << b.get_first() << ")" << endl;
    
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int MinDistance = 999999;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
//선택된 치킨집을 의미함
bool visited[14]={false,};

void calculate(void);
void do_it(int idx, int cnt);

//0 : 빈칸, 1 : 집, 2 : 치킨집
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];

            //집이면 
            if(graph[i][j] == 1){
                home.push_back(make_pair(i,j));
            }
            //치킨집이면
            else if(graph[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    //이제 치킨집 M개를 고른다.
    do_it(0,0); //일단 고른게 0개, 인덱스 0부터시작
    cout << MinDistance <<endl; //최종 결과를 출력한다.

    return 0;
}

void calculate(void){
    int cityDistance=0;
    
    for(int i=0; i<home.size(); i++){
        //집에서 가장가까운 치킨집을 찾아야함.
        int min_distance = 9999999;
        for(int j=0; j<chicken.size(); j++){
            if(visited[j] == false){
                continue;
            }
            int houseDistance = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);

            if(houseDistance < min_distance){
                min_distance = houseDistance; //각 집마다 가장가까운 치킨집을 찾는다.
            }
        }
        cityDistance +=min_distance;
    }

    if(cityDistance < MinDistance ){
        MinDistance = cityDistance;
    }
}

void do_it(int idx, int cnt){
    if(cnt==M){//치킨집은 3개를 고르기 때문에
        calculate();
        return;
    }

    //이제 3개를 고르면된다. 중복 x, 순서 x
    //치킨집을 3개 고른다.
    for(int i=0; i<chicken.size(); i++){
        if(visited[i] == true){
            continue;
        }
        visited[i] = true;
        do_it(i,cnt+1);
        visited[i]= false; //선택되었으면 풀어준다.
    }
}
#endif

#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &A, pair<int,int> & B){
        if(A.first > B.first){ //오름차순으로 정렬한다.
            return true;
        }
        else{
            return false;
        }
    }
};

struct compare1{
    bool operator()(int &a, int &b){
        if(a < b){ //내림차순 정렬한다.
            return true;
        }
        else{
            return false;
        }
    }
};

int N,M,K;

vector<int> visited;
vector<vector<pair<int,int>>> graph;
vector<int> mdistance;

//작은게 우선순위가 높아야한다.
priority_queue<pair<pair<int,int>, vector<pair<int,int>>, compare> pd;
priority_queue<int, vector<int>, compare1> disQueue[1001]; //이거는 내림차순이 우선순위이다.

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;

        //모든 정보를 저장한다.
        graph[start].push_back(make_pair(end,weight));
    }

    mdistance.resize(N+1, INT_MAX);

    pd.push(make_pair(0,1)); //0은 가중치이고, 1은 시작 노드이다.
    disQueue[1].push(0);

    while(!pd.empty()){
        int start_node = pd.top().second;
        int next_distance = pd.top().first;

        pd.pop(); //정보를 뽑았으면 pop을 해준다.

        //start_node에 연결되엉 있는 노드들을 다탐색한다.
        for(pair<int,int> node1 : graph[start_node]){
            int end = node1.first;
            int next_weight = node1.second;

            //만약 disQueue 사이즈가 K보다 작으면 그냥 넣어준다.
            if(disQueue[end].size() < K){
                pd.push(make_pair(next_distance + next_weight, end));
                disQueue[end].push(next_distance + next_weight);
            }
            else if(disQueue[end].size() >= K && disQeueu[end].top() > next_distance + next_weight){
                disQueue[end].pop();
                disQueue[end].push(next_distance + next_weight);
                pd.push(make_pair(next_distance + next_weight, end));    
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(disQueue[i].size() == K){
            cout << disQueue[i].pop() << endl;
        }
        else{
            cout << -1 <<endl;
        }
    }
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>degree;
vector<int>setbuild;
vector<vector<int>>graph;
vector<int>goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        setbuild[i] = time;

        //이제 우선순위 건물을 비교해줘야함
        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                degree[i]++; //먼저 지어지는 건물이 있으면 ++을 해줘서 우선순위를 낮춤
            }
        }
    }

    //이제 위상정렬을 세운다.
    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i]==0){ //우선순위가 가장 높은 것부터 해준다.
            myqueue.push(i);
        }
    }

    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node : graph[now]){
            degree[node]--;

            if(degree[node]==0){
                myqueue.push(node);
            }

            goal[node] = max(goal[node], goal[now] + setbuild[now]);
        }
    }

    //이제 모든 노드에 자기 자신의 시간을 더해준다.
    for(int i=1; i<=N; i++){
        goal[i] = goal[i] + setbuild[i];
        cout << goal[i]<<endl;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namesapce std;

vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while(getline(mystream, splitdata, delimeter)){
        result.push_back(splitdata);
    }

    return result;

    //-기준으로 짜르고 짤린것은 string이니까
    while(getline(mystream, splitdata, delimeter)){
        result.push_back(splitdata);
    }
    return result;
}

int mysum(strina a){
    int sum=0;
    vector<string> temp = split(a,'+');
    for(int i=0; i<temp.size(); i++){
        sum  stoi(temp[i]);
    }
    return sum;
}

int mysum(string a){
    int sum=0;
    vector<string> temp = split(a,'+');
    
    for(int i=0; i<temp.size();i++){
        sum = stoi(temp[i]);
    }
    return sum;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <cstriing>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter);
int mysum(string a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer =0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');

    for(int i=0; i<str.size(); i++){
        int temp = mysum(str[i]);
        if(i==0){
            answer = answer + temp; 
        }
        else{
            answer = answer - temp;
        }
    }
    cout << answer << endl;
}

vector<string> split(string input, char delimiter){
    stringstream str(input);
    string str1;
    vector<string> save_string;

    while(getline(str,str1,delimiter)){
        save_string.push_back(str1);
    }

    return save_string;
}

int mysum(string a){
    //여기서는 짜른 걸 더한다.
    vector<string> partial_sum;
    partial_sum = split(a,'+');
    int partial_suml=0;

    for(int i=0; i<partial_sum.size();i++){
        partial_sum1 += stoi(partial_sum[i]);
    }
    return partial_sum1;
}
#endif

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

#if 0
#include <iostream>
#include <queue>

using namespace std;

void swap(int *data,int start, int end){
    int temp = data[start];
    data[start] = data[end];
    data[end] = temp;
}

void quick_sort(int *data, int start, int end){
    int pivot = start;
    int low = start +1;
    int high = end;

    if(start >= end){
        return;
    }
    
    //만약 start랑 end가 같아지면 안됨.
    while(low <= high){
        cout << "hello1" << endl;
        while(data[low] <= data[pivot] && low <= end){
            low++;
            cout << "hello1" << endl;
        }
        while(data[high] >= data[pivot] && high >= start+1){
            high--;
        }
        if(low < high){
            swap(data,low,high);
        }
    }
    swap(data,high,pivot);
    //cout << "hello" << endl;
    quick_sort(data, start, high-1);
    quick_sort(data, high+1, end);
}

int main(void){
   int data[] = {23,32,34,100,87,76,23,65,2,90,21,1,3};
   int sz = sizeof(data)/sizeof(data[0]);
   quick_sort(data,0,sz-1);

   for(int i : data){
        cout << i << " ";
   }
   cout << endl;

    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>

using namespace std;

void do_merge(int *data, int start, int mid, int end, int *tarray){
    int lstart = start;
    int rstart = mid+1;
    int lend = mid;
    int rend = end;
    int i = start;
    int j = rstart;
    int t = start;

    //merge sort를 진행한다. 비교를 시작한다.
    while(1){
        if(i > lend && j > rend){
            break;
        }

        //이미 왼쪽은 다 넣었으면 오른쪽만 넣으면된다.
        if(i > lend){
            tarray[t] = data[j];
            t++;
            j++;
        }
        else if(j > rend){
            tarray[t] = data[i];
            t++;
            i++;
        }
        
        //이제 비교를 해줘야한다.
        //오름차순 정렬을 기준으로 한다.
        else{
            if(data[i] > data[j]){
                tarray[t] = data[j];
                j++;
                t++;
            }
            else{
                tarray[t] = data[i];
                i++;
                t++;
            }
        }
    }

    //tarray에 모든 정보를 넣어 줬음
    //복사된 것을 이제 원본에 넣어줘야한다.
    for(int i=start; i<=end; i++){
        data[i] = tarray[i];
    }
    cout << endl;
}

void merge_sort(int *data, int start, int end, int *tarray){
    int cnt=0;

    if(start == end){ //1개일 때는 return을 해줌
        return;
    }
    
    merge_sort(data, start, (start+end)/2, tarray);
    merge_sort(data, (start+end)/2+1, end, tarray);
    do_merge(data, start, (start+end)/2 , end, tarray);
}

int main(void){
    int data[10] = {1,2,3,4,5,6,100,20,81,100};
    int sz = sizeof(data)/ sizeof(data[0]);

    int *tarray = new int[sz];
    merge_sort(data,0,sz-1,tarray);

    for(int i=0; i<sz; i++){
        cout << data[i] << " ";
    }

    cout << endl;

    delete[] tarray;
    return 0;
}
#endif

#if 0
#include <iostream>
#include <limits.h>

using namespace std;

int N, M;

long long mdistance[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j){
                mdistance[i][j] =0;
            }
            else{
                mdistance[i][j] = LLONG_MAX;
            }
        }
    }

    for(int i=0; i<M; i++){
        int start, end ,weight;
        cin >> start >> end >> weight;

        if(mdistance[start][end] > weight){
            mdistance[start][end] = weight;
        }
    }

    //플로이드 와셜 알고리즘을 실시한다.
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                //우선 연결이 전제되어야 한다.
                if(mdistance[i][k]!= LLONG_MAX && mdistance[k][j]!=LLONG_MAX){
                    if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j]){
                        mdistance[i][j] = mdistance[i][k] + mdistnace[k][i];
                    }
                }
            }
        }
    }

    //이제 모든 노드에서의 최단거리를 출력해주면된다.

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N ; j++){
            if(mdistance[i][j] == LLONG_MAX){
                cout << "0" << endl;
            }
            else{
                cout << mdistance[i][j] << " ";            }
        }
    }

    cout << endl;
}
#endif


#if 0
//미로문제
#include <iostream>
#include <queue>
#include <vector>

using namespace std

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int graph[100][100];
bool visited[100][100] = {false,};
int M,N;
void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    //미로 정보를 입력해준다.
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            graph[i][j] = s[j] -'0';
        }
    }

    //시작 지점은 (0,0)이다.
    BFS(0,0);

    cout << graph[N-1][M-1] << endl;

}

//queue 구현, BFS 탐색을 실시한다.
void BFS(int i, int j){
    //먼저 queue를 구현해주다.
    queue<pair<int,int>> myqueue;
    //받아온 정보를 넣어준다.
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int now_x = myqueue.front().first;
        int now_y = myqueue.front().second;

        //정보를 뽑았으면 이제 pop을 해준다.
        myqueue.pop();
        //방문한 정보에는 visited을 true로 설정을 해준다.
        visited[now_x][now_y] = true;

        //이제 모든 방향을 BFS을 통해서 탐색해 보자
        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            //정보를 뽑았으면 방문한 노드가 false가 아니고 벽이 0이 아니면 전의 값을 더해준다.
            if(visited!=true && (next_x >=0 && next_y <N && next_y >=0 && next_y <N)){
                if(graph[next_x][next_y]!=0){
                    graph[next_x][next_y] = graph[now_x][now_y] + 1;
                    visited[next_x][next_y] = true;
                    myqueue.push(make_pair(next_x,next_y));
                }
            }
        }
    }

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define Max 15

using namespace std;

int N=0;
int col[Max]={0,};

bool condition(int i); //주변에 놓인것이 없는지 있는지 본다. 만약에 true를 반환하면 놓아도 되는것
void queen_N(int i); //주변에 없으면 +1을 해준다.
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    queen_N(0);
    cout << reuslt << endl;

    return 0;
}

bool condition(int i){
    //여기선 false를 반환하면 주변에 놓인것이 있어서 더이상 체스말을 못 놓는 것이된다.
    for(int k=0; k<i; k++){
        if(col[k] == col[i] || abs(col[k] - col[i] == i-k)){
            return false;
        }
        else{
            reutnr true;
        }
    }
}

void quuen_N(int i){
    if(i==N){ //만약에 끝까지 queuen을 다 놨으면
        result++;
        return;
    }

    //처음 행을 0이라고 시작을 한다.
    for(int j=0; j<N; j++){
        col[i] = j;

        if(condition(i)){
            cout << i << endl;

            queen_N(i+1);
        }
    }
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &a, pair<int,int> & b){
        if(a.first > b.first){ //우선 순위 queue에서 오름차순을 의미한ㄷ.
            return ture;
        }
        else{
            return false;
        }
    }
};

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool>visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pd;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K; //K는 start veretex이다.

    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), int_MAX);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    //일단 노드 개수만큼 해준다.
    mlist.resize(V+1);

    for(int i=0l i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(u,w));
    }

    pd.push(make_pair(0,k));
    mdistance[k] =0;

    while(!pd.empty()){
        pair<int,int> current = pd.top();
        pd.pop();
        int c_v = current.second; //해당 노드를 가져온다.

        //만약 이미 방문한 노드라면 
        if(visited[c_v]){
            continue;
        }
        visited[c_v] = true;

        for(pair<int,int> node : mlist[c_v]){
            int next = node.first; //next_node를 위미한다.
            int weight = node.second;

            if(mdistance[next] > mdistance[c_v] + weight){
                mdistance[next] = mdistance[c_v] + weight;
                myqueue.push(make_pair(mdistance[next], next));
            }
        }
    }

    for(int i=1; i<mdistance.size(); i++){
        if(mdistance[i] = INT_MAX){
            cout << "INF" << endl;
        }
        else{
            cout << mdistance[i] << endl;
        }
    }

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limists.h>
#include <tuple>

using namesapce std;

int N, M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    mdistance.resize(M+1, LONG_MAX);
    mdistance[1]=0; //시작 지점을 1이라고 명시를 했다.

    for(int i=1; i<=M; i++){
        int start, end ,weight;
        cin >> start>> end >> weight;
        edges.push_back(make_tupel(start, end, weight));
    }

    //이제 다 넣었으니 N-1 만큼 반복을 한다.

    for(int i=1; i<N-1; i++){
        for(int j=0; j<M ;j++){
            tuple<int,int,int> medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            //일단 방문을 해야지 최단거리를 구할수 잇음
            if(mdistance[start] != LONG_MAX && mdistnace[end]> mdistance[start] + weight){
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool Cycle - false;
    //노드를 다시 한번 갱신했는데 값이 바뀌면 안됨

    for(int j=0l j<M; j++){
        tuple<int,int,iont> medges = edges[j];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start]!=LONG_MAX && mdistance[end] > mdistanc[start] + weight){
            Cycle = false;
        }
    }

    if(Cycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i <=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}

#endif

//이분그래프 구하기 백준 1707번

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

void DFS(int i);
int K,V,E;
vector<vector<int>>distance_info;
vector<bool> mdistance;
vector<int> check; //인접한 노드인지 아닌지 확인하는 flag라고 생각하면 편함.
int flag = false;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    for(int j=0; j<K; j++){
        flag = false;
        cin >> V >> E;

        //1부터 V까지 번호가 붙어져 있음
        distance_info.resize(V+1);
        mdistance.resize(V+1, false);
        check.resize(V+1,0);

        //edge의 수만큼 반복을 한다.
        for(int i=0; i<E; i++){
            int start,end;
            cin >> start >> end;
            distance_info[start].push_back(end);
             distance_info[end].push_back(start);
        }

        //이제 모든 정보를 넣었으니까 DFS로 비교를 해준다.

        //그래프가 다 붙어 있어야 될 보장은 없다. 따라서 모든 노드에 대해서 다 해준다.
        // for(int i=1; i<=V; i++){
        //     DFS(i); //어디부터 시작을 해야할까 ?
        // }

        for(int i=1; i<=V; i++){
            DFS(i);
        }
        

        //여기에서 모든 정보를 초기화 시켜준다.
        fill(mdistance.begin(), mdistance.end(),false);
        

        //distnace_info 정보도 다 날린다. 즉 clear해줘야한다.
        for(int i=0; i<V; i++){
            distance_info[i].clear(); //  이 문법이 맞나 ?
        }

        check.clear();

        if(flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }


    return 0;
}


void DFS(int i){
    
    //방문을 했으면 일단 true로 설정을 해준다.
    mdistance[i] = true;

    for(int node : distance_info[i]){
        //처음 방문을 했으면 check +1 을해준다. 전 노드의
        if(mdistance[node]==false){
            check[node] = (check[i]+1)%2;
            mdistance[node] = true;
            DFS(node);
        }
        else if(mdistance[node]==true){
            if(check[node] == check[i]){
                flag = true;
            }
        } 
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namesapce std;

vector<int> degree;
vector<int>setbuild;
vector<vector<int>>graph;
vector<int> goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int tiem;
        cin >> time;
        setbuild[i] = time;

        //이제 우선순위 건물을 비교해줘야함.
        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            
            else{
                graph[prebuild].push_back(i);
                //그리고 degree를 1씩 증가 시킨다.
                //차수가 올라간 것은 지어지는 순위가 밀린다.
                degree[i]++;
            }
        }
    }

    //이제 위상 정렬이 완성되엇음
    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            //차수가 0인 노드는 우선순위가 높으므로 push를 해준다.
            myqueue.push(i);
        }
    }

    //이제 push된 것부터 출력을 해준다. 그리고 queue가 빌때까지 출력해준다.
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node: graph[now]){
            //이제 순서대로 해당 종속 노드가 나오게 된다.
            degree[node]--;

            //push를 해준다.
            if(degree[node]==0){
                myqueue.push(node);
            }

            //그 다음에 해당 노드 혀냊 상태에다 setbuild를 더해준다.
            //2개 이상의 건물이랑 종속성이 있을경우 큰 build 시간이 지난 후 지어진다
            goal[node] = max(gol[node], goal[now] + setbuild[now]);
        }
    }

    //이제 모든 노드에 자신 자신의 시간을 더한다.
    for(int i=1; i<=N; i++){
        goal[i] = goal[i]+setbild[i];

        cout << goal[i] << endl;
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int graph[100][100];
bool visited[100][100] = {false,};
int N, M;
void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        
        for(int j=0; j<M; j++){
            graph[i][j] = s[j] - '0';
        }
    }

    BFS(0,0);


    cout << graph[N-1][M-1] << endl;


    return 0;
}

//queue 구현, BFS 탐색

void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int cur_x = myqueue.front().first;
        int cur_y = myqueue.front().second;
        visited[cur_x][cur_y] = true;

        myqueue.pop();

        for(int i=0; i<4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            //칸이 초과 되
            if(x < 0 || y < 0 || x >=N || y >= N){
                if(graph[next_x][next_y] !=0 && visited[next_x][next_y] == false){
                    myqueue.push(make_pair(next_x,next_y));
                    graph[next_x][next_y] = graph[cur_x][cur_y] + 1;
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter);
int mySum(string a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example,'-');

    for(i=0; i<str.size(); i++){
        int temp = mySum(str[i]);
        if(i==0){
            answer = answer + temp;
        }
        else{
            answer = anser -temp;
        }
    }

    cout << answer << endl;
}

vector<string> split(string input, char delimiter){
    vector<string>result;
    stringstream mystream(input);
    string splitdata;

    while(getline(mystream, splitdata, delimiter)){
        result.push_back(splitdata);
    }
    return result;
}

int mySum(string a){
    int sum=0;
    vector<string>temp = split(a,'+');

    for(int i=0; i<temp.size(); i++){
        sum +=stoi(temp[i]);
    }
    return sum;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namesapce std;

int N;
int MAP[51][51]={0,};
int visited[51][51] = {false,};
int dist[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int,pair<int,int>> &b){
        //오름 차순을 우선순위로 놓아야 된다.
        return a.first > b.first;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string a;

    //0은 검은방, 1은 희방이다. 여기서 반전을 ㅐㅎ준다.

    for(int i=0; i<N; i++){
        cin >> a;

        for(int j=0; j<N; j++){
            MAP[i][j] = a[j] = '0';
            if(MAP[i][j] == 1){
                MAP[i][j] == 0;
            }
            else if(MAP[i][j]==0){
                MAP[i][j]=1;
            }
        }
    }

    //각 자리를 무한대로 초기화시킨다.
    for(int i=0; i<N ; i++){
        fill(dist[i], dist[i]+N, INT_MAX);
    }

    priority_queue<int,pair<int,int>>, vector<int,pair<int,int>>>, compare> pd;

    pd.push(make_pair(0,make_pair(0,0)));

    dist[0][0] =0;

    while(!pd.empty){
        pair<int,int> now = pd.top().second;
        int distance = pd.top().first;
        pd.pop();

        if(visited[now.first][now.second] == true){
            continue;
        }

        for(int i=0; i<4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx<0 || nx >=N || ny <0 || ny >=N){
                continue;
            }

            if(dist[now.firt][now.second] + MAP[nx][ny] < dist[nx][ny]){
                dist[nx][ny] = dist[now.first][now.second] + MAP[nx][ny];
                pd.push(make_pair(dist[nx][ny], make_pair(nx,ny)));
            }
        }
    }

    cout << dist[N-1][N-1] << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueperson;
vector<vector<int>> party;
int result;
void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >> T;
    tureperson.reisze(T);

    for(int i=0; i<T; i++){
        cin >> trueperson[i];
    }

    party.resize(M);

    for(int i=0; i<M ; i++){
        int party_size;
        cin >> party_size;

        for(int j=0; j< party_size; j++){
            int temp;
            cin >> temp;
            //i번째 party에 오는 사람들의 수이다.
            //graph로 저장을 한다.
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=0; i<M ;i++){
        //첫번째 사람을 기준으로 하면 편하다.
        int firstPeople = party[i][0];
        
        for(int j=1; j<party[i].size(); j++){
            unionfunc(firstPeople, party[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        //이제 각 파티에 진실을 알고 있는 사람이 존재하는 지 본다.
        bool isPossible = true;
        int cur = party[i][0];

        for(int j=0; j<T; j++){
            if(find(cur) == find(trueperson[i])){
                isPossible = false;
                break;
            }
        }

        if(isPossible){
            result++;
        }
    }
    
    cout << result;


}

void unionfunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b] =a;
    }
}

int find(int node){
    if(node == parent[node]){
        return node;
    }
    else{
        return parent[a] = find[parent[a]];
    }
}
#endif

#if 0
//칵테일 문제 복습
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10]; //최소가 되는 재료량을 저장한다.

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; 
    minn =1;

    A.resize(N+1);
    visited.resize(N+1, false);
    

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a >>b >>p >> q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        minn = minn*(p*q)/gcd(p,q);
    }

    //0번 재료부터 순서대로 공백으로 구분해서 출력해야 하기 때문에
    D[0] = minn;

    DFS(0); //연결되어 있는 정보를 뽑는다.
    
    for(int i=1; i<N; i++){
        minn = gcd(minn, D[i]);
    }

    for(int i=0; i<N ; i++){
        D[i] = D[i] / minn;
        cout << D[i] <<" ";
    }

    return 0;
}

//모든 비율을 맞춰야함
void DFS(int node){
    visited[node] = true;
    
    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] * (get<2>(i)) / (get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

long gcd(long a, long b){
    if(b==0){
        return a;
    }
    return gcd(b,(a%b));
}
#endif

#if 0
//물의 양구하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//A:0, B:1, C:2
int A,B,C;
int send[6] = {0,0,1,1,2,2};
int receive[6] = {1,2,0,2,0,1};
int bottle[3] = {0,};
int full_standard[3];
vector<int> answer;
//부피는 200이니까
bool visited[201][201] = {false,};
int MAX_bottle;

void BFS();

//정렬하는 프로그램을 짠다.
bool compare(int &a, int &b){
    if(a<b){ //오름 차순이다.
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++){
        cin >> full_standard[i];
    }

    BFS();

    sort(answer.begin(), answer.end(), compare);

    for(int i:answer){
        cout << i <<" ";
    }

    return 0;

}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        //0은 A, 1은 B, 2는 C용량이다.
        int current[3];

        //현재 남은 병의 용량을 표현한다.
        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];

        visited[current[0]][current[1]] = true;

        //만약 a의 물병이 비었따면 C물병의 용량을 구한다.
        if(current[0] == 0){
            answer.push_back(current[2]);
        }

        myqueue.pop();

        for(int i=0; i<6; i++){
            int next[3];
            next[0] = current[0];
            next[1] = current[1];
            next[2] = current[2];

            int ns = send[i];
            int nr = receive[i];

            //다음 것을 정의해줌
            next[nr] = current[nr] + current[ns];
            next[ns] =0;

            if(next[nr] > full_standard[nr]){
                //넘치면 나머지를 전 send 물병에 넘겨주고 리시브 물병은 최대로 채운다.
                int rest = next[nr] - full_standard[nr];
                next[ns] = rest;
                next[nr] = full_standard[nr];
            }

            //이제 push를 해준다.
            //3개니까 next[0], next[1]를 보내면 자연스럽게 next[2]를 알 수 있기 때문이다.
            if(!visited[next[0]][next[1]]){
                myqueue.push(make_pair(next[0], next[1]));
                //push를 했으면 방문 했으니까 visited 처리를 해준다.
                visited[next[0]][next[1]] = true;
            }
        }
    }
}
#endif

#if 0
//tuple로 구현한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <tuple>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> & b){
        return a.first > b.first; //우선순위 queue에서는 오름차순 정렬이다.
    }
};

vector<bool> visited;
vector<long> mdistance;

vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    cin >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    int start, end;
    cin >> start >> end;

    //자기 출발 위치는 0이다.
    mdistance[start]=0;

    myqueue.push(make_pair(0,start)); //최소거리 start node

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node]= true;

        

        for(pair<int,int> node : mlist[now_node]){
            
            pair<int,int> medges = node;
            int end = medges.first;
            int edge_weight = medges.second;


            if(mdistance[end] > mdistance[now_node] + edge_weight){
                mdistance[end] = mdistance[now_node] + edge_weight;
                myqueue.push(make_pair(mdistance[end], end));  //weight
            }
        }
    }

    //이제 다 탐색했음
    cout << mdistance[end] << "\n";
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N은 도시의 개수, M은 경로의 개수
    cin >> N >> M;

    mdsitance.resize(N+1, LONG_MAX);

    //출발이 1이니까 1을 0으로 초기화함.
    mdistance[1] =0;

    //시작, 도착, 가중치를 넣는다.
    for(int i=1; i<=M; i++){
        int start, end ,weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start,end,weight));
    }

    //이제 다 넣었으니 N-1만큼 반복한다.
    for(int i=1; i<N; i++){
        //모든 노드를 탐색한다.
        for(int j=0; j<M; j++){
            tuple<int,int,int> medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            //일단 방문을 했어야 갱신이 가능하다.
            if(mdistance[start]!=LONG_MAX && mdistance[end] > mdistance[start] + weight){
                //작은 distance로 갱신한다.
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    //모든 노드를 갱신했다면 한번 더 사이클을 돌려서 가중치가 바뀌는지 본다.
    for(int j=0; j<M; j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N);

    int start =0;
    int end =0;

    //전체 길이를 돌면서 최소, 최대값을 search 한다.
    for(int i=0; i<N; i++){
        cin >> A[i];
        //최대값을 반환한다.
        if(start < A[i]){
            start = A[i];
        }
        end = end + A[i];
    }

    while(start <=end){
        int middle = (start + end)/2;
        int sum =0;
        int count =0;

        //middle값으로 모든 레슨을 저장할 수 있는지 확인한다.
        for(int i=0; i<N; i++){
            if(sum + A[i] > middle){
                count++;
                sum =0;
            }
            sum = sum + A[i];
        }
        if(sum!=0){
            count++;
        }
        if(count > M){
            start = middle +1;
        }
        else{
            end = middle-1;
        }
    }
    
    cout << start << endl;
}
#endif 

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <algorithm>

using namespace std;

int N,M;
int MinDistance = INT_MAX;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
vector<int> array;

//치킨집을 고르는 함수이다.
void select_chicken(int cnt);

//치킨 거리를 계산하는 함수이다.
void calculation_distance(void);

//선택된 치킨집을 말함
bool visited[14] = {false,};

//0은 빈칸, 1은 집, 2는 치킨집이다.

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> graph[i][j];

            //집이라면 집 배열에 저장을 한다.
            if(graph[i][j] == 1){
                home.push_back(make_pair(i,j));
            }
            else if(graph[i][j] == 2){
                //치킨집이면 치킨 vector에 저장을 한다.
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    
    select_chicken(0);

    cout << MinDistance<<'\n';

    return 0;
}

//총 m객를 선택하게 된다. 
void select_chicken(int cnt){
    if(cnt == M){
        //여기서 고른 것을 calculation해준다.
        calculation_distance();
        return;
    }

    //여기서 M개를 선택한다.
    for(int i=0; i<chicken.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            select_chicken(cnt+1);
            visited[i] = false;
        }
    }
}

//시나리오 : 각 3개를 고른뒤 모든 집에서의 거리를 구해준다.

void calculation_distance(void){
    //처음에는 최대로 설정을 해준다.
    int cityDistnace =0;
    //모든 집에 대해서 chicken거리를 계산한다.
    for(int i=0; i<home.size(); i++){
        int min_distance = INT_MAX;

        for(int j=0; j<chicken.size(); j++){
            if(visited[j]){
                int min_temp;
                min_temp = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);

                if(min_distance> min_temp){
                    min_distance = min_temp;
                }
            }
        }

        //이제 여기에 값을 더해주면 된다.
        cityDistnace +=min_distance;

    }
    if(cityDistnace < MinDistance){
        MinDistance = cityDistnace;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

void do_merge(int data[], int start, int mid, int end, int tarray[]){
    int lstart = start;
    int rstart = mid+1;
    int lend = mid;
    int rend = end;
    int i = start;
    int j = rstart;
    int t = start;

    while(1){
        if(i > lend && j > rend){
            break;
        }
        //이미 왼쪽은 다 넣었으면 오른쪽만 넣으면됨
        if(i>lend){
            tarray[t] = data[j];
            t++;
            j++;
        }
        else if(j > rend){
            tarray[t] = data[i];
            t++;
            i++;
        }
        //이제 서로 비교를 해줘야함
        //오름차순 정렬임
        else{
            if(data[i] > data[j]){
                tarray[t] = data[j];
                t++;
                j++;
            }
            else{
                tarray[t] = data[i];
                t++;
                i++;
            }
        }
    }

    //이제 tarray에 복사된 것을 원본에 넣어줘야함
    for(int i=start; i<=end; i++){
        data[i] = tarray[i];
        cout << data[i] << " ";
    }
    cout << endl;
}

void merge_sort(int data[], int start, int end, int tarray[]){
    int cnt=0;
    if(start == end){
        return;
    }

    merge_sort(data, start, (start_end)/2, tarray);
    merge_sort(data, (start+end)/2+1, end, tarray);
    do_merge(data, start,(start_end)/2, end, tarray);
}
#endif

#if 0
#include <iostream>
#include <vector>

using namesapce std;

void do_merge(int data[], int start, int mid, int end, int tarray[]){
    int lstart = start;
    int rstart = mid+1;
    int rend = end;
    int lend = mid;
    int i = start;
    int j = rstart;
    int t = start;

    while(1){
        if(i > lend && j > rend){
            break;
        }
        //이미 왼쪽은 다 넣었으면 오른쪽만 넣으면 된다.
        if(i > lend){
            tarray[t] = data[j];
            t++;
            j++;
        }
        else if(j > rend){
            tarray[t] = data[i];
            t++;
            i++;
        }
        //이제 서로 비교를 해줘야한다.
        //오름차순으로 정렬을 해준다.
        else{
            if(data[i] > data[j]){
                tarray[t] = data[j];
                t++;
                j++;            
            }
            else{
                tarray[t] = data[i];
                t++;
                i++;
            }
        }
    }

    //이제 taary에 복사된 값을 원본에 넣어줘야한다.
    for(int i = start; i<=end; i++){
        data[i] = tarray[i];

        cout << data[i] << " ";
    }
    cout << endl;
}

void merge_sort(int data[], int start, int end, int tarray[]){
    int cnt=0;
    int(start == end){
        return;
    }

    merge_sort(data, start, (start+end/2, tarray));
    merge_sort(data, (start+end)/2+1, end, tarray);
    do_merge(data, start, (start+end)/2, end, tarray);
}
#endif



#if 0
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
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//K는 test case 개수이다.
int K,V,E;
vector<vector<int>> graph;
vector<int> check;
vector<bool> visited;
void DFS(int i);
bool flag = false;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //먼저 case 개수를 입력을 해준다.
    cin >> K;

    for(int i=0; i<K; i++){
        flag = false;
        cin >> V >> E;
        check.resize(V+1,0);
        visited.resize(V+1,false);
        graph.resize(V+1);

        for(int j=0; j < E ; j++){
            int start, end;
            cin >> start >> end;

            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        //이제 DFS로 각 이분 그래프인지 비교해주면된다.

        for(int i=1; i<=V; i++){
            DFS(i);
        }

        //모든 정보를 추출했으면 이제 clear을 해준다.
        check.clear();
        visited.clear();
        graph.clear();

        if(flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }

    }
    
}

//이제 여기에 DFS를 구혆나다.
void DFS(int now){
    //대표값을 한개 뽑아야한다.

    //방문을 했으면 일단 true로 설정을 해준다.
    visited[now] = true;

    for(int node : graph[now]){
        if(visited[node] == true){
            if(check[now] == check[node]){
                flag = true;
            }
        }
        else if(visited[node] == false){
            visited[node] = true;
            check[node] = (check[now] + 1)%2;
            DFS(node);
        }
    }
}
#endif

#if 0
//물의 양 구하기 문제
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//A : 0, B : 1, C : 2라고 가정한다.
int A,B,C;
//총 6가지 경우로 나누어 볼 수 있음
int sender[6] ={0,0,1,1,2,2};
int receiver[6]={1,2,0,2,0,1};
int full_standard[3];
vector<int>answer;
//A,B경우의 수를 구할 때 총 용량이 200이기 때문에
bool visited[201][201];

void BFS();

//오름차순 정렬을 실시한다.
bool compare(int & a, int &b){
    if(a < b){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++){
        cin >> full_standard[i];
    }

    //이제 용량을 다 설정했으니까 비교 연산을 실시한다.
    BFS();

    //이러면 오름차순 정령이된다.
    sort(answer.begin(), answer.end());

    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }

    cout << endl;

    return 0;
}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));


    while(!myqueue.empty()){

        int current[3];
        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];

        if(current[0]==0){
            answer.push_back(current[2]);
        }

        //그리고 이제 visited을 tru로 만든다.
        visited[current[0]][current[1]] = true;

        myqueue.pop();

        //이제 next를 구해야 하기 때문에 6가지 경우의 수를 실시해준다.
        for(int i=0; i<6 ; i++){
            int next_info[3];
            next_info[0] = current[0];
            next_info[1] = current[1];
            next_info[2] = current[2];

            next_info[sender[i]] = 0;
            next_info[receiver[i]] = current[receiver[i]] + current[sender[i]];

            //이제 물병이 넘칠 경우를 고려해줘야한다.
            if(next_info[receiver[i]] > full_standard[receiver[i]]){
                int rest;
                rest = next_info[receiver[i]] - full_standard[receiver[i]];

                //이제 남은 것을 sender쪽으로 넘겨주면된다.
                next_info[sender[i]] = rest;
                next_info[receiver[i]] = full_standard[receiver[i]];
            }

            if(visited[next_info[0]][next_info[1]] == true){
                continue;
            }

            //visited도 true로 설정을 해야한다.
            visited[next_info[0]][next_info[1]]= true;
            
            //넘치지 않을 경우 그대로 유지해 주면된다.
            //A물병이 빌 경우 C 물병을 고려해 ㅜ저야한다.
            //만약 방문한 node이면 push를 해줄 필요가 없음, BFS는 while문 안에서 visited check
            myqueue.push(make_pair(next_info[0], next_info[1]));
        }

    }
}
#endif

#if 0
//백준 칵테일 만들기 문
#include <iostrema>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10]; // 최소가 되는 재료량을 구한다.

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn = 1;

    A.resize(N+1);
    visited.resize(N+1, false);

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        minn = minn*(p*q)/gcd(p,q);
    }

    D[0] = minn;

    DFS(0); // 연결되어 있는 정보를 뽑는다.

    for(int i=1; i<N; i++){
        minn = gcd(minn, D[i]);
    }

    for(int i=0; i<N ; i++){
        D[i] = D[i]/minn;
        cout << D[i] << " ";
    }

    return 0;
}

//모든 비율을 맞춰야한다.

void DFS(int node){
    visited[node] = true;

    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] * (get<2>(i)) / (get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

int gcd(long a, long b){
    if(b==0){
        return a;
    }
    else if(b !=0){
        return gcd(b,(a%b));
    }
}
#endif



#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namesapce std;

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
        int start, end;

        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int index = 1;

    for(int i=1; i<=N ; i++){
        int min_distance = BFS(i);

        if(MIN_distance > min_distance){
            Min_distance = min_distance;
            index = i;
        }
        else if(Min_distance == min_distance){
            index = min(index,i);
        }

        fill(visited.begin(), visited.end(), false);
        fill(mdistance.begin(), mdistance.end(), 0);
    }

    cout << index << endl;
}

int BFS(int i){
    queue<int> myqueue;
    myqueue.push(i);

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        visited[i] = true;
        myqueue.pop();

        for(int node : graph[now_node]){
            if(!visited[node]){
                visited[node] = true;
                mdistance[node] = mdistance[now_node] + 1;
                myqeueu.push(node);
            }
        }
    }

    int total = 0;
    for(int i=1; i<=N; i++){
        total += mdistance[i];
    }

    return total;
}
#endif


#if 0
//이제 프로이드 워셜로 구현
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int graph[101][101]={0,};
int N,M;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){

            if(i==j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = 9999999;
            }
        }
    }

    for(int i=1; i<=M; i++){
        int start, end;

        cin >> start >> end;

        graph[start][end]  = 1;
        graph[end][start] = 1;
    }

    //이제 플로이드 워셜로 구현
    
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int index =1;
    int Min_distance = INT_MAX;

    for(int i=1; i<=N; i++){
        int min_distance=0;

        for(int j=1; j<=N; j++){
            min_distance += graph[i][j];
        }

        if(min_distance < Min_distance){
            Min_distance = min_distance;

            if(index == i){
                index = min(index,i);
            }
            
            else{
                index = i;
            }
        }
    }

    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << index << endl;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include queue>

using namespace std;

static int N;
static vector<vector<int>> tree;
static int answer =0;
static int deletenode =0;
static vector<bool> visited;
void DFS(int number);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    coutt.ie(NULL);

    cin >> N;
    visited.resize(N);
    tree.resize(N);
    int root =0;

    for(int i=0; i<N; i++){
        int parent;
        cin >> parent;

        if(parent != -1){
            tree[i].push_back(parent);
            tree[parent.push_back(i);]
        }
        else{
            root = i;
        }
    }

    //이제 지워줄 노드를 입력한다.
    cin >> deletenode;

    //만약 지울 노드가 root이면 리프노드는 0이돈다.
    if(deletenode == root){
        cout << 0 << endl;
    }
    else{
        DFS(root);
        cout << answer << endl;
    }

    return 0;
}

void DFS(int number){
    visited[number] = true;
    int cNode = 0; //이건 childe node를 의미한다.

    for(int i:tree[number]){
        if(visited[i] == true && i != deletenode){
            //방문하지 않았고 delenodenode가 아니라면 ++를 증가 시켜준다.
            cNode++;
            DFS(i);
        }
    }

    //마냑 childe node가 0이라면 리프노드이다
    if(cNode ==0){
        answer++;
    }
}
#endif

#if 0
//여행계획 세우기 코드를 코딩한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namesapce std;

int N,M;
vector<vector<int>>graph;
vector<int>parent;
vector<int>route;
int amp[201][201]={0,};

int find(int node);
void union_function(int a, int b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    parent.resize(N+1);
    graph.resize(N+1);
    route.resize(M+1);

    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    //이제 union을 실시한다.
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j/++){
            cin >> map[i][j];

            //1이면 연결이 되었다는 말
            if(mape[i][j] == 1){
                union_function(i,j);
            }
        }
    }

    이제 연결을 다끝냈음
    bool flag = false;

    cin >> route[1];
    int index = find(route[1]);

    for(int i=2; i<=M; i++){
        cin >> route[i];

        //모든 route를 비교해준다.
        if( (find(route[i]) != find(route[i-1]))){
            cout << "NO" << endl;
            flag = true;
            break;
        }
    }

    if(!flag){
        cout << "YES" << endl;
    }

    return 0;
}

void union_function(int a, int b){
    int root_a = find(a);
    int root_A = find(b);

    if(root_a != root_b){
        parent[root_b] = root_a;
    }
}

int find(int node){
    if(parent[node] == node){
        return node;
    }

    else{
        return parent[node] = find(parent[node]);
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> & b){
        if(a.first > b.first){//오름 차순으로 정렬한다.
            return true;
        } 
        else{
            return false;
        }
    }
};

vector<vector<pair<int,int>>> graph;
vector<int> visited;
vector<int> mdistance;

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> myqueue;

int V,E,K;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    graph.resize(V+1);
    mdistance.resize(V+1,INT_MAX);
    visited.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v,w));
    }

    //자기 자신은 0으로 만들어줘야함.
    mdistance[K] = 0;
    myqueue.push(make_pair(0,K));

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_node = now.second;
        int now_value = now.first;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node] = true;

        for(pair<int,int> node : graph[now_node]){
            int next_node = node.first;
            int next_value = node.second;

            if(mdistance[next_node] > mdistance[now_node] + next_value ){
                mdistance[next_node] = mdistance[now_node] + next_value;
                myqueue.push(make_pair(mdistance[next_node], next_node ));
            }  
        }
    }

    for(int i=1; i<=V; i++){
        if(mdistance[i] == INT_MAX){
            cout << "INF" << "\n";
        }
        else{
            cout << mdistance[i] << "\n";
        }
    }

    return 0;

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namesapce std;

int N=0;
int col[15] = {0,};

bool condition(int i); //주변에 놓인것이 없는지
void queen_N(int i); //주변에 없으면 +1를 해준다.
int result = 0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    queen_N(0);
    cout << result << endl;
    return 0;
}

bool condition(int i){
    for(int k=0; k<i ; k++){
        if(col[k] == col[i] || abs(col[k] - col[i]) == i-k){
            return false;
        }
    }
    return true;
}

void queen_N(int i){
    if(i==N){
        result++;
        return;
    }
    for(int j=0; j<N; j++){
        col[i]=j;

        if(condition(i)){
            queen_N(i+1);
        }
    }
}
#endif

#if 0
//백준 18352
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//이때 N은 도시의 개수, M은 간선의 개수, K는 거리, X는 출발지점이다.
//X로 부터 출발하여 도달할 수 있는 도시 중에서 최단거리가 K인 모든 도시의 번호를 한 줄에 하나씩
//나오게 오름차순으로 출력해라
//이때 도달할 수 있는 도시 중에서 최단 거리가 K인 도시가 하나도 존재하지 않은면 -1을 출력한다.
int N,M,K,X;

//여기선 가중치가 주어지지 않음 따라서 다익스트라로 구현하지 않아도 된다.
vector<vector<int>> graph;
vector<bool> visited;
vector<int> mdistance;
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;

    graph.resize(N+1);
    visited.resize(N+1,false);
    //일단 모든 값을 1로 초기화 시켜준다.
    mdistance.resize(N+1,0);

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;

        //모든 정보를 입력한다.
        //모든 도시의 거리는 1이다. BS로 구현하면 될듯 ?
        graph[start].push_back(end);
    }

    BFS(X);
    int flag = false;
    //여기에서 이제 mdistance를 출력한다.
    for(int i=1; i<=N; i++){
        if(mdistance[i] == K){
            flag = true;
            cout << i << endl;
        }
    }

    if(!flag){
        cout << -1 << endl;
    }
    return 0;
}

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        visited[now_node] = true;
        myqueue.pop();

        for(int next_node : graph[now_node]){
            if(!visited[next_node]){
                mdistance[next_node] = mdistance[now_node] + 1;
                visited[next_node] = true;
                myqueue.push(next_node);
            }
        }
    }
}
#endif


#if 0
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int my_heap[20];
int heap_size = 0;

void swap(int *my_heap, int me, int parent){
    int temp = my_heap[me];
    my_heap[me] = my_heap[parent];
    my_heap[parent] = temp;
}

void enqueue(int _data){
    if(heap_size == 20-1){
        return;
    }
    heap_size++;

    my_heap[heap_size] = _data;

    int me = heap_size;
    int parent = me/2;

    while(1){
        if(me == 1){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] <= my_heap[parent]){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] > my_heap[parent]){
            swap(my_heap,me,parent);
            me = parent;
            parent = me/2;
        }
    }
}

int find_index(int me){
    int left_child = me*2;
    int right_child = left_child + 1;

    //무자식 이라면
    if(left_child > heap_size){
        return 0;
    }
    //만약 부모 노드에 자식이 혼자라면
    if(right_child > heap_size){
        return left_child;
    }
    //만약 자식이 두명이라면
    if(my_heap[left_child] < my_heap[right_child]){
        return right_child;
    }
    //이제 right_child랑 left_child를 비교해 줄때 left_child가 더 크면 return left해줌
    else{
        return left_child;
    }
}

//이제 heap에서 자식을 뺀다. 정렬을 한 후 한개씩 빼준다.
void dequeue(void){
    if(heap_size == 0){
        cout << "heap이 비어 있습니다." << endl;
        return;
    }
    if(heap_size == 1){
        cout << my_heap[1] << endl;
        heap_size--;
        return;
    }
    //heap[1]에 최대값이 저장되어 있음
    int res = my_heap[1];
    cout << res << " ";
    swap(my_heap, 1 , heap_size);
    heap_size--;
    int me = 1;
    //이제 me의 자식 중에서 큰것을 반환해준다.
    int find = find_index(me);


    while(1){
        if(find ==0){
            //만약 자식이 없다면 return을 해주낟.
            return;
        }
        else if(my_heap[find] > my_heap[me]){
            //만약 자식이 더 크면 내림차순에 위반됨
            swap(my_heap,me,find); //큰 숫자랑 바꿔준다.
            //그러면 이제 me가 findrk 된다.
            me = find;
            find = find_index(me); //또 자식을 찾아준다.
        }
        else if(my_heap[find] < my_heap[me]){
            //이제 내 자리를 잘 찾아왔음
            return;
        }
    }
}


void show(int my_heap[], int heap_size){
    for(int i=1; i<=heap_size;i++){
        cout << my_heap[i] <<" ";
    }
    cout << endl;
}

int main(void){
    //오름 차순으로 정렬한다.
    enqueue(10);
    enqueue(100);
    enqueue(5);
    enqueue(1000);
    enqueue(202031);

    dequeue();
    dequeue();
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define heap_len 20

int heap_size = 0; //최대로 담을 수 있는 것이 19개라고 가정한다.
int me =0;
int parent =0;
int graph1[20];

//enqueue을 구현하낟.

void swap(int graph1[], int node1, int node2){
    int temp = graph1[node1];
    graph1[node1] = graph1[node2];
    graph1[node2] = temp;
}

void enqueue(int _data){
    //모든 데이터가 들어갔음
    if(heap_size == 20-1){
        return; 
    }
    heap_size++;

    graph1[heap_size] = _data;
    
    me = heap_size;
    parent = me/2;

    //이제 data를 알맞는 위치에 놓는다
    while(1){
        if(me == 1){
            graph1[me] = _data;
            return;
        }
        else if(graph1[me] > graph1[parent]){
            swap(graph1,me,parent);
            me = parent;
            parent = parent/2;
        }
        else if(graph1[me] <= graph1[parent]){
            return;
        }
    }
}

int find_index(int parent){
    int left_child = 2*parent;
    int right_child = 2*parent +1;

    if(left_child > heap_size){
        return 0;
    }
    else if(right_child > heap_size){
        return left_child;
    }
    else if(graph1[left_child] > graph1[right_child]){
        return left_child;
    }
    else{
        return right_child;
    }
}

void dequeue(void){
    if(heap_size == 0){
        cout << "heap이 비어 있습니다."<<endl;
        return;
    }
    if(heap_size == 1){
        cout << graph1[heap_size] << " ";
        heap_size--;
        return; 
    }
    //만약 heap size가 2이상이면 비교를 해줘야한다.
    //일단 맨 위에 있는 것이 무조건 큰것이다.
    cout << graph1[1] << " ";
    //이제 맨위에 것을 출력했으니 heap_size랑 바꿔준다.
    swap(graph1, heap_size, 1);
    //그러면 이제 heap size를 줄여서 없애준다.
    heap_size--;
    int me =1;
    //이제 1을 자기 자리 원래 자리를 찾게 해주면된다.
    int find = find_index(1);

    //자리를 맞춰준다.
    while(1){
        //자리가 한번에 안 찾아 질 수도 있기 때문에 계속 반복한다.
        if(find ==0){
            return;
        }
        else if(graph1[find] > graph1[me]){
            swap(graph1, find, me);
            me = find;
            find = find_index(me);
        }
        else if(graph1[find] < graph1[me]){
            return;
        }
        
    }
}

void show(int graph1[], int heap_size){
    for(int i=1; i<=heap_size;i++){
        cout << graph1[i] <<" ";
    }
    cout << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    enqueue(10);
    enqueue(100);
    enqueue(5);
    enqueue(1000);
    enqueue(20323);

    show(graph1, heap_size);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int x=0;
vector<vector<pair<int,int>>>graph;
vector<bool> visited;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<N; i++){
        int p, c;
        cin >> p>>c;
        graph[i].push_back(make_pair(p,c));
    }

    // ∣Pi​−X≤Ci​여야지 철민이의 인기도가 1 올라간다.
    //차례대로 수행한다.

    for(int i=0; i<N; i++){
        pair<int,int> now_info = graph[i][0];
        int now_p = now_info.first;
        int now_c = now_info.second;

        if(abs((now_p - x)) <= now_c){
            
            x = x +1;
        }
        else{
            x;
        }
    }

    cout << x << endl;
    
}
#endif

#if 0
#incnlude <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namesapce std;

struct compare{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        if(get<2>(a) > get<2>(b)){
            return true;
        }
        else{
            return false;
        }
    }
};

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void union_function(int a, int b){
    int node_a = find(a);
    int node_b = find(b);

    if(a == b){
        return;
    }
    else{
        parent[b] = a;
    }
}

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin >> V >> E;

    parent.reisze(V+1);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
    //최소신장 트리
    for(int i=0; i<E; i++){
        int start, end, weight;
        cin >> start>> end >> weight;
        myqueue.push(make_tuple(start, end, weight));
    }
    int edge_add = 0;
    
    while(!myqueue.mepty() && edge_add < V-1){
        tuple<int,int,int> now_node = myqueue.top();
        myqueue.pop();
        int start_node = get<0>(now_node);
        int end_node = get<1>(now_node);
        int weight = get<2>(now_node);

        if(find(start_node) == find(end_node)){
            //Cycle이 있기 때문이다.
            continue;
        }
        else{
            inion_function(start_node, end_node);
            edge_add++;
            result + = weight;
        }
    }

    cout << result;

    
}
#endif

#if 0
#include <iosteream>
#include <vector>
#include <algorithm>
#incnlude <queue>
#include <limits.h>

using namesapce std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> &b){
        if(a.first > b.fist){
            return true;
        }
        else{
            return false;
        }
    }
};

struct compare1{
    bool operator()(int &a, int &b){
        if(a < b){
            return true;
        }
        else{
            return false;
        }
    }
};

//K번째 경로를 찾는 프로그램이다.
int N,M,K;

vector<int>visited;
vector<vector<tuple<int,int,int>>> graph;
vector<int> mdistance;

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pd;
priority_queue<int,vector<int>, compare1> disQueue[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end,weight));
    }

    mdisntace.resize(N1, INT_MAX);

    pd.push(make_pair(0,1));
    disQueue[1].push(0); //일단 우선순위 qeuue에 1을 0으로 넣는다.

    while(!pd.emptu()){
        pair<int,int> u = pd.top();
        int now = u.second;
        int distance = u.first;

        pd.top();

        //now에 연결한 시작노드에 end node를 다 탐색한다.
        for(pair<int,int> node1 : graph[now]){
            int end = node1.first;
            int weight = node1.second;

            //저장된 경로가 K개가 안됐을때 그냥 추가하기
            if(disQeueu[end].sie() < K){
                disQeueu[end].push(distance + wegiht);
                pd.push(make_pair(distance + weight, end));
            }

            //만약 저장된 개수가 K개가 초과도리때 가장 큰값을 꺼내 비교를 해준다.
            else if(disQueueu[end].size() >=K && disQueue[end].top() > distance + weight){
                disQueue[end].pop();
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distance + weight),end);
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(disQueue[i].size() == K){
            cout << disQueue[i].top() << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
#endif

#if 0


#include <iostream>
#include <vector>

using namespace std;

void do_merge(int *data, int start, int mid, int end, int tarray[]){
    int lstart = start;
    int rstart = mid+1;
    int lend = mid;
    int rend = end;
    int i = start;
    int j = rstart;
    int t = start;

    while(1){
        if(i > lend && j > rend){
            //이 경우 모든 값을 다복사함
            break;
        }
        //이미 왼쪽은 다 넣었으면 오른쪽만 넣으면됨
        if(i > lend){
            tarray[t] = data[j];
            t++;
            j++;
        }
        else if(j > rend){
            tarray[t] = data[i];
            t++;
            i++;
        }
        //이제 서로 비교를 해줘야함 오름 차순 정렬을 기준으로 한다면
        else{
            if(data[i] > data[j]){
                tarray[t] = data[j];
                j++;
                t++;
            }
            else{
                tarray[t] = data[i];
                i++;
                t++;
            }
        }
    }

    //이제 taaray에 복사된 것을 원본에 넣어줘야함
    for(int i =start; i<=end; i++){
        data[i] = tarray[i];
        
    }
    cout << endl;
}

void merge_sort(int data[], int start, int end, int tarray[]){
    int cnt =0;
    if(start == end){
        return;
    }

    merge_sort(data, start, (start + end)/2, tarray);
    merge_sort(data, (start+end)/2 +1, end, tarray);
    do_merge(data, start, (start + end)/2, end, tarray);
}

int main(void){
    int data[] = {1,2,3,4,5,100,5,17};
    int sz = sizeof(data) / sizeof(data[0]);
    cout << sz << endl;

    int *tarray = new int[sz];
    merge_sort(data, 0, sz-1, tarray);

    for(int i=0; i<sz ; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] tarray;
    return 0;
}
#endif


//quick_sort을 구현한다.
#if 0
#include <iostream>
#include <queue>

using namespace std;

void swap(int *data, int a, int b){
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void quick_sort(int *data, int start, int end){

    if(start >= end){
        return;
    }
    int low = start +1;
    int high = end;
    int pivot = start;

    //2개를 비교해줄때 low랑 high가 같게된다.
    while(low <= high){
        while(data[low] < data[pivot] && low <=end){
            low++;
        }
        while(data[high] >= data[pivot] && high >=start+1){
            high--;
        }

        if(low < high){
            swap(data, low, high);
        }
    }
    //이제 모두 바꿔주었으면
    //high랑 pivot을 바꿔준다. 그리고 pivot을 기준으로 다시 기준을 나눠준다.
    //pivot은 자기 자리를 찾아간 것이다.
    swap(data, high, pivot);
    quick_sort(data, start, high-1);
    quick_sort(data, high+1, end);
}

int main(void){
    int data[] = {23,32,34,100,87,76,23,65,2,90,21,1,3};
	int sz = sizeof(data)/sizeof(data[0]);
	quick_sort(data,0,sz-1);

    for(int i=0; i<sz; i++){
        cout << data[i] << " ";
    }
	
	return 0;

}
#endif

#if 0
#include <iostream>
#include <vector>
#inlcude <limits.h>
#include <tuple>

using namesapce std;

int N,M;
vector<long> mdsitance;
vector<tuple<int,int,int> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;

    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);

    mdistance[1]=0;

    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start, end, weight));
    }

    //이제 다 넣어으니 N-1만큼 반복한다.
    for(int i=1; i<N; i++){
        //모든 노드를 탐색한다.
        for(int j=0; j<M; j++){
            tuple<int,int,int> medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            if(mdistance[start!=LONG_MAX && mdistance[end] > mdistnace[start] + weight]){
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    //이제 한번 더 수행해서 cycle이 있는지 없느지 확인한다.
    bool nCycle = false;

    for(int j=0; j<M ;j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0>(medges);
        int end = get1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + wegiht){
            nCycle = false;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int>> party;
int result;
void unionfunction(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >> T;
    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin >> trueP[i];
    }
    party.resize(M);

    for(int i=0; i<M; i++){
        int party_size;
        cin >> party_size;

        for(int j=0; j<party_size j++){
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=0; i<M; i++){
        int firstPeople = party[i][0];
        for(int j=1; j< party[i].size(); j++){
            union_function(firstPeople, party[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        bool isPossible = true;
        int cur = party[i][0];
        
        for(int j=0; j<T; j++){
            if(find(cur) == find(trueP[i])){
                isPossible = false;
                break;
            }
        }

        if(isPossible){
            result++;
        }
    }
    
    cout << result;

    return 0;
}

void unionfunction(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b]=a;
    }
}

int find(int a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
        
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter);
int mySum(string a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');

    for(int i=0; i<str.size(); i++){
        int temp = mySum(str[i]);
        if(i==0){
            answer = answer + temp;
        }
        else{
            answer = answer - temp;
        }
    }
    cout << answer << endl;
}

vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while(getline(mystream, splitdata, delimiter)){
        result.push_back(splitdata);

    }
    return result;
}

int mySum(string a){
    int sum=0;
    vector<string> temp = split(a, '+');

    for(int i=0; i< tempsize(); i++){
        sum += stoi(temp[i]);
    }
    return sum;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>>graph;
vector<bool> visited;
vector<int> answer;

void SEARCH_NODE(int start_vertex);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    graph.resize(N+1);
    answer.resize(N+1);
    visited.resize(N+1,false);
    
    for(int i=0; i<M ;i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end); //역으로 저장을 한다.
    }

    for(int i=0; i<=N; i++){
        //일단 모두 false로 바꿔주다.
        fill(visited.begin(), visited.end(), false);
        //하나씩 탐색해서 가장 많은 것을 가지고 있는 것을 채택해준다.
        SARCH_NODE(i);
    }

    int maxVal =0;

    for(int i=0; i<=N; i++){
        maxVal = max(maxVal, answer[i]);
    }

    for(int i=1; i<=N ;i++){
        if(answer[i] == maxVal){
            cout << i << " ";
        }
    }
}

void SEARCH_NODE(int start_veretx){
    queue<int>myqueue;

    //단방향이고 특정 current가 비어있따면 처음부터 1을 증가
    visited[start_vertex]= true;

    myqueue.push(start_vertex);

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();

        for(int i : graph[current]){
            if(visited[i] == false){
                visited[i] =true;
                answer[i]++;
                myqueue.push(i); //신규노드 인덱스의 정답 배열값을 증가 시킨다. 
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> visited;
vector<int> node_distance;
void BFS(int start_vertex);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin >> v;

    graph.resize(v+1);
    visited.resize(v+1,false);

    for(int i=0; i<v;i++){
        int start;
        cin >> start;

        while(1){
            int end, weight;
            cin >> end;
            if(end == -1){
                break;
            }
            cin >> weight;
            graph[start].push_back(make_pair(end,weight));
        }
    }

    node_distance.resize(v+1,0);
    BFS(1);

    int MAX=1;

    for(int i=2; i<=v; i++){
        if(node_distance[Max] < node_distance[i]){
            Max =i;
        }
    }

    fill(node_distance.begin(), node_distance.end(), 0);
    fill(visited.begin(), visitied.end(),0);
    BFS(Max); //1로 탐색 후 가장 거리가 길게 나온 노드로 다시한번 돌리낟.
    sort(node_distance.begin(), node_distance.end());
    cout << node_distance[0] << endl;
}

void BFS(int start_vertex){
    queue<int> myqueue;
    myqueue.push(start_vertex);
    visited[start_vertex] =1;

    while(!myqueue.mepty()){
        int now_node = myqueue.front();
        myqueue.pop();
        for(pair<int,int> i : graph[now_node]){
            visited[i.first] =1;
            myqueue.push(i.first);
            node_distance[i.first] = node_distance[now_node] + i.second;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> degree;
vector<int>setbuild;
vector<vector<int>>graph;
vector<int> goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

        //이제 우선순위를 비교해줘야함.
        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_bakc(i);
                degree[i]++;
            }
        }
    }

    //이제 위상정렬을 완성해준다.
    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            //차수가 0인 노드는 우선순위가 높으므로 push해준다.
            myqueue.push(i);
        }
    }

    //이제 push된 것부터 출력을 해준다. 그리고 queue가 빌때까지 출력
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node:graph[now]){
            //이제 순서대로 출력을 해준다.
            //일단 차수 하나를 낮춰준다.
            degree[node]--;

            //이제 낮춰진 것에서 0이되면 이것을 push해줌
            if(degree[node] == 0){
                myqueue.push(node);
            }

            //그 다음에 해당 노드 현재 상태이다. setbuild을 더해준다.
            goal[node] = max(goal[node],(goal[now] + setbuild[now]));
        }
    }

    //이제 모든 노드에 자기 자신의 시가나을 더한다.
    for(int i=1; i<=N; i++){
        goal[i] = goal[i] + setbuild[i];

        cout << goal[i] << endl;
    }
}

#endif

#if 0

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
            MAP[i][j] = s[j-1] -'0';

            if(MAP[i][j] == 1){
                MAP[i][j] = 0;
            }
            else{
                MAP[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=N; N++){
        fill(mdistance[i], mdistnace[i] + N+1, INT_MAX);
    }

    mdistance[1][1] = 0;

    pd.push(make_pair(0,make_pair(1,1)));

    while(!pd.empty()){
        pair<int,pair<int,int>> now_node = pd.top();
        int distance = now_node.first;
        int now_x = now_node.second.first;
        int now_y = now_node.second.second;
        pd.pop();

        //다익스타라는 최소 거리 노드만 체크해주면됨 foransdksdptj visited을 true할 필요없음

        if(visited[now_x][now_y] == true){
            continue;
        }

        visited[now_x][now_y] = true;

        for(int i=0; i<4; i++){
            int now_x = now_x + dx[i];
            int now_y = now_y  + dy[i];

            //범위를 넘어서면
            if(next_x <=0 || next_x >N || next_y <=0 || next_y >N){
                continue;
            }

            if(mdistance[next_x][next_y] < mdistnace[now_x][now_y] + MAP[next_x][next_y]){
                mdistance[next_x][next_y] = mdistance[now+x][now_y] + MAP[next_x][next_y];
                pd.push(make_pair(mdistance[next_x][next_y], make_pair(next_x, next_y)));
            }
        }
    }

    cout << mdistance[N][N] << endl;
}
#endif



#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


//N자리 수에서 신기한 소수를 찾는 프로그램을 짜라
int N;

bool isPrime(int number);
void calculation_prim(int number, int delimeter);

int main(void){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    calculation_prim(2,0);
    calculation_prim(3,0);
    calculation_prim(5,0);
    calculation_prim(7,0);
    return 0;
}

void calculation_prim(int number, int delimeter){
    //이미 자리수를 다채움, 모든 자리가 소수임.
    if(delimeter == N-1){
        if(isPrime(number) == true ){
            return;
        }
        cout << number << endl;
        return;
    }
    for(int i=0; i<=9; i++){
        if(isPrime(number) == true ){
            return;
        }
        else{
            calculation_prim(number*10 + i, delimeter+1);
        }
    }
}



bool isPrime(int number){
    for(int i=2; i<=sqrt(number); i++){
        if(number %i ==0){
            return true;
        }
    }

    return false;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namesapce std;

static int N;
static vector<vector<int>> tree;
static int answer =0;
static int deleteNode =0;
static vector<bool> visited;
void DFS(int number);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    coutt.ie(NULL);

    cin >> N;
    visited.resize(N);
    tree.resize(N);
    int root =0;

    for(int i=0; i<N; i++){
        int parent;
        cin >> parent;

        if(parent != -1){
            tree[i].push_back(parent);
            tree[parent].push_back(i);
        }
        else{
            root =i;
        }
    }
    
    cin >> deleteNode;

    if(deleteNode == root){
        cout << 0 << endl;
    }
    else{
        DFS(root);
        cout << answer << endl;
    }

    return 0;
}

void DFS(int number){
    visited[number] = true;
    int cNode =0;

    for(int i: tree[number]){
        if(visited[i] == false && i != deleteNode){
            cNode++;
            DFS(i);
        }
    }

    if(cNode == 0){
        anser++;
    }
}
#endif 

#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    int start =0, end =0;

    for(int i=0; i<N ;i++){
        cin >> A[i];

        if(start < A[i]){
            start = A[i];
        }
        end = end + A[i];
    }

    while(start <= end){
        int middle = (start + end)/2;
        int sum =0;
        int count =0;

        //middle값을 기준으로 모든 레슨을 저장할 수 있는지 본다.
        for(int i=0; i<N ;i++){
            if(sum + A[i] >middle){
                count++;
                sum =0;
            }
            sum = sum + A[i];
        }

        if(sum !=0){
            count++;
        }

        if(M > count){
            start = middle + 1;
        }
        else{
            end = middle -1;
        }
    }

    cout << start << endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
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

    graph.rsize(N+1);
    visited.resize(N+1,false);
    mdistance.resize(N+1,0);

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int index =1;

    //모든 관계를 고려해줘야함. 그 중 최소값을 반환해야함. index를 반환해야함
    for(int i=1; i<=N; i++){
        int min_distance = BFS(i);

        if(Min_distance > min_distance){
            Min_distance = min_distance;
            index = i;
        }
        else if(Min_distance == min_distance){
            index = min(index,i);
        }
        
        fill(visited.begin(), visited.end(), false);
        fill(mdistance.begin(), mdistance.end(), 0);
    }

    cout << index << endl;
}

int BFS(int i){
    queue<int> myqueue;
    myqueue.push(i);

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        visited[i] = true;
        myqueue.pop();

        for(int node : graph[now_node]){
            if(!viisted[node]){
                viisted[node] = true;
                mdistance[node] = mdistance[now_node] +1;
                myqueue.push(node)];
            }
        }
    }

    int total =0;

    for(int i=1; i<=N; i++){
        total += mdistance[i];
    }

    return total;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int MAP[51][51]={0,};
int visited[51][51] = {0,};
int mdistance[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

strcut compare{
    bool operator()(pair<int,pair<int,int>> & a, pair<int,pair<int,int>>&b){
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
            MAP[i][j] = s[j-1] -'0';

            if(MAP[i][j] == 1){
                MAP[i][j] =0;
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
        int now_u = now_node.second.second;
        pd.top();

        if(visited[now_x][now_y] == true){
            continue;
        }

        visited[now_x][now_y] = true;

        //이제 4방향으로 탐색을 실시한다
        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            //범위를 넘어서면
            if(next_x <=0 || next_x >N || next_u <-0 || next_y >N ){
                continue;
            }
            
            if(mdistance[next_x][next_y] > mdistance[now_x][now_y] + MAP[next_x][next_y]){
                mdistance[next+x][next_y] = mdistance[now+x][now_y] + MAP[next_x][next_y];
                pd.push(make_pair(mdistance[next_x][next_y], make_pair(next_x,next_y)));
            }
        }
    }

    cout << mdistance[N][N] << endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#inlcude <limits.h>
#include <tuple>

uisng namespace std;

int N, M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);

    //출발이 1이니까 1을 0으로 초기화한다.
    mdisance[1]=0;

    //시작,도착 가중치를 넣어준다.
    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start>> end>> weight;
        edges.push_back(make_tuple(start, end, wegiht));
    }

    //이제 모든 정보를 다 넣었으니 N-1만큼 반복을 해준다.
    for(int i=1; i<N; i++){
        for(int j=0; j<M; j++){
            tuple<int,int,int> medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            //d일단 방문을 했어야한다.
            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
                //작은 distance로 갱신을 한다.
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    for(int j=0; j<M; j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0> medges = edges[j];
        int start = get<0> (medges);
        int end = get<1> (medges);
        int weight = get<2> (medges);

        if(mdistance[start]!=LONG_MAX && mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << -1 << endl;
    }
    else{
        for(int i=2; i<-N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vecor<bool> visited;
vector<int> parent;
void DFS(int node);
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N+1);
    visited.resize(N+1,false);
    parent.resize(N+1,0);

    for(int i=0; i<N-1; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    //이제 노드를 다 넣어주었으니 1부터 다시 출력한다.
    DFS(1);

    for(int i=2; i<=N; i++){
        cout << panret[i] << endl;
    }

    return 0;
}

void DFS(int node){
    visited[node] = true;

    //1인 노드는 출력을 안해도됨
    for(int i: graph[node]){
        if(!visited[i]){
            parent[i] = node;
            visited[i] = true;
            DFS(i);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N,M;
vector<vector<int>> tree;
vector<bool>visited;
vector<int> depth;
vector<int> parent;
vector<int> answer;

int LCA(int a, int b);
void BFS(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    tree.resize(N+1);
    visited.resize(N+1,false);
    depth.resize(N+1);
    parent.resize(N+1);

    for(int i=1; i<=N-1; i++){
        int start, end;
        cin >> start >> end;
        tree[start].push_back(end);
        tree[end].push_back(start);
    }

    //이제 구한 노드에 대해 BSF을 실행해 depth랑 parent을 입력해준다.
    //1이 root node이다.
    BFS(1);
    
    //이제 M을 입력받는다.
    cin >> M;

    answer.resize(M+1);

    for(int j=1; j<=M; j++){
        int s,e;
        cin >> s >> e;
        
        //정답을 넣는다.
        answer[j] = LCA(s,e);
    }

    for(int i=1; i<=M ;i++){
        cout << answer[i] << endl;
    }

    return 0;
}

void BFS(int a){
    queue<int> myqueue;
    //일단 a를 넣어줘야하낟.
    myqueue.push(a);
    int depth_info = 1;
    int count =0;
    int now_size =1;

    while(!myqueue.empty()){
        int now = myqueue.front();
        visited[now] = true;
        myqueue.pop();
         
        for(int node : tree[now]){
            //아직 방문하지 않았다면
            if(!visited[node]){
                //일단 모든 노드를 입력받는다.
                parent[node] = now;
                visited[node] = true;
                depth[node] = depth_info;
                myqueue.push(node);
            }
        }

        count++;

        //일단 다 탐색을 했으면 dpeth을 갱신해줘야함.
        //myqueu에 들어간 모든 노드를 반복하면 한 depth를 완료한 것이다.
        if(count == now_size){
            count =0;
            now_size = myqueue.size();
            depth_info = depth_info +1;
        } 
    }
}

//depth a가 깊이가 더 깊은 것으로 가정을 한다.
int LCA(int a, int b){
    if(depth[a] < depth[b]){
        int temp = a;
        a =b;
        b = temp;
    }

    //일단 depth를 맞춰줘야한다
    while(depth[a] != depth[b]){
        a = parent[a];
    }

    //이제 depth를 통일해 주었음 이제 공통조상을 찾음
    while(a!=b){
        a = parent[a];
        b = parent[b];
    }

    //이제 공통 조상을 구했음
    return a;
}
#endif

#if 0
#include <iostream>
#include <qeueu>
#include <vector>

using namespace std;

#define heap_len 20
int my_heap[heap_len];
int heap_size =0;

void swap(int my_heap[], int me, int parent){
    int temp = my_heap[me];
    my_heap[me] = my_ehap[parent];
    my_heap[parent] = temp;
}

//부모의 data가 자식보다 무조건 크게 설계한다.
void enqueue(int _data){
    if(heap_size == heap_len-1){
        return;
    }
    heap_size++;

    my_heap[heap_size] = _data;

    int me = heap_size;
    int parent = me/2;

    while(1){
        if(me==1){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] <= my_heap[parent]){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] > my_heap[parent]){
            swap(my_heap,me,parent);
            me = parent;
            parent = me/2;
        }
    }
}

int find_index(int _me){
    int left_child = me*2;
    int right_child = left_child +1;
    
    if(left_child > heap_size){
        return 0;
    }
    
    if(right_child > heap_size){
        return left_child;
    }

    if(my_heap[left_child] < my_heap[right_child]){
        return right_child;
    }
    else{
        return left_child;
    }

}

void dequeue(void){
    if(heap_size ==0){
        cout << "heap이 비어있음" << endl;
        return;
    }

    if(heap_size == 1){
        cout << my_heap[heap_size] <<endl;
        heap_size--;
        
        return;
    }
    int res = my_heap[1];
    cout << res << endl;
    swap(my_heap, 1, heap_size);
    heap_size--;
    int me = 1;
    int find = find_index(me);

    while(1){
        if(find ==0){
            return;
        }
        else if(my_heap[find] > my_heap[me]){
            swap(my_heap,me, find);
            me = find;
            find = find_index(me);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define heap_len 20
int my_heap[heap_len];
int heap_size =0;

void swap(int my_heap[], int me, int parent){
    int temp = my_heap[me];
    my_heap[me] = my_heap[parent];
    my_heap[parent] = temp;
}

void enqueue(int data){
    if(heap_size == heap_len-1){
        return;
    }
    heap_size++;

    my_heap[heap_size] = data;

    int me = heap_size;
    int parent = me/2;

    while(1){
        if(me==1){
            
            return;
        }
        
        if(my_heap[me] < my_heap[parent]){
            return;
        }
        else{
            swap(my_heap, me, parent);
            me = parent;
            parent = me/2;
        }
    }
}

int find_index(int me){
    int left_child = me*2;
    int right_child = left_child +1;

    //자식이 없는 경우를 의미한다.
    if(left_child > heap_size){
        return 0;
    }
    if(right_child > heap_size){
        return left_child;
    }
    if(my_heap[left_child] < my_heap[right_child]){
        return right_child;
    }
    else{
        return left_child;
    }
}

void dequeue(void){
    if(heap_size == 0){
        cout << "empty" << endl;
        return;
    }
    if(heap_size == 1){
        cout << my_heap[heap_size] << endl;
        heap_size--;
        return;
    }
    //일단 root에 있는것이 제일 큰 노드일 것이다.
    int res = my_heap[1];
    cout << res << " ";
    //이제 다 넣었으니까 맨 위에 꺼랑 맨 아래꺼를 바꿔준다.
    swap(my_heap, 1, heap_size);
    heap_size--;
    int me =1;
    int find = find_index(me);

    //이제 맨 위에 꺼를 아래로 내려준다.
    while(1){
        if(find == 0){
            return;
        }
        else if(my_heap[find] > my_heap[me]){
            swap(my_heap, me, find);
            me = find;
            find = find_index(me);
        }
        else if(my_heap[find] < my_heap[me]){
            return;
        }
    }
}

void show(int my_heap[], int heap_size){
    for(int i=1; i<=heap_size; i++){
        cout << my_heap[i] << " ";
    }
    cout << endl;
}

int main(void){
     enqueue(10);
    enqueue(100);
    enqueue(5);
    enqueue(1000);
    enqueue(20323);

    show(my_heap, heap_size);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    cout << endl;
    return 0;

}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
//quick sort를 구현해보자

using namespace std;

void swap(int data[], int a, int b){
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void quick_sort(int data[], int start, int end){
    int pivot = start;
    int low = start +1;
    int high = end;

    if(start >= end){
        return;
    }

    //일단 low랑 high가 바뀔 때까지 계속 진행한다.

    while(low <= high){
        while(data[pivot] > data[low] && low <=end){
            //pivot이 low보다 작을때까지 계속늘려준다.
            low++;
        }
        while(data[pivot] <= data[high] && high >= start +1){
            high--;
        }
        //이제 다 이동을 해주었고 low랑 high가 만족을 한다면 
        if(low < high){
            swap(data, low, high);
        }
    }
    //이제 low랑 high가 역전이 되었음
    swap(data, high, pivot);
    //이제 quick osrt을 실행해준다.
    quick_sort(data, start , high-1);
    quick_sort(data, high+1, end);
}


int main(void){
	int data[] = {23,32,34,100,87,76,23,65,2,90,21,1,3};
	int sz = sizeof(data)/sizeof(data[0]);
    //시작 끝점을 입력한다.
	quick_sort(data,0,sz-1);

    for(int i=0; i<sz; i++){
        cout << data[i] << " ";
    }
	
	return 0;
}
#endif 

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int MinDistance = 99999999;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;

//초기화를 하면 다 0값이 나온다.
bool visited[14] = {false,};

void selection_chicken(int index, int depth);
void calculation(void);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    //0은 빈칸, 1은 집, 2는 치킨집이다.
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];

            if(graph[i][j]==1){
                home.push_back(make_pair(i,j));
            }
            else if(graph[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    //이제 모든 값을 넣었음 
    //이제 M개 의 치킨집을 골라야한다.
    selection_chicken(0,0);

    cout << MinDistance << endl;
    return 0;
}

void calculation(void){
    //여기서는 선택된 치킨집에서 거리를 구한다.
    int total=0;

    for(int i=0; i < home.size(); i++){
        int min_distance=999999;
        
        for(int j=0; j< chicken.size(); j++){
            if(visited[j] == true){
                int house_Distance= abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);

                if(min_distance >  house_Distance ){
                    min_distance = house_Distance;
                }
            }
        }
        total += min_distance;
    }

    if(MinDistance > total){
        MinDistance = total;
    }
}



void selection_chicken(int index, int depth){
    //M개를 다 골랐으면 
    if(depth == M){
        //계산하는 함수를 실행시킨다.
        calculation();
        return;
    }

    //치킨 배열을 chickent vector에 넣어주었기 때문에
    for(int i=index; i < chicken.size(); i++){
        if(visited[i] == false){
            visited[i] = true;
            selection_chicken(i, depth+1);
            visited[i] = false;
        }
    }
}
#endif

#if 0
#include <iostream>
#inlcude <vector>
#include <algorithm>
#include <queue>

using naemspace std;

vector<vecot<int>> graph;
vecotR<bool>visited;
vector<int> answer;

void search_node(int start_node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    graph.resize(N+1);
    answer.resize(N+1);
    visited.resize(N+1, false);
}

void search_node(int start_vertex){
    queue<int> myqueue;

    visited[start_vertex] = true;
    myqueue.push(start_vertex);

    while(!myqueue.empty()){
        int current = myqueue.front();
        myqueue.pop();
        for(int i: graph[current]){
            if(!visted[i]){
                visited[i] = true;
                answer[i]++;
                myqueue.push(i);
            }
        }
    }
}

void BFS(int start_node){
    queue<int> myqueue;
    myqueue.push(start_node);
    visited[start_node] =1;
}
#endif

#if 0
//최소스패닝 트리임.
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

//cycle이 있는지 없는지를 확인한다.
vector<int> parent;
int result =0;
int V,E;

struct compare{
    bool operator()(tuple<int,int,int> & a, tuple<int,int,int> & b){
        //차례대로 시작 node, 종점 node , 가중치이다.
        if(get<2>(a) > get<2>(b)){ //오름 차순으로 정렬을 한다.
            return true;
        }
        else{
            return false;
        }
    }
};

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> myqueue;

int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}

void union_function(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b] = a;
    }
    else{
        return;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    parent.resize(V+1);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    for(int i=0; i<E; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        
        myqueue.push(make_tuple(start, end, weight));
    }

    //이제 V-1 만큼 돌면서 Cycle이 발생하는지 확인한다.
    int nCycle = 0;

    while(nCycle < V-1){
        //우선 순위 queue에 따라 가중치가 가장 작은 것을 선택한다.
        tuple<int,int,int> now = myqueue.top();
        int now_x = get<0>(now);
        int now_y = get<1>(now);
        int weight = get<2>(now);

        //골랐으면 x,y의 node의 parent가 같은지 확인한다.
        if(find(now_x) == find(now_y)){
            myqueue.pop();
            continue;
        }
        else{
            union_function(now_x, now_y);
            nCycle++;
            result += weight;
            myqueue.pop();

        }
    }

    cout << result << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX 15

using namespace std;

int N=0;
int col[MAX] = {0,};

bool condition(int i);
void queen_N(int i);
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    queen_N(0);

    cout << result << endl;

    return 0;
}

void queen_N(int i){
    if(i == N){
        result++;
        return;
    }

    for(int j=0; j<N; j++){
        col[i]=j;

        if(condition(i)){
            cout << i << endl;
            queen_N(i+1);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int N,Q;
//F에는 자리별 만들 수 있는 경우의 수를 저장한다.
//S에는 순열을 담는 배열을 저장한다.
static long F[21], S[21];
static bool visited[21] = {false},;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    coutt.tie(NULL);

    cin >> N >> Q;
    //0번째 자리는 0으로 설정을 해준다.
    F[0]=1;

    for(int i=1; i<=N; i++){
        F[i] = i*F[i-1];
    }

    if(Q==1){
        long K;
        //몇번째 순열을 출력할 건지 결정을 한다.
        cin >> K;

        for(int i=1; i<=N; i++){
            for(int j=1, cnt=1; j<=N; j++){
                //이미 사용한 숫자는 사용 못함
                if(visited[j] == true){
                    continue;
                }
                if(K <=cnt*F[N-i]){
                    K = K - (cnt-1)*F[N-i];
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
            
        }
        for(int u=1; i<=N ; u++){
            cout << S[u] << " ";
        }
    }
    else{
        long K=1;

        for(int i=1; i<=N ; i++){
            cin >> S[i];
            long cnt =0;

            for(int j=1; j<S[i]; j++){
                if(visited[j] == false){
                    cnt++;
                }
            }
            K += cnt * F[N-i];
            visited[s[i]] = true;
        }

        cout << K << endl;
    }
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
vectort<int> parent;
vector<bool> visited;

int LSA(int a, int b);
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    tree.resize(N+1);
    depth.resize(N+1);
    parent.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<N-1; i++){
        int s,e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        int LCA = LSA(a,b);
        cout << LCA << endl;
    }
}

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    int level = 1;
    int now_size =1;
    int count =0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(int next : tree[now_node]){
            if(!visted[next]){
                visited[next] = true;
                myqeueu.push(next);
                panret[next] = now_node;
                //level 1부터 시작
                depth[next] = level;
            }
        }

        //깊이와 parent을 구했음
        count++;
        if(conut == now_node){
            cout =0;
            now_size = myqueue.size();
            level++;
        }
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]){
        int temp =a;
        a = b;
        b = temp;
    }

    while(depth[a]!= depth[b]){
        a = parent[a];
    }

    while(a!=b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

vector<int> parent;
int result =0;

struct compare{
    bool operator()(tuple<int,int,int> &a, tuple<int,int,int> &b){
        if(get<2>(a) > get<2>(b)){//오름 차순으로 정렬한다.
            return true;
        }
        else{
            return false;
        }
    }
};

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parnet[node] = find(parnet[node]);
    }
};

void union_function(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b){
        return;
    }
    else{
        parent[b] = a;

        return;
    }
}

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin >> V >> E;

    parent.resize(V+1);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    for(int i=0; i<E; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        myqueue.push(make_tuple(start, end, weight));
    }

    int edge_add =0;

    while(!myqueue.empty() && edge_add < V-1){
        tuple<int,int,int> now_node = myqueue.top();
        myqueue.pop();
        int start_node = get<0>(now_node);
        int end_node = get<1>(now_node);
        int weight = get<2>(now_node);

        if(find(start_node) == find(end_node)){
            continue;
        }
        else{
            union_function(start_node, end_node);
            edge_add++;
            result +=weight;
        }
    }

    cout << result;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int LSA(int a, int b);
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    tree.resize(N+1);
    depth.resize(N+1);
    parent.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<N-1; i++){
        int s,e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        int LSA = LSA(a,b);
        cout << LSA << endl;
    }
}

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    depth[1] =0;

    int level =1;
    int now_node =1;
    int count =0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(int next : tree[now_node]){
            if(!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                parent[next] = now_node;
                depth[next] = level;
            }
        }
        count++;
        if(count == now_node){
            count =0;
            now_node = myqueue.size();
            level++;
        }
    }
}

int LSA(int a, int b){
    if(depth[a] < depth[b]){
        int temp = a;
        a = b;
        b = temp;
    }

    while(depth[a] != depth[b]){
        a = parent[a];
    }

    while(a!=b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,Q;
long F[21], S[21];
bool visited[21] = {false,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    F[0] =1;

    for(int i=1; i<=N; i++){
        F[i] = i * F[i-1];
    }

    if(Q==1){
        long K;
        cin >> K;

        for(int i=1; i<=N; i++){
            for(int j=1,cnt=1, j<=N; j++){
                if(visited[j]){
                    continue;
                }
                if(K <= cnt*F[N-i]){
                    K = K - (cnt-1)*F[N-i];
                    s[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }

        for(int u=1; u<=N; u++){
            cout << S[u] << " ";
        }
    }
    else{
        long K=1;

        for(int i=1; i<=N; i++){
            cin >> S[i];
            long cnt =0;

            for(int j=1; j<S[j] ; j++){
                if(visted[j] == false){
                    cnt++;
                }
            }
            K += cnt * F[N-i];
            visited[S[i]] = true;
        }

        cout << K << endl;
    }

    return 0;
    
}
#endif

#if 0
#include <iostream>

using namespace std;

static int T,N,M;
static int D[31][31];

int main(void){
    for(int i=1; i<=30; i++){
        D[i][0] =1;
        D[i][1] = i;
        D[i][i] = 1;
    }

    for(int i=2; i<=30; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1]D[j-1] + D[i-1][j];
        }
    }

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N >> M;
        cout << D[M][N] << endl;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10];

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn = 1;

    A.resize(N+1);
    visited.resize(N+1,false);

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        minn = minn * (p*q)/gcd(p,q);
    }

    D[0] = minn;
    DFS(0);

    for(int i=1; i<N; i++){
        minn = gcd(minn,D[i]);
    }

    for(int i=0; i<N; i++){
        D[i] D[i]/minn;
        cout << D[i] << " ";
    }
}

void DFS(int node){
    visited[node] = true;

    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] * (get<2>(i)) / (get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

long gcd(long a, long b){
    if(b==0){
        return a;
    }
    return gcd(b,(a%b));
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int>> party;
int result;
void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >> T;
    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin >> trueP[i];
    }
    party.resize(M);

    for(int i=0; i<M; i++){
        int party_size;
        cin >> party_size;
        cin >> party_size;

        for(int j=0; j<party_size; j++){
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<M; i++){
        parent[i] = i;
    }

    for(int i=0; i<M; i++){
        int firstPeople = party[i][0];
        for(int j=1; j<party[i].size(); j++){
            unionfunc(firstPeople, party[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        bool isPossible = true;
        int cur = party[i][0];
        for(int j=0; j<T; j++){
            if(find(cur) == find(trueP[i])){
                isPossible = false;
                break;
            }
        }

        if(isPossible){
            result++;
        }
    }

    cout << result;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> tree;
int answer =0;
int deleteNode =0;
vector<bool> visited;
void DFS(int number);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N);
    tree.resize(N);

    int root =0;

    for(int i=0; i<N; i++){
        int parent;
        cin >> parent;

        if(parent != -1){
            tree[i].push_back(parent);
            tree[parent].push_back(i);
        }
        else{
            root = -1;
        }
    }

    cin >> deleteNode;

    if(deleteNode  == root){
        cout << 0 << endl;
    }
    else{
        DFS(root);
        cout << answer << endl;
    }

    return 0;
}

void DFS(int number){
    visited[number] = true;
    int cNode =0;

    for(int i : tree[number]){
        if(visited[i] == false && i !=deleteNode){
            cNode++;
            DFS(i);
        }
    }

    if(cNode ==0){
        asnwer++;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;

    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);
    //출발을 1로 설정을 했기 때문디ㅏ.
    mdistance[1] = 0;

    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >>weight;
        edges.push_back(make_tuple(start,end, weight));
    }

    for(int i=1; i<N; i++){
        //모든 노드를 탐색한다.
        for(int j=0; j<M; j++){
            tuple<int,int,int> medges = edges[i];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            //일단 방문을 했어야함
            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    //모든 노드를 갱신했다면 한번 더 사이클을 돌려서 가중치가 바뀌는지 본다.
    for(int j=0; j<M; j++){
        tuple<int,int,int> medges = edges[i];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start] != LONG_MAX && mdistnace[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif

#if 0
//크루스칼 알고리즘
#include <iostream>
#include <limits.h>

using namespace std;

int N,M;

long long mdistance[101][101];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;


    //모든 노드를 고려해준다. 자기자신은 0으로 해주고 다른 자리는 LLONGMAX로 설정을 한다.
    for(int i=1; i<=N; i++){
        for(int j=1; j <= N; j++){
            if(i == j){
                mdistance[i][j] =0;
            }
            else{
                mdistance[i][j] = LLONG_MAX;
            }
        }
    }

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> end;

        //각 정보에 맞게 입력을 해준다.
        if(mdistance[start][end] > weight){
            mdistance[start][end] = weight;
        }
    }


    //이제 모든 정보를 입력 했기때문에 Floyd-warshall 아로리즘을 수행한다.
    //N-1번만 돌리면 모든 경우의 수가 나온다.
    for(int k=1; i<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(mdistance[i][k] != LONG_MAX && mdistance[k][j] != LONG_MAX){
                    if(mdistance[i][j] > mdistance[i][k] + mdistnace[k][j]){
                        mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                    }
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(mdistance[i][j] == LLONG_MAX){
                cout << "0" << " ";
            }
            else{
                cout << mdistance[i][j] << " ";
            }
        }

        cout << endl;
    }

    
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

uisng namespace std;

int N,M;

vector<bool> visited;
vector<vector<int>> graph;
vector<int> mdistnace;
int Min_Distance = INT_MAX;
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

    int index =1;

    //모든 관계를 고려해줘야하고 그 중 최소값을 반환해야한다. 즉 최소 index를 반환해야한다.
    for(int i=1; i<=N; i++){
        int min_distance = BFS(i);

        if(Min_distance > min_distance){
            Min_distance = min_distance;
            index = i;
        }
        else if(Min_distance == min_distance){
            index = min(index, i);
        }

        fill(visited.begin(), visited.end(), false);
        fill(mdistance.begin(), mdistance.end(),0);
    }

    cout << index << endl;
}

int BFS(int i){
    queue<int> myqueue;
    myqueue.push(i);

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        visited[i] = true;
        myqueue.pop();

        for(int node : graph[now_node]){
            if(!visited[node]){
                visited[node]=true;
                mdistance[node] = mdistance[now_node] +1;
                myqueue.push(node);
            }
        }
    }
    int total =0;

    for(int i=1; i<=N; i++){
        total +=mdistance[i];
    }
    
    return total;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <cstirng>

using namespace std;

int N;
int MAP[51][51] = {0,};
int visited[51][51] = {false,};
int mdistance[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct compare{
    bool operator()(pair<int,pair<int,int>> &a, pair<int, pair<int,int>> &b){
        //오름 차순으로 정렬을 한다.
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
            MAP[i][j] = s[j-1] -'0';

            if(MAP[i][j] == 1){
                MAP[i][j] = 0;
            }
            else{
                MAP[i][j] =1;
            }
        }
    }

    for(int i=1; i<=N; i++){
        fill(mdistance[i], mdistance[i] + N+1, INT_MAX);
    }

    mdistance[1][1] =0;

    pd.push(make_pair(0, make_pair(1,1)));

    while(!pd.empty()){
        pair<int,pair<int,int>> now_node = pd.top();
        int distance_node = now_node.first;
        int now_x = now_node.second.first;
        int now_y = now_node.second.second;

        pd.pop();

        //다익스트라는 최소 거리 노드만 체크해주면 되므로 for안에 visitedㅇ를 안해도된다.
        if(visited[now_x][now_y] == true){
            continue;
        }

        visited[now_x][now_y] = true;

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            //범위를 넘어서면
            if(next_x <=0 || next_x > N || next_y <=0 || next_y >N){
                continue;
            }

            if(mdistance[next_x][next_y] > mdistance[now_x][now_y] + MAP[next_x][next_y]){
                mdistance[next_x][next_y] = mdistance[now_x][now_y] + MAP[next_x][next_y];
                pd.push(make_pair(mdistance[next_x][next_y], make_pair(next_x, next_y)));
            }
        }
    }

    cout << mdistance[N][N] << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int LSA(int a, int b);
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    tree.resize(N+1);
    depth.resize(N+1);

    parent.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<N-1; i++){
        int s,e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        int LSA = LSA(a,b);
        cout << LSA << endl;
    }
}

int LSA(int a, int b){
    if(depth[a] < dpeth[b]){
        int temp =a;
        a =b;
        b = temp;
    }

    while(depth[a] != depth[b]){
        a = parent[a];
    }

    while(a!=b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    depth[1] =0;

    int level =1;
    int now_size =1;
    int count =0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(int next : tree[now_node]){
            if(!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                parent[next] = now_node;
                depth[next] = level;
            }
        }

        count++;

        if(count == now_size){
            count =0;
            now_size = myqueue.size();
            level++;
        }
    }
}
#endif

#if 0
#inclnude <iostream>
#include <vector>
#include <algorithm>
#incnlude <queue>

uisng namespace std;

int A,B,C;
int send[6] = {0,0,1,1,2,2};
int receive[6] = {1,2,0,2,0,1};
int bottle[3] = {0,};
int full_standard[3];
vector<int> answer;

bool visited[201][201] = {false,};
int MAX;

void BFS();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++){
        cin >> full_standard[i];
    }

    //이제 물병의 양을 다알 았으니까 BFS를 해준다.
    BFS();

    sort(answer.begin(), answer.end()); //오름차순정렬을 해준다.

    for(int i=0; i<asnwer.size(); i++){
        cout << answer[i] << " ";
    }
}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        int current[3];

        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];

        visited[current[0]][current[1]] = true;

        if(current[0] == 0){
            answer.push_back(current[2]);
        }

        myqueue.pop();

        for(int i=0; i<6; i++){
            int next[3];
            next[0] = current[0];
            next[1] = current[1];
            next[2] = current[2];

            int ns = send[i];
            int nr = reeive[i];

            next[nr] = current[nr] + current[ns];
            next[ns] =0;

            if(next[nr] > full_standard[nr]){
                //넘치면 나머지 전 send 물병에 넘겨주고 리시브 물병은 최대치로
                int rest = next[nr] - full_standard[nr];
                next[ns] = rest;
                next[nr] = full_standard[nr];
            }

            //이제 push를 수해앻준다.
            if(!visited[next[0]][next[1]]){
                myqueue.push(make_pair(next[0],next[1]));
                //push를 했으면 방문 했으니까 visited 처리를 해준다.
                visited[next[0]][next[1]] = true;
            }
        }
    } 
}
#endif

#if 0
#include <iotream>
#include <vector>
#include <qeueue>
#include <algorithm>

using namespace std;

int N,Q;
long F[21], S[21];
bool visited[21] = {false,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    F[0] = 1;

    for(int i=1; i<=N; i++){
        F[i] = i * F[i-1];
    }

    if(Q==1){
        long K;
        cin >> K;

        for(int i=1; i<=N; i++){
            for(int j=1,int cnt=1; j<=N; j++){
                if(visited[j]){
                    continue;
                }

                if(K <= cnt*F[N-i]){
                    K = K - (cnt-1) * (F[N-i]);
                    s[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }

        for(int u=1; u<=N; u++){
            cout << S[u] << " ";
        }
    }

    else{
        long K=1; //처음에는 최소값으로 시작을 한다. 최소값이 1이다.

        for(int i=1; i<=N; i++){
            cin >> S[i];
            long cnt =0;

            for(int j=1; j<S[i]; j++){
                if(visited[j] == false){
                    cin++;
                }
            }
            K+=cnt * F[N-i];
            visited[S[i]] = true;
        }

        cout << K << endl;

    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namesapce std;

vector<string> split_minus;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //일단 문자열을 입력받는다.
    string str;
    cin >> str;

    stringstream input_string;
    input_string.str(str);
    string type_string;

    //이러면 -을 기준으로 짜른 배열이 나오게 된다.
    while(getline(input_string, type_string, '-')){
        split_mius.push_back(type_string);
    }

    int sum=0;
    //split_minus에 -기준으로 저장된 덩어리가 저장되어 있으니 이제 이것을 기준으로 조합
    stringstream front_string;
    //첫번째 꺼는 모두 더해줘야하기 때문이다.
    front_string.str(split_minus[0]);

    while(getline(front_string, type_string, '+')){
        sum += stoi(type_string);
    }

    //이제 첫번째 sum이 나오게 되고 나머지 들은 다 더하면된다.
    for(int i=1; i< split_minus.size(); i++){
        int minus_sum =0;
        stringstream unit_minus;
        unit_minus.str(split_minus[i]);

        while(getline(unit_minus, type_string, '+')){
            minus_sum += stoi(type_string); 
        }

        //이제 각 조각의 전체 -를 구했기 때문에 이것을 진짜 sum에서 빼준다.
        sum -= minus_sum;
    }

    cout << sum << endl;
}
#endif

#if 0
#include <iostream>

using namespace std;

int n;
//총 노드의 개수가 26개라고 문제에서 주어졌기 대문에 이렇게 설정을함
int tree[26][2];
void preorder(int now);
void inorder(int now);
void postorder(intn now);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    //이제 알파벳 대문자를 입력을 받는다.
    for(int i=0; i<n; i++){
        char node_char, left_child, right_child;
        cin >> node_char >> left_child >> right_child;
        //알파벳 대문자를 입력 받았기 때문에 쉽게 바뀌기 위해 숫자로 변경한다.
        int node = node_char -'A';

        //이제 왼쪽 자식, 오른쪽 자식을 비교해준다.
        if(left == '.'){
            //왼쪽 자식이 없으면 leaf node라는 뜻이ㅏㄷ.
            tree[node][0] = -1;
        }
        else{
            tree[node][0] = left_child - 'A';
        }

        if(right == '.'){
            tree[node][1] = -1;
        }
        else{
            tree[node][1] = right_child = 'A';
        }
    }

    //이제 순서에 맞겍 배열을 출력을 해주면된다.
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;
}

//preor
//자기자신, left, right 순으로 출력한다.
void preorder(int node){
    //자식이 없으면 return을 해준다.
    if(now == -1){
        return;
    }
    cout << (char)(node + 'A');
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

void inorder(int now){
    if(now == -1){
        return;
    }
    inorder(tree[now][0]);
    cout << (char)(now + 'A');
    inorder(tree[now][1];)
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(const pair<int,iint> &a, const pair<int,int> &b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,int>> A;

    for(int i=0; i<N; i++){
        int s,e;
        cin >> s >> e;
        A.push_back(make_pair(s,e));
    }

    //이제 뒷숫자가 작은 오름차순으로 정렬을 한다.
    sort(A.begin(), A.end(), compare);

    int count=0;
    int end= -1;

    //총 회의 숫자에서
    for(int i=0; i<N; i++){
        //제일 빨리 끝나는 회의를 첫번째 기준으로 삼음
        if(A[i].first >= end){
            end = A[i].second; //종료시간을 update해줌
            count++;
        }
    }
}

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first ; //오름 차순해주고
    }
    return a.second < b.second; //이것도 오름차순해줌
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> degree;
vector<int> setbuild;
vector<vector<int>> graph;
vector<int> goal;

int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    coutt.ie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,false);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuld == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                degree[i]++;
            }
        }
    }

    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            //차수가 0인 노드는 우선순위가 높으므로 push해준다.
            //전에 지어야할 것이 없는 것을 push해준다.
            myqueue.push(i);
        }
    }

    //이제 push된 것부터 출력을 해준다. 그리고 queue가 빌때까지 출력해준다.
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node : graph[now]){
            //먼저 지어야할것을 down시킨다.
            degree[node]--;

            //push해준다.
            if(degree[node] == 0){
                myqueue.push(node);
            }

            //그 다음에 해당 노드에 먼저 지어야할 건물을 더해준다.
            goal[node] = max(goal[node], goal[now] + setbuild[now]);
        }
    }

    //이제 모든 노드에 자기 자신의 시간을 더한다.
    for(int i=1; i<=N; i++){
        goal[i] = goal[i] + setbuild[i];
        cout << goal[i] << endll
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    priority_queue<int, vector<int>, less<int>> Plus_Component;
    priority_queue<int, vector<int>, greater<int>> Minus_Component;

    int One_Component =0;
    int Zero_Component = 0;

    for(int i=0; i<N; i++){
        int data;
        cin >> data;

        if(data > 1){
            Plus_Component.push(data);
        }
        else if(data == 1){
            One_Component++;
        }
        else if(data == 0){
            Zero_Component++;
        }
        else if(data < 0 ){
            Minus_Component.push(data);
        }
    }

    int result =0;

    //양수는 큰수끼리 곱하고 하나 남으면 더해준다.
    //음수는 작은 수끼리 곱해주고 만약 하나의 음수가 있고 0이 있으면 0이랑 곱해준다.

    while(Plus_Component.size()>1){
        int first = Plus_Component.top();
        Plus_Component.pop();
        int second = Plus_Component.top();
        Plus_Component.pop();
        result = result + first*second;
    }

    if(!Plus_Component.empty()){
        result = result + Plus_Compoent.top();
        Plus_Component.pop();
    }

    while(Minus_Component.size()>1){
        int first = Minus_Component.top();
        Minus_Component.pop();
        int second = Minus_Component.too();
        Minus_Component.pop();
        result = result + first * second;
    }

    if(!Minus_Component.empty()){
        if(!Zero_Component){
            result = result + Minus_Component.top();
            Minus_Component.pop();
        }
    }

    result = result + One_Component;

    cout << result << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlit;
priority_queue<pair<int,int>, vecotr<pair<int,int>>, greater<pair<int,int>>> pd;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K; // K는 start node이다.
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistnace.end(), INT_MAX);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    //처음 거리는 0이니까
    myqueue.push(make_pair(0,K));
    mdistnace[K] = 0;

    while(!myqueue.empty()){
        pair<int,int> current = myqueue.top();
        myqueue.pop();
        int c_v = current.second;

        if(visited[c_v]){
            continue;
        }
        visited[c_v] = true;

        for(int i=0; i< mlist[c_v].size(); i++){
            pair<int,int> tmp = mlist[c_v][i];
            int next = tmp.first;
            int weight = tmp.second;

            if(mdistance[next] > mdistance[c_v] + value){
                mdistance[next] = mdistnace[c_v] + value;
                myqueue.push(make_pair(mdistance[next],next));
            }
        }
    }

    for(int i=1; i<mdistnace.size(); i++){
        if(mdistance[i] == INT_MAX){
            cout << " INF" <<endl;
        }
        else{
            cout << mdistance[i] << endl;
        }
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int A,B,C;
int send[6] = {0,0,1,1,2,2};
int receive[6] = {1,2,0,2,0,1};
int bottle[3] = {0,};
int full_standard[3];
vector<int>answer;
//처음에는 모든 visitied을 방문하지 않았기 때문에 이렇게 설정한다.
bool visited[201][201] ={false,};

int MAX;

void BFS();

int main(void){
    ios::sync_with_stdio(fasle);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3;i ++){
        cin >> full_standard[i];
    }
    BFS();

    sort(answer.begin(), answer.end());

    for(int i : answer){
        cout << i <<  " ";
    }
    return 0;
}

void BFS(void ){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        int current[3];

        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];

        visited[current[0]][current[1]] = true;

        if(current[0] == 0){
            answer.push_back(current[2]);
        }
        
        //그 다음에 next 용량을 계산한다.
        myqueue.pop();

        for(int i=0; i<6; i++){
            //여기서 send랑 receive를 구해야한다.
            int next[3];
            next[0] = current[0];
            next[1] = current[1];
            next[2] = current[2];

            //다음 것을 정의해준다.
            next[nr] = current[nr] + current[ns];
            next[ns] = 0;

            if(next[nr] > full_standard[nr]){
                //넘치는 경우가 생긴다.
                int rest = next[nr] - full_standard[nr];
                next_s = rest;
                next[nr] = full_standard[nr];
            }

            //이제 push를 해준다.
            //3개니까 next[0] next[1]를 보내면 자연스럽게 next[2]를 알 수 있음
            if(!visited[current[0]][current[1]]){
                myqueue.push(make_pair(next[0], next[1]));
                visited[next[0]][next[1]] = true;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

vector<int> parent;
int result =0;

struct compare{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        if(get<2>(a) > get<2> (b)){
            return true;
        }
        else{
            return false;
        }
    }
};

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void union_function(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return;
    }
    else{
        panret[b] =a;
        return;
    }
}

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;

    cin >> V >> E;

    parent.resize(V+1);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    for(int i=0; i<E; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        myqueue.push(make_tuple(start, end, weight));
    }

    int edge_add =0;

    while(edge_add < V-1){
        tuple<int,int,int> now_node = myqueue.top();
        myqueue.pop();
        int start_node = get<0>(now_node);
        int end_node = get<1>(now_node);
        int weight = get<2>(now_node);

        if(find(start_node) == find(end_node)){
            continue;
        }
        else{
            union_function(start_node, end_node);
            edge_add++;
            result +=weight;
        }
    }
    cout << result << endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M, sCity, eCity;
vector<long> mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //여기서 N은 도시 개수를 의미함.
    cin >> N >> sCity >> eCity >> M;
    mdistnace.resize(N);
    cityMoney.reseize(N);
    
    //최대값을 구하는 문제기 때문에 LONG_MIN으로 초기화 시킨다.
    fill(mdistance.begin(), mdistnace.end(), LONG_MIN);

    for(int i=0; i<M; i++){
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end , price));
    }

    //이제 각도시의 비용을 입력해준다.
    for(int i=0; i<N; i++){
        cin >> cityMoney[i];
    }

    //시작할때 시작 노시의 돈을 획득할수 있음
    mdistnace[sCity] = cityMoney[sCity];

    //충분히 돌려준다.
    for(int i=0; i <=N+50; i++){
        for(int j=0; j<=edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            //이 도시까직 가는데 필요한 비용을 말한다.
            int weight = get<2>(edges[j]);

            if(mdistance[start] == LONG_MIN){
                continue;
            }

            //양수 사이클이 존재하면 넘어간다.
            else if(mdistnace[start] == LONG_MAX){
                mdistance[end] = LONG_MAX;
            }

            else if(mdistance[end] < mdistnace[start] + cityMoney[end] -wieght ){
                mdistance[end] = mdistance[start] + cityMoney[end] -weight;

                //사이클을 충분히 돌았는데 여기에 들어오면 문제가 있는것
                if(i >= N-1){
                    mdistance[end] = LONG_MAX;
                }
            }
        }
    }

    
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

uisng namespace std;

struct compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first > b.first){
            return true;
        }
        else{
            return false;
        }
    }
};

struct compare1{
    bool operator()(int a, int b){
        //내림차순으로 정렬을 한다.
        if(a < b){
            return true;
        }
        else{
            return false;
        }
    }
};

int N,M,K;

vector<int> visited;
vector<vector<pair<int,int>>> graph;
vector<int> mdistance;

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pd;
priority_queue<int,vector<int>, compare1> disQueue[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end, weight));
    }

    //처음 거리는 모두 무한대로 설정을 해준다. 그래야지 잘 됨
    distance.resize(N+1, INT_MAX);

    //처음 거리는 0, 시작노드는 1이다.
    distance[1] =0;
    pd.push(make_papir(0,1));
    //일단 1번 노드의 최단거리는 0이다.
    disQueue[1].push(0);

    while(!pd.empty()){
        pair<int,int> u = pd.top();
        int now = u.second;
        int distance = u.first;

        pd.pop();

        //now에 연결된 시작노드에서 end node를 탐색한다.
        for(pair<int,int> next_node : graph[now]){
            int end = next_node.first;
            int wegiht = next_node.second;

            //지정된 경로가 K개가 안됐을때는 그냥 추가를 해준다.
            if(disQueue[end].size() < K){
                disQueue[end].push(distance + weight);
                //이제 여기 있는 정보도 push를 해줘야한다.
                pd.push(make_pair(distance + weight , end));
            }
            //여기서는 경쟁을 하게 된다.
            else if(disQueue[end].size() >=K && disQueue[end].top() > distance + wegiht){
                //내림 차순을 했기때문에 가장큰 것이 top에 있음
                disQueue[end].pop();
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distance+weight, end));
            }
        }
    }

    //이제 모든 K 값을 다 넣어 주었음. 이제 비교를 해야함

    for(int i=1; i<=N; i++){
        //K개가 다 찼으면 K번째 노드를 출력한다.
        if(disQueue[i].size == K){
            cout << disQueue[i].top() << endl;
        }
        //만약 K가 다 차지 않았다면 출력을 한다.
        else{
            cout << "-1" << endl;
        }
    }
}
#endif

#if 0
//kruscal로 모드 노드에서 최소 거리를 구하기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
//최대 node의 수는 100으로 설정을 함.
int distnace[101][101];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL)
    cin >> N >> M;

    //이제 초기화 작업을 해줌.
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j){
                mdistnace[i][j] =0;
            }
            else{
                mdistance[i][j] = LLOMG_MAX;
            }
        }
    }


    //초기화를 해주었으면 이제 모든 node의 최단 거리를 구한다.

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;

        if(mdistance[start][end] > weight){
            mdistnace[start][end] = weight;
        }
    }

    //거리 정보를 갱신했으면
    for(int k=1; i<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                //경우하는 지점에는 무한대 값이 있으면 안됨
                if(mdistance[i][k] != LLONG_MAX && mdistance[k][j] !=LLONG_MAX){
                    if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j]){
                        mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                    }
                }
            }
        }
    }
    //모든 정보를 갱신했음

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(mdistance[i][j] == LLONG_MAX){
                cout << "0" << " ";
            }
            else{
                cout<< mdistance[i][j] <<" ";
            }
        }
        cout << endl;
    }

    return 0;
}
#endif

#if 0
//문자열에 따라 최소, 최대를 만들어라

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> split_minus;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    stringstream input_string;
    input_string.str(str);
    string type_string;

    while(getline(input_string, type_string, '-')){
        split_minus.push_back(type_string);
    }

    int sum =0;
    stringstream plus_string;
    plus_string.str(split_minus[0]);
    string plus_type;

    int sum =0
    while(getline(plus_string, plus_type, '+')){
        sum += stoi(plus_string);
    }

    //이제 빼줄 부분만 남았음

    for(int i=1; i< split_minus.size(); i++){
        int minus_sum =0;
        stringstream plus_string;
        plus_string.str(split_minus[i]);
        while(getline(plus_string, type_string, '+')){
            minus_sum += stoi(type_string);
        }
        //이제 minus 부분을 다 모았으면 빼준다.
        sum -= minus_su,;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pd;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(). 30000000);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    pd.push(make_pair(0,K));
    mdistance[K] =0;

    while(!pd.empty()){
        pair<int,int> current = pd.top();
        pd.pop();
        int c_v = current.second;

        //이제 distnace의 current node를 알았음
        //확정된 node라면 그냥 넘어가도 됨.
        if(visited[c_v]){
            continue;
        }
        visited[c_v] = true;

        for(pair<int,int> a : mlist[c_v]){
            pair<int,int> next_node = a;
            int next_distance = a.first;
            int next_weight = a.second;

            if(mdistance[next_node] > mdistance[c_v] + next_weight){
                mdistance[next_node] = mdistance[c_v] + next_weight;
                pd.push(make_pair(mdistance[next_node], next_node));
            }
        }
    }

    for(int i=1; i<mdistance.size(); i++){
        if(mdistance[i] == 3000000){
            cout << "INF" << endl;
        }
        else{
            cout << mdistance[i] << endl;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

uisng namespace std;

pair<int,int> edges;
int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), 30000000);
    visited.resize(V+1,false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;

        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    myqueue.push(make_pair(0,K));
    mdistance[K]=0;

    while(!myqueue.empty()){
        pair<int,int> current = myqueue.top();
        myqueue.pop();
        int c_v = current.second;

        //만약 방문한 node라면 그냥 넘어간다.

        if(visited[c_v]){
            continue;
        }
        
        visited[c_v] = true;

        for(pair<int,int> node : mlist[c_v]){
            int next_node = node.first;
            int weight_node = node.second;

            if(mdistance[next_node] > mdistance[c_v] + weight_node){
                mdistance[next_node] = mdistance[c_v] + weight_node;
                myqueue.push(make_pair(distance[next_node],next_node));
            }
        }
    }
    
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int LCA(int a, int b);
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    tree.resize(N+1);
    depth.resize(N+1);

    for(int i=0; i<N-1; i++){
        int s,e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    //이제 질의를 시작한다.
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >>b;
        in LCA = LCA(a,b);
        cout << LCA << endl;
        
    }
    
}

//BFS를 이용해dpeth를 구하는 프로그램을 짠다.

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    depth[1] = 0; //첫번째 root node의 깊이를 0이라고 생각ㅎ낟.

    int levle =1;
    int now_size = 1;
    int count =0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(int next : tree[now_node]){
            if(!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                parent[next] = now_node;
                depth[next] = level;
            }
        }

        //이 문를 빠져 나오면 count를 계산한다.
        count++;
        if(count == now_size){
            count=0;
            now_size  = myqueue.size();
            level++;
        }
    }
     
}

int LCA(int a, int b){
    if(depth[a] < depth[b]){
        int temp = a;
        a =b;
        b = temp;
    }

    while(depth[a] != depth[b]){
        a = parent[a];
    }
    while(a!=b){
        a = parent[a];
        b = parnet[b];
    }
    //공통 조상을 출력한다.
    return a;
}
#endif

#if 0
#include <iostream>
#include <limits.h>

using namespace std;

int N,M;

long long mdistance[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j){
                mdistance[i][j] =0;
            }
            else{
                mdistance[i][j] = LLONG_MAX;
            }
        }
    }

    //이제 node의 정보를 입력했으니 node의 정보를 입력받는다.
    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start>> end>> weight;
        
        if(mdistance[start][ned]  >  weight){
            mdistnace[start][end] = weight;
        }
    }

    for(int k=1; i<=N; k++){
        for(int i=1; i <=N; i++){
            for(int j=1; j<=N; j++){
                if(mdistance[i][k] != LLONG_MAX && mdistnace[k][j] != LLONG_MAX){
                    if(mdistance[i][j] > mdistance[i][k] + mdistance[k][j]){
                        mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                    }
                }
            }
        }
    }

    //이제 모든 노드의 정보를 업데이트함.

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(mdistance[i][j] == LLONG_MAX){
                cout << "0" << " ";
            }
            else{
                cout << mdistnace[i][j] << " ";
            }
        }
        cout <<endl;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M, sCity, eCity;
vector<long> mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;

    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistance.end(), LONG_MIN);

    for(int i=0; i<M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start, end, weight));
    }

    //이제 각 도시마다 Money를 입력받음
    for(int i=0; i<N ;i++){
        cin >> cityMoney[i];
    }

    //startcity의 초기값은 그 도시에서 얻을 수 있는 돈이다.
    mdistance[sCity] = cityMoney[sCity];

    //이제 벨만포드알고리즘을 이용해 거리를 계산한다.
    for(int i=0; i<=N+50; i++){
        for(int j=0; j<edges.size(); j++){
            tuple<int,int,int> medges = edges[j];
            int start_node = get<0>(edges[j]);
            int end_node = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            //먼저 연결이 되어 있어야한다. 연결이 되어 있찌 않으면 되돌린다.
            if(mdistance[start_node] == LONG_MIN){
                continue;
            }
            
            else if(mdistance[start_node] == LONG_MAX){
                mdistance[end_node] = LONG_MAX;
            }

            else if(mdistance[end_node] < mdistance[start_node] + cityMoney[end_node] - weight){
                mdistance[end_node] = mdistance[start_node] + cityMoney[end_node] - weight;

                //그리고 N-1이상 돌렸는데 계속 갱신이 되면 이것은 양의 사이클 즉 무한대 값이 있는것
                if(i >= N-1){
                    mdistance[end_node] = LONG_MAX;
                }
            }
        }
    }

    if(mdistance[eCity] == LONG_MAX){
        cout << "Gee" << endl;
    }
    else if(mdistance[eCity] == LONG_MIN){
        cout << "gg" << endl;
    }
    else{
        cout << mdistance[eCity] << endl;
    }

}
#endif

#if 0
#include <iostrea>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> & b){
        return a.first > b.first;
    }
};

vector<bool> visited;
vector<long> mdistance;

vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pd;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    cin >> M;

    visited.resize(N+1,false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }
    int start,end;
    cin >> start >> end;

    mdistance[start] =0;
    myqueue.push(make_pair(0,start));

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance =  now.first;
        int now_node = now.second;

        myqueue.pop();

        //다익스트라 알고리즘이기 때문에 visited를 여기서 해준다.
        if(visited[now_node] == true){
            continue;
        }
        visited[now_node] = true;

        for(pair<int,int> i : mlist[now_node]){
            int next_node = i.first;
            int next_value = i.second;

            if(mdistance[next_node] > mdistance[now_node] + next_value){
                mdistance[next_node] = mdistance[now_node] + next_value;
                myqueue.push(make_pair(mdistance[next_node],next_node));
            }
        }
    }

    //만약 end에 값이 없으면 
    if(visited[end] == true){
        cout << mdistance[end] << endl;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int i);
vector<bool> visited;
vector<vector<int>> graph;
vector<int> mdistance;
int Min_distance = INT_MAX;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(N+1);
    visited.resize(N+1,false);
    mdistance.resize(N+1,0);

    for(int i=0; i<M; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int index =1;

    for(int i=1; i<=N; i++){
        int min_distance = BFS(i);

        if(Min_distance > min_distance){
            Min_distance = min_distance;
            index = i;
        }
        else if(Min_distance == min_distance){
            index = min(index, i);
        }
        //모두 완료를 했으면 이제 초기화를 시켜준다.
        fill(viisted.begin(), visited.end(),false);
        fill(mdistnace.begin(),mdistance.end(), 0);
    }

    //최소가 되는 index를 출력한다.
    cout << index << endl;
}

int BFS(int i){
    queue<int> myqueue;
    myqueue.push(i);

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        visited[i] = true;
        myqueue.pop();

        for(int node : graph[now_node]){
            if(!visited[node]){
                visited[node] = true;
                mdistance[node] = mdistnace[now_node] + 1;
                myqueue.push(node);
            }
        }
    }

    int total =0;

    for(int i=1; i<=N; i++){
        total += mdistnace[i];
    }

    return total;

}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int graph[100][100];
bool visited[100][100] = {0,};
int N,M;
void BFS(int i, int j);

int main(void){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            graph[i][j] = s[j] -'0';
        }
    }
    BFS(0,0);

    cout << graph[N-1][M-1] << endl;
}

void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.front();
        int now_x = now.first;
        int now_y = now.second;
        visited[now_x][now_y] = true;

        myqueue.pop();

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x < 0 || next_x >=N || next_y <0 || next_y >=M){
                continue;
            }
            if(graph[next_x][next_y] !=0 &&  !visited[next_x][next_y]){
                myqueue.push(make_pair(next_x,next_y));
                graph[next_x][next_y] = graph[now_x][now_y] + 1;
                visited[next_x][next_y] = true;
            }
        }
    }
    
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51] = {0,};
int visited[51][51] = {0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void DFS(int i, int j);

int M,N,K; //M은 가로길이, N은 세로길이, K는 배추가 심어져있는 개수이다.

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; //case 입력을 한다.

    cin >> T;

    for(int i=1; i<=T; i++){
        //M은 가로길이, N은 세로길이 이다.
        cin >> M >> N;
        cin >> K;
        //배추가 심어져 있는 case를 입력함
        
        for(int i=0; i<K; i++){
            //가로길이, 세로 길이가 주어진다.
            int w,h;
            cin >> w >> h;
            arr[h][w] = 1;
        }

        int cnt=0;

        //N은 세로길이, M은 가로길이
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }

        //이제 cnt의 개수를 추력한다.
        cout << cnt << endl;

        //이제 초기화를 시킨다.
        for(int i=0; i<N; i++){
            //배추의 길이를 초기화 시킨다.
            fill(arr[i], arr[i] + M, 0);
            fill(visited[i], visited[i] + M, false);
        }
    }

    return 0;
}

//지렁이가 얼마큼 필요한지 구하는 DFS 함수 
void DFS(int i, int j){
    //길이가 1이면 DFS를 수행하면서 0으로 바꿔준다.
    visited[i][j] = 1;
    //arr[i][j] = 0;
    
    for(int u=0; u<4; u++){
        int next_x = i + dx[u];
        int next_y = j + dy[u];

        if(next_x <0 || next_x >= N || next_y < 0 || next_y >= M){
            continue;
        }

        //방문한 곳은 안가도 됨
        if(!visited[next_x][next_y]){
            //1이여야됨.
            if(arr[next_x][next_y] == 1){
                visited[next_x][next_y] = 1;
                //지렁이가 지나갈 수 있는 장소이기 때문에 0으로 초기화를 시킨다.
                arr[next_x][next_y] = 0;

                DFS(next_x, next_y);
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,deleteNode;
void DFS(int node);
vector<int> parent;
vector<vector<int>> graph;
vector<bool> visited;
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N,false);
    parent.resize(N);
    graph.resize(N);
    int root;

    for(int i=0; i< N; i++){
        int parent_node;

        cin >> parent_node;

        if(parent_node == -1){
            root = i;
            continue;
        }

        graph[i].push_back(parent_node);
        graph[parent_node].push_back(i);
    }

    cin >> deleteNode;

    if(deleteNode == root){
        cout << 0 << endl;
    }
    else{
        //이제 DFS를 수행한다.
        DFS(root);
        cout << result << endl;
    }

   

    return 0;
}

void DFS(int node){
    visited[node] = true;
    int cnt =0;
    for(int childNode : graph[node]){
        if(!visited[childNode]){
            if(childNode != deleteNode){
                visited[childNode] = true;
                cnt++;
                DFS(childNode);
            }
        }
    }
    if(cnt ==0){
        result++;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int MinDistance = 999999999;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
bool visited[14] = {false,};

void calculate(void);
void do_it(int idx, int depth);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];

            if(graph[i][j] == 1){
                home.push_back(make_pair(i,j));
            }
            else if(graph[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    //이제 치킨집 M개를 골느다.
    //고른것, depth표현
    do_it(0,0);

    cout << MinDistance << endl;
}

void calculate(void){
    int cityDistance =0;
    for(int i=0; i< home.size(); i++){
        int min_distnace = 999999;
        
        for(int j=0; j<chicken.size(); j++){
            if(visited[j] == false){
                continue;
            }

            int houseDistance = abs(home[i].first - chicken[j].first) + abs(chicken[i].second - home[i].second);

            if(houseDistance < min_distance){
                min_distance = houseDistance;
            }  
        }
        cityDistance +=min_distance;
    }
    if(cityDistance < MinDistance){
        MinDistance = cityDistance;
    }
}

//치킨집 3개를 뽑는다.
void do_it(int idx, int cnt){
    if(cnt == M){
        calculate();
        return;
    }

    //치킨 3개를 고른다.
    for(int i= idx; i< chicken.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            do_it(i, cnt+1);
            visited[i] = false;
        }
    }
}
#endif

#if 0
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
            //visited[collection] = true;
            answer[collection]++;
            DFS(collection);
        }
    }

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> degree;
vector<int> setbuild;
vector<vector<int>> graph;
vector<int> goal;

int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                degree[i]++;
            }
        }
    }

    //위상정렬을 실행한다.
    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            myqueue.push(i);
        }
    }

    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node : graph[now]){
            degree[node]--;

            if(degree[node] == 0){
                myqueue.push(node);
            }

            goal[node] = max(goal[node], (goal[now] + setbuild[now]));
        }
    }

    //이제 모든 사전작업을 마침
    for(int i=1; i<=N ;i++){
        goal[i] += setbuild[i];
        cout << goal[i]<< " ";
    }

}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,Q;
long F[21], S[21];
long visited[21] = {false,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    //자리수 별로 만들 수있는 경우의 수를 집어 넣는다.
    F[0] = 1;

    for(int i=1; i<=N; i++){
        F[i] = i*F[i-1];
    }

    if(Q==1){
        long K;
        cin >> K;

        for(int i=1; i<=N; i++){
            for(int j=1; cnt=1; j<=N; j++){
                if(visited[j]){
                    continue;
                }
                if(K<=cnt*F[N-i]){
                    K = K - (cnt-1)*(F[N-i]);
                    s[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }

        //이제 남은 숫자들을 출력한다.
        for(int u=1; u<=N; u++){
            cout << S[u] << " ";
        }
    }

    else{
        long K=1; //처음에는 최소값 1로 시작을 한다. 최소값이  임
        
        for(int i=1; i<=N; i++){
            cin >> S[i];
            long cnt =0;

            for(int j=1; j<S[i]; j++){
                if(visited[j] == false){
                    cnt++;
                }
            }
            K +=cnt * F[N-i];
            visited[S[i]] = true;
        }

        cout << K << endl;
    }
}
#endif

#if 0
#include <iostream>

using namespace std;

int int T,N,M;
int D[31][31];

int main(void){
    for(int i=1; i<=30; i++){
        D[i][0]=1;
        D[i][i] =1;
        D[i][1] = i;
    }

    for(int i=2; i<=30; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j-1] + D[i-1][j];
        }
    }

    cin >> T;

    for(int i=0; i<T; i++){
        ccin >> N >> M;
        cout << D[M][N] << endl;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int LCA(int a, int b);
void BFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    tree.resize(N+1);
    depth.resize(N+1);
    parent.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<N-1; i++){
        int s,e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin >> M;

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        int LCA = LCA(a,b);
        cout << LCA << endl;
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]){
        int temp =a;
        a = b;
        b = temp;
    }

    while(depth[a] != depth[b]){
        a = parent[a];
    }

    while(a !=b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    
    visited[node] = true;
    depth[1] = 0;

    int level =1;
    int now_size = 1;
    int count =0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(int next : tree[now_node]){
            if(!visited[next]){
                visited[next] = true;
                myqueue.push(next);
                parent[next] = now_node;
                depth[next] = level;
            }
        }

        count++;
        if(count == now_size){
            count =0;
            now_size = myqueue.size();
            level++;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

uinsg namespace std;

int N,M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);

    mdistance[1]=0;

    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start, end ,weight));
    }

    //이제 다 넣었으니까 N-1번 만큼 반복한다.
    for(int i=1; i<=N-1; i++){
        for(int j=0; j < edges.size(); j++){
            tuple<int,int,int> medges = edges[i];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            if(mdistance[start]!=LONG_MAX && mdistnace[end] > mdistance[start] + weight){
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    for(int j=0; j<M; j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 >> endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
    
}
#endif

#if 0
#include <iostream>
#include <limits.h>
#include <tuple>

using namespace std;

int result =0;
vector<int> parent;

struct compare{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        if(get<2>(a) > get<2>(b)){
            return true;
        }
        else{
            return false;
        }
    }
};

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void union_function(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return;
    }
    else{
        parent[b] = a;
        return;
    }
    
}

priority_queue<tuple<int,int.int>, vector<tuple<int,int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin >> V >> E;

    parent.resize(V+1);

    for(int i=1; i<=V; i++){
        parent[i]=i;
    }

    for(int i=0; i<E; i++){
        int start,end,weight;
        cin >> start >> end >> weight;
        myqueue.push(make_tuple(start,end,weight));
    }

    int edge_add =0;

    while(edge_add < V-1){
        tuple<int,int,int> now_node = myqueue.top();
        myqueue.pop();
        int start_node = get<0>(now_node);
        int end_node = get<1>(now_node);
        int weight = get<2>(now_node);

        if(find(start_node) == find(end_node)){
            continue;
        }
        else{
            union_function(start_node, end_node);
            edge_add++;
            result +=wegiht;
        }

    }

    cout << result;


}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.first > b.first;
    }
};

vector<bool> visited;
vector<long> mdistance;

vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pd;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    int start, end;
    cin >> start >> end;

    mdistance[start] =0;

    myqueue.push(make_pair(0,start));

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int next_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node] = true;

        for(pair<int,int> i : mlist[now_node]){
            int next_node = i.first;
            int next_value = i.second;

            if(mdistance[next_node] > mdistance[now_node] + next_value){
                mdistance[next_node] = mdistance[now_node] + next_value;
                myqueue.push(make_pair(mdistance[next_node], next_node));
            }
        }
    }

    if(visited[end] == true){
        cout << mdistance[end] << endl;
    }

    
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define Max 15

uisng namesapce std;

int N=0;
int col[Max] = {0,};

bool condition(int i);
void queen_N(int i);
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    queen_N(0);

    cout << result << endl;

    return 0l
}

void queen_N(int i){
    if(i==N){
        result++;
        return;
    }

    for(int j=0; j<N; j++){
        col[i] = j;

        if(condition(i)){
            queen_N(i+1);
        }
    }
}

bool condition(int i){
    for(int k=0; k<i; i++){
        if(col[k] == col[i] || abs(col[k] - col[i]) == i-k){
            return false;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10];

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn =1;

    A.resize(N+1);
    visited.resize(N+1,false);

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a >> b >>p >> q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        minn = minn*(p*q)/gcd(p,q);
    }

    D[0] = minn;

    DFS(0);

    for(int i=1; i<N; i++){
        minn = gcd(minn, D[i]);
    }

    for(int i=0; i<N; i++){
        D[i] = D[i]/minn;
        cout << D[i] << " ";
    }
    return 0;



}

void DFS(int node){
    visited[node] = true;
    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] * get<2>(i) / get<1>(i);
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

long gcd(long a, long b){
    if(b==0){
        return a; 
    }
    else{
        return gcd(b,(a%b));
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
int MAP[51][51] = {0,};
int visited[51][51] ={0,};
int mdistance[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct compare{
    bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
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

        if(visited[now_x][now_y] == true){
            continue;
        }
        visited[now_x][now_y] =true;

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x <=0 || next_x > N || next_y <=0 || next_y >N){
                continue;
            }

            if(mdistance[next_x][next_y] > mdistance[now_x][now_y] + MAP[next_x][next_y]){
                mdistance[next_x][next_y] = mdistance[now_x][now_y] + MAP[next_x][next_y];
                pd.push(make_pair(mdistnace[next_x][next_y], make_pair(next_x, next_y)));
            }
        }
    }

    cout << mdistance[N][N] << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M, sCity, eCity;
vector<long> mdistance, cityMoney;
vector<tupple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistnace.end(), LONG_MIN);

    for(int i=0; i<M; i++){
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end, price));
    }

    for(int i=0; i<N; i++){
        cin >> cityMoney[i];
    }

    mdistance[sCity] = cityMoney[sCity];

    for(int i=0; i<=N+50; i++){
        for(int j=0; j<edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            //일단 연결은 되어 있어야지 가중치를 뽑을 수 있음
            if(mdistance[start] == LONG_MIN){
                continue;
            }

            else if(mdistance[start] == LONG_MAX){
                mdistance[end] = LONG_MAX;
            }

            //시작 노드가 양수 사이클에 연결된 노드라면 종료하고
            else if(mdistance[end] < mdistance[start] + cityMoney[end] - weight){
                mdistance[end] = mdistance[start] + cityMoney[end] - weight;

                //만약 사이클인 넘어갔는데도 바뀌면 문제가 있음
                if(i >=N-1){
                    mdistance[end] = LONG_MAX;
                }
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51] = {0,};
int visited[51][51] = {0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void DFS(int i, int j);

int M,N,K;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;

    cin >> T;

    for(int i=1; i<=T; i++){
        cin >> M >> N;
        cin >> K;

        for(int i=0; i<K; i++){
            int w,h;
            cin >> w >> h;
            arr[h][w] = 1;
        }

        int cnt=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;

        for(int i=0; i<N; i++){
            fill(arr[i], arr[i] + M, 0);
            fill(visited[i], visited[i] + M, false);
        }
    }

    return 0;
}

void DFS(int i, int j){
    visited[i][j] = true;
    arr[i][j] = 0;

    for(int u=0; u<4; u++){
        int next_x = i + dx[u];
        int next_y = j + dy[u];

        if(next_x <0 || next_x >=N || next_y <0 || next_y >=M){
            continue;
        }

        if(!visited[next_x][next_y]){
            if(arr[next_x][next_y] == 1){
                visited[next_x][next_y] = true;
                arr[next_x][next_y] = 0;
                DFS(next_x, next_y);
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int A,B,C;
int send[6] = {0,0,1,1,2,2};
int receive[6] = {1,2,0,2,0,1};
int bottle[3] = {0,};
int full_standard[3];

vector<int> answer;
bool visited[201][201]={false,};
int MAX;

void BFS();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++){
        cin >> full_standard[i];
    }

    BFS();
    sort(answer.begin(), answer.end());

    for(int i : answer){
        cout << i << " ";
    }
}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        int current[3];

        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];

        visited[current[0]][current[1]]= true;

        if(current[0] == 0){
            answer.push_back(current[2]);
        }

        myqueue.pop();

        for(int i=0; i<6; i++){
            int next[3];
            next[0] = current[0];
            next[1] = current[1];
            next[2] = current[2];

            int ns = send[i];
            int nr = receive[i];

            next[nr] = next[nr] + next[ns];
            next[ns] = 0;

            if(next[nr] > full_standard[nr]){
                int rest = next[nr] - full_standard[nr];
                next[ns] = rest;
                next[nr] = full_standard[nr];
            }

            if(!visited[next[0]][next[1]]){
                myqueue.push_back(make_pair(next[0])[next[1]]);
                visited[next[0]][next[1]] = true;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> myqueue;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), 30000000);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    myqueue.push(make_pair(0,K));
    mdistance[K] = 0;

    while(!myqueue.empty()){
        int now = myqueue.top();
        int distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(!visited[now_node]){
            continue;
        }

        visited[now_node] = true;

        for(pair<int,int> node : mlist[now_node]){
            int next_node = node.first;
            int weight = node.second;

            if(mdistance[next_node] > mdistance[now_node] + weight){
                mdistance[next_node] = mdistance[now_node] + weight;
                myqueue.push(make_pair(mdistance[next_node], next_node));
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, less<int>> Plus_Compoenet;
    priority_queue<int, vector<int>, greater<int>> Minus_Component;

    int One_Component = 0;
    int Zero_Component = 0;

    for(int i=0; i<N; i++){
        int data;
        cin >> data;

        if(data > 1){
            Plus_Compoenet.push(data);
        }
        else if(data < 0 ){
            Minus_Component.push(data);
        }
        else if(data == 1){
            One_Component++;
        }
        else if(data == 0){
            Zero_Component++;
        }
    }


        int total_result =0;
        //이제 모든 컴포넌트를 확인햇음

        while(Plus_Compoenet.size() > 1){
            int plus_1 = Plus_Compoenet.top();
            Plus_Compoenet.pop();
            int plus_2 = Plus_Compoenet.top();
            Plus_Compoenet.pop();

            int result = plus_1 * plus_2;
            total_result+= result;
        }

        if(!(Plus_Compoenet.empty())){
            total_result += Plus_Compoenet.top();
            Plus_Compoenet.pop();
        }

        while(Minus_Component.size() > 1){
            int minus_1 = Minus_Component.top();
            Minus_Component.pop();
            int minus_2 = Minus_Component.top();
            Minus_Component.pop();

            int result = minus_1 * minus_2;

            total_result += result;
        }

        if((!Minus_Component.empty()) && Zero_Component == 0){
            total_result += Minus_Component.top();
            Minus_Component.pop();
        }
    

    cout << total_result + One_Component << endl;
    
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define heap_len 20
int my_heap[heap_len];
int heap_size =0;

void swap(int my_heap[], int me, int parent){
    int temp = my_heap[me];
    my_heap[me] = my_heap[parent];
    my_heap[parent] = temp;
}


//값을 넣어주는 sequence
void enqueue(int _data){
    if(heap_size == heap_len -1){
        return;
    }
    heap_size++;

    my_heap[heap_size] = _data;

    int me = heap_size;
    int parent = me/2;

    while(1){
        if(me==1){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] <= my_heap[parent]){
            my_heap[me] = _data;
            return;
        }
        else if(my_heap[me] > my_heap[parent]){
            swap(my_heap,me,parent);
            me = parent;
            parent = me/2;
        }
    }
}

int find_index(int _me){
    int left_child = _me*2;
    int right_child = left_child +1;

    if(left_child > heap_size){
        return 0;
    }
    if(right_child > heap_child){
        return left_child;
    }

    if(my_heap[left_child] < my_heap[right_child]){
        return right_child;
    }
    else{
        return left_child;
    }
}

void dequeue(void){
    if(heap_size ==0){
        return;
    }
    if(heap_size == 1){
        cout << my_heap[1] << endl;
        heap_size--;
        return;
    }

    //일단 위에 있는 것이 가장 큰것
    int rest = my_heap[1];
    cout << rest << " ";
    swap(my_heap,1,heap_size);
    
    heap_size--;
    int me = 1;
    int find = find_index(me);

    //이제 자리를 찾아줌

    while(1){
        if(find ==0){
            return;
        }
        else if(my_heap[find] > my_heap[me]){
            swap(my_heap,me, find);
            me = find;
            find = find_index[me];
        }
        else if(my_heap[find] < my_ehap[me]){
            return;
        }
    }
}

void show(int my_heap[], int heap_size){
    for(int i=1; i<=heap_size; i++){
        cout << my_heap[i] << " ";
    }
    cout << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

uisng namespacee std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
void DFS(int node);
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    graph.resize(N+1);
    visited.resize(N+1,false);
    parent.resize(N+1,0);

    for(int i=0; i<N-1; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    DFS(1);

    for(int i=2; i<=N; i++){
        cout << parent[i] << endl;
    }
    return 0;
}

void DFS(int node){
    visited[node] = true;

    for(int i : graph[node]){
        if(!visited[i]){
            parent[i] = node;
            visited[i] = true;
            DFS(i);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M,sCity,eCity;
vector<long> mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistance.end(), INT_MAX);

    for(int i=0; i<M; i++){
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tupel(start, end, price));
    }

    for(int i=0; i<N ;i++){
        cin >> cityMoney[i];
    }

    mdistance[sCity] = cityMoney[sCity];

    for(int i=0; i<=N+50; i++){
        for(int j=0; j<edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            if(mdistance[start] == LONG_MIN){
                continue;
            }
            else if(mdistance[start] == LONG_MAX){
                mdistance[end] = LONG_MAX;
            }

            else if(mdistance[end] < mdistnace[start] + cityMoney[end] - weight){
                mdistance[end] = mdistance[start] + cityMoney[end] - weight;

                if(i >=N-1){
                    mdistnace[end] = LONG_MAX;
                }
            }
        }
    }
}
#endif

#if 0
//이분 그래프문제

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

void DFS(int i);
int K,V,E;
vector<vector<int>> distance_info;
vector<bool> mdistance;
vector<int> check;
int flag = false;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K; //K는 test를 몇번할 것인가.....

    for(int j=0; j<K; j++){
        flag = false;
        cin >> V >> E;

        distance_info.resize(V+1);
        mdistance.resize(V+1, false);
        check.resize(V+1,0);

        for(int i=0; i<E; i++){
            int start, end;
            cin >> start >> end;
            distance_info[start].push_back(end);
            distance_info[end].push_back(start);
        }

        //이제 모든 노드에 대해 DFS를 실행해준다.
        for(int i=1; i<=V; i++){
            DFS(i);
        }

        //검증이 끝났으니 이제 초기화를 한다.
        fill(mdistance.begin(), mdistance.end(), false);

        for(int i=1; i<=V; i++){
            distance_info[i].clear();
        }

        //chekc 부분도 clear을 시켜준다.
        cheick.clear();

        if(flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }

    return 0;
}

void DFS(int i){
    //방문을 했으면 일단 true로 설정을 해둔다.
    mdistance[i] = true;

    for(int node : distance_info[i]){
        if(mdistance[node] == false){
            check[node] = (check[i] + 1) %2;
            DFS(node);
        }
        else if(mdistance[node] == true){
            if(check[node] == check[i]){
                flag = true;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int N,Q;
//F에는 자리별 만들 수 있는 경우의 수를 저장한다.
//S에는 순열을 담는 배열임
//visited는 숫자 사용 여부를 물어본다.
static long F[21], S[21];
static bool visited[21] = {false,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    F[0] = 1;

    for(int i=1; i<=N; i++){
        F[i] = F[i-1] * i;
    }

    if(Q == 1){
        long K; //몇번째 순열을 출력할 건지 결정한다.
        cin >> K;

        for(int i=1; i<=N; i++){
            for(int j=1; cnt=1; j<=N; j++){
                //이미 사용한 숫자는 사용 안함
                if(visited[j]){
                    continue;
                }
                if(K <= cnt * F[N-i]){
                    K = K - (cnt-1) * F[N-i];
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }
        for(int u=1; u<=N; u++){
            cout << S[u] << " ";
        }
    }

    else{
        long K =1;

        for(int i=1; i<=N; i++){
            cin >> S[i];
            long cnt =0;

            for(int j=1; j<S[j]; j++){
                if(visited[j] == false){
                    cnt++;
                }
            }
            K += cnt*F[N-i];
            visited[S[i]] = true;
        }
        cout << K << endl;
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10];

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn =1;

    A.resize(N+1);
    visited.resize(N+1,false);

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_pair(b,p,q));
        A[b].push_back(make_pair(a,q,p));
        minn = minn*(p*q)/gcd(p,q);
    }

    D[0] = minn;

    DFS(0);

    for(int i=1; i<N; i++){
        minn = gcd(minn, D[i]);
        //최소공배수를 구한다.
    }

    for(int i=0; i<N; i++){
        D[i] = D[i] / minn;
        cout << D[i] << " ";
    }
    
    return 0;

}

void DFS(int node){
    visited[node] = true;
    
    for(tuple<int,int,int> i : A[node]){
        if(!visited[i]){
            D[get<0>(i)] = D[node] * (get<2>(i))/ (get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

long gcd(long a, long b){
    if(b ==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int D[201][201];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;

    cin >> N >> M >> K;

    for(int i=1; i<=200; i++){
        D[i][0] = 1;
        D[i][1] = i;
        D[i][i] = 1;
    }

    for(int i=1; i<=200; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1];

            //이 부분 왜하는지 확실치않음
            if(D[i][j] > 1000000000){
                D[i][j] = 10000000000;
            }
        }
    }

    if(D[N+M][M] < K){
        cout << "-1" << endl;
        return 0;
    }

    //이제 사전순서를 고려해준다.
    while(M){
        if(D[M+N-1][M] >= K){
            cout << "a";
            N--;
        }
        else if(D[M+N-1][M] < K){
            cout << "z";
            K = K - D[N+M-1][M];
            M--;
        }
    }

    for(int i=0; i<N; i++){
        cout << "a";
    }

    cout << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first > b.first){
            return true;
        }
        else{
            return false;
        }
    }
};

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>,compare> pd;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    myqueue.push(make_pair(0,K));
    mdistance[K] =0;

    while(!myqueue.empty()){
        pair<int,int> current = myqueue.top();
        myqueue.pop();
        int c_v = current.second;

        if(visited[c_v]){
            continue;
        }
        visited[c_v] = true;

        for(int i=0; i < mlist[c_v].size(); i++){
            pair<int,int> tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;

            if(mdistance[next] > mdistance[c_v] + value){
                mdistance[next] = mdistance[c_v] + value;
                myqueue.push(make_pair(mdistance[next], next));
            }
        }
    }
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node *root =0;

void addToData(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = root;
    newnode->left = newnode->right =0;
    newnode->data = n;

    if(root ==0){
        root = newnode;
        return;
    }

    while(1){
        if(temp->data > n){
            if(temp->left ==0){
                temp->left = newnode;
                return;
            }
            else{
                temp = temp->left;
            }
        }

        else if(temp->data <= n){
            if(temp->right == 0){
                temp->right = newnode;
                return;
            }
            else{
                temp = temp->right;
            }
        }
    }
}

void delFromBST(int data, struct node* r){
    struct node *t = r;
    struct node *t_p = 0;

    while(1){
        if(t==0){
            return;
        }

        else if(t->data == data){
            if(t->left == 0 && t->right == 0){
                if(t==root){
                    root =0;
                    free(t);
                    return;
                }

                if(t_p->left == t){
                    t_p->left =0;
                }
                else if(t_p->right == t){
                    t_p->right = 0;
                }
                free(t);
                return;
            }

            else if(t->left !=0 && t->right == 0){
                if(t == root){
                    root = t->left;
                    free(t);
                    return;
                }

                if(t_p->left == t){
                    t_p->left = t->left;
                    free(t);
                    return;
                }
                
                else if(t_p->right == t){
                    t_p->right = t->left;
                    free(t);
                    return;
                }
            }

            else if(t->left == 0 && t->right != 0){
                if(t == root){
                    root = t->right;
                    free(t);
                    return;
                }
                
                if(t_p->left == t){
                    t_p->left = t-> right;
                    free(t);
                    return;
                }

                else if(t_p->right == t){
                    t_p->right = t->right;
                    free(t);
                    return;
                }
            }

            else if(t->left !=0 && t->right != 0){
                //왼쪽 자식을 고려한다.
                struct node *r = t->left;
                struct node *r_p = t;

                while(r->right != 0){
                    r_p = r;
                    //제일 큰거를 찾아야한다.
                    r = r->right;
                }

                //제일 큰거를 찾았음
                t->data = r->data;

                if(r_p->right == r){
                    r_p->right = r->left;
                }
                else{
                    r_p->left = r->left;
                }
                free(r);
                return;
            }
        }

        else{
            t_p =t;
            if(t->data > data){
                t = t->left;
            }
            else if(t->data <= data){
                t = t->right;
            }
        }
    }
}

struct node* findNode(int _data){
    struct node*cur = root;

    if(cur == 0){
        return 0;
    }

    if(cur->data == _data){
        return cur;
    }
    else if(cur->data > _data){
        cur = cur->left;
    }
    else if(cur->data < data){
        cur = cur->right;
    }
}


//이제 BST 포함된 terminal node의 개수를 구한다.
int cntBSTNodes(struct node *r){
    if(_r ==0 ){
        return 0;
    }

    if(_r->left == 0 && _r->right ==0){
        return 1;
    }
    else{
        return cntBSTNodes(_r->right) + cntBSTNodes(_r->left);
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using naemspace std;

int N;
vector<vector<int>> tree;
int answer =0;
int deleteNode = 0;
vector<bool> visited;
void DFS(int number);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N);
    tree.resize(N);
    int root =0;

    for(int i=0; i<N; i++){
        int parent;
        cin >> parent;

        if(parent != -1){
            tree[i].push_back(parent);
            tree[parent].push_back(i);
        }
        else{
            root = i;
        }
    }

    cin >> deleteNode;

    if(deleteNode == root){
        cout << 0 << endl;
    }

    return 0;
}

void DFS(int number){
    visited[number] = true;
    int cNode =0;

    for(int i: tree[number]){
        if(visited[i] == false && i != deleteNode){
            cNode++;
            DFS(i);
        }
    }

    if(cNode ==0){
        answer++;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm?
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
void DFS(int node);
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    graph.resize(N+1);
    visited.resize(N+1,false);
    parent.resize(N+1,0);

    for(int i=0; i<N-1; i++){
        int start, end;

        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    DFS(1);

    //1이 root니까 parent가 없으니까 1은 뺀다.
    for(int i=2; i<=N; i++){
        cout << parent[i] << endl;
    }

    return 0;
}

void DFS(int node){
    visited[node] = true;

    for(int i: graph[node]){
        if(!visited[i]){
            parent[i] = node;
            visited[i] = true;
            DFS(i);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

void DFS(int i);
int K,V,E;
vector<vector<int>> distance_info;
vector<bool> mdistance;
vector<int> check;
int flag = false;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    for(int j=0; j<K; j++){
        flag = false;
        cin >> V >> E;

        distance_info.resize(V+1);
        mdistance.resize(V+1, false);
        check.resize(V+1,0);

        for(int i=0; i<E; i++){
            int start, end;
            cin >> start >> end;
            distance_info[start].push_back(end);
            distance_info[end].push_back(start);
        }

        //이제 모든 정보를 넣었으니까 DFS로 비교를 해준다.
        //그래프가 다 붙어 있어야 될 보장은 없다.

        for(int i=1; i<=V; i++){
            DFS(i);
        }

        fill(mdistance.begin(), mdistance.end(),false);

        for(int i=1; i<=V; i++){
            distance_info[i].clear();
        }

        check.clear();

        if(flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }

    return 0;
}

void DFS(int i){
    //방문을 했으면 일단 true로 설정을 해준다.
    mdistance[i] = true;

    for(int node : distance_info[i]){
        if(mdistance[node] == false){
            check[node] = (check[i] +1 )%2;
            DFS(node);
        }
        else if(mdistance[node] == true){
            if(check[node] == check[i]){
                flag = true;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> degree;
vector<int> setbuild;
vector<vector<int>> graph;
vector<int> goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

        //이제 build time을 입력했음
        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                degree[i]++;
            }
        }
    }

    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            myqueue.push(i);
        }
    }

    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node : graph[now]){
            degree[node]--;

            if(degree[node] == 0){
                myqueue.push(node);
            }

            goal[node] = max(goal[node] , goal[now] + setbuild[now]);
        }
    }

    for(int i=1; i<=N; i++){
        goal[i] = goal[i] + setbuild[i];

        cout << goal[i] << endl;
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;

    cin >> N >> M;

    mdistance.resize(N+1, LONG_MAX);

    mdistance[1] = 0;

    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start,end,weight));
    }

    //이제 정보를 다 저장했음.
    for(int i=1; i<N; i++){
        for(int j=0; j<M; j++){
            tuple<int,int,int> medges = edges[j];

            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight){
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;

    //일단 음의 사이클이 없으면 false를 입력해준다.
    for(int j=0; j<M; j++){
        tuple<int,int,int> medges = edges[j];
        
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout << -1 << endl;
            }
            else{
                cout << mdistance[i] << endl;
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int>> party;
int result;

void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >> T;
    //일단 진실을 아는 사람의 수를 설정을 해준다.
    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin >> trueP[i];
    }

    party.resize(M);
    
    for(int i=0; i<M; i++){
        int party_size;
        cin >> party_size;

        for(int j=0; j<party_size; j++){
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=0; i<M; i++){
        int firstPeople = party[i][0];
        
        //0번은 위에서 설정을 해주었기 때문에....
        for(int j=1; j<=M; j++){
            unionfunc(firstPeople, party[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        bool isPossible = true;
        int cur = party[i][0];

        for(int j=0; j<T; j++){
            if(find(cur) == find(trueP[i])){
                isPossible = false;
                break;
            }    
        }

        if(isPossible){
            result++;
        }
    }

    cout << result;
}

void unionfunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b] =a;
    }
}

int find(int a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int N;
//총 개수가 50개 이기 때문이다.
int MAP[51][51] = {0,};
int visited[51][51] = {0,};
int mdistance[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct compare{
    bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
        if(a.first > b.first){ // 내림차순임.
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
        for(int j=0; j<s.size(); j++){
            MAP[i][j] = S[j] - '0';

            if(MAP[i][j] == 1){
                MAP[i][j] =0;
            }
            else{
                MAP[i][j] =1;
            }
        }
    }

    //mdistance의 모든 값을 처음에는 INT_MAX로 초기화 시켜준다.
    for(int i=1; i<=N; i++){
        fill(mdistance[i], mdistance[i] + N+1, INT_MAX);
    }

    mdistance[1][1] =0;

    pd.push(make_pair(0,make_pair(1,1)));

    //priority queue에 값이 남아 있지 않을때동안
    while(!pd.empty()){
        pair<int,pair<int,int>> now_now = pd.top();
        int distance_node = now_node.first;
        int now_x = now_node.second.first;
        int now_y = now_node.second.second;
        pd.pop();

        if(visited[now_x][now_y] == true){
            continue;
        }

        visited[now_x][now_y] = true;

        //4가지 방향으로 탐색한다.
        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x <=0 || next_x > N || next_y <=0 || next_y > N){
                continue;
            }

            if(mdistance[next_x][next_y] > mdistance[now_x][now_y] + MAP[next_x][next_y]){
                mdistance[next_x][next_y] = mdistance[now_x][now_y] + MAP[next_x][next_y];
                pd.push(make_pair(mdistance[next_x][next_y], make_pair(next_x,next_y)));
            }
        } 
    }

    cout << mdistance[N][N] << endl;
}
#endif

#if 0
for detection in detections:
            x1, y1, x2, y2 = detection['box'].astype(int)
            class_id = detection['class_index']
            confidence = detection['confidence']

            #레이블을 int형식으로 바꿈.
            cls_id1 = int(class_id)

            #차량이 몇대인지 나타내기 위하 id 2번인 car이거나 id 67인 truck이면 변수 list_bboxes_vehicle 증가 
            if (cls_id1 == 2 or cls_id1 == 67):
                self.list_bboxes_vehicle += 1

            #id 2번인 car이거나 id 67인 truck이면 바운딩 박스를 침.
            if ((cls_id1) == 67 or (cls_id1) == 2):
                cv2.rectangle(img, (x1, y1), (x2, y2), color, 2)

                # Create the label text with class name and score
                label = f"{self.classes[class_id]}: {confidence:.2f}"

                # Calculate the dimensions of the label text
                (label_width, label_height), _ = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 1)

                # Calculate the position of the label text
                label_x = x1
                label_y = y1 - 10 if y1 - 10 > label_height else y1 + 10

                # Draw a filled rectangle as the background for the label text
                cv2.rectangle(
                    img, (label_x, label_y - label_height), (label_x + label_width, label_y + label_height), color, cv2.FILLED
                )

                # Draw the label text on the image
                cv2.putText(img, label, (label_x, label_y), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1, cv2.LINE_AA)


while True:
        if not frame_queue.empty():
            frame = frame_queue.get()
            detections = detector.detect(frame)
            detector.draw_detections(frame, detections=detections)
            //프레임에 차량이 몇대인지 나타내는 변수 detector.list_bboxes_vehicle를 표시해준다.
            cv2.putText(frame, f"Vehicle: {detector.list_bboxes_vehicle}", (10, 150), cv2.FONT_HERSHEY_SIMPLEX, 2.0, (0, 0, 255), 3)
            cv2.imshow(window_name, frame)
            
            detector.list_bboxes_vehicle = 0
            detector.list_bboxes_person = 0
            if cv2.waitKey(1) == ord('q'):
                break
        else:
            time.sleep(0.1)  # Reduce CPU usage when no frame is available
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> check;
int N,M,sCith, eCity;
vector<long> mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    /일단 distance를 제일 작은 값으로 바꿔준다.
    fill(mdistance.begin(), mdistance.edn(), LONG_MIN);

    for(int i=0; i<M; i++){
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(maek_tuple(start, end, price));
    }

    for(int i=0; i< N; i++){
        cin >> cityMoney[i];
    }

    mdistnace[sCity] = cityMoney[sCity];

    for(int i=0;i <=N+50; i++){
        for(int j=0; j<edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            //아직 방문하지 않았으면
            if(mdistance[start] == LONG_MIN){
                continue;
            }

            //양의 사이클을 만족 시키면
            else if(mdistance[start] == LONG_MAX){
                mdistance[end] = LONG_MAX;
            }

            else if(mdistance[end] < mdistance[start] + cityMoney[end] - weight){
                mdistance[end] = mdistance[start] + cityMoney[end] - weight;
                
                //사이클을 초과하면 양의 사이클이 생기기 때문에 무한대가 된다.
                if(i >=N-1){
                    mdistance[end] = LONG_MAX;
                }
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int D[201][201];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;

    cin >> N >> M >> K;

    for(int i=1; i<=200; i++){
        D[i][0] =1;
        D[i][i] =1;
        D[i][1] = i;
    }

    for(int i=2; i<=200; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j-1] + D[i-1][j];

            if(D[i][j] > 100000000){
                D[i][j] = 100000000;
            }
        }
    }

    if(D[M+N][M] < K){
        cout << "-1" << endl;
    }

    while(M){
        if(D[N+M-1][M] >= K){
            cout << "a";
            N--;
        }
        else if(D[M+N-1][M] < K){
            cout << "z";
            K = K - D[M+N-1][M];
            M--;
        }
    }

    for(int i=0; i<N; i++){
        cout << "a";
    }
    cout << endl;
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10];

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn =1;

    A.resize(N+1);
    visited.resize(N+1, false);

    for(int i=0; i<N-1; i++){
        int a,b,c,d;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        minn = minn * (p*q)/gcd(p,q);
    }

    D[0] = minn;

    DFS(0); //연결되어 있는 정보를 뽑는다.

    for(int i=1; i<N; i++){
        minn = gcd(minn, D[i]);
    }

    for(int i=0; i<N; i++){
        D[i] = D[i] / minn;
        cout << D[i] << " ";
    }
}

void DFS(int node){
    visited[node] = true;

    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] * (get<2>(i)) / (get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

long gcd(long a, long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
#endif

#if 0
#include <iostream>

using namespace std;

int main(void){
    int r=100;
    cout << r/4 << endl;
    r = 100 >> 2;
    cout << r << endl;

    int k;
    k= 4 + (4 << 2);
    cout << k << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int,int>>> A;
long minn;
vector<bool> visited;
long D[10];

long gcd(long a, long b);
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    minn =1;

    A.resize(N+1);
    visited.resize(N+1,false);

    for(int ni=0; i<N-1; i++){
        int a,b,p,q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        minn = minn*(p*q) /gcd(p,q); //이러면 최소 공약수가 나돈다.
    }

    D[0] = minn;

    DFS(0); //일단 0번째 재료부터 탐색을 한다.
    
    for(int i=1; i<N; i++){
        minn = gcd(minn,D[i]);
    }

    //총 N개의 재료가 있다고 가정했기 때문에 이런 가정이 세워짐.
    for(int i=0; i<N; i++){
        D[i] = D[i]/minn;
        cout << D[i] << " ";
    }

    return 0;
}

void DFS(itn node){
    visited[node] = true;

    for(tuple<int,int,int> i : A[node]){
        //일단 방문을 하지 않아야 한다
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] * (get<2>(i))/(get<1>(i));
            visited[get<0>(i)] = true;
            DFS(get<0>(i));
        }
    }
}

//이제 최대 공약수를 구하는 함수를 구현한다.
void gcd(long a, long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
#endif

#if 0
//미로 탐색 문제
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int graph[100][100];
//이러면 default로 0으로 다 초기화가 된다. 즉 false로 된다는 뜻임
bool visited[100][100] = {0,};
void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        
        for(int j=0; j<M; j++){
            graph[i][j] = s[j] - '0';
        }
    }

    //이제 정보를 다 입력했으니까 
    BFS(0,0);

    cout << graph[N-1][N-1] << endl;
}

//queue로 구현한다. BFS를 탐색한다.
void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(i,j));
    visited[i][j] = true;
    
    while(!myqueue.empty()){
        int current[2];
        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        visited[current[0]][current[1]] = true;

        //이제 정보를 다 뽑았으니까 이제 pop을 해준다.
        myqueue.pop();

        int x,y;
        
        //사방으로 탐색을 해준다.
        for(int i=0; i<4; i++){
            int next_x = current[0] + dx[i];
            int next_y = current[1] + dy[i];
            

            //이제 범위를 넘어가는지 안가는지 탐색을 한다.
            //범위를 넘어가는 것이 있으면 contiune를 해줌.
            if(next_x <0 || next_y <0 || next_y >= N || next_x >= N){
                continue;
            }
            
            //일단 1로 되어 있는 칸만 이동할 수 있음
            if(graph[next_x][next_y] && !visited[next_x][next_y]){
                myqueue.push(make_pair(next_x,next_y));
                graph[next_x][next_y] = graph[current[0]][current[1]] + 1;
                visited[next_x][next_y] =1;
            }
        }  
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51] = {0,};
int visited[51][51] = {0,};
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

void DFS(int i, int j);

//M은 가로길이, N은 세로길이, K는 배추가 심어져있는 개수이다.
int M,N,K;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; //case를 입력한다.

    for(int i=1; i<=T; i++){
        cin >> N >> M;
        cin >> K;

        //배추가 심어져 있는 case를 입력한다.

        for(int i=0; i<K; i++){
            int w,h;
            cin >> w >> h;
            arr[h][w] =1; //배추가 심어져있는 공간을 1로 표시르르 해줌.
        }

        int cnt =0;

        //N은 세로길이, M은 가로길이
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 1){
                    DFS(i,j);
                    cnt++;
                }
            }
        }

        //이제 cnt의 개수를 출력한다.

        for(int i=0; i<N; i++){
            fill(arr[i], arr[i]+M,0);
            fill(visited[i],visited[i]+M, false);
        }
    }

    return 0;
}

void DFS(int i, int j){
    visited[i][j] = true;

    //이제 중요한게 범위를 넘어가는지 아닌지 확인한다.
    if(next_x <0 || next_y <0 || next_x >=N || next_y >= N){
        continue;
    }

    for(int i=0; i<4; i++){
        int next_x = i + dx[i];
        int next_y = j + dy[i];

        //이제 next_x랑 next_y를 구했으니 
        if(!visited[next_x][next_y] && arr[next_x][next_y] == 1){
            //배추 벌레가 관리하는 곳이기 대문에
            arr[next_x][next_y] = 0;
            visited[next_x][next_y] = 1;
            DFS(next_x, next_y);
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;
struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first > b.first){
            return true;
        }
        else{
            return false;
        }
    }
};


int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> myqueue;

int main(void){
    cin >> V >> E >> K;
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    myqueue.push(make_pair(0,K));
    mdistance[K] = 0;

    while(!myqueue.empty()){
        pair<int,int> current = myqueue.top();
        myqueue.pop();
        int c_v = current.second;

        if(visited[c_v]){
            continue;
        }

        visited[c_v] = true;

        for(pair<int,int> node : mlist[c_v]){
            int next_node = node.first;
            int weight = node.second;
            
            if(mdistance[next_node] > mdistance[c_v] + weight){
                mdistance[next_node] = mdistance[c_v] + weight;
                myqueue.push(make_pair(mdistance[next_node],next_node));
            }
            
        }
    }

    for(int i=1; i < mdistance.size();i++){
        if(mdistance[i] == INT_MAX){
            cout << "INF" << endl;
        }
        else{
            cout << mdistance[i] << endl;
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, deleteNode;
void DFS(int node);
vector<int> parent;
vector<vector<int>> graph;
vector<bool> visited;
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N, false);
    parent.resize(N);
    graph.resize(N);
    int root;

    for(int i=0; i<N; i++){
        int parent_node;
        cin >> parent_node;

        if(parent_node == -1){
            root = i;
            continue;
        }

        graph[i].push_back(parent_node);
        graph[parent_node].push_back(i);
    }

    cin >> deleteNode;

    if(deleteNode == root){
        cout << 0 << endl;
    }
    else{
        //이제 DFS를 수행한다.
        DFS(root);
        cout << result << endl;
    }
    
    return 0;
}

void DFS(int node){
    visited[node] = true;
    int cnt =0;
    for(int cNode : graph[node]){
        if(!visited[cNode]){
            if(cNode != deleteNode){
                visited[cNode] = true;
                cnt++;
                DFS(cNode);
            }
        }
    }
    if(cnt == 0){
        result++;
    }
}
#endif

#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

vector<int> parent;
int result =0;

struct compare{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        if(get<2>(a) > get<2>(b)){
            return true;
        }
        else{
            return false;
        }
    }
};

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void union_function(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return;
    }
    else{
        parent[b] =a;
        return;
    }
}

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    parent.resize(V+1);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    //최소 신장 트리
    for(int i=0; i<E; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        myqueue.push(make_tuple(start, end, weight));
    }

    int edge_add = 0;

    while(edge_add < V-1){
        tuple<int,int,int> now_node = myqueue.top();
        myqueue.pop();
        int start_node = get<0>(now_node);
        int end_node = get<1>(now_node);
        int weight = get<2>(now_node);

        if(find(start_node) == find(end_node)){
            continue;
        }
        else{
            union_function(start_node, end_node);
            edge_add++;
            result +=weight;
        }
    }

    cout << result;

    return 0;
}

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int D[201][201];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;

    cin >> N >> M >> K;

    for(int i=1; i<=200; i++){
        D[i][0] = 1;
        D[i][i] = 1;
        D[i][1] = i;
    }

    for(int i=2; i<=200; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j-1] + D[i-1][j];

            //범위를 넘어가면 다시 돌려줌.
            if(D[i][j] > 10000000){
            }
        }
    }

    if(D[N+M][M] < K){
        cout << "-1" << endl;
        return 0;    
    }

    while(M){
        if(D[N+M-1][M] >= K){
            cout << "a";
            N--;
        }
        else if(D[N+M-1][M] < K){
            cout << "z";
            K = K - D[N+M-1][M];
            M--;
        }
    }

    for(int i=0; i<N; i++){
        cout << "a";
    }

    cout << endl;
}
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> degree;
vector<int> setbuild;
vector<vector<int>> graph;
vector<int> goal;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    degree.resize(N+1);
    setbuild.resize(N+1);
    goal.resize(N+1,0);
    graph.resize(N+1);

    for(int i=1; i<=N; i++){
        int time;
        cin >> time;
        setbuild[i] = time;

        //이제 우선순위 건물을 비교해줘야함
        while(1){
            int prebuild;
            cin >> prebuild;

            if(prebuild == -1){
                break;
            }
            else{
                graph[prebuild].push_back(i);
                degree[i]++;
            }
        }
    }

    queue<int> myqueue;

    for(int i=1; i<=N; i++){
        if(degree[i] == 0){
            myqueue.push(i);
        }
    }

    //이제 push된 것부터 출력을 해준다. 그리고 queue가 빌때까지 출력함
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();

        for(int node : graph[node]){
            degree[node]--;

            if(degree[node] == 0){
                myqueue.push(node);
            }

            goal[node] = max(goal[node], goal[now] + setbuild[now]);
        }
    }

    //이제 자기 자신의 건물을 지을 것을 더해준다.
    for(int i=1; i<=N ; i++){
        goal[i] += setbuild[i];

        cout << goal[i] << endl;
    }
}