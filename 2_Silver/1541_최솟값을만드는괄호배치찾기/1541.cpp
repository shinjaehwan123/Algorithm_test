#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespcae std;

vector<string> split(string input, char delimiter);
int mySum(string a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');

    for(int i=0; i< str.size(); i++){
        int temp = mySum(str[i]);
        if(i==0){
            answer = answer + temp; //제일 앞에 것만 더함
        }
        else{
            answer = answer - temp;
        }
    }
    cout << answer << endl;
}

vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while(getlin(mystream, splitdata, delimiter)){
        result.push_back(splitdata);
    }
    return result;
}

int mySum(string a){
    int sum =0;
    vector<string> temp = split(a,'+');

    for(int i=0; i< temp.size(); i++){
        sum += stoi(temp[i]);
    }
    return sum;
}


#if0
#include <iostream>
#include <string>
using namespace std;

int main() {
	string ex;                   // 입력받을 식
	bool check = false;          // - 판별
	string number = "";          // 식에 사용된 숫자
	int min_answer = 0;          // 식의 최솟값

	cin >> ex;

	for (int i = 0; i <= ex.size(); i++) {
		// 1. 기호를 만났거나, 식이 끝났을 시
		if (ex[i] == '-' || ex[i] == '+' || i == ex.size()) {  

			// 앞서 '-'가 있었다면, 숫자를 빼줌
			if (check == true) {    
				// 문자열 형태의 숫자를 정수형으로 변환
				min_answer -= stoi(number);    
				// 사용된 숫자는 공백으로 초기화
				number = "";                    

			}

			// 앞서 '-'가 없었다면, 숫자를 더해줌
			else if (check == false) {
				min_answer += stoi(number);
				number = "";

			}

		}


		// 2. 기호가 아닌 경우 (숫자인 경우)
		else {
			number += ex[i];     // 문자열 형태로 숫자 저장
		}


		// 3. '-'를 만난 경우
		/* 
		해당 구문을 for문의 가장 마지막에 둔 이유는, 
		해당 구문이 앞에 있을 경우 '-' 앞의 숫자부터 빼주게 되기 때문이다.
		예를 들어, 55 - 50 + 40 의 경우, 55 - (50 - 40) 을 해주어야 한다.
		만약, 이 구문을 앞에 두게 되면,
		1의 첫번째 경우를 따르게 되고 앞서 저장되어있던 숫자인 55를 빼주게 된다.
		따라서, -55 - 50 - 40 = -135 라는 결과가 나오게 된다.
		이러한 경우를 방지하기 위해 해당 구문을 가장 아래에 배치하였다.
		*/

		if (ex[i] == '-') {      // - 발견 시, true로 변경
			check = true;
		}


	}

	cout << min_answer;

	return 0;
}
#endif

#include <iostream>
#include <string>

using namespace std;

int main(){
	string A;
	bool Minus_Check = false;
	string number="";
	int answer=0;
	
	cin >>A;

	for(int i=0; i<=A.size(); i++){
		if(A[i]=='-' || A[i]=='+' || i == A.size()){
			if(Minus_Check == true){
				answer = answer - stoi(number);
				number = "";
			}
			else if(Minus_Check = false){
				answer = answer + stoi(number);
				number="";
			}
		}
		//기호가 아닌 숫자일 경
		else{
			number += A[i];

		}

		if(A[i]=='-'){
			Minus_Check = 1;
		}
	}

	cout << answer << endl;
}