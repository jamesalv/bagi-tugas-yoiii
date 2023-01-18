#include <stdio.h>
#include <string.h>
int main()
{
	int T, M, len, i, j, k;
	char S[10000], a, b;
	 
	scanf("%d", &T);
	fflush(stdin);
	for(i = 1; i <= T; i++)
	{
		// Input the string
		gets(S);
		len = strlen(S);

		// input M
		scanf("%d", &M);
		fflush(stdin);
		for(j = 0; j < M; j++)
		{
			// Input a and b
			scanf("%c %c", &a, &b);
			// fflush(stdin);
			// If a is found, change to b
			for(k = 0; k < len; k++)
			{
				if(S[k] == a)
					S[k] = b;
			}
		}
		
		// print the answer
		printf("Case #%d: %s\n", i, S);
	}
		
	return 0;
}
