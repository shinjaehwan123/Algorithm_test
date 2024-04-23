#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> visited;
bool isPrime(int n);
void DFS(int number, int num_size);
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    visited.resize(N,false);
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
    return 0;
}

void DFS(int number, int num_size){

    if(num_size > N){
        return;
    }

    if(num_size==N){
        cout << number <<endl;
    }
    
    //1. logic : 0, or 짝수는 고려해 줄 필요없음. 총
    //2. logic : 총 자리수 만큼 for문을 돌리면 됨.
    for(int i=1; i<=9;i++){
        if(i%2==0){
            continue;
        }
        else if(isPrime(number*10 + i)){ //소수임.            
            DFS(number*10 + i, num_size + 1);
        }
    }
}


bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true; // 이때는 소수임
}