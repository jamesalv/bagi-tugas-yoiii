#include <stdio.h>

void ipt(int x[]){
    
    for(int i=0;i<10;i++){
        scanf("%d", &x[i]);
    }
}

int max(int z[]){
    
    int maks = z[0];
    
    for (int i =0; i<10;i++){
        if (maks < z[i]) maks = z[i];
    }
    return maks;
}

int minim(int y[]){
    
    int min = y[0];
        
    for (int i =0; i<10;i++){
        if (min > y[i]) min = y[i];
    }
    return min;
}

int print(int iya[]){
    
    ipt(iya);
    
    printf("Isi array :");
    for (int i=0;i<10;i++){
        printf("%d ", iya[i]);
    }
    printf("\n");
    
    printf("Max : %d\n", max(iya));
    
    printf("Min : %d\n", minim(iya));
    
    return 0;
}

int main(){
    
    int arr[10];
    print(arr);
    
    return 0;
}