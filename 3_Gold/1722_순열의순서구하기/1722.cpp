//소문제 1을 푸는 알고리즘, 예제 1을 이용해 K번째 순열을 출력한다.
//1. 주어진 값(K)과 현재 자리(N) -1 에서 만들 수 있는 경우의 수를 비교한다.
//2. 1에서 K가 더 작아질 때까지 경우의 수를 배수(cnt)로 증가시킨다.(순열의 경우 1씩 늘림)
//3. K가 더 작아지면 순열에 값을 저장하고 K를 K - (경우의 수 * (cnt -1))로 업데이트한다.
//4. 순열이 완성될 때까지 1~3을 반복하고 완료된 순열을 출력한다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int N,Q;
//F에는 자리별 만들 수 있는 경우의 수를 저장한다.
//S에는 순열을 담는 배열임
//visited는 숫자 사용 여부를 물어본다.
static long F[21] , S[21];
static bool visited[21] = {false,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    //자리수 별로 만들 수 있는 경우의 수를 집어 넣는다.
    F[0] = 1;

    //팩토리얼 초기화 -> 각 자리수에서 만들 수 있는 경우의 수
    for(int i=1; i<=N; i++){
        F[i] = i * F[i-1];
    }

    if(Q == 1){
        long K;
        //몇번째 순열을 출력할 건지 결정을 한다.
        cin >> K;

        for(int i=1; i<= N; i++){
            for(int j=1, cnt =1; j<=N; j++){
                //이미 사용한 숫자는 사용 못함
                if(visited[j]){
                    continue;
                }
                //이제 주어진 K에 따라 각 자리에 들어갈 수 있는 수를 차즌다.
                if(K <=cnt* F[N-i]){
                    K = K - ((cnt-1)*(F[N-i]));
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
            
        }
        for(int u= 1; u<=N; u++){
            cout << S[u] << " ";
        }

    }
    else{
        long K=1; //처음에는 최소값으로 시작을 한다. 최소값이 1이다.

        for(int i=1; i<=N; i++){
            //입력받을 순열을 입력한다.
            cin >> S[i];
            long cnt = 0;

            for(int j=1; j<S[i]; j++){
                if(visited[j] == false){
                    cnt++;
                }
            }
            K += cnt * F[N-i];
            visited[S[i]] = true;
        }
         cout << K << endl;
    }
    return 0;
}