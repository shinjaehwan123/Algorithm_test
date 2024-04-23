#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long  gcd(long long  result_a, long long result_b);

void swap(long long  &a, long long  &b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long  a=0,b=0;
    cin >> a >> b;

    //long long result_a =0, result_b=0;


    // for(int i=0; i<a; i++){
    //     result_a += pow(10,i);
    // }

    // for(int j=0; j <b; j++){
    //     result_b += pow(10,j);
    // }

    //최대 공약수를 구하기 위해서 유클리드 호제법을 이용함.

    if(a < b){
        swap(a, b);
    }

    long long answer = gcd(a, b);

    while(answer > 0){
        cout << 1;
        answer--;
     }

     cout << endl;
    
    return 0;
}

long long  gcd(long long  result_a, long long result_b){
    long long  Max = result_a;
    long long  Min = result_b;
    long long  answer = 1;

    while(1){
        if(answer == 0){
            return Min;
        }

        if(Max < Min){
            swap(Max , Min);
        }

        answer = Max % Min;

        Max  = Min;

        if(answer !=0){
            Min = answer;
        } 

    }

    return 1;
    
}

void swap(long long  &a, long long &b){
    long long  temp =a;
    a = b;
    b = temp;
}