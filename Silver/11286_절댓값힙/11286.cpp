#include <iostream>
#include <queue>

using namespace std;

struct condition{
    bool operator()(int a, int b){
        int first = abs(a);
        int second = abs(b);
        if(first == second){
            return a > b; //오름차순 정렬을 함
        }
        else if(first != second){
            return first > second; //오름차순 정렬을 함
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, condition> Queue;

    int N;
    cin >> N;
    int current;

    for(int i=0; i<N;i++){
        cin >> current;

        if(current ==0){
            if(Queue.empty()){
                cout << "0" << endl;
            }
            else{
                cout << Queue.top() << endl;
                Queue.pop();
            }
        }
        else{
            Queue.push(current);
        }
    }
}