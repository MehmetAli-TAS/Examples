#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void islem8();
void giris();
void islemler();
void yazdir(char islem[100], int kim, int kime, float tutar){
	time_t simdikiZaman;
    struct tm *zamanBilgisi;
    char zamanStr[100];
    time(&simdikiZaman);
    zamanBilgisi = localtime(&simdikiZaman);
    strftime(zamanStr, sizeof(zamanStr), "%d-%m-%Y %H:%M:%S", zamanBilgisi);
    
	FILE *islemler;
    islemler = fopen("islem_gecmisi.txt", "a");
    fprintf(islemler, "ISLEM:%s  GONDERICI:%d  ALICI:%d  TUTAR:%.2f",islem, kim, kime, tutar);
    fprintf(islemler, "  TARIH VE SAAT: %s\n", zamanStr);
    fclose(islemler);
}

void islem1(int _no){
	FILE *musteriler;
    musteriler = fopen("musteriler.txt", "r");
	int a;
	char b[100];
	float c;
	while (fscanf(musteriler, "%d %s %f", &a, b, &c) != EOF) {
		if(_no == a){
			 printf("\033[32m\nHESAP BAKIYENIZ: \033[0m");
			printf("%f\n\n", c);
			fclose(musteriler);
			break;
		}
    }
    fclose(musteriler);
}

void islem2(int _no){
	FILE *musteriler;
	char islem[100] = "para yatirma";
    musteriler = fopen("musteriler.txt", "r+");
    //gecici dosya
    FILE *temp;
    temp = fopen("temp.txt", "w");
    
    float tutar;
    printf("\033[32mTUTAR GIRINIZ: \033[0m");
    scanf("%f", &tutar);
	int a;
	char b[100];
	float c;
	
	while (fscanf(musteriler, "%d %s %f", &a, b, &c) != EOF) {
		if(_no == a){
			fprintf(temp, "%d %s %f\n", a, b, c+tutar);
		}else{
			fprintf(temp, "%d %s %f\n", a, b, c);
		}
	
    }
    fclose(musteriler);
    fclose(temp);
    temp = fopen("temp.txt", "r");
    musteriler = fopen("musteriler.txt", "w");
    while (fscanf(temp, "%d %s %f", &a, b, &c) != EOF) {
		fprintf(musteriler, "%d %s %f\n", a, b, c);
    }
    fclose(musteriler);
    fclose(temp);
    remove("temp.txt");
    yazdir(islem, _no, _no, tutar);
}

void islem3(int _no){
	char islem[100] = "PARA CEKME";
	FILE *musteriler;
    musteriler = fopen("musteriler.txt", "r+");
    //gecici dosya
    FILE *temp;
    temp = fopen("temp.txt", "w");
    bool check = true;
    float tutar;
    printf("\033[32mTUTAR GIRINIZ: \033[0m");
    scanf("%f", &tutar);
	int a;
	char b[100];
	float c;
	
	while (fscanf(musteriler, "%d %s %f", &a, b, &c) != EOF) {
		if(_no == a){
			if(tutar > c){
				printf("\033[31mYETERSIZ BAKIYE!\033[0m\n");
				check = false;
				remove("temp.txt");
				break;
			}
			fprintf(temp, "%d %s %f\n", a, b, c-tutar);
		}else{
			fprintf(temp, "%d %s %f\n", a, b, c);
		}
	
    }
    if(check){
    	fclose(musteriler);
    	fclose(temp);
    	temp = fopen("temp.txt", "r");
    	musteriler = fopen("musteriler.txt", "w");
    	while (fscanf(temp, "%d %s %f", &a, b, &c) != EOF) {
			fprintf(musteriler, "%d %s %f\n", a, b, c);
    	}
    	fclose(musteriler);
    	fclose(temp);
    	remove("temp.txt");
    	yazdir(islem, _no, _no, tutar);
	}
    
}

void islem4(int _no){
	FILE *musteriler;
	char islem[100] = "PARA GONDERME";
    musteriler = fopen("musteriler.txt", "r+");
    //gecici dosya
    FILE *temp;
    temp = fopen("temp.txt", "w");
    int alici;
    printf("\033[32mALICI: \033[0m");
    scanf("%d", &alici);
    float tutar;
    bool check = true;
    printf("\033[32mTUTAR GIRINIZ: \033[0m");
    scanf("%f", &tutar);
	int a;
	char b[100];
	float c;
	
	while (fscanf(musteriler, "%d %s %f", &a, b, &c) != EOF) {
		if(_no == a){
			if(tutar > c){
				printf("\033[31mYETERSIZ BAKIYE!\033[0m\n");
				check = false;
				remove("temp.txt");
				break;
			}
			fprintf(temp, "%d %s %f\n", a, b, c-tutar);
		}
		else if(alici == a){
			fprintf(temp, "%d %s %f\n", a, b, c+tutar);
		}else{
			fprintf(temp, "%d %s %f\n", a, b, c);
		}
	
    }
    if(check){
    	fclose(musteriler);
    	fclose(temp);
    	temp = fopen("temp.txt", "r");
    	musteriler = fopen("musteriler.txt", "w");
    	while (fscanf(temp, "%d %s %f", &a, b, &c) != EOF) {
			fprintf(musteriler, "%d %s %f\n", a, b, c);
    	}
    	fclose(musteriler);
    	fclose(temp);
    	remove("temp.txt");
    	yazdir(islem, _no, alici, tutar);
	}
    
}

void islem5(int _no){
	char islem[100] = "SIFRE DEGISIKLIGI";
	FILE *musteriler;
    musteriler = fopen("musteriler.txt", "r");
    FILE *temp;
    temp = fopen("temp.txt", "w");
    bool check = false;
	int a;
	char b[100];
	float c;
	char sifre[100];
	char nsifre[100];
	char nsifre2[100];
	printf("\033[34mSIFRENIZI GIRIN\033[0m");
	scanf("%s", sifre);
	while (fscanf(musteriler, "%d %s %f", &a, b, &c) != EOF) {
		if(_no == a && strcmp(sifre, b) == 0){
			printf("yeni sifrenizi girin: ");
			scanf("%s", nsifre);
			printf("yeni sifrenizi tekrar girin: ");
			scanf("%s", nsifre2);
			if(nsifre != nsifre2){
				printf("sifreler uyusmuyor!");
				islem8();
				remove("temp.txt");
				break;
			}else{
				fprintf(temp, "%d %s %f\n", a, nsifre, c);
    			check = true;
			}
			
		}else{
			fprintf(temp, "%d %s %f\n", a, b, c);
		}
    }
    if(check == false){
    	printf("\033[31mISLEM BASARISIZ, SIFRE HATALI!!!\033[0m\n");
    	fclose(musteriler);
    	islem8();
	}else{
		fclose(musteriler);
		fclose(temp);
    	temp = fopen("temp.txt", "r");
    	musteriler = fopen("musteriler.txt", "w");
    	while (fscanf(temp, "%d %s %f", &a, b, &c) != EOF) {
			fprintf(musteriler, "%d %s %f\n", a, b, c);
    	}
    	fclose(musteriler);
    	fclose(temp);
    	remove("temp.txt");
    	yazdir(islem, _no, _no, 0);
		}
	
	
}

void islem6(){
	FILE *islemler;
	char line[100];
    islemler = fopen("islem_gecmisi.txt", "r");
    while (fgets(line, sizeof(line), islemler) != NULL) {
        printf("%s", line); // Satýrý ekrana yazdýr
}
}

void islem7(){
	printf("\033[31mOTURUM SONLANDIRILDI\033[0m\n");
	Sleep(1000);
	system("cls");
	giris();
}

void islem8(){
	printf("\033[1mISLEM SONLANDIRILDI!!!\033[0m\n");
	Sleep(1000);
	exit(0);
}

void islemler(int no) {
	while (true){
		getchar();
		getchar();
		system("cls");
		int secim;
		printf("\n\nISLEM LISTESI\n\n");
		printf("1.BAKIYE GORUNTULEME\n2.PARA YATIRMA\n3.PARA CEKME\n4.PARA GONDERME\n5.SIFRE DEGISTIRME\n6.ISLEM GECMISI GORUNTULEME\n7.OTURUM KAPATMA\n8.PROGRAMDAN CIKMA\n\n");
    	printf("\033[33mSECIMINIZI YAPIN: \033[0m");
    	scanf("%d", &secim);
    	switch(secim){
    		case 1:
    			islem1(no);
    			break;
    		case 2:
    			islem2(no);
    			break;
    		case 3:
    			islem3(no);
    			break;
    		case 4:
    			islem4(no);
    			break;
    		case 5:
    			islem5(no);
    			break;
    		case 6:
    			islem6();
    			break;
    		case 7:
    			islem7();
    			break;
    		case 8:
    			islem8();
    			break;
	}
	}

}

int dogrulama(int _no,char _sifre[100]){
	FILE *musteriler;
    musteriler = fopen("musteriler.txt", "r");
    bool check = false;
	int a;
	char b[100];
	float c;
	while (fscanf(musteriler, "%d %s %f", &a, b, &c) != EOF) {
		if(_no == a && strcmp(_sifre, b) == 0){
			check = true;
			return check;
			fclose(musteriler);
			break;
		}
    }
    if(check == false){
    	printf("\033[31mISLEM BASARISIZ!\033[0m\n");
    	fclose(musteriler);
    	islem8();
	}
}

void giris(){
	int no;
	char sifre[100];
	printf("\033[34mHESAP NUMARANIZI GIRIN: \033[0m");
    scanf("%d", &no);
    printf("\033[34mSIFRENIZI GIRIN: \033[0m");
    scanf("%s", &sifre);
	if(dogrulama(no, sifre)){
		islemler(no);
	}
}

int main() {
	int no;
	char sifre[100];
    int secim;
	FILE *file;

    file = fopen("musteriler.txt", "r"); // "a" modu dosya sonuna ekler, yoksa oluþturur

    if (file == NULL) {
    	fclose(file);
        printf("\033[31mKULLANICI VERILERI DOSYASI BULUNAMADI, VARSAYILAN VERILER KULLANILACAK\n\n\033[0m\n");
        file = fopen("musteriler.txt", "w");
        fprintf(file, "1001 PASS1 1000.00\n1002 PASS2 1500.00\n1003 PASS3 2000.00\n1004 PASS4 2500.00\n1005 PASS5 3000.00\n");
        fclose(file);
		giris();
		
    } else {
    	fclose(file);
        giris();
    }
    fclose(file);
    return 0;
}
