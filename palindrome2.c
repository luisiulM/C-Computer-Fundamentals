#include <stdio.h>

int ispalindrome(char *word)
{
    int left, right;
    int ispal = 1; // Assume for now the word IS a palindrome
    int len;
    
    // Find the length of the null-terminated string
    len = 0;
    while (word[len] != 0)
        len++;  
    
    left = 0;
    right = len-1;
    while (left < right) {
        // Compare the left and right characters to see
        // if this is perhaps NOT a palindrome
        if (word[left] != word[right]) {
            ispal = 0;
        }
        left++;
        right--;
    }
    return ispal;
}

void keepletters(char *src, char *dst)
{
    int i = 0;
    int n = 0;
    
    while (src[i] != 0) {
        char ch = src[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'a' + (ch - 'A');
        }
        if (ch >= 'a' && ch <= 'z') {
            dst[n] = ch;
            n++;
        }
        i++;
    }
    dst[n] = 0;
}

void getstring(char *dst, int max)
{
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

void main()
{
    char str[100];
    char str2[100];
    
    printf("Type in a word!\n");
    getstring(str, 99);
    printf("str = %s\n", str);
    keepletters(str, str2);
    printf("str2 = %s\n", str2);
    if (ispalindrome(str2)) {
        printf("Ja, ordet \"%s\" er et palindrom.\n", str);
    }
    else {
        printf("Nei, ordet \"%s\" er ikke et palindrom.\n", str);
    }
} 
