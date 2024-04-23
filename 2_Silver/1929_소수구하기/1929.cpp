#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N;
    cin >> M >> N;
    vector<int> A(N+1);
    
    for(int i=2; i<=N; i++){
        A[i]=i;
    }
    for(int i=2; i<=sqrt(N); i++){ //제곱근까지 수행해도 대칭이 되기 때문에 가능
        if(A[i]==0){ //만약 0이라면 소수가 아님.
            continue;
        }
        for(int j=i*2; j<=N; j=j+i){ //여기서 소수의 배수를 다 날림
            A[j]=0;
        }
    }

    //이제 0이 아닌것은 모두 소수임.
    for(int i= M; i<=N; i++){
        if(A[i]!=0){
            cout << A[i] << endl;
        }
    }
}

#if 0
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   int n,m;

   cin >>n>>m;

   vector<int>A(m+1);


    for(int i=2; i<=m; i++){
        A[i] = i;
    }


    for(int i=2; i<=sqrt(m);i++){
        if(A[i] == 0){
            continue;
        }
        for(int j=i*2;j<=m;j=j+i){
            A[j]=0;
        }
    }


    for(int i=n; i<=m; i++){
        if(A[i]!=0){
            cout << A[i]<< endl;
        }
    }
}
#endif