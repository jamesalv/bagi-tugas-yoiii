#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MenuAwal()
{
	printf ("Welcome to BEE BANK!\nBEE BANK is a digital bank where you can do your transactions safely.");
	printf ("\n-----------------------------------------------------------------------\n\n");
	printf ("Please choose what option would you do today : \n");
	printf ("1. Deposit\n");
	printf ("2. Planned Saving\n");
	printf ("3. Done/ cancel transaction\n\n");
	printf ("Enter your option using number only (1/2/3) : ");
}

struct tabungan
{
	char savingName[101];
	long long saving2, month2, date, total[1001];
	double interest2;
}
savingBgt[1001], temp;

float plannedSaving(int x)
{
	if (savingBgt[x].saving2 < 1000000)
	{
		if (savingBgt[x].month2 >= 12 && savingBgt[x].month2 < 36)
		{
			return 0.01;
		}
		else if (savingBgt[x].month2 >= 36 && savingBgt[x].month2 < 60)
		{
			return 0.012;
		}
		else if (savingBgt[x].month2 >= 60 && savingBgt[x].month2 <= 120)
		{
			return 0.015;
		}
	}
	else if (savingBgt[x].saving2 >= 1000000)
	{
		if (savingBgt[x].month2 >= 12 && savingBgt[x].month2 < 36)
		{
			return 0.012;
		}
		else if (savingBgt[x].month2 >= 36 && savingBgt[x].month2 < 60)
		{
			return 0.015;
		}
		else if (savingBgt[x].month2 >= 60 && savingBgt[x].month2 <= 120)
		{
			return 0.017;
		}
	}
}

int main ()
{
	int inputMenu;
	
	do
	{
		// system("cls"); //untuk menampulkan halaman kosong baru tanpa ada tampulan main menu
		MenuAwal(); //memanggil function menu awal
		scanf("%d", &inputMenu);
		
		while (inputMenu < 1 && inputMenu > 3) //validasi jika user memasukkan angka selain 1 sampai 3
		{
			printf("\nSorry, your input must be a number between 1 2 or 3\nPlease input the correct number\n");
			scanf("%d", &inputMenu);
		}
		
		if (inputMenu == 1)
		{
			FILE *deposito = fopen ("DEPOSIT_REPORT.txt", "w");
			fprintf (deposito, "BEE BANK Deposit Report\n");
			
			long long month, totalBunga, x;
			double interest, saving;
			char yaTidak;
			x = 1;

			do //looping ketika user ingin melakukan deposito lagi dan memilih opsi y di akhir transaksi
			{
				system  ("cls"); //untuk menampulkan halaman kosong baru tanpa ada tampulan main menu
				printf ("Welcome to BEE BANK!\nBEE BANK is a digital bank where you can do your transactions safely.");
				printf ("\n-----------------------------------------------------------------------\n\n");
				printf ("DEPOSIT MENU\n\n");
				
				do //validasi ketika user menginput 0 atau negatif
				{
					printf ("Enter the desired savings :  \n");
					scanf ("%lf", &saving);
				}
				while (saving<1);
			
				do //validasi ketika user menginput diluar bulan yang ada
				{
					printf ("Enter the desired month to do deposit :  \n");
					scanf ("%lld", &month);
			
				}
				while (month<1);
			
				do //validasi ketika user menginput 0 atau negatif
				{
					printf ("Enter the desired interest per month (%) :  \n");
					scanf ("%lf", &interest);
				}
				while (interest<1);
				system ("cls");

				printf ("DEPOSIT REPORT\n");
				printf("-------------------\n\n");
				fprintf (deposito, "\nDeposit Report %d\n", x++); //untuk menulis di file DEPOSIT_REPORT
				
				for (int i=1; i<=month; i++) //menghitung total depositnya
				{
					totalBunga = saving * interest * 80 / 12 / 100 / 100;
					saving += totalBunga; //untuk menambahkan total bunga dari deposit ke saving
					
					printf("Deposit on the month %d: Rp.%-14.2lf\n", i, saving);
					
					fprintf (deposito, "Deposit on the month %d: Rp.%-14.2lf\n", i, saving); //untuk menulis di file DEPOSIT_REPORT
				}
				
				printf("\nYou can see the Deposit Report on the DEPOSIT_REPORT.txt\n\n");
    			printf("Do you want to do another deposit? (y/n): ");
    			
				scanf("%s",&yaTidak);
				printf ("\n");
    			system("cls"); 
			}	
			while (yaTidak == 'y');
			fclose(deposito);
		}
		
		
		else if (inputMenu == 2)
		{
			FILE *tabunganBerencana = fopen ("PLANNED_SAVING", "w");
			fprintf (tabunganBerencana, "BEE BANK Planned Saving\n");
			fprintf (tabunganBerencana, "---------------------------\n\n");
		
			
			int x=0, tabunganSementara, i;
			char yaTidak;
			
			//jangan lupa declare ya
	
			do
			{
				system ("cls");
				printf ("Welcome to BEE BANK!\nBEE BANK is a digital bank where you can do your transactions safely.");
				printf ("\n-----------------------------------------------------------------------\n\n");
				printf ("PLANNED SAVING MENU\n");
				printf ("input your name : \n"); getchar();
				scanf ("%[^\n]s", &savingBgt[x].savingName); 
				
		
				do //validasi ketika user menginput 0 atau negatif
				{
					printf ("Enter the desired savings per month :  \n");
					scanf ("%lld", &savingBgt[x].saving2); 
				}
				while (savingBgt[x].saving2<1);
			
				do //validasi ketika user menginput diluar bulan yang ada
				{
					printf ("Enter the desired month to do saving (min 12 months, max 120 months) :  \n");
					scanf ("%lld", &savingBgt[x].month2);
				}
				while (savingBgt[x].month2<12 || savingBgt[x].month2>120);
			
				do //validasi ketika user menginput 0 atau negatif
				{
					printf ("Enter the autodebet date (1 - 31):  \n");
					scanf ("%lld", &savingBgt[x].date);
				}
				while (savingBgt[x].date<1 || savingBgt[x].date>31);
				
				savingBgt[x].saving2 = savingBgt[x].saving2 + (savingBgt[x].saving2 * plannedSaving(x));
				tabunganSementara = savingBgt[x].saving2;
				
				system ("cls");
				printf ("BEE BANK\n");
				printf ("%s PLANNED SAVING REPORT\n", savingBgt[x].savingName);
				printf ("Autodebet date %d\n\n", savingBgt[x].date);
				
				for (int i=1;i<=savingBgt[x].month2;i++)
				{
					printf ("Saving in month %d : %lld\n", i, savingBgt[x].saving2);
					savingBgt[x].total[i-1] = savingBgt[x].saving2;
				//	fprintf (tabunganBerencana,"Saving in month %d : %lld\n", i, savingBgt[x].saving2); //write di file planned_saving
					savingBgt[x].saving2 += tabunganSementara;
				}
				printf("\nYou can see the Planned Saving Report on the PLANNED_SAVING.txt\n\n");
    			printf("Do you want to do another planned saving? (y/n): ");
    			
				scanf("%s",&yaTidak);
				printf ("\n");
    			x++;
			}
			while (yaTidak == 'y');
			
			for (int i=0;i<x;i++)// untuk sorting tanggal
			{
				for (int j=x-1;j>i;j--)
				{
					if (savingBgt[j].date < savingBgt[j-1].date)
					{
						temp = savingBgt[j];
						savingBgt[j] = savingBgt[j-1];
						savingBgt[j-1] = temp;
					}
				}
			}
			
			for (int p=0; p<x; p++)
			{
				fprintf(tabunganBerencana, "\n%s\n", savingBgt[x].savingName);//print nama tabungan di file
				fprintf(tabunganBerencana, "Tanggal autodebit: %lld\n", savingBgt[p].date);
				fprintf(tabunganBerencana, "------------------------------\n\n");
				
				for (int q=1; q<=savingBgt[p].date; q++)
				{
					fprintf(tabunganBerencana, "Tabungan pada bulan ke-%d: %lld\n", q, savingBgt[p].total[q-1]);	
				}
				fprintf(tabunganBerencana, "\n");
			}
			fclose(tabunganBerencana);
		}	
	}
	while (inputMenu != 3);
	return 0;
}
