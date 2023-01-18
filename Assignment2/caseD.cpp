#include <stdio.h>

int main(){
	
	int x1, x2, x3, x4, a, b, c, d, e, f, g, h;
	double rx1x2x3x4, rabcd, refgh;
	
	scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	scanf("%d %d %d %d", &e, &f, &g, &h);
	
	rx1x2x3x4 = (x1 / 1 * 2) + (x2 / 2 * 4) + (x3 / 3 * 6) + (x4 / 4 * 4);
	rabcd = (a / 1 * 2) + (b / 2 * 4) + (c / 3 * 6) + (d / 4 * 4);
	refgh = (e / 1 * 2) + (f / 2 * 4) + (g / 3 * 6) + (h / 4 * 4);
	
	printf("%.2lf\n", rx1x2x3x4);
	printf("%.2lf\n", rabcd);
	printf("%.2lf\n", refgh);
	
	return 0;
}
