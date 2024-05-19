#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void count_chars(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    fclose(file);
    printf("字符数：%d\n", count);
}

void count_words(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    int count = 0;
    char c;
    int in_word = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            if (in_word) {
                in_word = 0;
                count++;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        count++;
    }

    fclose(file);
    printf("单词数：%d\n", count);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("用法: %s [-c|-w] <文件名>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        count_chars(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
        count_words(argv[2]);
    } else {
        printf("无效参数 %s\n", argv[1]);
        return 1;
    }

    return 0;
}

