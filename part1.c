//
// Part 1 - manipulating char lists
//
// Created by Tom Grozev.
//

#include <stdio.h>
#include <stdlib.h>

char *read() {
    // Reads an input word and returns the char list

    // Allocates a max size of 20 bytes for the word
    char *word = malloc(20);

    printf("Please input a word: ");
    scanf("%s", word);

    return word;
}

int strLength(char *word) {
    // Gets the length of a string (char list)

    int length = 0;
    for (char *c = word; *c != '\0'; c++) {
        length++;
    }
    return length;
}

int charCount(char *str, char character) {
    // Counts the occurrences of `character` in a char list

    int count = 0;
    for (char *c = str; *c != '\0'; c++) {
        if (*c == character) count++;
    }
    return count;
}

void setCaseNums(char *str, int *uppercase, int *lowercase) {
    // Counts the uppercase and lowercase characters in a char list

    for (char *c = str; *c != '\0'; c++) {
        if (*c >= 'A' && *c <= 'Z') {
            // If uppercase
            (*uppercase)++;
        } else if (*c >= 'a' && *c <= 'z') {
            // If lowercase
            (*lowercase)++;
        }
        // Otherwise don't count
    }
}
void changeCase(char *str, int mode, int *changed, int *same) {
    // Change the case of a char list
    // `mode` of 1 for uppercase and 0 for lowercase

    for (char *c = str; *c != '\0'; c++) {
        if (*c >= 'A' && *c <= 'Z' && mode != 1) {
            // If uppercase and converting to lower

            // Convert to lower
            *c += 32;
            (*changed)++;
        } else if (*c >= 'a' && *c <= 'z' && mode == 1) {
            // If lowercase and converting to upper

            // Convert to upper
            *c -= 32;
            (*changed)++;
        } else {
            // Otherwise no change

            (*same)++;
        }
    }
}

int runPart1() {
    printf("*** Part 1 ***\n\n\n");

    char *word = read();
    printf("First char is: %c \n", word[0]);

    int length = strLength(word);
    printf("Word length: %d. \n", length);

    int mCount = charCount(word, 'm');
    printf("'m' appears in the string %d time%c. \n", mCount, mCount == 1 ? '\0' : 's');

    int uppercase = 0, lowercase = 0;
    setCaseNums(word, &uppercase, &lowercase);
    printf("There are %d uppercase letters and %d lowercase letters.\n", uppercase, lowercase);

    int changed = 0, same = 0;
    changeCase(word, 1, &changed, &same);
    printf("All uppercase %s, changed %d characters and %d stayed the same. \n", word, changed, same);

    // Reset both vars
    changed = same = 0;

    changeCase(word, 0, &changed, &same);
    printf("All lowercase %s, changed %d characters and %d stayed the same. \n", word, changed, same);

    return 0;
}
