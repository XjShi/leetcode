/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
**/

#include <stdio.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    int count = 0;
    int wordLength = 0;
    for (; *s != '\0'; s++) {
        if (!isalpha(*s)) {
            if (count > 0) {
                wordLength = count;
            }
            count = 0;
        } else {
            count++;
        }
    }
    wordLength = count > 0 ? count : wordLength;
    printf("%d\n", wordLength);
    return wordLength;
}

int main() {
	int length = lengthOfLastWord("abc 789joi");
	printf("%d\n", length);
	return 0;
}