#include <stdio.h>
#include <string.h>

struct data{
    char name[101];
    int num;
}file[101],swap;

int main()
{
    int t;
    FILE *ptr = fopen("sort.txt","r");

    fscanf(ptr,"%d\n",&t);

    for(int k=0;k<t;k++)
    {
        fscanf(ptr,"%s %d\n",file[k].name,&file[k].num);getchar();
    }

    //sorting
    for(int k=0;k<t;k++)
    {
        for(int y=t-1;y>k;y--)
        {
            if(file[y].num < file[y-1].num)
            {
                swap = file[y];
                file[y] = file[y-1];
                file[y-1] = swap;
            }
        }
    }
    //sorting
    for(int k=0;k<t;k++)
    {
        for(int y=t-1;y>k;y--)
        {
            if(strcmp(file[y].name,file[y-1].name)==0)
            {
                swap = file[y];
                file[y] = file[y-1];
                file[y-1] = swap;
            }
        }
    }

    for(int k=0;k<t;k++)
    {
        printf("%s %d\n",file[k].name,file[k].num);
    }

    fclose(ptr);
    return 0;
}