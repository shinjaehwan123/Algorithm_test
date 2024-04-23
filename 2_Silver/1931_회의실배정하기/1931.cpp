#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> & a, const pair<int,int> &b);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int,int>> A;
    vector<pair<int,int>> B(1,{0,0});


    //cout << B.back().first << " "<< B.back().second << endl;

    for(int i=0; i<N; i++){
        int s,e;
        cin >>s >>e;
        A.push_back(make_pair(s,e));
        //cout << A[i].first << " " << A[i].second << endl;
    }


    sort(A.begin(), A.end(),compare); //오름차순 정렬이 됨. second에 대해서

    //  for(int i=0; i<N; i++){
    //     cout << A[i].first << " " << A[i].second << endl;
    // }


    int count =0;
    int end=-1;

     for(int i=0; i<N; i++){
        if(A[i].first >=end){
            end = A[i].second; // 종료시간 update
            count++;
        }
    }


    cout << count<< endl;

    // //  for(int i=0; i<N; i++){
    // //     cout << A[i].first << " " << A[i].second << endl;
    // // }

    // return 0;
    
}

bool compare(const pair<int, int> & a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first  < b.first;
    }
    return a.second < b.second; //오름차순
}

