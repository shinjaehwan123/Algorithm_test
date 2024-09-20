#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#if 0
//동적 계획문제임.
static int dp[][];

static int binomial(int n, int r){
    if(r==0 || n==r){
        return 1;
    }
    if(dp[n][r]==0){
        dp[n][r] = binomial(n-1,r-1) + binomial(n-1,r);
    }
    return dp[n][r];
}

#endif
#include <iostream>

static int N,K;
static int D[11][11];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i=1; i<=N; i++){
        D[i][1] =i;
        D[i][0]= 1;
        D[i][i] =1;
    }

    for(int i=2; i<=N; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1];
        }
    }

    cout << D[N][K] << endl;

    
}