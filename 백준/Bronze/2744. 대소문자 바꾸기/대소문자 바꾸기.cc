//command + R 이 실행 단축키
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    //cout << i.length() <<endl;
    //cout << i << endl;
    for (int i=0; i<str.length(); i++){
        if ('A' <= str[i] && str[i] <='Z'){
            //str[i] += 32;
            str[i] = tolower(str[i]);
        }
        else if('a' <= str[i] && str[i] <='z'){
            //str[i] -= 32;
            str[i] = toupper(str[i]);
        }
    }

    cout << str << endl;
    return 0;
}