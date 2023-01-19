#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int monthlyInterest(int amount, double interestRate)
{
    return amount * (interestRate/100) / 12 * 80/100;
}

void deposit()
{
    int duration, amount, interest;
    double interestRate;
    printf("Amount: ");
    scanf("%d", &amount);
    fflush(stdin);
    printf("Interest Rate: ");
    scanf("%lf", &interestRate);
    fflush(stdin);
    printf("Duration: ");
    scanf("%d", &duration);

    for (int i = 0; i < duration; i++)
    {
        interest = monthlyInterest(amount, interestRate);
        amount += interest;
        printf("| %-5d | Rp %-10d | Rp %-10d |\n", i+1, interest, amount);
    }
}

void plannedSaving()
{
}

int main()
{

    int option;
    char repeat;
    printf("Welcome to Bee Bank\n");

    do
    {
        printf("Select Menu\n");
        printf("1. Deposit\n");
        printf("2. Planned Saving\n");
        printf("Choose Option: ");
        scanf("%d", &option);
        fflush(stdin);
        bool valid = true;
        repeat = 'Y';
        switch (option)
        {
        case 1:
            deposit();
            break;
        case 2:
            plannedSaving();
            break;
        default:
            printf("Please enter a Valid Option\n\n");
            valid = !valid;
            break;
        }
        if (!valid)
            continue;
        fflush(stdin);
        printf("\nDO YOU WANT TO DO ANOTHER TRANSACTION ?(Y/n): ");
        scanf("%c", &repeat);
    } while ('Y' == toupper(repeat));
    printf("THANK YOU FOR USING OUR SERVICE\n");
    return 0;
}