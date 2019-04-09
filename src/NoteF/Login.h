#ifndef Login_h
#define Login_h

#define true    1
#define false   0

typedef struct login {
    char id[20];
    char password[20];
    struct login* next;
} Login;

void show_menu(int login);
int ask_menu(int login);

void load_file(Login** userlist, int* many);

void login(Login* userlist, int* is_login);
void logout();
void join(Login* userlist, int* N);


#endif
