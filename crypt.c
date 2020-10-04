#include <stdio.h>

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

void getint(char *prompt, int *dst)
{
    printf("%s\n", prompt);
    scanf("%d", dst);
}

void encrypt(char *s, int shift)
{
    // Modify the string s in-place, and encrypt all letters.
    // This means we cannot pass a string literal like "some text"
    // to this function, because string literals are allocated in
    // read-only memory.
    int i;
    
    for(i = 0; s[i] != 0; i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') {
            int x = ch - 'A';
            x = (x + shift) % 26;
            if (x < 0)
                x += 26;
            s[i] = 'A' + x;
        }
        else if (ch >= 'a' && ch <= 'z') {
            int x = ch - 'a';
            x = (x + shift) % 26;
            if (x < 0)
                x += 26;
            s[i] = 'a' + x;
        }
    }
}

void main()
{
    char text[100];
    int shift;
    
    // Infinite loop... use Ctrl-C to terminate the program
    while(1) {  
        getstring("Input your text:", text, 99);
        getint("Input the shift:", &shift);
        
        printf("text=%s\n", text);
        printf("shift=%d\n", shift);
        encrypt(text, shift);
        printf("Encrypted text=%s\n", text);
        encrypt(text, -shift);
        printf("Decrypted text=%s\n\n", text);
    }
}