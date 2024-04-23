#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 22;
const int MAX_DEPTH = 3;
int n, m;
int graph[MAX_N][MAX_N]={0,};
vector<pair<int, int>> friends;

vector<vector<vector<pair<int, int>>>> paths;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int depth, vector<pair<int, int>>& current_path, vector<vector<pair<int, int>>>& all_paths) {
    if (depth == MAX_DEPTH) {
        all_paths.push_back(current_path);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
            current_path.push_back(make_pair(nx,ny));
            dfs(nx, ny, depth + 1, current_path, all_paths);
            //depth가 4개인 것을 pop해줌. vector는 후입선출
            current_path.pop_back();
        }
    }
}

int calculateHarvest(const vector<vector<pair<int, int>>>& chosen_paths) {
    int harvest = 0;

    int temp_graph[MAX_N][MAX_N]={0,};

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            temp_graph[i][j] = graph[i][j];
        }
    }

    for (const auto& path : chosen_paths) {
        for (const auto& p : path) {
            int x = p.first, y = p.second;
            //if (temp_graph[x][y] > 0) {
                harvest += temp_graph[x][y];
                temp_graph[x][y] = 0; // Avoid double counting
            //}
        }
    }
    return harvest;
}

void findMaxHarvest(int idx, vector<vector<pair<int, int>>>& chosen_paths, int& max_harvest) {
    if (idx == m) {
        max_harvest = max(max_harvest, calculateHarvest(chosen_paths));
        return;
    }

    for (const vector<pair<int, int>> & path : paths[idx]) {
        chosen_paths.push_back(path);
        findMaxHarvest(idx + 1, chosen_paths, max_harvest);
        chosen_paths.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    //n*n 정사각형 격자모형임.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    //사람 수를 resizing 해줌.
    friends.resize(m);
    paths.resize(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends[i].first =x;
        friends[i].second =y;

        //초기화 해줌
        vector<pair<int, int>> current_path;

        //초기화해줌
        current_path.push_back(make_pair(x,y));

        //초기화 해줌
        vector<vector<pair<int, int>>> all_paths;

        //모든 경우의 수를 path에 저장해 놓음.
        dfs(x, y, 0, current_path, all_paths);
        paths[i] = all_paths;
    }

    int max_harvest = 0;

    vector<vector<pair<int, int>>> chosen_paths;
    findMaxHarvest(0, chosen_paths, max_harvest);

    cout << max_harvest << "\n";

    return 0;
}













//chat gpt code
////////////////////////////////////////
#if 0
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 22;
const int MAX_DEPTH = 3;
int n, m;
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N));
vector<pair<int, int>> friends;
vector<vector<vector<pair<int, int>>>> paths;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int depth, vector<pair<int, int>>& current_path, vector<vector<pair<int, int>>>& all_paths) {
    if (depth == MAX_DEPTH) {
        all_paths.push_back(current_path);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
            current_path.push_back({nx, ny});
            dfs(nx, ny, depth + 1, current_path, all_paths);
            current_path.pop_back();
        }
    }
}

int calculateHarvest(const vector<vector<pair<int, int>>>& chosen_paths) {
    int harvest = 0;
    vector<vector<int>> temp_graph = graph;  // Deep copy 생성
    for (const auto& path : chosen_paths) {
        for (const auto& p : path) {
            int x = p.first, y = p.second;
            if (temp_graph[x][y] > 0) {
                harvest += temp_graph[x][y];
                temp_graph[x][y] = 0; // Avoid double counting
            }
        }
    }
    return harvest;
}

void findMaxHarvest(int idx, vector<vector<pair<int, int>>>& chosen_paths, int& max_harvest) {
    if (idx == m) {
        max_harvest = max(max_harvest, calculateHarvest(chosen_paths));
        return;
    }

    for (const auto& path : paths[idx]) {
        chosen_paths.push_back(path);
        findMaxHarvest(idx + 1, chosen_paths, max_harvest);
        chosen_paths.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    friends.resize(m);
    paths.resize(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends[i].first =x;
        friends[i].second =y;
        vector<pair<int, int>> current_path = {{x, y}};
        vector<vector<pair<int, int>>> all_paths;
        dfs(x, y, 0, current_path, all_paths);
        paths[i] = all_paths;
    }

    int max_harvest = 0;
    vector<vector<pair<int, int>>> chosen_paths;
    findMaxHarvest(0, chosen_paths, max_harvest);

    cout << max_harvest << "\n";

    return 0;
}

#endif






/////////////////////////////////////////


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;

const int MAX_N = 22;
int n, m;
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int, int>> friends;
vector<int> max_harvest_per_friend;

// Directions: up, right, down, left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int depth, int harvest, int &max_harvest) {
    if (depth == 3) {
        max_harvest = max(max_harvest, harvest);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny]) {
            //DFS로 3개를 택함.
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, harvest + graph[nx][ny], max_harvest);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    friends.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    //최대 수혹량
    max_harvest_per_friend.resize(m, 0);

    for (int i = 0; i < m; i++) {
        int x = friends[i].first;
        int y = friends[i].second;
        for(int i=0; i<=n; i++){
            fill(visited[i],visited[i]+(n+1),0);
        }
        visited[x][y] = true;
        dfs(x, y, 0, graph[x][y], max_harvest_per_friend[i]);
    }

    int total_max_harvest=0;

    for(int i=0; i<m; i++){
        cout << total_max_harvest <<" ";
        total_max_harvest += max_harvest_per_friend[i];
    }
    cout << total_max_harvest << "\n";

    return 0;
}
#endif


#if 0
//함께하는효도
#include <iostream>
#include <vector>
#include <algorithm>
//수확량이 최대여야함.

using namespace std;
//n은 정사각형 격자 모양, m명의 친구
//총 3초동안 움직임
int n,m;
int graph[21][21];
bool visited[21][21]= {false,};
int ans=0; //열매수확량
//up, right, down, left
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int maximum =0;
int answer[3]={0,};
vector<pair<int,int>> person;

void DFS(int a, int b, int depth, int person);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    //각 나무마다 가능한 열매 수확량이 주어져 있음.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    //친구의 초기위치가 주어짐.
    for(int i=0; i<m; i++){
        int r,c;
        cin >>r >>c;
        person.push_back(make_pair(r,c));
    }

    //일단 DFS로 해결해야됨.
    //사람 따로 따로 하면 안됨. 돌아 가면서 해야됨.
    for(int i=0; i<person.size(); i++){
        answer[i] = answer[i] + graph[person[i].first][person[i].second];
        graph[person[i].first][person[i].second]=0;
    }


    for(int i=0; i< person.size();i++){
        //cout << person[i].first<<" "<<person[i].second<<endl;
        DFS(person[i].first, person[i].second,0,i);
        answer[i] = maximum;
        cout << answer[i] << " ";
        maximum=0;
    }

    for(int i=0; i<person.size();i++){
        ans+=answer[i];
    }

    cout << ans << "\n";


}

//3번 움직인다. // 깊이도 측정해준다.
void DFS(int a, int b, int depth, int person){
    
    visited[a][b] = true;

    answer[person] = answer[person] + graph[a][b];
    //열매를 수확하면 0이된다.
    graph[a][b]=0;

    if(depth==3){
        if(maximum < answer[person]){
            maximum = answer[person];
        }
        return;
    }

    for(int i=0; i<4 ; i++ ){
        int next[2];
        next[0] = a+dx[i];
        next[1] = b+dy[i];

        //일단 탐색을 한다. visited를 하면 안된다. 그냥 놔둔다.
        if(next[0] <1 || next[0] > n || next[1] <1 || next[1] >n ){
            continue;
        }
        DFS(next[0], next[1],depth+1,person);
    
        
    }
    
}
#endif