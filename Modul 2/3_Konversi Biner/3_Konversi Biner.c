 #include <stdio.h>
 #include <stdlib.h> 
 #include <conio.h>
 
void judul(); 
void reset();
void waiting();
int input_desimal();
int input_biner();
int desimalKeBiner();
int binerKeDesimal();
int angka, hasil, pilihan, biner, desimal, sisabagi, hasilbagi;

int main() {
	judul();
	printf("  \nJenis :\n  1. Desimal ke Biner\n  2. Biner ke Desimal\n");
	printf("\n  Masukkan Pilihan : ");
		scanf("%d", &pilihan);
	if (pilihan == 1) {
		system("cls");
		waiting();
		judul();
		printf("  1. Desimal ke Biner");
		printf("\n\n  Masukkan Angka Desimal : "); 
		desimal = input_desimal();
		hasil = desimalKeBiner(angka); 
    }
	else if (pilihan == 2) {
		system("cls"); 
		waiting();
		judul();
		printf("  2. Biner ke Desimal");
		printf("\n\n  Masukkan Angka Biner   : ");
		biner = input_biner();
		hasil = binerKeDesimal(angka);
	}
	else {
		printf("\n  Input Invalid"); 
		sleep(2);
		system("cls"); 
		main();
	}
	printf("\n Hasil Konversi\t : %d\n\n",hasil);
  	reset();
	return 0; 
}

void waiting(){

	system("cls");
		int a;
		for(a=0;a<=12;a++){
			printf("_______");
			Sleep(100);
		}
	system("cls");
}

void judul() {
		printf("\t\t\t\t|===============================================|\n"
           "\t\t\t\t|==========  PRAKTIKUM ALPROG MODUL 3 ==========|\n"
           "\t\t\t\t|==========         KELOMPOK 1        ==========|\n"
           "\t\t\t\t|           *************************           |\n"
           "\t\t\t\t|====       Program 2.3 Biner & Desimal    =====|\n"
           "\t\t\t\t|========       By Tjok Semarajaya      ========|\n"
           "\t\t\t\t|===============================================|\n\n");
}

void reset() {
	int ulang;
	printf("\n  Ingin Mengulangi? [y / t]  "); 
	ulang = getch();
	if (ulang == 'y' || ulang == 'Y') {
		system("cls");
 		main();
	}
	
	else if (ulang == 't' || ulang == 'T') {
		return; 
	}
		
	else {
	system("cls"); 
	judul();
	printf("  Input Invalid\n"); 
	reset();
	} 
}

int input_desimal() {
	char ch;
	char *data;
	int cek = 0;
	data = (char *)malloc(sizeof(char)); 
	
	while ((ch = getch()) != 13)//jadi di input desimal nii fungsinya yaitu ngecek angka desimal,misal yanng dimasukin tu angka 0-9,nah jika user ngetk angka segitu pas running program dia akan muncul di terminal,kalo bukan dari itu dia bakal gak muncul di terminal
	{
		if ((ch >= '0' && ch <= '9')) {
		printf("%c", ch); 
		data[cek] = ch; 
		cek++;
		} 
	}
	data[cek] = '\0'; 
	return atoi(data);
}

int input_biner() {
	char ch;
    char *data; 
	int cek = 0;
	data = (char *)malloc(sizeof(char));
 	while ((ch = getch()) != 13)
	{
		if (ch == '0' || ch == '1') {
			printf("%c", ch); 
			data[cek] = ch; 
			cek++;
			} 
	}
	
	data[cek] = '\0'; 
	return atoi(data);
}

int desimalKeBiner(int angka) {
	int biner = 0; 
	int bobot = 1; 
	angka = desimal;
	if (angka != 0 && angka != 1) {
		while (desimal != 0)
		 {
		 	//sb = 1
			sisabagi = desimal % 2;
			biner = biner + sisabagi * bobot; 
			desimal = desimal / 2;
			bobot = bobot * 10; 
		}
	}
	else 
	{
		biner = angka; 
	}
	return biner;
}

int binerKeDesimal(int angka) {//logika tiap bit dapat mengalikan bobotnya
	int desimal = 0;
 	int bobot = 1; 
	angka = biner; 
 	while (biner != 0)
	{
	sisabagi = biner % 10;
	desimal = desimal + sisabagi * bobot; 
	biner = biner / 10;
	bobot = bobot * 2;
	 }
	return desimal;
}
