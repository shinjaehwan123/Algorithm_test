//백준 14501
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<pair<int,int>>Schedule;
vector<int>D;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    Schedule.resize(N+1,{0,0});
    D.resize(N+2,0);

    for(int i=1; i<=N; i++){
        int Time, Process;
        cin >> Time >> Process;
        Schedule[i].first = Time;
        Schedule[i].second = Process;
    }
    
    for(int i= N; i>=1; i--){
        if(i + Schedule[i].first > N+1){
            D[i] = D[i+1];
        }
        else if(D[i] + Schedule[i].first <N+1){
            D[i] = max(D[i+1],D[i + Schedule[i].first] + Schedule[i].second );
        }
    }

    cout << D[1] << endl;

    return 0;


}