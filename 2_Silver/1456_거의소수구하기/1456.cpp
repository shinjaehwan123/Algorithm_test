#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long Min,Max;
    cin >> Min >> Max;
    long A[10000001];

    for(int i=2; i< 10000001; i++){
        A[i] = i;
    }

    // 모든 소수를 다 구했음.
    for(int i=2; i<=sqrt(10000001); i++){
        if(A[i]==0){
            continue;
        }
        for(int j= i*2; i<=10000000; j= j+i){
            A[j]=0;
        }
    }

    int count=0;

    for(int i=2; i < 10000001; i++){
        if(A[i]!=0){
            long temp = A[i];

            while((double)A[i] <= (double)Max / (double)temp){
                
            }
        }
    }



}