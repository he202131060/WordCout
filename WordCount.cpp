#include <stdio.h>
#include <ctype.h>
#define MAX_WORD_LEN 100
int main(int argc, char *argv[]) {
    FILE *fp;
    char c;
    int char_count = 0, word_count = 0;
    char word[MAX_WORD_LEN + 1];
    int word_len = 0;
    fp = fopen(argv[2], "r");
    if (fp == NULL) 
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    while ((c = fgetc(fp)) != EOF) {
        char_count++;
        if (isspace(c) || c == ',' || c == '.') {
            if (word_len > 0) {
                word[word_len] = '\0';
                word_count++;
                word_len = 0;
            }
        } else {
            if (word_len < MAX_WORD_LEN) {
                word[word_len] = c;
                word_len++;
            }
        }
    }
    if (argv[1][1] == 'w'){
    	printf("µ¥´ÊÊý=%d\n", word_count);
	}else if (argv[1][1] == 'c'){
		printf("×Ö·ûÊý=%d", char_count);
	}
    fclose(fp);
    return 0;
}
