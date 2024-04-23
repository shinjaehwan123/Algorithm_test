#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b);
void swap(int &a, int &b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int a, b;
        cin >> a >>b;
        int result = a*b / gcd(a,b);
        cout << result << "\n";
    }
    return 0;
}

int gcd(int a, int b){
    int Max = a;
    int pre_result = b;
    int result = 1;
 
    while(1){
        if(result == 0){
            return pre_result;
        }
    
        if(Max < pre_result)
        {
            swap(Max, pre_result);
        }

        result = Max % pre_result;
        Max = pre_result;
        if(result != 0){
            pre_result = result;
        }
    }

    return 1;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}