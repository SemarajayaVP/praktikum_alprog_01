#include <stdio.h>

int valid();
int cek_valid();

void keluar(){
	printf("\t==============================================\n");
	printf("\t|  TERIMAKASIH, SAMPAI JUMPA DI LAIN WAKTU   |\n");
	printf("\t==============================================\n");
}

int valid(){
	int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n' || bilangan<0){
        printf("\t\t Pilihan Tidak Tersedia  !!\n");
        printf("\n\t\t Masukan Ulang Pilihan : ");
        fflush(stdin);
        valid();
    }
	else{
        return bilangan;
    }
}


int cek_valid(){
	int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n' || bilangan<0){
        printf("\t\t Hanya Tersedia Inputan Angka!!\n");
        printf("\n\t\t Silahkan Memasukan Angka : ");
        fflush(stdin);
        cek_valid();
    }
	else{
        return bilangan;
    }
}

float luas_tabung(float jari, float PHI, int tinggi){
	float luas;
	
	luas = 2 * PHI * jari * (jari + tinggi);
	printf("\n\t\t Luas Permukaan Tabung Adalah  = %.2f cm2\n", luas);
	
	return luas;
}

float vol_tabung(float jari, float PHI, int tinggi){
	float vol;
	
	vol = PHI * jari * jari * tinggi;
	printf("\n\t\t Volume Tabung Adalah  = %.2f cm3\n", vol);
	
	return vol;
}

float luas_bola(float jari, float PHI){
	float luas;
	luas = 4 * PHI * ( jari * jari );
	printf("\n\t\t Luas Permukaan Bola adalah  = %.2f cm2\n", luas);
	return luas;
}

float vol_bola(float jari, float PHI){
	float vol;
	vol = (1.33333) * PHI * ( jari * jari * jari );
	printf("\n\t\t Volume Bola Adalah  = %.2f cm3\n", vol);
	return vol;
}

int luas_limas(int sisi, int tinggi){
	
	int luas_alas;
	int luas_sisit;
	int luas_limas;
	
	luas_alas = sisi * sisi;
	
	luas_sisit = 4 * ( 0.5 * sisi * tinggi );
	
	luas_limas = luas_alas + luas_sisit;
	printf("\n\t\t Luas Permukaan Limas Segiempat Adalah  = %d cm2\n", luas_limas);
	return luas_limas;
}

int vol_limas(int sisi, int tinggi){
	int vol;
	
	vol =  (0.33333) * (sisi * sisi)* tinggi;
	printf("\n\t\t Volume Limas Segiempat Adalah  = %d cm3\n", vol);
	return vol;
}

int luas_prisma(int alas,int tinggi, int tinggi_p){
	
	int l_prisma;
	l_prisma = (2 * (alas* tinggi)) + (3 * (tinggi_p * alas));
	printf("\n\t\t Luas Permukaan Prisma Adalah  = %d cm2\n", l_prisma);
	return l_prisma;
	
}

int vol_prisma(int alas, int tinggi, int tinggi_p){
	int vol;
	
	vol = (0.5 * alas * tinggi) * tinggi_p;
	printf("\n\t\t Volume Prisma Adalah  = %d cm3\n", vol);
	return vol;
}

float luas_kerucut(float PHI, float jari, int sisi){
	float l_kerucut;
	
	l_kerucut = (PHI) * (jari )* ( jari + sisi);
	printf("\n\t\t Luas Permukaan Prisma Adalah  = %.2f cm2\n", l_kerucut);
	return l_kerucut;
}

float vol_kerucut(float PHI, int tinggi,float jari ){
	float vol;
	
	vol = PHI*jari*jari*tinggi/3;
	printf("\n\t\t Vol Kerucut Adalah  = %.2f cm3\n", vol);
	return vol;
}

int main(){
	int sisi, panjang, lebar, tinggi, alas,tinggi_p;
	int pilihan;
	const float PHI = 3.14;
	float jari, vol, luas;
	char ulang;	
	
	do{
	//	system("Color 7F");
		printf("		=======================================================\n");		
		printf("		|                                                     |\n");
		printf("		|                ***Silahkan Pilih***                 |\n");
		printf("		|          ***Bangunan Yang Akan Dihitung***          |\n");
		printf(" 		|  1. TABUNG                                          |\n");
		printf("		|  2. BOLA                                            |\n");
		printf(" 		|  3. LIMAS SEGIEMPAT                                 |\n");
		printf(" 		|  4. PRISMA SEGITIGA                                 |\n");
		printf(" 		|  5. KERUCUT                                         |\n");
		printf("		=======================================================\n\n");
		printf(" 		Masukan Pilihan : ");
		
		pilihan=valid();
		printf("\n");
		system("cls");
		
		if (pilihan==1){
			printf("		===================================================\n");
			printf("		|                    TABUNG                       |\n");
			printf("		|             PERHITUNGAN LUAS DAN                |\n");
			printf("		|                 VOLUME TABUNG                   |\n");
			printf("		===================================================\n");
			
			printf("\t\t >>>>>Masukkan Jari-jari Alas Tabung (cm) = ");
			jari=cek_valid();
			printf("\t\t >>>>>Masukan Tingginya (cm) = ");
			tinggi=cek_valid();
			
			luas = luas_tabung( jari, PHI, tinggi);
			vol = vol_tabung( jari, PHI, tinggi);
			
			printf("\n\n\t\t Ingin memilih lagi? (Y/T) ");
			scanf("%s", &ulang);
			system("cls");
			
		}
		else if (pilihan==2){
			printf("		===================================================\n");
			printf("		|                     BOLA                        |\n");
			printf("		|             PERHITUNGAN LUAS DAN                |\n");
			printf("		|                  VOLUME BOLA                    |\n");
			printf("		===================================================\n");
						
			printf("\t\t >>>>>Masukkan Jari-jari Bola (cm) = ");
			jari = cek_valid();
			
			luas = luas_bola( jari, PHI);
			vol = vol_bola( jari, PHI);
			
			printf("\n\n\t\t Apakah anda ingin mengulang lagi? (Y/T) ");
			scanf("%s", &ulang);
			system("cls");
			
		}
		else if (pilihan==3){
			printf("		===================================================\n");
			printf("		|               LIMAS SEGIEMPAT                   |\n");
			printf("		|             PERHITUNGAN LUAS DAN                |\n");
			printf("		|                 VOLUME LIMAS                    |\n");
			printf("		===================================================\n");
		
			printf("\t\t >>>>>Masukkan Luas Sisi (cm) = ");
			sisi=cek_valid();
			printf("\t\t >>>>>Masukkan Tinggi (cm) = ");
			tinggi=cek_valid();
			
			luas = luas_limas(sisi, tinggi);
			vol = vol_limas(sisi, tinggi);
			
			printf("\n\n\t\t Apakah anda ingin mengulang lagi? (Y/T) ");
			scanf("%s", &ulang);
			system("cls");
		
		}
		else if (pilihan==4){
			printf("		===================================================\n");
			printf("		|                PRISMA SEGITIGA                  |\n");
			printf("		|             PERHITUNGAN LUAS DAN                |\n");
			printf("		|                 VOLUME TABUNG                   |\n");
			printf("		===================================================\n");			
		
			printf("\t\t >>>>>Masukkan Luas Alas (cm) = ");
			alas=cek_valid();
			printf("\t\t >>>>>Masukkan Tinggi (cm) = ");
			tinggi=cek_valid();
			printf("\t\t >>>>>Masukkan Tinggi Prisma (cm) = ");
			tinggi_p=cek_valid();
			
			luas = luas_prisma(alas, tinggi, tinggi_p);
			vol = vol_prisma(alas, tinggi, tinggi_p);
			
			printf("\n\n\t\t Ingin memilih lagi? (Y/T) ");
			scanf("%s", &ulang);
			system("cls");
		
		}
		else if (pilihan==5){
			printf("		===================================================\n");
			printf("		|                    KERCUT                       |\n");
			printf("		|             PERHITUNGAN LUAS DAN                |\n");
			printf("		|                VOLUME KERUCUT                   |\n");
			printf("		===================================================\n");			
			
			printf("\t\t >>>>>Masukkan Jari-jari = ");
			jari=cek_valid();
			printf("\t\t >>>>>Masukkan Tinggi (cm) = ");
			tinggi=cek_valid();
			printf("\t\t >>>>>Masukkan Alas(cm)  = ");
			sisi=cek_valid();
			
			luas = luas_kerucut( PHI, jari, sisi);
			vol = vol_kerucut(PHI, tinggi, jari);
			
			printf("\n\n\t\t Apakah anda ingin mengulang lagi? (Y/T) ");
			scanf("%s", &ulang);
			system("cls");
		
		}
		else if (pilihan == 6){
			keluar();
			return 0;
		}
		else{
			printf("\tMAAF, PILIHAN ANDA TIDAK VALID\n");
			printf("\tSILAHKAN MENGINPUTKAN ULANG\n\n");
			printf("\tIngin Mengulang Lagi?\n");
			printf ("\tYa atau Tidak (Y/T): "); 
			scanf ("%s", &ulang);
			system("cls");
		}
	}
	while (ulang=='Y'||ulang=='y');
	keluar();
}
