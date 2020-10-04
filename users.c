#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
	char *name;
	char *email;
};

struct user *new_user(char *n, char *e)
{
	struct user *v;
	
	v = malloc(sizeof(struct user));
	v->name = strdup(n);
	v->email = strdup(e);
	return v;
}

void free_users(struct user **users, int N)
{
	int i;
	
	for (i = 0; i < N; i++) {
		free(users[i]->name);
		free(users[i]->email);
		free(users[i]);
	}
	free(users);
}

void getstring(char *prompt, char *dst, int max)
{
    printf("%s\n", prompt);
    int n = 0;
    char ch;
    while (1) {
        scanf("%c", &ch);
        if (ch == '\n' || ch == '\r') {
            dst[n++] = 0;
            return;
        }
        if (n < max)
            dst[n++] = ch;  
    }
}

int getint(char *prompt)
{
	char buf[16];
	getstring(prompt, buf, sizeof(buf));
	return atoi(buf);
}

int main(int argc, char **argv)
{
	struct user *u;
	int i, N;
	struct user **users;
	char buf1[512];
	char buf2[512];
	
	while(1) {
		N = getint("Input the number of users:");
		users = malloc(sizeof(struct user *) * N);
		for (i = 0; i < N; i++) {
			printf("Input information about user #%d\n", i+1);
			getstring("Name:", buf1, sizeof(buf1));
			getstring("Email:", buf2, sizeof(buf2));
			u = new_user(buf1, buf2);
			users[i] = u;
		}
		for (i = 0; i < N; i++) {
			printf("%d: name=%s email=%s\n", i, users[i]->name, users[i]->email);
		}
		free_users(users, N);
	}
	return 0;
}
