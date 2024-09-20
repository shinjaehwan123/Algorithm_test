#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

vector<int> parent;
int result =0;

//우선순위 queue를 만든다
struct compare{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        //차례대로 시작node, 종점 node, 가중치이다.
        if(get<2>(a) > get<2>(b)){ //오름차순으로 정렬한다.
            return true;
        }
        else{
            return false;
        }
    }
};

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void union_function(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return;
    }
    else{
        parent[b] = a;

        return;
    }

    
}

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> myqueue;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin >> V >> E;

    parent.resize(V+1);

    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    //최소 신장 트리

    for(int i=0; i<E; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        myqueue.push(make_tuple(start, end, weight));
    }
    int edge_add =0;
    //이제 노드
    //while(!myqueue.empty() && edge_add < V-1 ){ //이렇게 써도 맞음
    while(edge_add < V-1 ){
        tuple<int,int,int> now_node = myqueue.top();
        myqueue.pop();
        int start_node = get<0>(now_node);
        int end_node = get<1>(now_node);
        int weight = get<2>(now_node);
       

        if(find(start_node) == find(end_node)){ 
            continue;
        }
        else{
            union_function(start_node, end_node);
            edge_add++;
            result += weight;
        }
        
    }

    cout << result;

    return 0;   
}