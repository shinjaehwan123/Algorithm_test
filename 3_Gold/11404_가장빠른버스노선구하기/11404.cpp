#include <iostream>
#include <limits.h>

using namespace std;

int N, M;

long long mdistance[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j){
                mdistance[i][j] = 0;
            } 
            else{
                mdistance[i][j] = LLONG_MAX;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;

        if(mdistance[start][end] > weight)
            mdistance[start][end] = weight;
    }

    // Floyd-Warshall 알고리즘
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mdistance[i][k] != LLONG_MAX && mdistance[k][j] != LLONG_MAX) {
                    if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j]) {
                        mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mdistance[i][j] == LLONG_MAX) {
                cout << "0" << " ";
            } else {
                cout << mdistance[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
