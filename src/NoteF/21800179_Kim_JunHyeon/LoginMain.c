/*
* ���� - ������ �о����
* ���ѹݺ�
* * User���� �޴��� �����ֱ�
* * * �޴��� ����
* * * �޴�(�α���) 1
* * * �޴�(ȸ������) 2
* * * �޴�(�α׾ƿ�) 3
* * * �޴�(����) 0
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Login.h"

int main(void) {
    int is_login = false;
    int menu;
    int many;

    Login* userlist;
    load_file(&userlist, &many);

    while(1) {
        show_menu(is_login);
        menu = ask_menu(is_login);
        if(menu == -1) break;

        switch(menu) {
            case 1: login(userlist, &is_login);
                    break;
            case 2: logout();
                    is_login = false;
                    break;
            case 3: join(userlist, &many);
                    break;
            default:printf("Wrong access\n");
                    break;
        }
    }

    return 0;
}
