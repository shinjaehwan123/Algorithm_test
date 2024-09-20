//경로 찾기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int graph[101][101];
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> graph[i][j]; 
        }
    }

    //플로이드 와셜 알고리즘을 실시한다.
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N ; j++){
                if(graph[i][k] == 1 && graph[k][j] == 1){
                    graph[i][j] = 1;
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}