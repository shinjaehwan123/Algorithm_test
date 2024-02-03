#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
//###################################################################################################
//[참고] 소수 판정 알고리즘 (에라토스테네스의 체)
#if 0

bool isPrime(){
    int number = 10000;
    int a[number+1]={0,};
    //2~10000까지 배열에 할당해줌
    for(int i=2; i<=number; i++){
        a[i] = i;
    }
    
    for(int i=2; i<=number;i++){
        if(a[i]==0){
            continue;
        }
        for(int j= i; j<=number; j+=i ){
            a[j]=0;
        }
    }

    for(int i=2; i<=number;i++){
        if(a[i]!=0){
            cout << a[i]<< " ";
        }
    }
    cout << endl;
}

bool isPrime_2(int N){
    for(int i=2; i <= sqrt(N) ; i++){ //짝을 이루기때문에 제곱근 까지만 고려해주면된다.
        if(N %i ==0){  //만약 떨어지는 수가 있으면 약수가 있는 
            return false;
        }
    }
    //만약 떨어지는 수가 없으면 소수임.
    retur true;
}
#endif
//###################################################################################################
int N=0;
void DFS(int num, int num_N);
bool isPrime(int num);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    //처음 시작은 자릿수 1개, 소수인 2,3,5,7로 시작함.
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
}

void DFS(int num, int num_N){
    if(num_N == N){
        if (isPrime(num)){
            cout << num << endl;
        }
        return;
    }
    for(int i =1; i< 10 ;i++){
        if(i%2==0){      //짝수이면 할 필요가 없음.
            continue;
        }
        if(isPrime(num*10 + i)){ //소수이면 찾으로 들어감.
            DFS(num*10 + i, num_N+1);
        }
    }
}

bool isPrime(int num){
    for(int i =2; i <= sqrt(num); i++){
        if(num %i ==0){
            return false;
        }
    }
    return true;
}