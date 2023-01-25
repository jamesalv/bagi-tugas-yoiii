#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Date
struct Date
{
    int day;
    int month;
    int year;
};

// All saving list
struct saving
{
    char title[40];
    int savingAmount, type;
    struct Date date;
} savingList[10000];
int x = 0;

// Title List
char depoTitleList[100][40], plannedSavingTitleList[100][40];
int y = 0, z = 0;

// Calculates deposit monthly interest gain
int monthlyInterest(int amount, double interestRate)
{
    return amount * interestRate / 12 * 80 / 100;
}

// Deposit Process
void deposit()
{
    char depoTitle[32], filename[60];
    int duration, amount, interest;
    double interestRate;

    // Deposit title length must be 5 - 30 characters
    do
    {
        printf("Title: ");
        scanf("%[^\n]", depoTitle);
        if (strlen(depoTitle) < 5 || strlen(depoTitle) > 30)
            printf("Title length must be 5 - 30 characters\n");
    } while (strlen(depoTitle) < 5 || strlen(depoTitle) > 30);
    fflush(stdin);
    strcpy(depoTitleList[y], depoTitle);
    y++;

    sprintf(filename, "Deposit_Report_%s.txt", depoTitle);
    FILE *depositReport = fopen(filename, "w");
    // Deposit amount must be at least 1,000,000 (like most of the bank in Indonesia)
    do
    {
        printf("Amount: ");
        scanf("%d", &amount);
        if (amount < 1000000)
            printf("Deposit amount must be at least 1,000,000\n");
    } while (amount < 1000000);
    fflush(stdin);

    interestRate = 0.05; // Assumption: Bee Bank's annual interest rate for deposit is 5%

    // Duration must be at least 1 month
    do
    {
        printf("Duration (in months): ");
        scanf("%d", &duration);
        if (duration < 1)
            printf("Duration must be at least 1 month\n");
    } while (duration < 1);

    struct Date D;
    // Date of deposit + validation
    do
    {
        printf("Date of deposit (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &D.day, &D.month, &D.year);
        if (D.day < 1 || D.day > 28 || D.month < 1 || D.month > 12)
        { // 28 is picked for convenience (because February only has 28 days)
            printf("Invalid date\n");
            continue;
        }
        break;
    } while (true);
    fflush(stdin);
    savingList[x].date = D;
    savingList[x].type = 1;
    savingList[x].savingAmount = amount;
    strcpy(savingList[x].title, depoTitle);

    interest = 0;
    printf("Report for '%s' Deposit\n", depoTitle);
    fprintf(depositReport, "Report for '%s' Deposit\n", depoTitle);
    printf("+------------+-----------+----------------+\n|    Date    |  Interest |  Total Amount  |\n+------------+-----------+----------------+\n");
    printf("| %-2d-%-2d-%-4d | Rp %-6d | Rp %-11d |\n", savingList[x].date.day, savingList[x].date.month, savingList[x].date.year, interest, amount);
    fprintf(depositReport, "+------------+-----------+----------------+\n|    Date    |  Interest |  Total Amount  |\n+------------+-----------+----------------+\n");
    fprintf(depositReport, "| %-2d-%-2d-%-4d | Rp %-6d | Rp %-11d |\n", savingList[x].date.day, savingList[x].date.month, savingList[x].date.year, interest, amount);
    x++;

    for (int i = 0; i < duration; i++)
    {
        interest = monthlyInterest(amount, interestRate);
        amount += interest;
        D.month++;
        if (D.month > 12)
        {
            D.month = 1;
            D.year += 1;
        }
        savingList[x].date = D;
        savingList[x].type = 1;
        savingList[x].savingAmount = amount;
        strcpy(savingList[x].title, depoTitle);
        printf("| %-2d-%-2d-%-4d | Rp %-6d | Rp %-11d |\n", savingList[x].date.day, savingList[x].date.month, savingList[x].date.year, interest, amount);
        fprintf(depositReport, "| %-2d-%-2d-%-4d | Rp %-6d | Rp %-11d |\n", savingList[x].date.day, savingList[x].date.month, savingList[x].date.year, interest, amount);
        x++;
    }
    printf("+------------+-----------+----------------+\n");
    fprintf(depositReport, "+------------+-----------+----------------+\n");

    fclose(depositReport);
}

// Determine planned saving's interest rate for i-th month
double savingInterestRate(int month, int monthlyAmount)
{
    if (month <= 12)
    {
        return 0.01;
    }

    if (monthlyAmount < 1000000)
    {
        if (month < 36)
            return 0.01;
        else if (month < 60)
            return 0.012;
        else
            return 0.015;
    }
    else
    {
        if (month < 36)
            return 0.012;
        else if (month < 60)
            return 0.015;
        else
            return 0.017;
    }
}

// Planned Saving Process
void plannedSaving()
{
    int initialAmount, monthlyAmount, duration, totalSaving = 0, interest;
    double interestRate;
    char savingTitle[100], filename[100];

    // Deposit title length must be 5 - 30 characters
    do
    {
        printf("Title: ");
        scanf("%[^\n]", savingTitle);
        if (strlen(savingTitle) < 5 || strlen(savingTitle) > 30)
            printf("Title length must be 5 - 30 characters\n");
    } while (strlen(savingTitle) < 5 || strlen(savingTitle) > 30);
    fflush(stdin);
    strcpy(plannedSavingTitleList[z], savingTitle);
    z++;


    sprintf(filename, "Planned_Saving_Report_%s.txt", savingTitle);
    FILE *plannedSavingReport = fopen(filename, "w");

    // Monthly Amount must be at least 100,000
    do
    {
        printf("Monthly Amount: ");
        scanf("%d", &monthlyAmount);
        if (monthlyAmount < 100000)
            printf("Monthly Amount must be at least 100,000\n");
    } while (monthlyAmount < 100000);
    fflush(stdin);

    // Duration must be at least 1 year / 12 months
    do
    {
        printf("Duration (in months): ");
        scanf("%d", &duration);
        if (duration < 12)
            printf("Duration must be at least 1 year\n");
    } while (duration < 12);
    fflush(stdin);

    struct Date D;
    // Date of SAVING + validation
    do
    {
        printf("Date of saving (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &D.day, &D.month, &D.year);
        if (D.day < 1 || D.day > 28 || D.month < 1 || D.month > 12)
        { // 28 is picked for convenience (because February only has 28 days)
            printf("Invalid date\n");
            continue;
        }
        break;
    } while (true);
    fflush(stdin);

    printf("Report for '%s' Saving Plan\n", savingTitle);
    fprintf(plannedSavingReport, "Report for '%s' Saving Plan\n", savingTitle);
    printf("+------------+-----------+----------------+\n|    Date    |  Interest |  Total Amount  |\n+------------+-----------+----------------+\n");
    fprintf(plannedSavingReport, "+------------+-----------+----------------+\n|    Date    |  Interest |  Total Amount  |\n+------------+-----------+----------------+\n");

    for (int i = 0; i < duration; i++)
    {
        interestRate = savingInterestRate(i + 1, monthlyAmount);
        interest = monthlyAmount * interestRate;
        totalSaving += monthlyAmount + interest;
        if (D.month > 12)
        {
            D.month = 1;
            D.year += 1;
        }
        savingList[x].date = D;
        savingList[x].type = 2;
        savingList[x].savingAmount = totalSaving;
        strcpy(savingList[x].title, savingTitle);

        printf("| %-2d-%-2d-%-4d | Rp %-6d | Rp %-11d |\n", savingList[x].date.day, savingList[x].date.month, savingList[x].date.year, interest, totalSaving);
        fprintf(plannedSavingReport, "| %-2d-%-2d-%-4d | Rp %-6d | Rp %-11d |\n", savingList[x].date.day, savingList[x].date.month, savingList[x].date.year, interest, totalSaving);
        D.month++;
        x++;
    }
    printf("+------------+-----------+----------------+\n");
    fprintf(plannedSavingReport, "+------------+-----------+----------------+\n");
    fclose(plannedSavingReport);
}

// Sort Savings by Date
void sortSaving()
{
    struct saving temp;
    for (int i = 0; i < x; i++)
    {
        for (int j = i + 1; j < x; j++)
        {
            if (savingList[i].date.year > savingList[j].date.year)
            {
                temp = savingList[i];
                savingList[i] = savingList[j];
                savingList[j] = temp;
            }
            else if (savingList[i].date.year == savingList[j].date.year)
            {
                if (savingList[i].date.month > savingList[j].date.month)
                {
                    temp = savingList[i];
                    savingList[i] = savingList[j];
                    savingList[j] = temp;
                }
                else if (savingList[i].date.month == savingList[j].date.month)
                {
                    if (savingList[i].date.day > savingList[j].date.day)
                    {
                        temp = savingList[i];
                        savingList[i] = savingList[j];
                        savingList[j] = temp;
                    }
                }
            }
        }
    }
}

// Compare date for search process
bool compareDate(struct Date check, struct Date start, struct Date end)
{
    if (check.year > start.year && check.year < end.year)
        return true;
    if ((check.year == start.year && check.month > start.month) ||
        (check.year == end.year && check.month < end.month))
        return true;
    if ((check.year == start.year && check.month == start.month && check.day >= start.day) ||
        (check.year == end.year && check.month == end.month && check.day <= end.day))
        return true;

    return false;
}

// Search All Saving
void searchAll(struct Date D_Start, struct Date D_End)
{
    printf("+------------+----------------+----------------+-------------------------------------+\n|    Date    | Saving Amount  |  Saving Type   |             Saving Title            |\n+------------+----------------+----------------+-------------------------------------+\n");
    for (int i = 0; i < x; i++)
    {
        if (compareDate(savingList[i].date, D_Start, D_End))
        {
            char type[20];
            if (savingList[i].type == 1)
                strcpy(type, "Deposit");
            else
                strcpy(type, "Planned Saving");
            printf("| %-2d-%-2d-%-4d | Rp %-11d | %-14s | %-35s |\n", savingList[i].date.day, savingList[i].date.month, savingList[i].date.year, savingList[i].savingAmount, type, savingList[i].title);
        }
    }
    printf("+------------+----------------+----------------+-------------------------------------+\n");
}

// Search Deposit
void searchDeposit(struct Date D_Start, struct Date D_End)
{
    int option;
    char title[50];
    printf("1. All Deposit\n");
    for(int i = 0; i < y; i++)
    {
        printf("%d. %s\n", i + 2, depoTitleList[i]);
    }
    printf("Choose option: ");
    scanf("%d", &option);
    strcpy(title, depoTitleList[option - 2]);
    printf("+------------+----------------+--------------------------------+\n|    Date    | Saving Amount  |          Saving Title          |\n+------------+----------------+--------------------------------+\n");
    for (int i = 0; i < x; i++)
    {
        if (savingList[i].type == 1 && compareDate(savingList[i].date, D_Start, D_End))
        {
            if(option == 1)
            printf("| %-2d-%-2d-%-4d | Rp %-11d | %-30s |\n", savingList[i].date.day, savingList[i].date.month, savingList[i].date.year, savingList[i].savingAmount, savingList[i].title);
            else{
                if(strcmp(savingList[i].title, title) == 0)
                    printf("| %-2d-%-2d-%-4d | Rp %-11d | %-30s |\n", savingList[i].date.day, savingList[i].date.month, savingList[i].date.year, savingList[i].savingAmount, savingList[i].title);
            }
        }
    }
    printf("+------------+----------------+----------------+---------------+\n");
}

// Search Planned Saving
void searchPlannedSaving(struct Date D_Start, struct Date D_End)
{
    char title[50];
    int option;
    printf("1. All Planned Saving\n");
    for(int i = 0; i < z; i++)
    {
        printf("%d. %s\n", i + 2, plannedSavingTitleList[i]);
    }
    printf("Choose option: ");
    scanf("%d", &option);
    strcpy(title, plannedSavingTitleList[option - 2]);
    printf("+------------+----------------+--------------------------------+\n|    Date    | Saving Amount  |          Saving Title          |\n+------------+----------------+--------------------------------+\n");
    for (int i = 0; i < x; i++)
    {
        if (savingList[i].type == 2 && compareDate(savingList[i].date, D_Start, D_End))
        {
            if(option == 1)
                printf("| %-2d-%-2d-%-4d | Rp %-11d | %-30s |\n", savingList[i].date.day, savingList[i].date.month, savingList[i].date.year, savingList[i].savingAmount, savingList[i].title);
            else{
                if(strcmp(savingList[i].title, title) == 0)
                    printf("| %-2d-%-2d-%-4d | Rp %-11d | %-30s |\n", savingList[i].date.day, savingList[i].date.month, savingList[i].date.year, savingList[i].savingAmount, savingList[i].title);
            }
        }
    }
    printf("+------------+----------------+----------------+---------------+\n");
}

// Search Process
void searchsaving()
{
    struct Date D_Start, D_End;
    printf("Time Period\n");
    printf("From (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &D_Start.day, &D_Start.month, &D_Start.year);
    printf("To (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &D_End.day, &D_End.month, &D_End.year);
    fflush(stdin);

    printf("Type of saving:\n");
    printf("1. All\n");
    printf("2. Deposit\n");
    printf("3. Planned Saving\n");
    printf("Choose Option: ");
    int option;
    scanf("%d", &option);
    fflush(stdin);

    switch (option)
    {
    case 1:
        searchAll(D_Start, D_End);
        break;
    case 2:
        searchDeposit(D_Start, D_End);
        break;
    case 3:
        searchPlannedSaving(D_Start, D_End);
        break;
    default:
        printf("Invalid Option\n");
        break;
    }
}

// Main Menu
int main()
{

    FILE *customerData = fopen("Customer_Data.txt", "r");
    char userName[100], password[100];
    int option;
    char repeat;
    printf("Welcome to Bee Bank\n");

    do
    {
        printf("Saving Menu\n");
        printf("1. Deposit\n");
        printf("2. Planned Saving\n");
        printf("3. Search Saving\n");
        printf("Choose Option: ");
        scanf("%d", &option);
        fflush(stdin);
        bool valid = true;
        repeat = 'Y';
        switch (option)
        {
        case 1:
            system("cls");
            deposit();
            break;
        case 2:
            system("cls");
            plannedSaving();
            break;
        case 3:
            system("cls");
            searchsaving();
            break;
        default:
            printf("Please enter a Valid Option !\n\n");
            valid = !valid;
            break;
        }
        if (!valid)
            continue;
        fflush(stdin);
        sortSaving();
        do
        {
            printf("Do you want to do another operation ?(Y/n): ");
            scanf("%c", &repeat);
            if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n')
            {
                printf("Please enter a valid option !\n");
            }
            fflush(stdin);
            system("cls");
        } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');
    } while ('Y' == toupper(repeat));
    printf("THANK YOU FOR USING OUR SERVICE\n");
    return 0;
}