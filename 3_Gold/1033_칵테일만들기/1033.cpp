//백준 골드 2 칵테일 만들기 문제
//임의의 노드에서 DFS를 진행하면서 정답을 찾으면됨. DFS과정에서 유클리드 호재법을 사용해 비율들의 최소 공배수와 최대 공약수를 구하고
//재료의 최소 질량을 구하는 데 사용해 문제를 해결하면 된다.

//1)인접 리스트를 이용해 각 재료의 비율 자료를 구래프로 구현함
//2)데이터를 저장할 때마다 비율과 관련된 수들의 최소 공배수를 업데이트함.
//3)임의의 시작점에 최소 공배수 값을 ㅜ함
//4)임의의 시작점에서 DFS로 탐색하면서 각 노드의 값을 이전 노드의 값과의 비율 계산을 통해 저장함.
//5)각 노드의 값을 모든 노드의 최대 공약수로 나눈 뒤 출력함.

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


