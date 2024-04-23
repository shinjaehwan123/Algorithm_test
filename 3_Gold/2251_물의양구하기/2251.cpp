//내코드
//BFS로 구현해야됨

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//A : 0, B :1, C : 2
int A,B,C;
int send[6] = {0,0,1,1,2,2};
int receive[6]={1,2,0,2,0,1};
int bottle[3]={0,};
int full_standard[3];
vector<int>answer;
//처음에는 모든 visited을 방문하지 않았기 때문에 이렇게 설정함.
bool visited[201][201]={false,};
int MAX;

void BFS();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++){
        cin >> full_standard[i];
    }

    //bottle[2] = full_standard[2];

    BFS();

    sort(answer.begin(),answer.end());

    for(int i: answer){
        cout << i << " ";
    }
    return 0;
}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        //0은 A, 1은 B, 2는 C 용량이다.
        int current[3];

        //현재 남은 병의 용량을 표현한다.
        current[0] = myqueue.front().first;
        current[1] = myqueue.front().second;
        current[2] = full_standard[2] - current[0] - current[1];
        
        visited[current[0]][current[1]]= true;

        //만약 a의 물병이 비었다면 c물병의 용량을 구한다. 
        if(current[0]==0){
            answer.push_back(current[2]);
        }
        
        //그다음에 next 용량을 입력한다.
        myqueue.pop();

        for(int i=0; i<6;i++){
            int next[3];
            next[0] = current[0];
            next[1] = current[1];
            next[2] = current[2];
            
            int ns = send[i];
            int nr = receive[i];

            //다음 것을 정의해줌
            next[nr] = current[nr] + current[ns];
            next[ns]=0;

            if(next[nr] > full_standard[nr]){
                //넘치면 나머지를 전 sned 물병에 넘겨주고, 리시브 물병은 최대로 채워준다.
                int rest = next[nr] - full_standard[nr];
                next[ns] = rest;
                next[nr] = full_standard[nr];
            }

            //이제 push를 해준다.
            //3개니까 next[0],next[1]를 보내면 자연스럽게 next[2]를 알 수 있기 때문이다.
            if(!visited[next[0]][next[1]]){
                myqueue.push(make_pair(next[0], next[1]));
                //push를 했으면 방문 했으니까 visited 처리를 해준다.
                visited[next[0]][next[1]]= true;
            }       
        }
    }
}





















////////////////////////////////////////////////
//정답참고
#if 0
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void BFS();
//6가지 이동 케이스를 표현하기 위한 배열
static int Sender[] ={0,0,1,1,2,2};
static int Receiver[] = {1,2,0,2,0,1};
//A,B의 용량만 있으면 C의 용량이 고정되므로 2개로만 체크 가능
static bool visited[201][201];
static bool answer[201];
static int now[3]; //A,B,C의 물의 양을 저장하는 배열

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now[0] >> now[1] >> now[2];
    BFS();

    for(int i=0; i<201;i++){
        if(answer[i]){
            cout << i<< " ";
        }
    }
}

void BFS(){
    queue<pair<int,int>>queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    answer[now[2]]= true;

    while(!queue.empty(){
        pair<int,int>p = queue.front();
        queue.pop();
        int A. p.first;
        int B = p.second;
        int C = now[2]-A-B; //c는 전체 물의 양에서 A,B를 뺀것

        for(int k=0; i<6;k++);
        int next[] = {A,B,C};
        next[Receiver[k]] +=next[Sender[k]];
        next[Sender[k]]=0;

        //대상의 물통의 옹량보다 물이 많아 넘칠때
        if(nex[Reciever[k]] > now[Recever[k]]){
            //초과하는 만큼 다시 이전 물통에 넣음
        }
    })
}
#endif


#if 0
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int a,b,c;

static int Sender[]= {0,0,1,1,2,2};
static int Receiver[] ={1,2,0,2,0,1};
vector<int> answer;
//전체용량 - -A - B하면 C 용량이 나오기 때문에 2차원 배열로 충분
bool visited[201][201]={false,};
static int now[3];
bool flag = false;

bool compare(int &a, int &b){
    if(a < b){ //오름차순 정렬임.
        return true;
    }
    else{
        return false;
    }
}

void BFS(void);

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>now[0] >> now[1] >> now[2];

    BFS();

    sort(answer.begin(), answer.end(),compare);

    for(int i: answer){
        cout << i << " ";
    }

    return 0;

}

void BFS(void){
    queue<pair<int,int>> myqueue;
    myqueue.push(make_pair(0,0));
    visited[0][0] = true;

    while(!myqueue.empty()){
        int A = myqueue.front().first;
        int B = myqueue.front().second;
        int C = now[2] -A - B;

        visited[A][B] = true;

        myqueue.pop();

        if(A == 0){
            for(int i : answer){
                if(i == C){
                    flag =true;    
                }
            } 
            if(!flag){
                answer.push_back(C);
            }
            flag = false;
        }

        for(int k=0; k<6; k++){
            int next[] = {A,B,C}; //next에 현재 물병 잔량을 저장함. 미로탐색 int x,y만든 거랑 동일함.
            next[Receiver[k]] = next[Receiver[k]] + next[Sender[k]];
            //물병을 보내면 Sender쪽의 물의 양은 0이 되는게 원칙임.
            next[Sender[k]] =0;

            //이때 case를 2개로 나눠 볼 수 있음. 1) 물의 양이 넘칠때 2)
            if(next[Receiver[k]] > now[Receiver[k]]){
                //초과하는 만큼 다시 이전 물통에 넣음
                next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
                //대상 물통은 최대로 채움
                next[Receiver[k]] = now[Receiver[k]];
            }

            //A,B의 물의 양을 통하여 방문 배열 체크

            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]] = true;

                myqueue.push(make_pair(next[0], next[1]));
            }
        }
    }
}
#endif