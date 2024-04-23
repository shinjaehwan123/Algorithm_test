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
