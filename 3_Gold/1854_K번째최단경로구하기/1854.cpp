//K번째 최단경로 구하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> &A, pair<int,int> &B){
        if(A.first > B.first){ //오름차순으로 정렬한다.
            return true;
        }
        else{
            return false;
        }
    }
};

struct compare1{
    bool operator()(int &a, int &b){
        if( a<b){ //내림차순 정렬
            return true;
        }
        else{
            return false;
        }
    }
};

int N,M,K;

vector<int>visited;
vector<vector<pair<int,int>>> graph;
vector<int> mdistance;

//작은게 우선순위에 와야함.
priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pd;
//내림차순 정렬해야한다.
priority_queue<int,vector<int>, compare1> disQueue[1001]; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    graph.resize(N+1);

    for(int i=0; i<M; i++){
        int start,end,weight;

        cin >> start >> end >> weight;

        //모든 정보를 저장한다.
        graph[start].push_back(make_pair(end,weight));
    }

    mdistance.resize(N+1,INT_MAX);

    pd.push(make_pair(0,1)); //여기선 0은 가중치이고, 1은 시작 노드이다.
    disQueue[1].push(0); //일단 우선순위 queue에 1을 0으로 넣는다.

    while(!pd.empty()){
        pair<int,int> u = pd.top();
        int now = u.second;
        int distance = u.first;

        pd.pop();

        //now에 연결된 시작노드에 end node를 다 탐색한다.
        for(pair<int,int> node1 :graph[now]){
            int end = node1.first;
            int weight = node1.second;

            //저장된 경로가 K개가 안됐을때 그냥 추가하기
            if(disQueue[end].size() <K){
                disQueue[end].push(distance + weight);
                pd.push(make_pair(distance + weight, end));
            }

            //만약 저장된 개수가 K개dlrh 현재 가장 큰 값보다 작을 때만 추가하기
            else if(disQueue[end].size() >=K && disQueue[end].top() > distance + weight){
                disQueue[end].pop();
                disQueue[end].push(distance+weight);
                pd.push(make_pair(distance +weight, end));
            }

        }
    }

    for(int i=1; i<=N; i++){
        if(disQueue[i].size() == K){
            cout << disQueue[i].top() << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    
}