#include<stdio.h>

int k, l, m, total, sum, n = 4;
int a[5] = {6, 15, 9, 3};

int main()
{
int t;
	char s[101], a, b;
	
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++){
		getchar();
		scanf("%[^\n]s", &s);
		scanf("%s", &a);
		for(int j = 0; j < strlen(s); j++){
			if(s[j] == a &&(s[j] >= 97 && s[j] <= 122)){//membuat kapital
				s[j] = s[j] - 32;//minus = membuat kapital
			}else if ( s[j] == a &&(s[j] >= 65 && s[j] <= 90)){//membuat kecil
				s[j] = s[j] + 32;//plus = membuat kecil
			}
		}
		printf("%s", s);
	}
    return 0;
}