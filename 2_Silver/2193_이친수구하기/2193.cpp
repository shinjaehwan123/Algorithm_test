




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//시간 초과
#if 0
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

void DFS(int n, string a);
int result=0;
int N;

bool isbad(string a){
    if(a.length()==1){
        return true;
    }

    if(a.substr(a.length()-1,1)=="1"){
        if(a.substr(a.length()-1*2,1) == a.substr(a.length()-1,1)){
            return false;
        }
    }
        
        return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    //처음에 0으로 시작하는 경우와 처음에 1로 시작하는 경우로 나눔.
    DFS(1,"1");
    //처음에 들어 왔을 때 1이 연속으로 나오지 않으면됨
    // string s="1234";
    // cout << s+'1' << endl;
    cout << result << endl;
}

void DFS(int n, string a){
    if(!isbad(a)){
        return;
    }

    if(n == N){
        result++;
        cout << a << endl;
        return;
    }

    DFS(n+1, a + "1");
    DFS(n+1, a + "0");

}
#endif





////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

//1의 자리 소수 : 2,3,5,7 , 자리수 : 1
using namespace std;

bool isPrime(int n);

void DFS(int a, int b);
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    cin >> N;

    //차례대로 하기 때문에 오름차순 효과도 생김
    DFS(2,1); //숫자 자리수를 저장
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
}

void DFS(int a, int b){
    if(b==N){
        cout << a << "\n";
        return;
    }
    
    for(int i=1; i<=9;i++){
        if((a*10+i) % 2 ==0){
            continue;
        }
        else if(isPrime(a*10+i)){
            DFS(10*a+i,b+1);
        }
    }
}

bool isPrime(int n){
    if(n==1){
        return false;
    }
    for(int i=2; i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
#endif
