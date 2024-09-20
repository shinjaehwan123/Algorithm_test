//진실을 아는 사람의 초기 연결 설정:
//진실을 아는 사람들 간의 연결을 설정하는 부분이 누락되어 있습니다. 이는 처음에 진실을 아는 모든 사람들이 서로 연결되어 있다는 것을 명확히 해야 합니다.
//파티 내 사람들의 초기 연결 처리:
//각 파티 내의 사람들이 파티에 처음 참여할 때, 파티의 첫 번째 사람과 나머지 사람들을 연결하는 과정이 명확하게 처리되지 않습니다. 특히, 진실을 아는 사람이 파티에 있을 때 그 사람을 기준으로 연결을 해야 합니다.
//flag 변수의 사용:
//flag 변수를 사용하여 진실을 아는 사람의 존재를 확인하지만, 이것이 파티 내 다른 사람들과의 연결을 제대로 관리하지 못할 수 있습니다. flag 변수의 처리 로직이 명확하지 않습니다.

#include <iostream>
#include <vector>

using namesapce std;

vector<int>parent;
vector<int> trueP;
vector<vector<int>>party;
int result;
void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,T;
    cin >> N >> M >>T;
    trueP.resize(T);

    for(int i=0; i<T: i++){
        cin >> trueP[i];
    }
    party.resize(M);

    for(int i=0; i<M; i++){
        int party_size;
        cin >> party_size;

        for(int j=0; j< party_size; j++){
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N+1);

    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=0; i<M; i++){
        int firstPeople = party[i][0];
        for(int j=1; j<party[i].size(); j++){
            unionfunc(firstPeople, party[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        bool isPossible = true;
        int cur = party[i][0];
        for(int j=0; j<T; j++){
            if(find(cur) == find(trueP[i])){
                isPossible = false;
                break;
            }
        }

        if(isPossible){
            result++;
        }
    }

    cout << result;
}

void unionfunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[b] = a;
    }
}

int find(int a){
    if(a == parnet[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}























#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int>parent;
vector<vector<int>> graph;
vector<int>true_person;
int find(int node);
void union_func(int a, int b);
vector<vector<int>>party;
int flag = false;
int cnt=0;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; //사람의 수, 파티의 수
    cin >> N >> M;
    parent.resize(N+1);
    party.resize(M+1);

    //사람들의 번호가 1부터 N까지 주어진다.
    for(int i=1; i<=N; i++){
        parent[i]= i; //각각의 parent를 할당해준다.
    }

    int N_1; //진실을 아는 사람들의 숫자이다.
    cin >> N_1;

    true_person.resize(N_1); //이건 +!해줄 필요가 없음

    //만약 N_1이 0이라면 안쳐도 된다.
    for(int i=0; i<N_1;i++){
        cin >> true_person[i]; //진실을 아는 사람들을 저장함.
    }

    //이제 파티에 진실을 아는 사람이 있으면 그 사람을 parnet로 해서 union_func을 진행한다.
    for(int i=0; i<M; i++){
        int person; //파티에 오는 사람 수
        cin >> person;
       

        //vector<vector<int>>party;

        int standard;
        for(int u=0; u<person; u++){
            int select;
            cin >> select;
            party[i].push_back(select);

            if(flag == false){
                for(int j=0; j<N_1;j++){
                    if(true_person[j]==party[i][u]){ //만약 파티안에 true를 아는 person이 있으면
                        standard = true_person[j];
                        flag = true;
                        break;
                    }
                    else if(true_person[j] == find(party[i][u])){
                        standard = true_person[j];
                        flag = true;
                        break;
                    }
                }
            }
        }

        if(flag == true){//과장을 못한다.
            for(int r=0; r<person;r++){
                union_func(standard, party[i][r]); //모든 요소를 연결함.
            }
        }
        flag = false;
    }

    //이제 파티를 비교하면서 가능한 파티를 차즌다.
    int true_flag = false;

    for(int i=0; i<M ; i++){
        for(int node : party[i]){
            for(int k=0; k<N_1; k++){
                //만약 파티에 진실을 아는 사람이 있따면
                if(find(node) == true_person[k]){
                    true_flag = true;
                    break;
                }
            }
        }

        if(true_flag == false){
            cnt++;
           
        }
        true_flag = false;
    }
    

    

    cout << cnt <<"\n";
    return 0;
}

void union_func(int a, int b){
    int i = find(a);
    int j = find(b);

    if(i!=j){
        parent[j]=i;
    }
}

//최종 부모 노드를 입력해준다.
int find(int node){
    if(parent[node] == node){
        return node; //이것이 최종 부모 노드이다.
    }
    return parent[node] = find(parent[node]);
}
#endif



#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> parent;
vector<vector<int>> party;
vector<int> true_person;
int cnt = 0;

int find(int node);
void union_func(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 사람의 수, 파티의 수
    cin >> N >> M;
    parent.resize(N + 1);
    party.resize(M);

    // 각각의 parent를 할당해준다.
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int N_1; // 진실을 아는 사람들의 수
    cin >> N_1;

    true_person.resize(N_1);

    // 진실을 아는 사람들을 저장함.
    for (int i = 0; i < N_1; i++) {
        cin >> true_person[i];
    }

    // 파티에 참가한 사람들을 처리한다.
    for (int i = 0; i < M; i++) {
        int person; // 파티에 오는 사람 수
        cin >> person;

        for (int u = 0; u < person; u++) {
            int select;
            cin >> select;
            party[i].push_back(select);

            // 파티에 진실을 아는 사람이 있으면, 해당 파티 멤버들끼리 연결한다.
            for (int j = 0; j < N_1; j++) {
                if (true_person[j] == select) {
                    union_func(true_person[j], party[i][u]);
                    break;
                }
                else if (true_person[j] == find(select)) {
                    union_func(true_person[j], party[i][u]);
                    break;
                }
            }
        }
    }

    // 과장된 이야기를 할 수 있는 파티 개수를 계산한다.
    for (int i = 0; i < M; i++) {
        bool can_exaggerate = true;
        for (int node : party[i]) {
            // 파티에 진실을 아는 사람이 있는지 확인한다.
            for(int j=0; j<N_1;j++){
                if (find(node) == true_person[j]) {
                    can_exaggerate = false;
                    break;
                }
            }
            if(can_exaggerate == false){
                break;
            }
        }
        if (can_exaggerate) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}

void union_func(int a, int b) {
    int i = find(a);
    int j = find(b);

    if (i != j) {
        parent[j] = i;
    }
}

// 최종 부모 노드를 찾는다.
int find(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find(parent[node]);
}
#endif
