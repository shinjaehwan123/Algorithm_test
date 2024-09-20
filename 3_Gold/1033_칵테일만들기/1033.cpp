//백준 골드 2 칵테일 만들기 문제

//칵테일 문제 복습 //2차원 vector로 구현
//주의 minn을 long으로 해야
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


#if 0
//내 코드
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




//교재 코드
//임의의 노드에서 DFS를 진행하면서 정답을 찾으면됨. DFS과정에서 유클리드 호재법을 사용해 비율들의 최소 공배수와 최대 공약수를 구하고
//재료의 최소 질량을 구하는 데 사용해 문제를 해결하면 된다.

//1)인접 리스트를 이용해 각 재료의 비율 자료를 구래프로 구현함
//2)데이터를 저장할 때마다 비율과 관련된 수들의 최소 공배수를 업데이트함.
//3)임의의 시작점에 최소 공배수 값을 ㅜ함
//4)임의의 시작점에서 DFS로 탐색하면서 각 노드의 값을 이전 노드의 값과의 비율 계산을 통해 저장함.
//5)각 노드의 값을 모든 노드의 최대 공약수로 나눈 뒤 출력함.
#if 0
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>> A[10];
long minn; //최소공배수
bool visited[10];
long D[10];

long gcd(long a, long b);
void DFS(int node);

//대이터를 저장할 때마다 비율 과 관련된 수들의 최소 공배수를 업데이트해줌
//A,B의 최소 공배수는 A*B/최대공약수임. 따라서 1,3,5,7의 최소 공배수는 1*3*5*7 / (최대공약수 =1) = 105이다. 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //임시의 시작점에 최소공배수 값을 저장함

    //임시의 시작점에서 DFS로 탐색을 수행하면서 각 노드의 값을 이전 노드의 값과의 비율 계산을 통해 계산하고 저장함.

    //각 노드의 값을 모든 노드의 최대 공약수로 나눈 뒤 출력함.

    int N;
    cin >> N;
    minn = 1;

    for(int i=0; i<N-1; i++){
        int a,b,p,q;
        cin>>a>>b>>p>>q;
        A[a].push_back(make_tuple(b,p,q));
        A[b].push_back(make_tuple(a,q,p));
        //두 수의 초소공배수는 두 수의 곱을 최대 공약수로 나눈것이다.
        minn= minn*(p*q/gcd(p,q));
    }

    D[0] = minn; //최소공배수를 저장함.
    DFS(0); //0부터 시작함.
    long mgcd = D[0]; //mgcd는 D 배열에 저장된 수들의 최대공배수임.

    for(int i=1; i<N; i++){
        mgcd = gcd(mgcd, D[i]);
    }

    for(int i=0; i<N; i++){
        cout << D[i]/ mgcd << ' ';
    }

    return 0;
}

//최대공약수를 구한다.
long gcd(long a, long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a % b );  //왜 여기에 return이 붙어야하지 ??? 재귀니까
    }
}



void DFS(int node){
    
    visited[node]=true;
    
    for(tuple<int,int,int> i : A[node]){
        if(!visited[get<0>(i)]){
            D[get<0>(i)] = D[node] *get<2>(i) / get<1>(i);
            DFS(get<0>(i));
        }
    }
}
#endif


