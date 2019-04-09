// JunHyeon Kim, section 03, st_num 21800179
    /*On my honour, I pledge that I have neither recived
    nor provided improer assistance in the completion of
    this assignment.*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string name;    // 사용자로부터 입력 받을 이름 저장.

    if(argc >= 2) {     // 만약 commend Line이 존재한다면
        cout << "Hello";
        for(int i = 1; i < argc; i++)
            cout << " " << argv[i];
        cout << "!\n";
    }
    else {              // 만약 commend Line이 존재하지 않는다면
        while(true) {
            cout << "Enter the name: ";
            getline(cin, name);

            if(name.length() == 0) {   // 아무것도 입력 받지 않았다면
                cout << "Hello World!" << endl;
                break;
            }
            cout << "Hello " + name + "!"<< endl;
        }
    }
}
