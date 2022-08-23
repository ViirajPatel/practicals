
#include<stdio.h>
#include <time.h>
#define MAX 8


int  main()
{
    int matA[MAX][MAX];
    int matB[MAX][MAX];

    int r1 = MAX, c1 = MAX, r2 = MAX, c2 = MAX, i, j, k;

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            matA[i][j] = 1;

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            matB[i][j] = 2;
    int r[MAX][MAX],ans,ans2;
 
    for (int i = 0; i < r1;i++)
    {
        for(int j=0;j<c1;j++)
        printf("%d\t", matA[i][j]);
        printf("\n");
    }
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j <c2; j++)
            printf("%d\t", matB[i][j]);
        printf("\n");
    }
    printf("%d \n", matA[0][0]);
    clock_t t;
    t = clock();
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            r[i][j] = 0;

            for (int k = 0; k < r2; k++)
            {
                r[i][j] += matA[i][k] * matB[k][j];
            }

            printf("%d\t", r[i][j]);
        }

        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("it took %f seconds to execute \n", time_taken);
    return 0;
}