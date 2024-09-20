#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T,k,n;
int data[15][15];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int i=0; i<T; i++){
        cin >>k>>n;

        for(int i=1; i<=14; i++){
            data[0][i] = i;
            data[i][1] = 1;
        }

        //1층 부터 k층까지
        for(int i=1; i<=14; i++){
            for(int j=2; j<=14 ;j++){
                data[i][j] = data[i][j-1] + data[i-1][j];
            }
        }

        cout << data[k][num] << endl;

    }


}