#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//1 ≤ N, M ≤ 100
//1 ≤ K ≤ 1,000,000,000
//첫째 줄에 규완이의 사전에서 K번째 문자열을 출력한다. 
//만약 규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1을 출력한다.

using namespace std;

int D[201][201];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;

    cin >> N >> M >> K;

    for(int i=1; i<=200; i++){
        D[i][0]=1;
        D[i][i] =1;
        D[i][1] = i;
    }

    for(int i=2; i<=200; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j-1] + D[i-1][j];
            
            //이 부분 왜하는지 확실하지 않음!!!
            if(D[i][j] > 1000000000){
                D[i][j] =  1000000000;
            }
        }
    }

    if(D[M+N][M] < K){
        cout << "-1" << endl;
        return 0;
    }

    //이제 사전 순서를 고려해준다.
    while(M){
        if(D[M+N-1][M] >= K){
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