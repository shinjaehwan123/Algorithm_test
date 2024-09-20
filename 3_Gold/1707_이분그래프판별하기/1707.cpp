//내코듣 방향성이 없으면 start, end 둘다 push를 해줘야한다.
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

void DFS(int i);
int K,V,E;
vector<vector<int>>distance_info;
vector<bool> mdistance;
vector<int> check; //인접한 노드인지 아닌지 확인하는 flag라고 생각하면 편함.
int flag = false;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    for(int j=0; j<K; j++){
        flag = false;
        cin >> V >> E;

        //1부터 V까지 번호가 붙어져 있음
        distance_info.resize(V+1);
        mdistance.resize(V+1, false);
        check.resize(V+1,0);

        //edge의 수만큼 반복을 한다.
        for(int i=0; i<E; i++){
            int start,end;
            cin >> start >> end;
            distance_info[start].push_back(end);
            distance_info[end].push_back(start);
        }

        //이제 모든 정보를 넣었으니까 DFS로 비교를 해준다.

        //그래프가 다 붙어 있어야 될 보장은 없다. 따라서 모든 노드에 대해서 다 해준다.

        for(int i=1; i<=V; i++){
            DFS(i);
        }
        

        //여기에서 모든 정보를 초기화 시켜준다.
        fill(mdistance.begin(), mdistance.end(),false);
        

        //distnace_info 정보도 다 날린다. 즉 clear해줘야한다.
        for(int i=1; i<=V; i++){
            distance_info[i].clear(); //  이 문법이 맞나 ?
        }

        check.clear();

        if(flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }


    return 0;
}


void DFS(int i){
    
    //방문을 했으면 일단 true로 설정을 해준다.
    mdistance[i] = true;

    for(int node : distance_info[i]){
        //처음 방문을 했으면 check +1 을해준다. 전 노드의
        if(mdistance[node]==false){
            check[node] = (check[i]+1)%2;
            //mdistance[node] = true;
            DFS(node);
        }
        else if(mdistance[node]==true){
            if(check[node] == check[i]){
                flag = true;
            }
        } 
    }
}

























#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K;
int V,E;
vector<bool> visited;
void DFS(int node, int r);
vector<vector<int>> graph[5];
int flag = true;
vector<int> check;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>> K;
    int r;
    for(int r=0; r<K; r++){
        flag = true;
        cin >> V >> E;

        visited.resize(V+1);
        graph[r].resize(V+1);

        check.resize(V+1,0);

        for(int i=0; i<E; i++){
            int start, end;
            cin >> start >> end;
            graph[r][start].push_back(end);
            graph[r][end].push_back(start);
        }

        //그래프가 꼭 다 연결된다는 보장은 없음
        for(int i=1; i<=V; i++){
            DFS(i,r);
            //초기화 시켜준다.
            //fill(visited.begin(), visited.end(), false);
        }

        if(flag){
            cout <<"YES"<<"\n";
        }
        else{
            cout <<"NO"<<"\n";
        }

        
        fill(visited.begin(), visited.end(),0);
        fill(check.begin(), check.end(),0);
    }
    return 0;
}

void DFS(int node,int r){
    visited[node] = true;
    
    for(int i : graph[r][node]){
        //방문하지 않았다면 일단 전 노드에서 1를 더한다.
        if(visited[i] == false){
            visited[i] = true;
            check[i] = (check[node] + 1) %2; //0과 1로 판단함.
            DFS(i,r);
        }
        //방문했다면 전 노드와 같은 숫자인지 비교 함. 근데 같은 같은 숫자이면 근접했는데 같기 때문에 틀리게 된다.
        else if(visited[i] == true){
            if(check[i] == check[node]){
                flag = false; //만약 인접한 노드와 같게 된다면 이진 노드가 아니게 된다.
            }
        }

    }

}
#endif




//교재 코드
#if 0
#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);
static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
static bool IsEven;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; 
    cin >> N;

    for(int t=0; t< N; t++){
       
        int V,E;
        cin >> V >> E;
        A.resize(V+1);
        visited.resize(V+1);
        check.resize(V+1);
        IsEven = true;

        for(int i=0; i<E; i++){
            int start,end;
            cin >> start >> end;
            A[start].push_back(end);
            A[end].push_back(start);
        }

        //주어진 그래프가 하나로 연결된다는 보장이 없으므로 모든 노드에서 수행함.
        for(int i=1; i<=V; i++){
            if(IsEven){
                DFS(i);
            }
            else{
                break;
            }
        }
        if(IsEven){
            cout << "YES" << endl;
        }
        else{
            cout << "NO"<< endl;
        }

        for(int i=0; i<=V ; i++){
            A[i].clear();
        }
        fill(visited.begin(), visited.end(), false);
        fill(check.begin(), check.end(), 0);

    }
}

void DFS(int node){
    visited[node] = true;

    for(int i : A[node]){
        if(!visited[i]){
            //인접한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리한다
            //여기서는 0,1 로 처리르 함.
            check[i] = (check[node]+1)%2;
            DFS(i);
        }
        else if(check[node] == check[i]){
            //이미 방문한 노드가 현재 노드와 같은 집합이면 이분 그래프가 인접.
            IsEven = false;
        }
    }
}
#endif