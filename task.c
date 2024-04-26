#include <stdio.h>
int main()
{
    int y = 0;
    int i, j, k;
    int n = 5;
    int m = 3;
    int need[5][3];
    int States[5] = {0, 0, 0, 0, 0};
    int Sequence[5];
    int ind = 0;
    int available[3] = {3, 3, 2};
    int Process[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};
    int Max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}};

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = Max[i][j] - Process[i][j];
    }
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (States[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    Sequence[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        available[y] = available[y] + Process[i][y];
                    }
                    States[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (States[i] == 0)
        {
            flag = 0;
            printf("The system is not safe");
            break;
        }
    }
    if (flag == 1)
    {
        printf("The Safe System is: \n");
        for (i = 0; i < n; i++)
        {
            printf(" P%d ->", Sequence[i]);
        }
    }
    return (0);
}