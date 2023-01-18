#include <stdio.h>
#include <string.h>

int main()
{

    int tc, m, len;
    char s[101], a, b;

    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++)
    {
        scanf("%s", s);
        len = strlen(s);
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {

            scanf("%c %c", &a, &b);
            for (int k = 0; k < len; k++)
            {
                if (s[k] == a)
                {
                    s[k] = b;
                }
            }
        }
        printf("Case #%d: %s\n", i, s);
    }

    return 0;
}