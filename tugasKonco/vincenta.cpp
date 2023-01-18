#include <stdio.h>
#include <string.h>

struct data{
	int jumDat;
	char teman[101];
	char pohon[101];
}p[11];

int main(){
	int n, t, cek;
	
	FILE *rd = fopen("testdata.in", "r");
	fscanf(rd, "%d\n", &n);
	if(!rd)
		printf("File not found");
	else{
		for(int i=0;i<n;i++){
			fscanf(rd, "%[^\#]#%[^\n]\n", &p[i].teman, &p[i].pohon);
			//printf("%s %s\n", p[i].teman, p[i].pohon);
		}
	}
	
	fscanf(rd, "%d\n", &t);
	for(int i=0;i<t;i++){
		fscanf(rd, "%[^\n]\n", &p[i].jumDat);
	}	
	fclose(rd);
	
	for(int j=1;j<t;j++){
		cek = 0;
		printf("Case #%d: ", j);
		for(int k=0;k<n;k++){
			if(strcmp(p[j].jumDat, p[k].teman)==0){
				printf("%s", p[k].pohon); break;
			}
			else{
				cek++;
			}
			if(cek == n){
				printf("N/A"); break;
			}
		}
		printf("\n");	
	}
}