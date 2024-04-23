#include <iostream>
#include <vector>

using namespace std;

vector<int>D;
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> N;
    D.resize(N+1,0);
    D[1] = 0;
    for(int i=2; i<=N; i++){
        D[i] = D[i-1] + 1;
        
        if(i%2==0){
            D[i] = min(D[i], D[i/2]+1);
        }
        else if(i%3==0){
            D[i] = min(D[i], D[i/3]+1);
        }
    }

    cout << D[N] <<"\n";
    

    
}