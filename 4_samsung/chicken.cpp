//시간초과가 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int MinDistance =999999999;
int graph[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
//선택된 치킨집을 말함.
bool visited[14]={false};

void calculate(void);
void do_it(int idx, int cnt);

//0 : 빈칸 , 1 : 집, 2 : 치킨집
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N ; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];

            //집이면
            if(graph[i][j]==1){
                home.push_back(make_pair(i,j));
            }
            //치킨집이면
            else if(graph[i][j]==2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }

    //이제 치킨집 M개를 고른다.
    //고른것, depth표현
    do_it(0,0);

    cout << MinDistance<<'\n';

return 0;
}

void calculate(void){
    int cityDistnace =0;
    for(int i=0 ; i < home.size(); i++){
        //집에서 가장 가까운 치킨집을 찾아서 함.
        int min_distance = 999999;
        for(int j=0; j<chicken.size(); j++){

            if(visited[j]==false){
                continue;
            }
           
           int  houseDistance = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
            
            if(houseDistance < min_distance){
                min_distance = houseDistance;
            }  
        }
        cityDistnace +=min_distance;
    }

    if(cityDistnace < MinDistance){
        MinDistance = cityDistnace;
    }
    
}

void do_it(int idx, int cnt){
    if(cnt == M){
       calculate();
        return;
    }

    //치킨 3개를 고른다.
    //중요!! i를 idx로 둠
    for(int i=idx; i<chicken.size();i++){
        if(!visited[i]){
            visited[i] = true;
            //M개를 고르면 return 됨.
            do_it(i, cnt+1);
            visited[i]=false;
        }
    }
}