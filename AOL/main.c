#include <stdio.h>

double deposit(double saving, double interestRate, int duration){
    if(duration == 0)
        return saving;
    else{
        double interest = saving * ((interestRate/100)/12) * 80/100;
        saving += interest;
        return deposit(saving, interestRate, duration-1);
    }
}


int main()
{
    printf("Enter your saving: ");
    double saving;
    scanf("%lf", &saving);

    printf("Enter your interest rate: ");
    double interestRate;
    scanf("%lf", &interestRate);

    printf("Enter your duration: ");
    int duration;
    scanf("%d", &duration);

    double total = deposit(saving, interestRate, duration);
    printf("Total:Rp %.0lf,00", total);

    return 0;
}