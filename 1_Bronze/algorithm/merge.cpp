#include <iostream>
#include <vector>

using namespace std;

void do_merge(int data[], int start, int mid, int end, int tarray[]){
    int lstart =start;
    int rstart = mid+1;
    int lend = mid;
    int rend = end;
    int i = start;
    int j = rstart;
    int t = start;

    while(1){
        if(i > lend && j >rend){
            break;
        }
        //이미 왼쪽은 다 넣었으면 오른쪽만 넣으면됨
        if(i > lend){
            tarray[t] = data[j];
            t++;
            j++;
        }
        else if(j > rend){
            tarray[t] = data[i];
            t++;
            i++;
        }
        //이제 서로 비교를 해줘야됨.
        //오름차순 정렬임.
        else{
            if(data[i] > data[j]){
                tarray[t]= data[j];
                t++;
                j++;
            }
            else{
                tarray[t] = data[i];
                t++;
                i++;
            }
        }
    }

    //이제 tarray에 복사된 것을 원본에 넣어줘야됨.
    for(int i=start; i<=end; i++){
        data[i] = tarray[i];

        cout<<data[i] << " ";
    }
    cout << endl;
}

void merge_sort(int data[], int start, int end, int tarray[]){
    int cnt=0;
    if(start == end){
        return;
    }

    merge_sort(data, start, (start+end)/2, tarray);
    cout << "enter" <<" "<< start << " "<<end <<endl;
    merge_sort(data, (start+end)/2 +1, end, tarray);
     cout << "enter2"<<" " << (start+end)/2 << " "<<end <<endl;
    do_merge(data, start, (start+end)/2, end, tarray);

}

int main(void){
    int data[8] = {1,2,3,4,5,6,7,8};
    int sz = sizeof(data) / sizeof(data[0]);
    cout << sz << endl;
    
    int *tarry = new int[sz];
    
    merge_sort(data, 0, sz-1, tarry);
   
    for(int i=0; i<sz;i++){
        cout << data[i] << " ";
    }

    cout << endl;

    delete[]tarry;
    return 0;
}