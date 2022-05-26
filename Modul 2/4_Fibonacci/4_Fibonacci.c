#include <stdio.h>
#include <stdlib.h>
 
void menu();
void rekursif();
int hitungrekursif(int bil);
void iteratif();
int validasi();
int validasimenu();
void opsi();
 
void menu(){
	
	int status,bil;
	
	printf ("\t\t=============================================\n");
    printf ("\t\t|          DERET BILANGAN FIBONACI          |\n");
    printf ("\t\t=============================================\n");
    printf ("\t\t| 1. DERET FIBONACI METODE REKURSIF         |\n");
    printf ("\t\t| 2. DERET FIBONACI METODE ITERATIF         |\n");
    printf ("\t\t| 3. KELUAR                                 |\n");
    printf ("\t\t=============================================\n");
    printf ("\t\t|Silahkan masukan pilihan anda :");
	status=validasimenu();
	system("cls");
 
	if(status==1){
 		rekursif();
	}
	else if(status==2){
  		iteratif();
	}	
	else if(status==3){
  		printf("\n\t\t=========== T E R I M A K A S I H ==========\n");
  		system("pause");
  		EXIT_SUCCESS;
	}
  	else{
  		printf("\t\tData yang Anda Masukan Tidak Valid !\n");
  		printf("\t\t--------------------------------------\n");
  		fflush(stdin);
  		system("pause");
  		system("cls");
  		menu();
	}
}

void rekursif(){
	int i,jumlah;
 
	char status;
	system("cls");
	printf ("\t\t=============================================\n");
    printf ("\t\t|           DERET FIBONACI REKURSIF         |\n");
    printf ("\t\t=============================================\n");
	printf("\t\tMasukkan Banyak Bilangan Fibonacci: ");
	jumlah=validasi();
	if(jumlah<=0){
		printf("\t\t~~~~~~~~Inputan tidak boleh kurang dari 1~~~~~~~~~");
		system("pause");
		rekursif();
	}
 
	printf("\nDeret fibonacci: ");
	for ( i = 0 ; i < jumlah ; i++ ){  
		printf("%d ", hitungrekursif(i)); 
	}	
	opsi();
}

int hitungrekursif(int bil) {
	if ( bil == 0 ){ 
		return 0;  
	}
	if ( bil == 1 ){
		return 1;  
	}
	return hitungrekursif(bil-1) + hitungrekursif(bil-2); 
}
 
void iteratif(){
	int nilai1,nilai2=0,nilai3=1,jumlah,keluar; 
	char status;
	system("cls");
	printf ("\t\t=============================================\n");
    printf ("\t\t|           DERET FIBONACI ITERATIF         |\n");
    printf ("\t\t=============================================\n");
	printf("\t\tMasukkan Banyak Bilangan Fibonacci: ");
	jumlah=validasi();
	if(jumlah<=0){
		printf("Inputan tidak boleh kurang dari 1");
		system("pause");
		iteratif();
	}
 
	printf("\nDeret fibonacci: ");
	for (nilai1=0; nilai1<jumlah; nilai1++){
		if (nilai1<=0){ 
			keluar=nilai1;  
		}
		else if (nilai1<=1){ 
			keluar=nilai1;
		}
		else{
			keluar=nilai2+nilai3; 
			nilai2=nilai3; 
			nilai3=keluar; 
		}
		printf("%d ", keluar);
	}
	opsi();
}
 
int validasi(){
    int  bilangan;
	char huruf;
  	if(scanf("%d%c", &bilangan, &huruf)!=2 || huruf!='\n' || huruf == ','){
	   printf("masukan nilai salah,silahkan masukan angka bukan huruf !.\n\n");
	   printf("--------------------------------------\n");
	   fflush(stdin);
	   system("pause");
	   system("cls");
	   rekursif(bilangan);
	   validasi();
  	}
	else{
		return bilangan;
  	}
}
 
int validasimenu(){
	int status;
	char huruf;
 
  	if(scanf("%d%c", &status, &huruf)!=2 || huruf!='\n' || huruf == ','){
   		printf("masukan nilai salah,silahkan masukan angka bukan huruf : \n");
   		printf("--------------------------------------\n");
    	fflush(stdin);
        system("pause");  
        system("cls");      
        main();            
   		validasimenu();
  	}
	else{
  		return status;
  	}
}
 
void opsi(){
	int bilangan;
	char status;
	printf("\nMenu Utama (y/n)");
	scanf("%s", &status);
	system("cls");

	if(status=='y'){
		main();
	}
	else if(status=='n') {
		rekursif(bilangan);
	}
	else{
  		printf("Data yang Anda Masukan Tidak Valid !\n");
  		fflush(stdin);
  		system("pause");
  		system("cls");
  		menu();
	}
}
 
int main(){
	menu();
	
	return 0;
}
