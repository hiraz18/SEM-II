#include <stdio.h>
#include <string.h>

int main() {
    char str[100], word[20];
    int i, j, k, len, word_len;
    
    printf("Enter the main string: ");
    gets(str);
    
    printf("Enter word to delete: ");
    gets(word);
    
    len = strlen(str);
    word_len = strlen(word);
    
    // Remove all occurrences of word
    for (i = 0; i <= len - word_len; i++) {
        if (strncmp(&str[i], word, word_len) == 0) {
            // Found the word, shift characters left
            for (j = i; j <= len - word_len; j++) {
                for (k = j; k < len - word_len; k++) {
                    str[k] = str[k + word_len];
                }
            }
            len -= word_len;
            i--;  // Check same position again
        }
    }
    
    printf("String after removing word: %s\n", str);
    return 0;
}
