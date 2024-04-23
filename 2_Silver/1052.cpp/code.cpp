#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체
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

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    isPrime();
}

// bool isPrime(int num){
//     for(int i=2; i <num ; i++){
//         if(num%i==0){
//             return false;
//         }
//     }
//     return true;
// }

