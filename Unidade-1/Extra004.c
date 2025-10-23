/*#include <stdio.h>

int main() {
    //!showMemory(start=65520)
    float * estudantes[3];
    float e1[2];
    float e2[2];
    float e3[2];
    estudantes[0] = e1;
    estudantes[1] = e2;
    estudantes[2] = e3;
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%f %f", &estudantes[i][0], &estudantes[i][1]);
    }
    for (i = 0; i < 3; i++) {
        if (estudantes[i][0] > estudantes[i][1]) {
            printf("%.2f\n", estudantes[i][0]);
        }
        else {
            printf("%.2f\n", estudantes[i][1]);
        }
    }
}*/
#include <stdio.h>

int main() {
    //!showMemory(start=65520)
    float * estudantes[3];
    float e1[2];
    float e2[2];
    float e3[2];
    estudantes[0] = e1;
    estudantes[1] = e2;
    estudantes[2] = e3;
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%f %f", (estudantes[i] + 0), (estudantes[i] + 1));
    }
    for (i = 0; i < 3; i++) {
        if (estudantes[i][0] > estudantes[i][1]) {
            printf("%.2f\n", estudantes[i][0]);
        }
        else {
            printf("%.2f\n", estudantes[i][1]);
        }
    }
}