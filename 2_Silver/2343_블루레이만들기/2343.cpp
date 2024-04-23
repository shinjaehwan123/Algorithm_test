#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    int start =0;
    int end=0;

    for(int i=0; i<N;i++){
        cin>>A[i];
        if(start < A[i]){
            start = A[i];
        }
        end = end + A[i];
    }

    while(start <= end){
        int middle = (start + end)/2;
        int sum=0;
        int count =0;

        //middle값으로 모든 레슨을 저장할 수 있는지 확인한다
        for(int i=0; i<N;i++){
            if(sum+A[i]>middle){
                count++;
                sum=0;
            }
            sum = sum + A[i];
        }
        if(sum !=0){
            count++;
        }
        if(count > M){
            start = middle + 1;
        }
        else{
            end = middle -1;
        }
    }

    cout << start << endl;
}

#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int start =0;
    int end =0;

    for(int i=0; i<N; i++){
        cin >> A[i];
        if(start < A[i]){
            start = A[i];
        }
        end = end + A[i];
    }

    while(start <= end){
        int middel = (start + end)/2;
        int sum =0;
        int count =0;

        //middel값으로 모든 레슨을 저장할 수 있는지 확인함.
        for(int i=0; i< N; i++){
            if(sum +  A{i} > middle){
                count++;
                sum =0;
            }
            sum = sum+ A[i];
        }

        if(sum!=0){
            count++;
        }
        if(count > M){
            start = middle + 1;
        }
        else{
            end = middel-1;
        }
    }

    cout << start << endl;
}

#endif


#include <iostream>
#include <queue>

using namespace std;

static int dx[] = {0,1,0,-1};
static int dy[] = {1,0,-1,0};

static int A[101][101];
static bool visited[101][101] = {false,};
static int N, M;
void BFS(int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i=0 i<N ; i++){
        string s;
        cin >>s;
        for(int j=0; i < M; j++){
            A[i][j] = s[j] - '0';
        }
    }

    BFS(0,0);
    cout << A[N-1][M-1] << endl;
}

void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(i,j));

    while(!myqueue.empty()){
        int current[2];
        current[0] = myqueue.front().first;
        current[1]=  myqueue.front().second;

        myqueue.pop();
        visited[i][j] = true;

        for(int k=0; k<4; k++){
            int x = current[0] + dx[k];
            int y = current[1] + dy[k];

            if(x >=0 && y>=0 && x < N && y < M){
                if(A[x][y] ! =0 && !visited[x][y]){
                    visited[x][y] = true;
                    A[x][y] = A[current[0]][current[1]] +1;
                    myqueue.push(make_pair(x,y));
                }
            }
        }
    }
}