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

void main()
{
    /*
    Here, we allocate an array of 100 characters and
    populate it explicitly with a null-terminated string.
    
    char word[100];
    
    word[0] = 'r';
    word[1] = 'a';
    word[2] = 'd';
    word[3] = 'a';
    word[4] = 'r';
    word[5] = 0;
    */
    
    // Here, we tell the compiler to allocate a null-terminated string.
    char *word = "level";
    
    if (ispalindrome(word)) {
        printf("Ja, ordet \"%s\" \\ er et palindrom.\n", word);
    }
    else {
        printf("Nei.\n");
    }
} 
