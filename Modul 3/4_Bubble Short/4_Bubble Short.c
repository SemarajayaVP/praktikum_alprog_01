#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validasiInt(int *var);
void tryagain();
void sort();

clock_t waktu;
double durasi[2];
int x, y, n, temp;

int main()
    {
    int input,n;

    mainmenu:
    fflush(stdin);
    system("cls");
    printf("\n\t\t\t\t------------PRAKTIKUM ALPROG MODUL 3------------");
    printf("\n\t\t\t\t\t================================");
    printf("\n\t\t\t\t\t     Program Bubblesort"     );
    printf("\n\t\t\t\t\t================================");
    printf("\n\t\t\tPilih operasi yang diinginkan :   \n");
    printf("\t\t\t[1] Bubblesort 1000                         \n");
    printf("\t\t\t[2] Bubblesort 16000                        \n");
    printf("\t\t\t[3] Bubblesort 64000                        \n");
    printf("\t\t\t[0] Keluar                                  \n");
    printf("\t\t\tMasukkan pilihan anda : ");
    if(validasiInt(&input))
        {
        if(input >= 0 && input <= 3)
        {
            system("cls");
            switch(input)
            {
                case 1:
                    sort(1000);//seribu();
                    break;
                case 2:
                    sort(16000);//enambelas();
                    break;
                case 3:
                    sort(64000);//enamempat();
                    break;
                case 0:
                    exit(0);
            }
            printf("\n              Tekan tombol apa saja untuk melanjutkan...\n");
            getch();
            tryagain();
        }
        else
        {
            printf("\n              Input salah! Silahkan coba lagi.");
            getch();
            main();
        }
    }
    else
    {
        printf("\n              Input salah! Silahkan coba lagi.");
        getch();
        main();
    }
    return 0;
}

void sort(int n){
    int *a = malloc(n*sizeof(int));
    int *b = malloc(n*sizeof(int));


    for(x=0; x<n; x++){
		a[x] = rand();
		b[x] = rand();
	}

    printf("  +-------------------------------------------------------------------------------------------------------------+\n");
    printf("\tSebelum Sorting\n\n");
    for(x=0; x<n; x++){
        printf("\t");
        for(y=0; y<=10; y++){
            printf("%d ", a[x]);
        }
        printf("\n");
	}

	waktu = clock();
	for(x=0; x<n; x++)
    {
		for(y=0; y<n-1-x; y++)
		{
			if(a[y] > a[y+1])
			{
				temp = a[y];
				a[y] = a[y+1];
				a[y+1] = temp;
			}
		}
	}
    waktu = clock() - waktu;
    durasi[0] = (double)(waktu) / CLOCKS_PER_SEC;

    waktu = clock();
    for(x=0; x<n; x++)
    {
		for(y=0; y<n-1-x; y++)
		{
			if(a[y] > a[y+1])
			{
				temp     = *(b+y);
				*(b+y)   = *(b+y+1);
				*(b+y+1) = temp;
			}
		}
	}
	waktu = clock() - waktu;
	durasi[1] = (double)(waktu) / CLOCKS_PER_SEC;

    printf("\n\n\n  +-------------------------------------------------------------------------------------------------------------+\n");
    printf("\tSesudah Sorting\n\n");
	for(x=0; x<n; x++)
    {
        printf("\t");
        for(y=0; y<=10; y++)
        {
            printf("%d ", a[x]);
        }
        printf("\n");
	}

	printf("\n\n");
	printf("  +-----------------------------------+\n");
	printf("          Waktu Yang Dibutuhkan        \n");
	printf("  +-----------------------------------+\n");
	printf("   Cara biasa : %f detik               \n", durasi[0]);
	printf("   Pointer    : %f detik               \n", durasi[1]);
	printf("  +-----------------------------------+\n");
}

int validasiInt(int *var)
{
	char buff[1024];
	char cek;

	if (fgets(buff, sizeof(buff), stdin) !=NULL)
        {
		if (sscanf(buff, "%d %c", var, &cek) ==1)
		{
			return 1;
		}
	}
	return 0;
}
void tryagain()
{
    fflush(stdin);
    system("cls");
    printf("\n\t\t\tApakah anda ingin mengulang program?(y/n)     \n");
    printf("\t\t\tJawaban : ");
    switch(getch())
    {
        case 'y':
            main();
            break;
        case 'Y':
            main();
            break;
        case 'n':
            exit(0);
            break;
        case 'N':
            exit(0);
            break;
        default:
            printf("\n\t\t\tInputan salah! Tekan Y untuk mengulang, N untuk menutup program.");
            getch();
            tryagain();
    }
}
