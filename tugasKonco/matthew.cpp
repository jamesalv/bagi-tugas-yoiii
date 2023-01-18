#include <stdio.h>
int main (){
	
char line [101];

fgets(line, 101, stdin);

printf("%s", line);
	
return 0;
}