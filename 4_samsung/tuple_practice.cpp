#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, string> getAge(){
    int age;
    string name;
    cout << "나이를 입력하세요 : ";
    cin >> age;

    cout << "이름을 입력하세요";
    cin >> name;

    return make_tuple(age, name);
}

int main(void){
    tuple<int, string> personInfo;
    personInfo = getAge();

    cout << "나이 : "<< get<0>(personInfo) << endl;
    cout << "이름 : " << get<1>(personInfo) << endl;

    return 0;
}