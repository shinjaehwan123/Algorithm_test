#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> splite_minus;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//일단 문자열을 입력받는다.
	string str;
	cin >> str;

	//입력 받으면 - 앞에서 문자열을 짜른다.
	stringstream input_string;
	input_string.str(str);
	string type_string;

	//이제 - 기준으로 짜른다.
	while (getline(input_string,type_string,'-')) { //짤란게 string 이다.
		//이제 getlinem 값이 나왔으면 저장한다.
		splite_minus.push_back(type_string);
	}

	int sum = 0;
	//splite_minus에는 -기준으로 짤린 -가 담겨있음
	//일단 맨 앞에 꺼는 더해야 된다.
	stringstream front_string;
	front_string.str(splite_minus[0]);

	//맨 앞에꺼는 더해야됨.
	while (getline(front_string, type_string, '+')) {
		sum = sum + stoi(type_string);
	}

	//이제 뒤에 꺼는 빼야함.
	for (int i = 1; i < splite_minus.size(); i++) {
		int minus_sum=0;
		stringstream plus_string;
		plus_string.str(splite_minus[i]);
		while (getline(plus_string, type_string, '+')) {
			minus_sum = minus_sum + stoi(type_string);
		}
		sum = sum - minus_sum;
	}

	cout << sum << endl;



}