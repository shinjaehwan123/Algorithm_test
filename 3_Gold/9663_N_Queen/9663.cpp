#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define Max 15

using namespace std;

int N= 0;
int col[Max]={0,};

bool condition(int i); //주변에 놓인것이 없는지
void queen_N(int i); //주변에 없으면 +1을 해줌. 이때 i는 층수임.
int result =0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    queen_N(0);

    cout << result << endl;
    
    return 0;
    
}

bool condition(int i){
    
    for(int k=0; k<i;k++){
        if(col[k] == col[i] || abs(col[k]- col[i]) == i-k){
            return false;
        }
    }

    return true;
}

void queen_N(int i){
    if(i == N){
        result++;
        return;
    }
    
    for(int j=0; j < N; j++){
        col[i] = j; //행이 주어지고 어떤 열에 queen이 놓이는지 알수 있음
        //0 열에는 모두 놓을 수 있음.

//만약 중간에 걸러지면 i는 어떻게 설정해야됨?
        if(condition(i)){ //층 수를 나타냄
            cout << i << endl;
            queen_N(i+1);
        }
    } 
}