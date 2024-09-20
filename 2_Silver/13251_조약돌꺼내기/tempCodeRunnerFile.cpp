#include <iostream>
#include <vector>

using namespace std;

int M,K;
int total =0;
vector<int> visited;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    visited.resize(M+1);

    for(int i=0; i<M ;i++){
        int start;
        cin >> start;
        visited[i] = start;
        
        total += start;
    }

    double data[total+1][total+1];

    for(int i=1; i <= total ; i++){
        data[i][0] = 1;
        data[i][i] = 1;
        data[i][1] = i;
    }

    for(int i=2; i<=total; i++){
        for(int j=1; j<i; j++){
            data[i][j] = data[i-1][j-1] + data[i-1][j];

        }
    }

    cin >> K;

    double total_p = data[total][K];

    double sub =0.0;
    
    
    for(int i=0; i < M; i++){
        
        sub += (double)data[visited[i]][K];
    }

    double answer = (double)sub/(double)total_p;
    
    cout << (double)answer << endl;

    
}
