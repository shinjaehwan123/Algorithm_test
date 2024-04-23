#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    string str = "ABCDEFG";
    cout << str.substr(1)<<"\n";
    cout << str.substr(3,2)<<"\n";
}