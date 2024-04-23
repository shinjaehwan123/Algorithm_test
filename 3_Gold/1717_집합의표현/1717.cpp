#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int>parent;

void union_func(int a, int b);
int find(int a);
void check(int a, int b);

//0은 합치기, 1은 check
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    parent.resize(N+1);

    //parent 설정
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    

    for(int i=0; i<M; i++){
        int quiz, start, end;
        cin >> quiz >> start >> end;

        if(quiz ==0){
            union_func(start, end);
        }

        else if(quiz == 1){
            check(start, end);
        }
    }

    return 0;

}

int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}

void union_func(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x == y){
        return;
    }
    else if(x !=y){
        parent[y] = x; 
        return;
    }
}

void check(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x == y){
        cout << "yes"<<"\n";
        return;
    }
    else{
        cout << "NO" << "\n";
        return;
    }
}




///////////////////////////////////////////////////////////////////

#if 0
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int find(int a);
void union_func(int a, int b);
bool check(int a, int b);
vector<int> parent;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    parent.resize(N+1);

    //parnet 초기화 함.
    for(int i=0; i<=N ; i++){
        parent[i] = i;
    }

    //question을 받음.
    for(int i=0 ; i< M; i++){
        int question, a, b;

        cin >> question >> a >> b;

        if(question == 0){
            union_func(a,b);
        }
        else{
            if(check(a,b)){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}

//대표값을 찾아 준다.
int find(int a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}

void union_func(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[b] = a;
        return;
    }

    return;
}

bool check(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return true;
    }
    else{
        return false;
    }
}
#endif