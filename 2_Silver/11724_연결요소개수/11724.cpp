#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int N, M;
int top = -1;
vector<vector<int>> graph;
vector<int> Mystack;
vector<bool> visited;

void DepthFirstSearch(vector<vector<int>> & A, int startVertex);

void push(int v){
    if(top == N){
        return;
    }
    int res = v;
    top++;
    Mystack[top] = res;
    return;
}

int pop(void){
    if(top == -1){
        return -999;
    }
    int res = Mystack[top];
    top--;
    return res;
}

bool instack(int v){
    for(int i=0; i<=top; i++){
        if(Mystack[i]==v){
            return true;
        }
    }
    return false;
}

void swap(vector<int> & A, int v1, int v2){
    int temp = A[v1];
    A[v1] = A[v2];
    A[v2] = temp;
}

void DepthFirstSearch(vector<vector<int>> & A, int startVertex){
    push(startVertex);
    
    while(1){
        int v = pop();
        if(v == -999){
            return;
        }
        visited[v] = 1; //방문한 vertex는 1로 표시를 해줌

        for(int i=1; i<N+1;i++){
            if(graph[v][i] != 0){
                if(visited[i] == 0 && instack(i)==0){
                    push(i);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >>N>>M;
    graph.resize(N + 1, vector<int>(N + 1, 0));
    Mystack.resize(N + 1, 0);
    visited.resize(N + 1, 0);
    

    for(int i=0; i<M; i++){
        int v1, v2;
        cin >>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }

    int count =0;

    for(int i=1; i<N+1;i++){
        if(!visited[i]){
            count++;
            DepthFirstSearch(graph, i);
        }
    }
    cout << count << endl;
}



// int main(){
//     vector < vector <int> > v;
//     vector <int> v2;
    
//     v.push_back(v2);
    
//     v[0].push_back(20);
//     v[0].push_back(10);
//     // v[0]에 담겨있는 v2 벡터에 7 입력
    
//     cout << v[0][0] << v[0][1]<<endl;; // 7 출력
    
//     cout << v.at(0).at(0); // 동일하게 7 출력
// }
