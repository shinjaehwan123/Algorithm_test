//백준 17298

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >>N;

    int ans[N]={0,};
    stack<int> myStack;

    for(int i=0; i<N ; i++){
        cin >> ans[i];
    }

    myStack.push(0);

    for(int i=1; i < N; i++){
        while(!myStack.empty() && ans[i] > ans[myStack.top()]){
            ans[myStack.top()] = ans[i];
            myStack.pop();
        }
        myStack.push(i);
    }

    while(!myStack.empty()){
        ans[myStack.top()] = -1;
        myStack.pop();
    }

    for(int i=0; i<N;i++){
        cout << ans[i] << " ";
    }
    return 0;
}