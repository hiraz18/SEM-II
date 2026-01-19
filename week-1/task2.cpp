#include <stdio.h>
#include <string.h>

int main() {
    char str[100], word[20];
    int i = 0, j, len, word_len;
    
    printf("Enter the main string: ");
    gets(str);
    
    printf("Enter word to delete: ");
    gets(word);
    
    len = strlen(str);
    word_len = strlen(word);
    
    // Remove all occurrences of word
    while (i <= len - word_len) {
        if (strncmp(&str[i], word, word_len) == 0) {
            // Shift characters LEFT by word length
            for (j = i; j < len - word_len; j++) {
                str[j] = str[j + word_len];
            }
            len -= word_len;
        } else {
            i++;
        }
    }
    str[len] = '\0';
    
    printf("String after removing word: %s\n", str);
    return 0;
}
