#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    vector<int> A(N,0);

    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    
    cin >> M;
    vector<int> B(M,0);
    
    for(int i=0; i< M;i++){
        cin >> B[i];
    }
    
     sort(A.begin(), A.end());
    
    for(int i=0; i<M ;i++){
        int start =0;
        int end = N-1;
        bool flag = false;

        while(start <= end){

            int mid = (start+end)/2;
            if(B[i] > A[mid]){
                start = mid+1;  
            }
            else if(B[i] < A[mid]){
                end = mid -1;
            }
            else if(B[i] == A[mid]){
                
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "1"<< "\n";
        }
        else{
            cout<<"0"<<"\n";
        }
    }
}








//시간 초과뜸 이유 모름
#if 0 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N;
    vector<int> A(N);

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

  
    cin >> M;
    
    for(int i=0; i<M ;i++){
        int target;
        cin >> target;
        int start =0;
        int end = N-1;
        bool flag = false;

        while(start <= end){

            int mid = (start+end)/2;
            if(target > A[mid]){
                start = mid+1;  
            }
            else if(target < A[mid]){
                end = mid -1;
            }
            else if(target == A[mid]){
                cout << "1" << endl;
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << "0" << endl;
        }
        
        
    }
}
#endif