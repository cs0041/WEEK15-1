#include <stdio.h>
#include <stdlib.h>
void FindAllline(int &c,int *i)
{
    while (true)
    {
        c -= *i;
        if (c <= 0)
        {
            break;
        }
        *i = *i + 1;
    }
}
int main()
{
    int n, c, i = 1;
    scanf_s("%d", &n);
    c = n;
    FindAllline(c, &i);
    int p = 64, w;
    int ans[100];
    for (int k = 1; i >= k; k++)
    {
        w = 0;
        if (k % 2 != 0)
        {
            for (int j = 1; i >= j; j++)
            {
                printf(" ");
            }
            for (p = p + 1; p <= 90; p++)
            {
                ans[p] = p;
                printf("%c", ans[p]);
                w++;
                if (w == k)
                {
                    break;
                }
                if (p == 90)
                {
                    p = 64;
                }
            }
            printf("\n");
        }
        w = 0;
        int check = 0, e = 0;
        if (k % 2 == 0)
        {
            for (int j = 1; (i - k) >= j; j++)
            {
                printf(" ");
            }
            if (p + k > 90)
            {
                int g = (p + k) - 90;
                e = g;
                for (g = 64 + g; g >= 65; g--)
                {
                    ans[g] = g;
                    printf("%c", ans[g]);
                    w++;
                    if (w == e)
                    {
                        check++;
                        break;
                    }
                }
            }
            int rb = 0;
            if (p + k > 90)
            {
                rb = (p + k) - 90;
            }
            for (int v = (p + k) - rb; v > p; v--)
            {
                ans[v] = v;
                printf("%c", ans[v]);
                w++;
                if (w == k)
                {
                    if (check > 0)
                    {
                        p = 64 + e;
                        if (p == 90)
                        {
                            p = 64;
                        }
                        break;
                    }
                    p = (v + k) - 1;
                    if (p == 90)
                    {
                        p = 64;
                    }
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
