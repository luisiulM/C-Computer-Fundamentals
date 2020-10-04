#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include "list.h"

struct word {
	char *wordstring;
	list_t *filenames;
};

char *readfile(int *size, char *filename)
{
	FILE *f;
	struct stat s;
	char *buf;
	
	if (stat(filename, &s) != 0) {
		printf("Could not stat file %s\n", filename);
		return NULL;
	}	
	*size = s.st_size;
	buf = malloc(s.st_size);
	if (buf == NULL) {
		printf("Could not allocate buffer\n");
		return NULL;
	}	
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("Could not open file %s\n", filename);
		free(buf);
		return NULL;
	}
	if (fread(buf, 1, s.st_size, f) != s.st_size) {
		printf("Could not read from file %s\n", filename);
		free(buf);
		fclose(f);
		return NULL;
	}
	fclose(f);
	return buf;
}

char *dupstring(char *str, int len)
{
	char *result = malloc(len+1);
	if (result == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}
	strncpy(result, str, len);
	result[len] = 0;
	return result;
}

list_t *parsewords(char *data, int size)
{
	char *word;
	list_t *result;
	int idx, wordidx = -1;
	
	result = list_create();
	for (idx = 0; idx < size; idx++) {
		if (isspace(data[idx])) {
			if (wordidx != -1) {
				// Extract word from wordidx to idx
				word = dupstring(&data[wordidx], idx-wordidx);
				list_addlast(result, word);
				wordidx = -1;
			}
		}
		else {
			if (wordidx == -1) {
				wordidx = idx;
			}
		}	
	}
	return result;
}

struct word *newword(char *word, char *filename)
{
	struct word *item = malloc(sizeof(struct word));
	
	if (item == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}
	item->wordstring = word;
	item->filenames = list_create();
	list_addlast(item->filenames, filename);
	return item;
}

void addword(list_t *words, char *filename, char *word)
{
	struct word *item;
	list_iterator_t *iter;
	int found = 0;
	
	iter = list_createiterator(words);
	item = list_next(iter);
	while (item != NULL) {
		if (strcmp(word, item->wordstring) == 0) {
			list_addlast(item->filenames, filename);
			found = 1;
			break;
		}
		item = list_next(iter);
	}
	list_destroyiterator(iter);
	
	if (!found) {
		item = newword(word, filename);
		list_addlast(words, item);
	}
}

void processfile(list_t *words, char *filename)
{
	char *data;
	int size;
	list_t *filewords;
	list_iterator_t *iter;
	char *word;
	
	data = readfile(&size, filename);
	if (data == NULL)
		return;
	filewords = parsewords(data, size);
	
	iter = list_createiterator(filewords);
	word = list_next(iter);
	while (word != NULL) {
		addword(words, filename, word); 
		word = list_next(iter);
	}
	list_destroyiterator(iter);
	
	list_destroy(filewords);
}

void printwordinfo(struct word *item)
{
	list_iterator_t *iter;
	char *filename;
	
	iter = list_createiterator(item->filenames);
	filename = list_next(iter);
	while (filename != NULL) {
		printf("Word %s occurs in %s\n", item->wordstring, filename);
		filename = list_next(iter);
	}
	list_destroyiterator(iter);
}

void lookup(list_t *words, char *word)
{
	struct word *item;
	list_iterator_t *iter;
	
	iter = list_createiterator(words);
	item = list_next(iter);
	while (item != NULL) {
		if (strcmp(word, item->wordstring) == 0) {
			printwordinfo(item);
			return;
		}
		item = list_next(iter);
	}
	list_destroyiterator(iter);
	printf("Word %s not found\n", word);
}

int main(int argc, char **argv)
{
	int i;
	list_t *filenames;
	list_t *words;
	list_iterator_t *iter;
	char *item;
	
	filenames = list_create();
	for (i = 1; i < argc; i++) {
		list_addlast(filenames, argv[i]);
	}
	
	iter = list_createiterator(filenames);
	item = list_next(iter);
	while (item != NULL) {
		printf("Reading file %s\n", item);
		processfile(words, item);
		item = list_next(iter);
	}
	list_destroyiterator(iter);
	
	lookup(words, "int");
	lookup(words, "char");
	lookup(words, "filenames");
	
	list_destroy(filenames);
	return 0;
}