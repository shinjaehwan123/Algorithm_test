#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N, M;
vector<long> mdistance;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N은 도시의 개수, M은 경로의 개수
    int N, M;

    cin >> N >> M;

    mdistance.resize(N+1,LONG_MAX);
    
    //출발이 1이니까 1를 0로 초기화한다.
    mdistance[1] =0;
    

    //시작, 도착, 가중치를 넣는다.
    for(int i=1; i<=M; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back(make_tuple(start,end,weight));
    }

    //이제 다 넣었으니 N-1만큼 반복한다.
    for(int i=1; i<N; i++){
        //모든 노드를 탐색한다.
        for(int j=0; j<M; j++){
            tuple<int,int,int>medges = edges[j];
            int start = get<0>(medges);
            int end = get<1>(medges);
            int weight = get<2>(medges);

            //일단 방문을 했어야하
            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + weight ){
                //작은 distnace로 갱신한다.
                mdistance[end] = mdistance[start] + weight;
            }
        }
    }

    bool nCycle = false;
    //모든 노드를 갱신했다면 한번 더 사이클을 돌려서 가중치가 바뀌는지 본다.
    for(int j=0; j<M ; j++){
        tuple<int,int,int> medges = edges[j];
        int start = get<0>(medges);
        int end = get<1>(medges);
        int weight = get<2>(medges);

        if(mdistance[start] != LONG_MAX &&  mdistance[end] > mdistance[start] + weight){
            nCycle = true;
        }
    }

    if(nCycle == true){
        cout << "-1" << endl;
    }
    else{
        for(int i=2; i<=N; i++){
            if(mdistance[i] == LONG_MAX){
                cout<< -1 <<endl;
            }
            else{
                cout << mdistance[i] <<endl;
            }
        }
    }

}



















#if 0
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

typedef tuple<int,int.int> edge;
int N, M;
vector<long> mdistance;
vector<edge> edges;

int main(){
    ios::sync_with_stdio(fasle);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N>>M;
    mdistace.reisze(N+1);
    fill(mdistance.begin(), mdistance.end(), LONG_MAX);

    for(int i=0; i<M; i++){
        int start,end,time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start,end,time));
    }

    mdistance[1] =0;


    //모든 edge를 탐색한다.
    for(int i=1; i<N; i++){ //N보다 하나 적은 수만큼 반복
        for(int j=0; j<M; j++){ //각각 edge들을 탐색한다.
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time= get<2>(medge);

            //더 각까운 최단 거리가 있으면 개인
            if(mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time){
                mdistance[end] = mdistance[start] + time;
            }
        }

    }

    
    bool mCycle = false;

    for(int i=0; i<M; i++){ //음수사이클 확인
        endge mdege = edges[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);

        if(mdistance[start] != LONG_MAX && mdistance[end] > mdistacne[start] + time){
            mCype = true;
        }
    }

    if(!mCype){
        for(int i=2; i<=N; i++){
            if(distance[i] == LONG_MAX){
                cout << -1 << "\n";
            }
            else{
                cout<<mdistance[i] << "\n";
            }
        }
    }
    else{
        cout << -1 >> "\n";
    }

}
#endif