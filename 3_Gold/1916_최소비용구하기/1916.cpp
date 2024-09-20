//N개의 도시, M개의 버스, 가중치는 주어지지 않음
//M+2번째 줄부터 1.버스의 출발노드 2. 도착지의 도시 번호 3. 버스 비용
//M+3에는 출발도시, 도착도시가 주어짐
//다익스트라로 접근한다.

//tuple로 구현
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <tuple>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> &b){
        return a.first > b.first; //우선순위queue에서는 오름차순 정령ㄹ이다.
    }
};

vector<bool>visited;
vector<long> mdistance;

vector<tuple<int,int,int>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    cin >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    //tuple로는 다익스타라 구현이 어렵나 ?
    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >>w;
        mlist.push_back(make_tuple(u,v,w));
    }

    int start, end;
    cin >>start >> end;

    //자기 출발 위치는 0이다.
    mdistance[start]=0;

    myqueue.push(make_pair(0,start)); //최소거리 start node

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node]= true;

        // for(pair<int,int> node : edges[now_node]){
        //     pair<int,int> medges = node;
        //     int end = node.first;
        //     int edge_weight = node.second;

        //     if(mdistance[end] > mdistance[now_node] + weight ){
        //         mdistance[end] = mdistance[now_node] + weight;
        //         myqueue.push(make_pair(mdistance[end], end)); //weight, star node를 넣어준다.
        //     }
           
        // }

        for(int i=0; i<mlist.size(); i++){
            int start = get<0>(mlist[i]);
            int end = get<1>(mlist[i]);
            int weight = get<2>(mlist[i]);

            if(start != now_node){
                continue;
            }

            //만약 시작 노드가 맞으면 이제 부터 비교
            if(mdistance[end] > mdistance[start] + weight){
                mdistance[end] = mdistance[start] + weight;
                myqueue.push(make_pair(mdistance[end], end));
            }
        }
    }

    //이제 다 탐색을 했음
    // if(visited[end] == true){
    //     cout << mdistance[end] << endl;
    // }
    cout << mdistance[end] << endl;
    return 0;

}












//my_code
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct compare{
    bool operator()(pair<int,int> & a, pair<int,int> & b){
        return a.first > b.first; //오름차순으로 정렬함. 
    }
};

vector<bool>visited;
vector<long>mdistance;

vector<vector<pair<int,int>>> mlist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M; //N개의 도시, M개의 버스가 있음.
    cin >> N;
    cin >> M;

    visited.resize(N+1, false);
    mdistance.resize(N+1, INT_MAX);
    mlist.resize(N+1);

    //M은 버스노선의 개수 즉 edge 개수이다.
    for(int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >>w;
        mlist[u].push_back(make_pair(v,w));
    }

    int start, end;
    cin >> start >> end;

    mdistance[start] =0;

    myqueue.push(make_pair(0,start)); //가중치, 노드

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node] = true;

        for(pair<int,int> i : mlist[now_node]){
            int next_node = i.first;
            int next_value = i.second;

            if(mdistance[next_node] > mdistance[now_node] + next_value){
                mdistance[next_node] = mdistance[now_node] + next_value;

                myqueue.push(make_pair(mdistance[next_node], next_node));
            }
        }
    }

     if(visited[end] == true){
        cout << mdistance[end] << endl;
    } 


}



#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

vector<bool>visited;
vector<long>mdistance;
//출발노드, 도착노드, 가중치를 저장할 컨테이너를 만든다.
vector<vector<pair<int,int>>> mlist;
//저장할 우선순위 queue를 만든다.
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> myqueue;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N; //N개의 도시를 입력한다.
    cin >> M; //M개의 버스노선을 입력한다.

    //이제 resize후 가중치를 입력한다.
    visited.resize(N+1,false);
    mdistance.resize(N+1,INT_MAX);
    mlist.resize(N+1);

    //M은 버스노선의 개수 즉 edge의 개수이다.
    for(int i=0; i<M ; i++){
        int u,v,w;
        cin >> u>>v>>w;
        //pair에 저장을 한다.
        mlist[u].push_back(make_pair(v,w));
    }

    //이제 버스의 실제 startvertex와 endvertex를 입력해준다.
    int start, end;
    cin >> start >> end;

    mdistance[start]=0;
    //가중치를 넣는다. 0은 거리이고 start는 시작 노드이다.
    //시작노드의 거리는 0이된다.
    myqueue.push(make_pair(0,start));

    while(!myqueue.empty()){
        pair<int,int> now = myqueue.top();
        int now_distance = now.first;
        int now_node = now.second;

        myqueue.pop();

        if(visited[now_node] == true){
            continue;
        }

        visited[now_node] = true;

        for(int i=0; i< mlist[now_node].size(); i++){
            int next = mlist[now_node][i].first;
            int value = mlist[now_node][i].second;

            if(mdistance[next] > mdistance[now_node] + value){
                mdistance[next] = mdistance[now_node] + value;
                myqueue.push(make_pair(mdistance[next], next)); //거리와 노드를 입력해준다.
            }
        }
    }

    //이제 모든 노드들의 distance가 나와았음. 우리는 5번 까지의 거리만 구하면된다. 즉 mdistance[5]를 출력하면 된다.
    if(visited[end] == true){
        cout << mdistance[end] << endl;
    } 
}
#endif