//노드순서 고려해줘야함 위상정렬임
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>degree;
vector<int>setbuild;
vector<vector<int>>graph;
vector<int>goal;
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	degree.resize(N + 1);
	setbuild.resize(N + 1);
	goal.resize(N + 1,0);
	graph.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int time;
		cin >> time;
		setbuild[i] = time;
		
		//이제 우선순위 건물을 비교해줘야함.
		while (1) {
			int prebuild;
			cin >> prebuild;
			
			if (prebuild == -1) {
				break;
			}
			else {
				graph[prebuild].push_back(i);
				//그리고 degree를 1씩증가 시킨다.
				degree[i]++;
			}
		}
	}

	//이제 위상정렬이 완성됨
	queue<int> myqueue;

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			//차수가 0인 노드는 우선순위가 높으므로 push해준다.
			myqueue.push(i);
		}
	}

	//이제 push된 것부터 출력을 해준다. 그리고 queueu가 빌때까지 출력해준다.
	while (!myqueue.empty()) {
		int now = myqueue.front();
		myqueue.pop();

		for (int node : graph[now]) {
			//이제 순서대로 해당 종속 노드가 나오게 된다.
			//일단 차수 하나를 낮춰준다.
			degree[node]--;

			//push를 해준다.
			if (degree[node] == 0) {
				myqueue.push(node);
			}
			
			//그 다음에 해당 노드 현재 상태에다 setbuild를 더해준다.
			//2개 이상의 건물이랑 종속성이 있을경우 큰 build 시간이 지난 후 지어진다.
			goal[node] = max(goal[node], (goal[now] + setbuild[now]));
		}
		
	}

	//이제 모든 노드에 자기 자신의 시간을 더한다.
	for (int i = 1; i <= N; i++) {
		goal[i] = goal[i] + setbuild[i];

		cout << goal[i] << endl;
	}


	return 0;
}