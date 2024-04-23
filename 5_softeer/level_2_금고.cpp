#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int w, m;
vector<pair<int,int>> arr;
int total=0;



//내림차순으로 정렬하는 기준임
struct compare1{
  bool operator()(int a, int b){
      if(a<b){
          return true;
      }
      else{
          return false;
      }
  }  
};

//내림 차순으로 정렬을 한다.
bool compare(pair<int,int> &a, pair<int,int> &b){
    if(a.second > b.second){
        return true;
    }
    else{
        return false;
    }
}

//second 2로 정렬을 한다.

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> m;

    for(int i=0; i<m ;i++){
        int m,p;
        cin >> m >> p;
        arr.push_back(make_pair(m,p));
    }

    //이제 내림 차수능로 정렬됐음.
    sort(arr.begin(),arr.end(),compare);

    for(int i=0; i<m;i++){

        if(w==0){
            break;
        }
        
        if(arr[i].first <= w){
            total += arr[i].second * arr[i].first;
            w -=arr[i].first;
            continue;
        }
            
        else if(arr[i].first > w){
            total += arr[i].second*w;
            w =0;
        }
    }

    
    cout << total <<'\n';
    
    
    return 0;
}