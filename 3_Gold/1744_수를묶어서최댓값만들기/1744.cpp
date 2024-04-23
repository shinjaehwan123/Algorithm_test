#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>,less<int>> Plus_Component;  //내림차순 정렬
    priority_queue<int, vector<int>, greater<int>> Minus_Component; //오름차순 정렬

    int One_Component = 0;
    int Zero_Component = 0;

    for(int i=0; i< N; i++){
        int data;
        cin >> data;

        if(data > 1){
            Plus_Component.push(data);
        }
        else if(data == 1){
            One_Component++;
        }
        else if(data ==0){
            Zero_Component++;
        }
        else if(data < 0 ){
            Minus_Component.push(data);
        }
    }

    int result=0;

    //양수는 큰수끼리 곱하고 하나 남으면 더해줌
    //음수는 작은 수끼리 곱해주고 만약 하나의 음수가 남으면 남기고 0이 있으면 0이랑 곱해줌

    while(Plus_Component.size()>1){ //일단 1이상이 2개 있어야함
        int first = Plus_Component.top(); //우선순위가 가장 큰거 제일 큰 수 임. less로 했기 때문에
        Plus_Component.pop();
        int second = Plus_Component.top();
        Plus_Component.pop();
        result = result + first*second;
    }

    if(!Plus_Component.empty()){
        result = result + Plus_Component.top();
        Plus_Component.pop();
    }

    while(Minus_Component.size()>1){
        int first = Minus_Component.top(); //오름차순 정렬 따라서 가장 작은수
        Minus_Component.pop();
        int second = Minus_Component.top();
        Minus_Component.pop();
        result = result + first* second;
    }

    if(!Minus_Component.empty()){
        if(!Zero_Component){
            result = result + Minus_Component.top();
            Minus_Component.pop();
            
        }
    }


    //0이 있으면 마이너스를 없애주면됨
    //1은 그냥 더해주면 됨
    result = result + One_Component;

    cout << result<< "\n";



    return 0;

}