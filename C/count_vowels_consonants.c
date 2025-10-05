#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0, i;
    printf("Enter a string: ");
    gets(str);
    for (i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    return 0;
}
