//1.거리 배열에서 아직 방문하지 않은 노드 중 현재 값이 가장 작은 노드를 선택함
//2.해당 노드와 연결된 노드들의 최단 거릿값을 다음 공식을 이용해 업데이트한다.
//[연결 노드 거리배열값]보다 [선택 노드의 거리 배열값 + 에지 가중치가]가 더 작은 경우 업데이트 수행
//업데이트가 수행되는 경우 연결 노드를 우선순위 큐에 삽입
//큐가 빌때까지 1~2 반복한다.

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
//#include <limits.h>

using namespace std;

pair<int,int> edge;
int V,E,K;
vector<int> mdistance;
vector<bool>visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myqueue;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >>E >> K; //K는 start node이다.
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(),3000000);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >>v >>w;
        mlist[u].push_back(make_pair(v,w));
    }

    myqueue.push(make_pair(0,K)); //greater하면 first를 비교해줌. 오름차순으로
    //start node의 거리값은 0이다.
    mdistance[K]=0;

    while(!myqueue.empty()){
        pair<int,int> current =  myqueue.top(); //작은거를 먼저 가져온다.
        myqueue.pop(); //버려준다.
        int c_v = current.second; //노드를 가져온다.

        if(visited[c_v]){ //방문을 했으면 while 문으로 돌아간다. 즉 사이클을 방지한다. 
            continue;
        }
        visited[c_v] = true;

        for(int i=0; i< mlist[c_v].size(); i++){
            pair<int,int> tmp = mlist[c_v][i];
            int next = tmp.first; //첫번째가 다음 노드.
            int value = tmp.second;

            if(mdistance[next] > mdistance[c_v] + value){
                mdistance[next] = mdistance[c_v]+value;
                myqueue.push(make_pair(mdistance[next],next));
            }
        }
    }

    for(int i=1; i<mdistance.size();i++){
        if(mdistance[i] == 3000000){
            cout << "INF" << endl;
        }
        else{
            cout << mdistance[i] <<endl;
        }
        
    }


}


//2번째 내코드
#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;
struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first > b.first){
            return true;
        }
        else{
            return false;
        }
    }
};


int V,E,K;
vector<int> mdistance;
vector<bool> visited;
vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> myqueue;

int main(void){
    cin >> V >> E >> K;
    mdistance.resize(V+1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    visited.resize(V+1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v,w));
    }

    myqueue.push(make_pair(0,K));
    mdistance[K] = 0;

    while(!myqueue.empty()){
        pair<int,int> current = myqueue.top();
        myqueue.pop();
        int c_v = current.second;

        if(visited[c_v]){
            continue;
        }

        visited[c_v] = true;

        for(pair<int,int> node : mlist[c_v]){
            int next_node = node.first;
            int weight = node.second;
            
            if(mdistance[next_node] > mdistance[c_v] + weight){
                mdistance[next_node] = mdistance[c_v] + weight;
                myqueue.push(make_pair(mdistance[next_node],next_node));
            }
            
        }
    }

    for(int i=1; i < mdistance.size();i++){
        if(mdistance[i] == INT_MAX){
            cout << "INF" << endl;
        }
        else{
            cout << mdistance[i] << endl;
        }
    }
}
#endif