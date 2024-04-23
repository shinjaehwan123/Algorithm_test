#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>>A;
vector<bool> visited;
bool check;
void DepthFirstSearch(int startVertex, int depth);


#if 0
int main(void){
    ios::syn_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    check = false;
    cin >> N >>N;
    
    A.resize(N,vector<int>(N,0));
    visited.resize(N,0);

    for(int i=0; i<M;i++){
        int start, end;
        cin >> start >> endl;
        A[start].push_back(end);
        A[end].push_back(start);
    }

    
    for(int i=0; i<N ; i++){
        DepthFirstSearch(i,1); //처음에 깊이 1, 모든 노드 탐색
    }

    if(check){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }

}

void DepthFirstSearch(int startVertex, int depth){
    if(depth == 5 || check == true){
        return;
    }
    visited[startVertex] = 1;

    if(!visi)


}
#endif



int main(void){

    int N;
    cin>>N;
    vector <vector<int>> A;
    A.resize(N);

    
    for(int i=0; i<N; i++){
        int s,e;
        cin >> s >>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    cout << endl;
    cout << endl;

    for(int i : A[N-1]){
        for(int j=0; j< A[i].size(); j++){
            cout << A[i][j]<< " ";
        }
    }
    cout << endl;
  
}
