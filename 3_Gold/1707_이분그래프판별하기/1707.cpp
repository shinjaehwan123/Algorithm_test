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