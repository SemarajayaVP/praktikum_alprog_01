#include <stdio.h>
#include <math.h>
 #include <conio.h>
 #include <stdlib.h>
//#define 

int input_desimal();
int welcome();
int input_pilihan();

float luassegitigasembarang (float a, float b, float c){
 return (a+b+c)/2;
}
float luasbelahketupat (float d1, float d2){
 return (d1*d2)/2;
}
float luasjajargenjang (float a, float t){
 return a*t;
}
float luastrapesium (float a, float b, float t){
 return (a*b)*t/2;
}
float luaslingkaran (float phi, float jarijari){
 return phi*jarijari*jarijari;
}
float kllsegitigasembarang (float a, float b, float c){
 return (a+b+c);
}
float kllbelahketupat (float sisi){
 return (4*sisi);
}
float klljajargenjang (float a, float b){
 return (2*(a+b));
}
float klltrapesium (float a, float b, float c, float d){
 return (a+b+c+d);
}
float klllingkaran (float phi, float jarijari){
 return (2*phi*jarijari);
}

int main(){
 float phi = 3.14159;
 float a, b, c, d, d1, d2, t, jarijari, sisi;
 int pilihan;
 int hasil;
 char jawaban = 'y';
 welcome();
 while(jawaban == 'y'){
 system("cls");
 }
}

int welcome(){
 float phi = 3.14159;
 float a, b, c, d, d1, d2, t, jarijari, sisi;
 int pilihan;
 int hasil;
 char jawaban = 'y';
 
 printf("\n\n\n\n\n\t\t************************************************************\n");
    printf("\t\t  ========================================================\n\n");
    printf("\t\t\t    SELAMAT DATANG DI SISTEM PENGHITUNGAN\n");
    printf("\t\t\t      LUAS DAN KELILING \n");
    printf("\t\t  ========================================================");
 printf("\n\t\t************************************************************");
 printf("\n\n\n\n\n Press any key to continue......");
 getch();
 system("cls");

  printf ("\n 1.Segitiga Sembarang\n 2.Belah Ketupat\n 3.Jajar Genjang\n 4.Trapesium\n 5.Lingkaran\n");
  printf ("\n Masukkan pilihanmu : " );
  pilihan = input_pilihan();
  getch();
  system("cls");
 
  switch (pilihan){
   case 1:
    printf ("\n masukkan nilai a : " );
    a = input_desimal();
    printf ("\n masukkan nilai b : " );
    b = input_desimal();
    printf ("\n masukkan nilai c : " );
    c = input_desimal();
  getch();
  system("cls");
    printf ("\n luas : %0.2f", luassegitigasembarang(a,b,c));
    printf ("\n keliling : %0.2f", kllsegitigasembarang(a,b,c));
   break;
   
   case 2:
    printf ("\n masukkan diameter 1 : " );
    d1 = input_desimal();
    printf ("\n masukkan diameter 2 : " );
    d2 = input_desimal();
    printf ("\n masukkan sisi : ");
    sisi = input_desimal();
  getch();
  system("cls");
    printf ("\n luas : %0.2f", luasbelahketupat(d1,d2));
    printf ("\n keliling : %0.2f", kllbelahketupat(sisi)); 
   break;
   
   case 3:
    printf ("\n masukkan alas : " );
    a = input_desimal();
    printf ("\n masukkan tinggi : " );
    t = input_desimal();
    printf ("\n masukkan  nilai a : " );
    a = input_desimal();
    printf ("\n masukkan  nilai b : " );
    b = input_desimal();
  getch();
  system("cls");
    printf ("\n luas : %0.2f", luasjajargenjang(a,t));
    printf ("\n keliling : %0.2f", klljajargenjang(a,b));
   break;
   
   case 4:
    printf ("\n masukkan nilai a : " );
    a = input_desimal();
    printf ("\n masukkan nilai b : " );
    b = input_desimal();
    printf ("\n masukkan tinggi : " );
    t = input_desimal();
    printf ("\n masukkan nilai c : " );
    c = input_desimal();
    printf ("\n masukkan nilai d : " );
    d = input_desimal();
  getch();
  system("cls");
    printf ("\n luas : %0.2f", luastrapesium(a,b,t));
    printf ("\n keliling : %0.2f", klltrapesium(a,b,c,d));
   break;
   
   case 5:
    printf ("\n masukkan jarijari : " );
    jarijari = input_desimal();
  getch();
  system("cls");
    printf ("\n luas : %0.2f", luaslingkaran(phi,jarijari));
    printf ("\n keliling : %0.2f", klllingkaran(phi,jarijari));
    
   default:
    printf ("\n\n pilihan tidak tersedia\n");
   break;
   
  }
  printf ("\nApakah Mengulang? : " );
  scanf (" %c", &jawaban); 
  if(jawaban == 'y'){
   main();
  }else{
   system("cls");
  }
 return 0;
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
	return atof(data);
}

int input_pilihan() {
	char ch;
	char *data;
	int cek = 0;
	data = (char *)malloc(sizeof(char)); 
	
	while ((ch = getch()) != 13)//jadi di input desimal nii fungsinya yaitu ngecek angka desimal,misal yanng dimasukin tu angka 0-9,nah jika user ngetk angka segitu pas running program dia akan muncul di terminal,kalo bukan dari itu dia bakal gak muncul di terminal
	{
			
		if ((ch >= '1' && ch <= '5')) {
		printf("%c", ch); 
		data[cek] = ch; 
		cek++;
			
		} 
	}
	data[cek] = '\0'; 
	return atoi(data);
}
