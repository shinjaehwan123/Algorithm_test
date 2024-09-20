#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

int N,M, sCity, eCity;
vector<long> mdistance, cityMoney;
vector<tuple<int,int,int>> edges;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistance.end(), LONG_MIN);

    for(int i=0; i<M; i++){
        int start, end, price;
        cin >> start>>end>>price;
        edges.push_back(make_tuple(start, end, price));
    }

    for(int i=0; i<N; i++){
        cin >> cityMoney[i];
    }

    mdistance[sCity] = cityMoney[sCity];

    for(int i=0; i<=N+50; i++){
        for(int j=0; j<edges.size(); j++){
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int weight = get<2>(edges[j]);

            //일단 연결은 되어 있어야지 가중치를 뽑을 수 있음.
            if(mdistance[start] == LONG_MIN){
                continue;
            }
            
            // if(mdistance[start] == LONG_MAX){
            //     continue;
            // }

            //양수 사이클에 있으면 다 LONG_MAX로 처리를 해준다.
            else if(mdistance[start] == LONG_MAX){
                mdistance[end] = LONG_MAX;
            }

            //시작 노드가 양수 사이클에 연결된 노드라면 종료하고, 아니면 mdistnace를 업데이트함.
            else if(mdistance[end] < mdistance[start] + cityMoney[end] -weight){
                mdistance[end] = mdistance[start] + cityMoney[end] - weight;

                //사이클을 충분히 돌았으면
                if(i >=N-1){
                    mdistance[end] = LONG_MAX;
                }
            }
        }
    }

    if(mdistance[eCity] == LONG_MIN){
        cout << "gg" << endl;
    }
    else if(mdistance[eCity] == LONG_MAX){
        cout << "Gee" <<endl;
    }
    else{
        cout << mdistance[eCity] << endl;
    }

}