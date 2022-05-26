#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

//menu pilihan aksi setelah program berjalan 
void pilihanAksi()
{
	printf("\n\n");
	printf("\n+=================================+");
	printf("\n|             Pilihan             |");
	printf("\n+=================================+");
	printf("\n|Apakah anda ingin mengulang?     |");
	printf("\n|---------------------------------|");
	printf("\n|1. Ya                            |");
	printf("\n|2. Tidak                         |");
	printf("\n+---------------------------------+");
	printf("\nMasukkan Pilihan Anda : ");
	
	int pilihan = validasi();
	if(pilihan == 1)
	{ 
		system("cls"); 
		main();
	}
	else if(pilihan == 2)
	{ 
		exit(0);
	} 
	else
	{
		printf("\nInput Anda Salah! Masukkan angka dari 1 - 3!"); 
		system("cls");
		pilihanAksi();
	}
}

int validasi ()
{
	int pilihan;
	if (scanf("%d", &pilihan) != 1) 
	{
		printf("\n\t\t\t\tHanya masukkan angka!"); 
		printf("\n\t\t\t\tMasukan Pilihan Ulang : "); 
		fflush(stdin);
		validasi(); 
	}
	return pilihan; 
}

//pembangkitan bilangan random
void bilanganRandom(int arr[], int n)
{ 
	int i;
	srand(0);
	for (i = 0; i < n; i++) 
	{ 
		arr[i] = rand();
	} 
}

//penduplikatan array
void duplikatArray(int asal[], int target[], int n)
{ 
	int i;
	for (i = 0; i < n; i++) 
	target[i] = asal[i];
}

//mencetak array
void printArray(int arr[], int n) 
{ 
	int i;
	for (i = 0; i < n; i++) 
	{
		printf("\nAngka ke-%d = %d", i + 1, arr[i]); 
	}
}

//titik acuan untuk quick sort
//pivot yang digunakan adalah value terakhir dari sebuah array,ditandai dengan variabel high
int pivot(int arr[], int low, int high)
{
	int p = arr[high];//element array yang lebih besar dari pivot taruh disebelah kanan pivot,yang lebih kecil ditaruh disebelah kiri pivot
	int temp;
	int i = (low - 1);
	int j;
	for (j = low; j <= high - 1; j++)
	{ 
	if (arr[j] <= p)
		{
			temp = arr[i]; 
			arr[i] = arr[j]; 
			arr[j] = temp;
			i++;
		} 
	}
	temp = arr[i + 1]; 
	arr[i + 1] = arr[high]; 
	arr[high] = temp;
	
	return (i + 1); 
}

//metode quick sort
void quickSort(int arr[], int low, int high)
{ 
	int p = pivot(arr, low, high);
	if (low < high)
	{
		quickSort(arr, low, p - 1); 
		quickSort(arr, p + 1, high);
	} 
}

//metode insertion sort
void insertionSort(int arr[], int n)
{ 
	int i, j, key;
	
	for (i = 1; i < n; i++)
	{ 
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{ 
			arr[j + 1] = arr[j];
			j--; 
		}
		arr[j + 1] = key;
	} 
}

//metode bubble sort
void bubbleSort(int arr[], int n)
{ 
	int i, j, temp;
	
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{ 
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j]; 
				arr[j] = arr[j + 1]; 
				arr[j + 1] = temp;
			} 
		}
	} 
}

//menu sorting
int sort()
{
	clock_t start, end;
	double waktu1, waktu2, waktu3; 
	int i, n;
	char pilihan2; 
	system("cls");
	printf("\t\t\t\t+------------------------------------------ +\n");
	printf("\t\t\t\t|             Pilihan Jumlah Data           |\n");
	printf("\t\t\t\t|------------------------------------------ |\n");
	printf("\t\t\t\t|             1. 1000  Data                 |\n");
	printf("\t\t\t\t|             2. 16000 Data                 |\n");
	printf("\t\t\t\t|             3. 64000 Data                 |\n"); 
	printf("\t\t\t\t|             4. Keluar                     |\n");
	printf("\t\t\t\t+------------------------------------------ +\n");
	printf("\n");
	printf("\n\t\t\t\tMasukkan pilihan Anda : "); 
	pilihan2 = validasi();
	if(pilihan2 < 1 || pilihan2 > 4)
	{ 
		system("cls");
		printf("\n\t\t\t\tMasukkan input dari angka 1 sampai 4\n\n");
		sort(); 
	}
	else
	{
		if(pilihan2 == 1)
		{
			n = 1000;
		}
		else if(pilihan2 == 2)
		{ 
			n = 16000;
		}
		else if(pilihan2 == 3)
		{ 
			n = 64000;
		}
		else if(pilihan2 == 4)
		{ 
			exit(0);
		} 
	}

	int arr[n];
	int arr2[n];
	int arr3[n];
	
	//print bilangan random 
	bilanganRandom(arr, n);
	printf("\n\n");
	printf("=================================");
	printf("Array %d random sebelum di sort :\n", n);
	printArray(arr, n); 
	duplikatArray(arr, arr2, n); 
	duplikatArray(arr, arr3, n);
	
	//insertion Sort 
	start = clock(); 
	insertionSort(arr, n); 
	end = clock();
	waktu1 = (double)(end - start) / CLOCKS_PER_SEC; 
	
	//bubble Sort
	start = clock(); 
	bubbleSort(arr2, n);
	end = clock();
	waktu2 = (double)(end - start) / CLOCKS_PER_SEC; 
	
	//quick Sort
	start = clock(); 
	quickSort(arr3, 0, n - 1); 
	end = clock();
	waktu3 = (double)(end - start) / CLOCKS_PER_SEC; 
	
	//print bilangan setelah disorting
	printf("\n\n");
	printf("==============================");
	printf("\n%d angka setelah disorting :\n", n); 
	sleep(2);
	printArray(arr, n); 
	
	//waktu yang diperlukan
	printf("\n\n");
	printf("\n+-------------------------------------------+");
	printf("\n|                 Hasil Waktu            	  |");
	printf("\n+-------------------------------------------+");
	
	printf("\nWaktu Insertion Sort = %f", waktu1);
	printf("\nWaktu Bubble Sort = %f", waktu2);
	printf("\nWaktu Quick Sort = %f\n", waktu3);

	//pembandingan
	if(waktu1 == waktu2 && waktu1 == waktu3)
	{
	printf("\n+-------------------------------------------+");
	printf("\n|            Kecepatannya Setara!  		  |");
	printf("\n+-------------------------------------------+");
	}
	else if(waktu1 == waktu2)
	{
	printf("\n+-------------------------------------------+");
	printf("\n|    Insertion dan Bubble Sort Setara!  	  |");
	printf("\n+-------------------------------------------+");
	}
	else if(waktu1 == waktu3)
	{
	printf("\n+-------------------------------------------+");
	printf("\n|     Insertion dan Quick Sort Setara!  	  |");
	printf("\n+-------------------------------------------+");
	}
	else if(waktu2 == waktu3)
	{
	printf("\n+-------------------------------------------+");
	printf("\n|       Bubble dan Quick Sort Setara!  	  |");
	printf("\n+-------------------------------------------+");
	}
	else if(waktu1 <= waktu2 && waktu1 <= waktu3)
	{
	printf("\n+-------------------------------------------+");
	printf("\n|           Insertion Sort Paling Cepat!    |");
	printf("\n+-------------------------------------------+");
	}
	else if(waktu2 <= waktu1 && waktu2 <= waktu3)
	{
	printf("\n+-------------------------------------------+");
	printf("\n|         Bubble Sort Paling Cepat!  		  |");
	printf("\n+-------------------------------------------+");
	}
	else if(waktu3 <= waktu1 && waktu3 <= waktu2)
	{
	printf("\n+-------------------------------------------+"); 
	printf("\n|          Quick Sort Paling Cepat!  		  |");
	printf("\n+-------------------------------------------+");
	}
	pilihanAksi();
}

	//metode sequential search
	double sequentialSearch(int arr[], int n, int angkaDicari) 
	{ 
		clock_t start, end;
		double waktu;
		int i, counter = 0; 
		start = clock();
		for (i = 0; i < n; i++)
		{
			if (arr[i] == angkaDicari)
			{ 
				counter++;
			}
			printf("Angka ke-%d = %d", i+1, arr[i]); 
			printf("\n");
		}
		end = clock();
		waktu = (double)(end - start) / CLOCKS_PER_SEC; 
		if (counter == 0)
		{
			printf("\n\n=================================================== =");
			printf("\nMencari dengan menggunakan metode Sequential Search");
			printf("\nAngka  %d  tidak  terdapat  pada  array", angkaDicari);
			printf("\n===================================================\n ");
		} 
		else
		{
			int indexAngkaDicari[counter]; 
			counter = 0;
			for (i = 0; i < n; i++)
			{
				if (arr[i] == angkaDicari)
				{ 
					indexAngkaDicari[counter] = i; 
					counter++;
				}
			}
			printf("\n===================================================") ;
			printf("\nMencari dengan menggunakan metode Sequential Search");
			printf("\nAngka terdapat pada indeks ke-"); 
			for (i = 0; i < counter; i++)
			{	
				if (i == 0 && i == counter - 1)
				{
					printf(" %d.", indexAngkaDicari[i]); }
				else
				{
					if (i == counter - 1)
					{
						printf(" dan %d.", indexAngkaDicari[i]); 
					}
					else
					{
						printf(" %d,", indexAngkaDicari[i]); 
					}
				}		 
			}
		printf("\n===================================================") ;
		}
		return waktu; 
	}
	double  binarySearch(int  arr[],  int  low,  int  high,  int angkaDicari) 
	{
		clock_t start, end; 
		double waktu;
		int i, counter = 0; 
		start = clock();
		while (low <= high)
		{
			int mid = low + (high - low) / 2; 
			if (arr[mid] == angkaDicari)
			{
				counter++;
				for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++)
				{
					counter++; 
				}
				for (i = mid - 1; i < high + 1 && arr[i] == angkaDicari; i++){
					counter++; 
				}
				break; 
			}
			else if (arr[mid] > angkaDicari)
			{ 
				high = mid - 1;
			} 
			else
			{
				low = mid + 1; 
			}
		}
		end = clock();
		waktu = (double)(end - start) / CLOCKS_PER_SEC; 
		if (counter == 0)
		{
			printf("\n\n==============================================="); 
			printf("\nMencari  dengan  menggunakan  metode  Binary Search");
			printf("\nAngka     %d tidak array",angkaDicari);
			printf("\n===============================================\n"); 
		}
		else
		{
			int indexAngkaDicari[counter]; 
			counter = 0;
			while (low <= high) 
			{
				int mid = low + (high - low) / 2; 
				if (arr[mid] == angkaDicari)
				{
					indexAngkaDicari[counter] = mid; 
					counter++;
					for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++)
					{
						indexAngkaDicari[counter] = i; 
						counter++;
					}
					for (i =  mid  - 1; i  >  0 && arr[i] == angkaDicari; i--)
					{
						indexAngkaDicari[counter] = i; 
						counter++;
					} 
					break;
				}
				else if (arr[mid] > angkaDicari)
				{ 
					high = mid - 1;
				} 
				else 
				{
					low = mid + 1; 
				}
			}
			printf("\n\n============================================="); 
			printf("\nMencari  dengan  menggunakan  metode  Binary Search");
			printf("\nAngka berada di array pada indeks ke-"); 
			insertionSort(indexAngkaDicari, counter);
			for (i = 0; i < counter; i++) 
			{
				if (i == 0 && i == counter - 1)
				{
					printf(" %d.", indexAngkaDicari[i]);
				} 
				else 
				{
					if (i == counter - 1)
					{
						printf(" dan %d.", indexAngkaDicari[i]); 
					}
					else 
					{
						printf("%d,", indexAngkaDicari[i]); 
					}
				}	
			}
			printf("\n===============================================\n");
		}
		return waktu; 
	}

int search()
{
	clock_t start, end; 
	double waktu1, waktu2;
	int i, n, menu, pilihan2, angkaDicari; 
	char karakterSearch;
	system("cls");
	printf("\t\t\t\t+------------------------------------------ +\n");
	printf("\t\t\t\t|             Pilihan Jumlah Data  			|\n");
	printf("\t\t\t\t|------------------------------------------ |\n");
	printf("\t\t\t\t|             1. 1000 Data				    |\n");
	printf("\t\t\t\t|             2. 16000 Data 				|\n");
	printf("\t\t\t\t|             3. 64000 Data 				|\n");
	printf("\t\t\t\t|             4.     Keluar  				|\n");
	printf("\t\t\t\t+------------------------------------------ +\n");
	printf("\n");
	printf("\n\t\t\t\tMasukkan pilihan Anda : "); 
	pilihan2 = validasi();
	if(pilihan2 < 1 || pilihan2 > 4)
	{ 
		system("cls");
		printf("\n\t\t\t\tMasukkan input dari angka 1 sampai 4\n\n");
		search(); 
	}
	else
	{
		if(pilihan2 == 1)
		{
		n = 1000; 
		}
		else if(pilihan2 == 2)
		{
		n = 16000;
		}
		else if(pilihan2 == 3)
		{ 
		n = 64000;
		}
		else if(pilihan2 == 4)
		{ 
			exit(0);
		} 
	}

	int arr[n]; 
	int arr2[n];
	bilanganRandom(arr, n);	
	
	printf("\n\n\n\t\t\t\tMasukkan Angka Yang Ingin Dicari: "); 
	inputAngka :
	angkaDicari = validasi(); 
	if (angkaDicari < 0) 
	{
		printf("Input Invalid! Angka tidak boleh dibawah '0'"); 
		goto inputAngka;
	}
	insertionSort(arr, n);
	waktu1 = sequentialSearch(arr, n, angkaDicari); 
	waktu2 = binarySearch(arr, 0, n - 1, angkaDicari);
	printf("\n+-------------------------------------------+");
	printf("\n|                 Hasil Waktu               |");
	printf("\n+-------------------------------------------+");
	printf("\n1. Sequential Search = %f", waktu1);
	printf("\n2. Binary Search = %f\n", waktu2);
	if(waktu1 < waktu2)
	{
		printf("\n+-------------------------------------------+");
		printf("\n|       Sequential Search Lebih Cepat!  	  |");
		printf("\n+-------------------------------------------+");
	}
	else if(waktu2 < waktu1)	
	{
		printf("\n+-------------------------------------------+");
		printf("\n|          Binary Search Lebih Cepat!  	  |");
		printf("\n+-------------------------------------------+");
	}
	else if( waktu1 == waktu2)
	{
		printf("\n+-------------------------------------------+");
		printf("\n|    Sequential dan Binary Search Setara!   |");
		printf("\n+-------------------------------------------+");
	}
	pilihanAksi();
}

int main()
{
	char pilihan, karakter; 
	int cek;
	
	system("cls");
	
	printf("\t\t\t\t|===============================================|\n"
           "\t\t\t\t|==========  PRAKTIKUM ALPROG MODUL 3 ==========|\n"
           "\t\t\t\t|==========         KELOMPOK 1        ==========|\n"
           "\t\t\t\t|           *************************           |\n"
           "\t\t\t\t|====   Program 3.1 Sorting and Searching  =====|\n"
           "\t\t\t\t|========       By Tjok Semarajaya      ========|\n"
           "\t\t\t\t|===============================================|\n\n");
	//pilihan program
	printf("\n\n");
	printf("\n\t\t\t\t|=====================|");
	printf("\n\t\t\t\t|   PILIHAN PROGRAM   |");
	printf("\n\t\t\t\t|---------------------|");
	printf("\n\t\t\t\t|[1] Sorting          |");
	printf("\n\t\t\t\t|[2] Searching        |");
	printf("\n\t\t\t\t|[3] Exit             |");
	printf("\n\t\t\t\t|=====================|");
	printf("\n\n\t\t\t\tMasukkan nomor urut dari pilihan anda : ");
	pilihan = validasi();
	
	if(pilihan < 1 || pilihan > 3)
	{ 
		system("cls");
		
		printf("\n\t\t\t\tInput Anda salah! Silahkan masukan angka 1 sampai 3.");
		printf("\n\n"); 
		main();
	}
	else if(pilihan == 1)
	{ 
		sort();
	}
	else if(pilihan == 2)
	{ 
		search();
	}
	else if(pilihan == 3)
	{ 
		exit(0);
	}
}

	
