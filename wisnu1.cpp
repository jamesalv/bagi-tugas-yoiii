#include <stdio.h>

struct info
{
    char city[51], type;
    float temp, compare;
} data[101], swap;

int main()
{
    FILE *ptr = fopen("temp.in", "r");
    int count = 0;

    while (fscanf(ptr, "%[^#]#%f#%c", data[count].city, &data[count].temp, &data[count].type) == 3)
    {
        count++;
    }

    for (int x = 0; x < count - 1; x++)
    {
        printf("%s %.2f %c\n", data[x].city, data[x].temp, data[x].type);
    }

    fclose(ptr);
    return 0;
}