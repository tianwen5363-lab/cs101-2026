/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SETS 5
#define PICK_COUNT 7
#define MIN_NUM 1
#define MAX_NUM 69

// 產生一組 7 個不重複且介於 1~69 的樂透號碼
void generate_lotto_set(int nums[PICK_COUNT]) {
    int used[MAX_NUM + 1] = {0};
    int count = 0;

    while (count < PICK_COUNT) {
        int r = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
        if (!used[r]) {
            used[r] = 1;
            nums[count++] = r;
        }
    }
}

int main(void) {
    int n;

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SETS) {
        printf("請輸入 1 到 %d 之間的整數！\n", MAX_SETS);
        return 1;
    }

    srand((unsigned int)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        perror("無法開啟 lotto.txt");
        return 1;
    }

    time_t now = time(NULL);
    char time_str[64];
    strcpy(time_str, ctime(&now));
    size_t len = strlen(time_str);
    if (len > 0 && time_str[len - 1] == '\n') {
        time_str[len - 1] = '\0';
    }

    fprintf(fp, "lotto649\n");
    fprintf(fp, "%s =\n", time_str);

    for (int i = 0; i < MAX_SETS; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        if (i < n) {
            int nums[PICK_COUNT];
            generate_lotto_set(nums);
            for (int j = 0; j < PICK_COUNT; j++) {
                fprintf(fp, "%02d", nums[j]);
                if (j < PICK_COUNT - 1) {
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "--\n");
        }
    }

    fprintf(fp, "csie@CGU\n");
    fclose(fp);

    printf("已為您購買的%d組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}