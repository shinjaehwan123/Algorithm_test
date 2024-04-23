//각각 그래프 독립적으로 그리기

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
        //cout << total_max_harvest <<" ";
        total_max_harvest += max_harvest_per_friend[i];
    }
    cout << total_max_harvest << "\n";

    return 0;
}