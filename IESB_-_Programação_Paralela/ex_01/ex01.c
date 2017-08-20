#include <stdio.h>
#include <time.h>

#define N 1024

int x[N][N];
int y[N][N];
int z[N][N];

void init() {
    int i, j, k = 1;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++) {
            x[i][j] = k++;
            y[i][j] = k++;
        }
    }
}

void mul1() {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int sum = 0;
            for (k = 0; k < N; k++)
                sum += x[i][k]*y[k][j];
            z[i][j] = sum;
        }
    }
}

void mul3() {
#define M N
#define K N
#define MBlock 8
#define NBlock 8
#define KBlock 8
    int i, j, l, r, s, t;
    for (i = 0; i < M; i += MBlock)
        for (j = 0; j < N; j+= NBlock)
            for (l = 0; l < K; l+= KBlock)
                for (r = i; r < i + MBlock; r++)
                    for (s = j; s < j + NBlock; s++) {
                        int sum = 0;
                        for (t = l; t < l + KBlock; t++)
                            sum += x[r][t] * y[t][s];
                        z[r][s] = sum;
                    }
}

void print(int z[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }
}

int main() {
    init();
    clock_t tic = clock();
    mul3();
    clock_t toc = clock();
    printf(" Time Elapsed for mul1: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    init();
    tic = clock();
    mul3();
    toc = clock();
    printf(" Time Elapsed for mul3: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}