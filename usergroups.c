#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct group {
	char *name;
	struct user *users;
	struct group *next;
};

struct user {
	char *name;
	char *email;
	struct group *group;
	struct user *next;
};

void *safemalloc(size_t size) {
	void *p = malloc(size);
	if (p == NULL) {
		printf("Fatal error: out of memory!");
		exit(1);
	}
	return p;
}

struct group *new_group(char *n)
{
	struct group *g;
	
	g = safemalloc(sizeof(struct group));
	g->name = strdup(n);
	g->users = NULL;
	g->next = NULL;
	return g;
}

struct user *new_user(char *n, char *e, struct group *g)
{
	struct user *v;
	
	v = safemalloc(sizeof(struct user));
	v->name = strdup(n);
	v->email = strdup(e);
	v->group = g;
	v->next = NULL;
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

struct group *find_group(struct group *list, char *name)
{
	struct group *g = list;
	while (g != NULL) {
		if (strcmp(g->name, name) == 0)
			break;
		g = g->next;
	}
	return g;
}	

struct user *find_user(struct user *list, char *name)
{
	struct user *u = list;
	while (u != NULL) {
		if (strcmp(u->name, name) == 0)
			break;
		u = u->next;
	}
	return u;
}

struct user *remove_user(struct user *list, struct user *node)
{
	struct user *u;
	
	// Remove the first node?
	if (list == node)
		return list->next;
	// Else, find the node to remove
	u = list;
	while (u != NULL) {
		if (u->next == node) {
			u->next = u->next->next;
			return list;
		}
		u = u->next;
	}
	return list;
}

int main(int argc, char **argv)
{
	struct group *groups = NULL;
	struct group *g, *g2;
	struct user *u;
	int command;
	char buf1[512];
	char buf2[512];
	char buf3[512];
	
	while(1) {
		printf("\nEnter command:\n");
		printf("1 - Add a group\n");
		printf("2 - Add a user\n");
		printf("3 - List groups\n");
		printf("4 - Move a user from one group to another\n");
		command = getint("Your command:");
		
		if (command == 1) {
			getstring("Input group name:", buf1, sizeof(buf1));
			// Insert new group first in linked list
			g = new_group(buf1);
			g->next = groups;
			groups = g;
		}
		else if (command == 2) {
			printf("Input user information\n");
			getstring("Group:", buf3, sizeof(buf3));
			g = find_group(groups, buf3);
			if (g == NULL) {
				printf("No group with that name!\n");	
			}
			else {
				getstring("Name:", buf1, sizeof(buf1));
				getstring("Email:", buf2, sizeof(buf2));
				// Insert user first in group's linked list
				u = new_user(buf1, buf2, g);
				u->next = g->users;
				g->users = u;
			}
		}
		else if (command == 3) {
			g = groups;
			while (g != NULL) {
				printf("Group %s:\n", g->name);
				u = g->users;
				while (u != NULL) {
					printf("%s (%s)\n", u->name, u->email);
					u = u->next;
				}
				g = g->next;
			}
		}
		else if (command == 4) {
			getstring("Input user name:", buf1, sizeof(buf1));
			getstring("Input current group:", buf2, sizeof(buf2));
			getstring("Input new group:", buf3, sizeof(buf3));
			g = find_group(groups, buf2);
			if (g == NULL) {
				printf("Group %s does not exist!\n", buf2);
				continue;
			}
			u = find_user(g->users, buf1);
			if (u == NULL) {
				printf("User %s is not in group %s!\n", buf1, g->name);
				continue;
			}
			g2 = find_group(groups, buf3);
			if (g2 == NULL) {
				printf("Group %s does not exist!\n", buf3);
				continue;
			}
			// Remove the user from g and insert it first in g2's list
			g->users = remove_user(g->users, u);
			u->next = g2->users;
			g2->users = u;
		}
		else {
			printf("Invalid command!\n\n");
		}
	}
	// TODO: Cleanup. :)
}
	