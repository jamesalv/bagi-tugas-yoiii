#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int monthlyInterest(int amount, double interestRate)
{
    return amount * interestRate / 12 * 80/100;
}

void deposit()
{
    int duration, amount, interest;
    double interestRate;
    FILE *depositReport = fopen("Deposit_Report.txt", "w");

    // Deposit amount must be at least 1,000,000 (like most of the bank in Indonesia)
    do
    {
        printf("Amount: ");
        scanf("%d", &amount);
        if(amount < 1000000)
            printf("Deposit amount must be at least 1,000,000\n");
    } while (amount < 1000000);
    fflush(stdin);

    interestRate = 0.05; // Assumption: Bee Bank's annual interest rate for deposit is 5%

    // Duration must be at least 1 month
    do
    {
        printf("Duration (in months): ");
        scanf("%d", &duration);
        if(duration < 1)
            printf("Duration must be at least 1 month\n");
    } while (duration < 1);

    printf("Deposit Report\n");
    fprintf(depositReport, "Deposit Report\n");
    printf("+-------+------------+----------------+\n| Month |  Interest  |  Total Amount  |\n+-------+------------+----------------+\n");
    fprintf(depositReport, "+-------+------------+----------------+\n| Month |  Interest  |  Total Amount  |\n+-------+------------+----------------+\n");

    for (int i = 0; i < duration; i++)
    {
        interest = monthlyInterest(amount, interestRate);
        amount += interest;
        printf("| %-5d | Rp %-7d | Rp %-11d |\n", i+1, interest, amount);
        fprintf(depositReport, "| %-5d | Rp %-7d | Rp %-11d |\n", i+1, interest, amount);
    }
    printf("+-------+------------+----------------+\n");
    fprintf(depositReport, "+-------+------------+----------------+\n");

    fclose(depositReport);
}

double savingInterestRate(int month, int monthlyAmount){
    if(month <= 12){
        return 0.01;
    }

    if(monthlyAmount<1000000){
        if(month < 36)
            return 0.01;
        else if (month < 60)
            return 0.012;
        else
            return 0.015;
    } else {
        if(month < 36)
            return 0.012;
        else if (month < 60)
            return 0.015;
        else
            return 0.017;
    }
}

void plannedSaving()
{
    int initialAmount, monthlyAmount, duration, totalSaving = 0, interest, autodebitDate;
    double interestRate;
    char savingTitle[100];
    FILE *plannedSavingReport = fopen("Planned_Saving_Report.txt", "w");

    // Title length must be 5 - 30 characters
    do
    {
        printf("Title: ");
        scanf("%[^\n]", savingTitle);
        if(strlen(savingTitle) < 5 || strlen(savingTitle) > 30)
            printf("Title length must be 5 - 30 characters\n");
    } while (strlen(savingTitle) < 5 || strlen(savingTitle) > 30);
    fflush(stdin);

    // Monthly Amount must be at least 100,000
    do
    {
        printf("Monthly Amount: ");
        scanf("%d", &monthlyAmount);
        if(monthlyAmount < 100000)
            printf("Monthly Amount must be at least 100,000\n");
    } while (monthlyAmount < 100000);
    fflush(stdin);

    // Duration must be at least 1 year / 12 months
    do
    {
        printf("Duration (in months): ");
        scanf("%d", &duration);
        if(duration < 12)
            printf("Duration must be at least 1 year\n");
    } while (duration < 12);
    fflush(stdin);

    // Autodebit Date must be between 1 - 28
    do
    {
        printf("Autodebit Date: ");
        scanf("%d", &autodebitDate);
        if(autodebitDate < 1 || autodebitDate > 28)
            printf("Autodebit Date must be between 1 - 28\n");
    } while (autodebitDate < 1 || autodebitDate > 28);

    printf("Report for '%s' Saving Plan\n", savingTitle);
    fprintf(plannedSavingReport, "Report for '%s' Saving Plan\n", savingTitle);
    printf("+-------+----------+----------------+\n| Month | Interest |  Total Amount  |\n+-------+----------+----------------+\n");
    fprintf(plannedSavingReport, "+-------+----------+----------------+\n| Month | Interest |  Total Amount  |\n+-------+----------+----------------+\n");

    for (int i = 0; i < duration; i++)
    { 
        interestRate = savingInterestRate(i+1, monthlyAmount);
        interest = monthlyAmount * interestRate;
        totalSaving += monthlyAmount + interest;
        printf("| %-5d | Rp %-5d | Rp %-11d |\n", i+1, interest, totalSaving);
        fprintf(plannedSavingReport, "| %-5d | Rp %-5d | Rp %-11d |\n", i+1, interest, totalSaving);
    }
    printf("+-------+----------+----------------+\n");
    fprintf(plannedSavingReport, "+-------+----------+----------------+\n");
    fclose(plannedSavingReport);
}

int main()
{

    int option;
    char repeat;
    printf("Welcome to Bee Bank\n");

    do
    {
        printf("Transaction Menu\n");
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
            printf("Please enter a Valid Option !\n\n");
            valid = !valid;
            break;
        }
        if (!valid)
            continue;
        fflush(stdin);
        do
        {
            printf("Do you want to do another transaction ?(Y/n): ");
            scanf("%c", &repeat);
            if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n')
            {
                printf("Please enter a valid option !\n");
            }
            fflush(stdin);
        } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');
    } while ('Y' == toupper(repeat));
    printf("THANK YOU FOR USING OUR SERVICE\n");
    return 0;
}