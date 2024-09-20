//조합문제이다.

#include <iostream>

using namespace std;

static int T,N,M;
static int D[31][31];

int main(void){
    for(int i=1; i<=30; i++){
        D[i][0] = 1;
        D[i][1] = i;
        D[i][i] = 1;
    }

    for(int i=2; i<=30; i++){
        for(int j=1; j<i; j++){
            D[i][j] = D[i-1][j-1] + D[i-1][j];
        }
    }

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N >> M;
        cout << D[M][N] << endl;
    }
}