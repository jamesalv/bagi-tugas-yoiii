#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int test, a, e, f, g, *hur, temp[127], temp3[127];
	char str[127], c[127], d[127], temp1;
	
	FILE *yey;
	yey = fopen ("testdata.in", "r");
	fscanf(yey, "%d", &test);
	
	for (int p=0; p<test; p++)
	{
		fscanf(yey, "%s", &str);
		fscanf(yey, "%d", &a);
		
		for (int q=0; q<a; q++)
		{
			fscanf(yey, "%s", &c[q]);
			fscanf(yey, "%s", &d[q]);
		}
		
		e = strlen(str);
		
		for (int q=0; q<a; q++)
		{
			for (int r=0; r<e; r++)
			{
				if (str[r] == c[q] && temp[r] != 1)
				{
					str[r] = d[q];
					temp[r] = 1;
				}
			}
		}
		
		printf("%s\n", str);
		hur = (int*)calloc(127, sizeof(int));
		
		for (int q=0; q<e; q++)
		{
			f = (int) str[q];
			hur[f]++;
		}
		
		for (int q=0; q<a; q++)
		{
			for(int r=0; r<a-1; r++)
			{
				if (d[r] > d[r+1])
				{
					temp1 = d[r];
					d[r] = d[r+1];
					d[r+1] = temp1;
				}
			}
		}
		
		for (int q=0; q<a; q++)
		{
			for (int r=0; r<127; r++)
			{
				g = (int) d[q];
				if (hur[r] != 0 && r == g && temp3[r] != 1)
				{
					printf("%c %d\n", r, hur[r]);
					temp3[r] = 1;
				}
			}
		}
		
		for (int q=0; q<127; q++)
		{
			temp3[q] = NULL;
			str[q] = NULL;
			c[q] = NULL;
			d[q] = NULL;
			temp[q] = NULL;
		}
	}
	fclose(yey);
	return 0;
}