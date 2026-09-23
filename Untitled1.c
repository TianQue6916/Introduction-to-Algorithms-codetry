#include <stdio.h>
int main(void)
{
    /*********Begin*********/
    int n, i;
    scanf("%d", &n);
    getchar();
    int j;
    for (i = 0; i < n; i++)
    {
        char str[100];
        int count = 0;

        j = -1;
        do
        {
            j++;
            scanf("%c", &str[j]);
        } while (str[j] != '\n');
        str[j] = '\0';
        for (j = 0; str[j] != '\0'; j++)
        {
            if (str[j] >= '0' && str[j] <= '9')
            {
                count++;
            }
        }
        printf("%d\n", count);
    }

    /*********End**********/
    return 0;
}