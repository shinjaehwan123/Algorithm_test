#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<int>A(N);

    //작은 것이 top
    priority_queue<int, vector<int>, greater<int>> Myqueue; // 오름 차순


    //정렬 후 작은거 더하고 다시 정렬해야 하기 때문에 우선순위큐를 선택했음.
    for(int i=0; i<N; i++){
        cin >> A[i];
        Myqueue.push(A[i]);
    }
    
    int sum=0;
    while(Myqueue.size()!=1){
        int data1 = Myqueue.top();
        Myqueue.pop();
        int data2 = Myqueue.top();
        Myqueue.pop();

        Myqueue.push(data1+data2); //오름차순으로 들어감
        sum +=data1 + data2;
    }
    cout << sum << endl;
    return 0;

}




 #if 0
class Student{
    public:
        int id;
        int math, eng;
        Student(int num, int m, int e){
            this->id = num;
            this->math = m;
            this->eng = e;
        }
};

struct cmp{
    bool operator()(Student a, Student b){
        return a.id>b.id;

    }
};
 
int main() {
    priority_queue<Student,vector<Student>,cmp> pq;  
 
    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));
    
// 학번을 기준으로 작은 것이 먼저 출력이 된다 그 이유는 구조체 내부의 연산자 오버로딩에 있다
    while (!pq.empty()) {
        Student ts = pq.top(); pq.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }
 
    return 0;
}
#endif


// struct cmp{
//     bool operator()(int n1, int n2){
//         if(abs(n1) > abs(n2)){
//             return true;
//         }
//         else if(abs(n1) == abs(n2)){
//             if(n1 > n2){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//         else{
//             return false;
//         }
//     }
// };


#if0
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >>N;

    priority_queue<int, vector<int>, greater<int>> pd;
    int data;

    for(int i=0; i<N ; i++){
        cin >> data;
        pd.push(data);
    }

    int data1 =0;
    int data2 = 0;
    int sum = 0;

    while(pd.size()! =1){
        data1 = pd.top();
        pd.pop();
        data2 = pd.top();
        pd.pop()
        sum + = data1 + data2;
        pd.push(data1 + data2);
    }

    cout << sum<< "\n";
}



#endif