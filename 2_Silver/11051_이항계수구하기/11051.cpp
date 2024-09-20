//1007로 나눈 나머지를 구하는 프로그램을 짜라
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[1001][1001];
int N, M;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        dp[i][0] =1;
        dp[i][i] =1;
        dp[i][1] =i;
    }

    //모든 수를 입력했으면 이제 이항계수를 구한다
    for(int i=2; i<=N ;i++){
        for(int j=1; j< i; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] = dp[i][j] %10007;
        }
    }

    cout << dp[N][M] <<endl;
}