/**
 * Manipulating char lists
 * Part 1 - Assignment 1 - CLA
 *
 * Created by Tom Grozev.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Reads an input word and returns the char list
 *
 * @return Inputted word
 */
char *read() {
    // Allocates a max size of 20 chars for the word
    char *word = malloc(20);

    printf("Please input a word: ");
    scanf("%s", word);

    return word;
}

/**
 * Gets the length of a string (char list)
 *
 * @param [in] word Char list to calculate length of
 * @return The integer length of the input
 */
int strLength(char *word) {
    int length = 0;

    // Loop over each character in word until at the end ('\0' character)
    for (char *c = word; *c != '\0'; c++) {
        length++;
    }
    return length;
}

/**
 * Counts the occurrences of `character` in a char list
 *
 * @param [in] str The string to count in
 * @param [in] character The character to count
 * @return The integer number of occurrences of `character` in `str`
 */
int charCount(char *str, char character) {
    int count = 0;

    // Loop over each character in word until at the end ('\0' character)
    for (char *c = str; *c != '\0'; c++) {
        if (*c == character) count++;
    }
    return count;
}

/**
 * Counts the uppercase and lowercase characters in a char list
 *
 * @param [in] str The string to count on
 * @param [out] uppercase Number of uppercase chars is written to this
 * @param [out] lowercase Number of lowercase chars is written to this
 */
void setCaseNums(char *str, int *uppercase, int *lowercase) {
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

/**
 * Change the case of a char list
 *
 * @param [in,out] str The char list to modify
 * @param [in] mode 1 for convert to uppercase and 0 (or anything else) for lowercase
 * @param [out] changed The number of characters that were changed is written to this
 * @param [out] same The number of characters that were not changed is written to this
 */
void changeCase(char *str, int mode, int *changed, int *same) {
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

/**
 * Main testing function
 *
 * @return
 */
int main() {
    printf("*** Part 1 ***\n\n");

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
