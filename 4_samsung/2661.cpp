//좋은 수열
#if 0
#include <iostream>
#include <cstring>

using namespace std;

int N;

bool isbad(string str);

void good(int a , string str);


int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;

    good(0,"");

    return 0;
}

bool isbad(string str){
    for(int i=1; i<=str.length()/2; i++){
        if (str.substr(str.length() - 2 * i, i) == str.substr(str.length() - i, i)) {
            return false;
        }
    }
    return true;
}

void good(int a, string str){

    if(!isbad(str)){
        return;
    }

    if(a== N){
        cout << str << endl;
        exit(0);
    }

    good(a+1, str + "1");
    good(a+1, str + "2");
    good(a+1, str + "3");
    return;
}
#endif



//--------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;

bool isbad(string str);

void good(int a , string str);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    good(N,"");

    return 0;
}

bool isbad(string str){
    for(int i=1; i<=str.length()/2; i++){
        if (str.substr(str.length() - 2 * i, i) == str.substr(str.length() - i, i)) {
            return false;
        }
    }
    return true;
}

void good(int a, string str){
    //if(isbad(str)){
    //    return;
    //}


    if(str.length()== a){
        cout << str << "\n";
        exit(0);
    }

    if(isbad(str)){
        good(a, str + "1");
        good(a, str + "2");
        good(a, str + "3");
    }
    
}
