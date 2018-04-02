#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("usage error: %s <textfile.txt>\n", argv[0]);
        return 1;
    }
    FILE *words = fopen(argv[1], "r");
    if (words == NULL) {
        printf("failed to open file %s\n", argv[1]);
        return 1;
    }
    int letters[26] = {0};
    int total = 0;

    printf("\nGETTING LETTER COUNTS\n\n");
    for (int c; ((c = fgetc(words)) != EOF);) {
        if (isalpha(c)) {
            total++;
            if (isupper(c)) c = tolower(c);
            letters[c - 'a']++;
        }
    }
    // print the frequencies out a-z
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", ('a'+i), letters[i]);
    }
    printf("total is: %d\n\n", total);

    printf("SORTING ON FREQUENCY\n\n");
    int saved = 0;
    for (int i = 0; i < 26; i++) {
        for (int i = 0, highest = 0; i < 26; i++) {
            if (letters[i] > highest) {
                saved = i;
                highest = letters[i];
            }
        }
        printf("%c: %4d %%%.2lf\n", ('a'+saved), letters[saved], ((double)letters[saved]/total)*100);
        letters[saved] = -1;
    }

    return 0;
}
