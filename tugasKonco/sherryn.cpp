#include<stdio.h>
#include<string.h>

int main()
{
        char str[1001];
        int t, i, j;
        
        scanf("%d", &t);
        for(j = 1 ; j <= t ; j++) 
        {
            getchar();
        	scanf("%[^\n]s", &str);
			
        	for (i = 0 ; i <= strlen(str) ; i++) 
        	{
            	if (str[i] >= 'A' && str[i] <= 'Z') // convert ke lowercase
            	{
                	str[i] = str[i] + ('a' - 'A');
            	}    

            	else if (str[i] >= 'a' && str[i] <= 'z') // convert ke uppercase
            	{
                	str[i] = str[i] - ('a' - 'A');
            	}
        	}

            
        printf("%s\n", str);
		}

    return 0;
}