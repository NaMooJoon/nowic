// JunHyeon Kim, section 03, st_num 21800179
    /*On my honour, I pledge that I have neither recived
    nor provided improer assistance in the completion of
    this assignment.*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string name;    // ����ڷκ��� �Է� ���� �̸� ����.

    if(argc >= 2) {     // ���� commend Line�� �����Ѵٸ�
        cout << "Hello";
        for(int i = 1; i < argc; i++)
            cout << " " << argv[i];
        cout << "!\n";
    }
    else {              // ���� commend Line�� �������� �ʴ´ٸ�
        while(true) {
            cout << "Enter the name: ";
            getline(cin, name);

            if(name.length() == 0) {   // �ƹ��͵� �Է� ���� �ʾҴٸ�
                cout << "Hello World!" << endl;
                break;
            }
            cout << "Hello " + name + "!"<< endl;
        }
    }
}
