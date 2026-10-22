#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
   
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
   
    int ra[3];
    char rb[4];
    float rc[3];

    if ((fp = fopen("a.bin", "wb+")) == NULL) {
        printf("Can not open the file ...\n");
        exit(1);
    }

    if (fwrite(a, sizeof(a), 1, fp) != 1) {
        printf("Write file error (a)\n");
    }
    if (fwrite(b, sizeof(b), 1, fp) != 1) {
        printf("Write file error (b)\n");
    }
    if (fwrite(c, sizeof(c), 1, fp) != 1) {
        printf("Write file error (c)\n");
    }

    fseek(fp, 0, SEEK_SET);

    if (fread(ra, sizeof(ra), 1, fp) != 1) {
        printf("Read file error (ra)\n");
    }
    if (fread(rb, sizeof(rb), 1, fp) != 1) {
        printf("Read file error (rb)\n");
    }
    if (fread(rc, sizeof(rc), 1, fp) != 1) {
        printf("Read file error (rc)\n");
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%c ", rb[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%f ", rc[i]);
    }
    printf("\n");

    fclose(fp);

    return 0;
}
