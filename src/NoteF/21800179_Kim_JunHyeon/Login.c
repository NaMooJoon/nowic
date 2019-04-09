#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Login.h"


void show_menu(int login) {
    if(login == true) {
        printf("=================MENU================\n");
        printf("0. quit  2. Logout\n");
        printf("====================================\n\n");
    }else {
        printf("=================MENU================\n");
        printf("0. quit  1. Login  2. logout  3. make id\n");
        printf("=====================================\n\n");
    }
}


int ask_menu(int login) {
    int menu;
    printf("Enter the input: ");
    scanf(" %d", &menu);
    if(menu == 0)
        return -1;

    return menu;
}


void load_file(Login** userlist, int* many) {
    FILE* fp = NULL;
    int N;
    char line[20];
    Login* newNode = NULL;
    Login* head = NULL;
    fp = fopen("password.txt", "r");

    // 몇명인지 입력
    fscanf(fp, "%d", &N);
    // 그 만큼 정보 입력

    for(int i = 0; i < N; i ++) {
        newNode = (Login*)malloc(sizeof(Login));
        fscanf(fp, "%s", line);
        strcpy(newNode->id, line);

        fscanf(fp, "%s", line);
        strcpy(newNode->password, line);

        if(head == NULL){
            head = newNode;
            newNode->next = NULL;
        }else {
            newNode->next = head;
            head = newNode;
        }
    }

    *userlist = head;
    *many = N;

    fclose(fp);
}

void login(Login* userlist, int* is_login) {
    char id[20];
    char password[20];
    Login* head;

    printf("Input the ID >> ");
    scanf("%s", id);

    head = userlist;
    while(head != NULL) {
        if(strcmp(head->id, id) == 0) {
            printf("Input the password >> ");
            scanf("%s", password);
            if(strcmp(head->password, password) == 0) {
                printf(">> Login is successed.\n\n");
                *is_login = true;
                return ;
            }else {
                printf(">> Wrong password\n\n");
                *is_login = false;
                return ;
            }
        }
        head = head->next;
    }
    printf("Wrong ID\n\n");
    *is_login = false;
}

void logout() {
    printf("Logout is successed.\n\n");
}

void join(Login* userlist, int* N) {
    char id[20];
    char password[20];
    Login* head = NULL;
    printf("Make new ID!\n\n");

    printf("Input the new ID >> ");
    scanf("%s", id);
    printf("Input the new password >> ");
    scanf("%s", password);
    *N += 1;

    Login* newNode = (Login*)malloc(sizeof(Login));
    strcpy(newNode->id, id);

    strcpy(newNode->password, password);

    newNode->next = userlist;
    userlist = newNode;

    FILE* fp = NULL;
    fp = fopen("password.txt", "w");

    head = userlist;
    fprintf(fp, "%d\n", *N);
    while(head != NULL) {
        fprintf(fp, "%s ", head->id);
        fprintf(fp, "%s\n", head->password);

        head = head->next;
    }

    fclose(fp);
}
