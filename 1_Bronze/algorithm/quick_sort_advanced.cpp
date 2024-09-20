//정렬 후 앞에서 K번째 수를 출력하는 프로그램이다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void quicksort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N  >> K;
    vector<int> A(N,0);

    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    quicksort(A,0,N-1, K-1);
    cout << A[K-1];
    
    cout << endl;
}

void quicksort(vector<int> &A, int S, int E, int K){
    int pivot = partition(A,S,E);
    if(pivot == K){ //K번째 수가 pivot이면 더는 구할 필요가 없음
        return;
    }
    else if(K < pivot){
        quicksort(A,S,pivot-1, K);
    }
    else{
        quicksort(A,pivot+1, E, K);
    }
}

int partition(vector<int> &A, int S, int E){
    if(S+1 == E){
        if(A[S] > A[E]){
            swap(A,S,E);
        }
        return E;
    }

    int M = (S+E)/2;
    swap(A,S,M); //중앙값을 1번째 요소로 이동
    int pivot = A[S];
    int i = S+1, j = E;

    while(i<=j){
        while(pivot < A[j] && j>0){
            j--;
        }
        while(pivot >= A[i] && i < A.size()-1){
            i++;
        }
        if(i<=j){
            swap(A,i,j);
        }
    }

    //i == j 피벗의 값을 양쪽으로 분리한 가운데로 오도록 설정
    A[S] = A[j];
    A[j] = pivot;
    return j;
}

void swap(vector<int> &A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}