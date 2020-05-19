#include "jatek.h"
#pragma once


char** beolvasPalya(const char* fajlNev)
{
	int hossz, szel;
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel); //beolvasom a palya hosszat es szelesseget
	char** palya = (char**)(calloc(hossz, sizeof(char*)));
	for (int i = 0; i < hossz; ++i) {
		palya[i] = (char*)(calloc(szel, sizeof(char)));
	}
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);//beolvasom a palya elemeit
		}
	}
	return palya;
} 
void kirajzolPalya(char** palya, int hossz, int szel, int lepesekszama,int elet)
{
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			if (palya[i][j] == 'u')
			{
				printf("%c", 187);//a palya korvonala
			}
			if (palya[i][j] == 'i')
			{
				printf("%c", 188);//a palya korvonala
			}
			if (palya[i][j] == 'O')
			{
				printf("%c", 201);//a palya korvonala
			}
			if (palya[i][j] == 'y')
			{
				printf("%c", 200);//a palya korvonala
			}
			if (palya[i][j] == '3')
			{
				printf("%c", 205);//a palya korvonala
			}
			if (palya[i][j] == '4')
			{
				printf("%c", 186);//a palya korvonala
			}
			if (palya[i][j] == '0') {
				printf(" "); // jarhato retulet
			}
			if (palya[i][j] == '1') {
				printf("%c", 219);//falak
			}
			if (palya[i][j] == 'P') {
				piros();
				printf("%c", 219);//jatekos
				reset();
			}
			if (palya[i][j] == 'g') {
				sarga();
				printf("%c", 219);//a jatekos altal atjart terulet
				reset();
			}
			//printf("%c", palya[i][j]);
		}
		printf("\n");
		
	}
	printf("A hatralevo lepesek szama: ");
	if (lepesekszama > 5)
	{
		printf("%i", lepesekszama); // a lepesek szama
	}
	else
	{
		piros();
		printf("%i", lepesekszama); // ha 5 nel kevesebb lepes van akkor pirosan irja ki a lepesek szamat
	}
	boldsarga();
	printf("\nA palya urjatoltesehez nyomja meg az R-t");
	piros();
	printf("\nA jatek elhagyasahoz nyomja meg a 0-t");
	zold();
	printf("\nHatramaradt eletek szama : %i",elet); // hatralevo eletek szama
	reset();

	//ora();
}
void piros(){
	printf("\033[0;31m");
}
void reset() {
	printf("\033[0m");
}
void delay(ms) 
{
	clock_t timeDelay = ms + clock();    
	while (timeDelay > clock());        //varokozasi ido
}
void sarga()
{
	printf("\033[0;33m");
}
void zold() {
	printf("\033[0;32m");
}
void cyan() {
	printf("\033[0;36m");
}
void kek() {
	printf("\033[0;34m");
}
void magenta()
{
	printf("\033[1;35m");
}
void boldsarga()
{
	printf("\033[1;33m");
}
int jatek(char** palya, int hossz, int szel, int playerX, int playerY, int lepesekszama,int elet)
{
	int regiX, regiY;
	int mozog=mozoghatoresz(palya,hossz,szel); // megnezi hogy hany bejarhato terulet van
	while (1)
	{
		kirajzolPalya(palya, hossz, szel, lepesekszama,elet); // kirajzolom az frissult palyat
		char irany = getch();
		regiX = playerX;
		regiY = playerY;
		if (irany == '0')
		{
			return -1; //ha a jatekos kiakar lepni a jatekbol
		}
		if (irany == 'r')
		{
			return -2; // ha a jatekos ujraakraja kezdeni a palyat anelkul hogy eletet veszitsen
		}
		if (irany == 'd')
		{
			while (palya[playerX][playerY + 1] == '0' || palya[playerX][playerY + 1] == 'g') //megvizsgalom hogy a jatekos jarhato teruletre lep vagy mar jart teruletre
			{
				palya[playerX][playerY] = 'g';
				playerY++; // jobbra mozgatas
			}
		}
		else if (irany == 'a')
		{
			while (palya[playerX][playerY - 1] == '0' || palya[playerX][playerY - 1] == 'g')//megvizsgalom hogy a jatekos jarhato teruletre lep vagy mar jart teruletre
			{
				palya[playerX][playerY] = 'g';
				playerY--;//balra mozgatas

			}
		}
		else if (irany == 's')
		{
			while (palya[playerX + 1][playerY] == '0' || palya[playerX + 1][playerY] == 'g')//megvizsgalom hogy a jatekos jarhato teruletre lep vagy mar jart teruletre
			{
				palya[playerX][playerY] = 'g';
				playerX++;//lefele mozgatas
			}
		}
		else if (irany == 'w')
		{
			while (palya[playerX - 1][playerY] == '0' || palya[playerX - 1][playerY] == 'g')//megvizsgalom hogy a jatekos jarhato teruletre lep vagy mar jart teruletre
			{
				palya[playerX][playerY] = 'g';
				playerX--;//felfele mozgatas
			}
		}
		if (palya[playerX][playerY] == '0' || palya[playerX][playerY] == 'g') //megvizsgalom hogy a jatekos jarhato teruletre lep vagy mar jart teruletre
		{
			palya[playerX][playerY] = 'P'; // jatekos uj pozicioja
			palya[regiX][regiY] = 'g'; // jatekos regi pozicioja befestese
			lepesekszama--;// a lepesek levonasa
		}
		system("cls");
		if (teljesapalya(palya, hossz, szel,mozog)) //megvizsgalom hogyha a palya telyesitve van-e?
		{
			return 1; //telsetitve a palya
		}
		if (lepesekszama <= 0) //ha elfogytak a lepesek
		{
			system("cls");
			piros();
			printf("\n\n\n          SIKERTELEN!");
			printf("\n            -1 ELET");
			reset();
			delay(1000); //varakozasi ido
			system("cls");
			return 0;
		}
	}
}
int gethossz(const char* fajlNev)
{
	int hossz, szel;
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	return hossz; // a palya hosszusaganak lekerdezese
}
int getszel(const char* fajlNev)
{
	int hossz, szel;
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	return szel;// a playa szellesegenek a lekerdezese
}
int mozoghatoresz(char** palya, int hossz, int szel)
{
	int db = 0;
	for (int i = 0; i < hossz; i++)
	{
		for (int j = 0; j < szel; j++)
		{
			if (palya[i][j] == '0') db++;
		}
	}
	return db;//megszamolja hogy mennyi bejarhato resz talalhato a palyan
}
bool teljesapalya(char** palya, int hossz, int szel, int lepes)
{
	int db = 0;
	for (int i = 0; i < hossz; i++)
	{
		for (int j = 0; j < szel; j++)
		{
			if (palya[i][j] == 'g') db++;
		}
	}
	if (db == lepes) return true;
	else return false; //megvizsgalom hogy a palya teljesitve van-e vagy sem
}
void menukiir()
{
	FILE* fin;
	fin = fopen("Start_menu.txt", "rt");
	if (!fin)
	{
		printf("HIBA");
		return 1;
	}
	char startmenu[160];
	printf("\n\n");
	zold();
	while (fscanf(fin, "%[^\n]\n", &startmenu) != EOF)//feolvasom a menut a fail vegeig
	{
		printf("\t   %s\n", startmenu);
	}
	kek();
	printf("\n\n\t\t\t\t\t1.JATEK INDITASA\n");
	cyan();
	printf("\n\t\t\t\t\t2.JATEK LEIRASA\n");
	piros();
	printf("\n\t\t\t\t\t   3.KILEPES\n");
	reset();
	//fomenu kiirasa
}
void jatekleiras()
{
	printf("A jatek lenyege az hogy egy piros teglatestett iranyitva az osszes fekete teruletett kiszinezni!\nA piros negyzettel athalad teruleteket a jatek sargara festi!\nA jatekos csak faltol falig tud haladni.\n");
	sarga();
	printf("A palya akkor van teljesitve ha minden szabad terulet sarga\n");
	reset();
	printf("Figyelni kell es kikel talani azt a strategiat amivel a legkevesebb mozdulattal teljesitheto.\nA lepesek szama limitalt, ha kifogyunk belole a palya urjatoltodik\n");
	printf("A jatekosnak ");
	piros();
	printf("3");
	reset();
	printf(" elete van, eletlevonas akkor jar ha kifogyunk a lepesekbol,\nde ha ugy latjuk hogy mar nem tudjuk kivinni a palyat,\nakkor az :");
	cyan();
	printf(" R ");
	reset();
	printf("-betuvel ujratudjuk tolteni az adott szintet, ilyenkor nem jar eletlevonas!\n");
	printf("A jatekost a ");
	zold();
	printf("w,a,s,d");
	reset();
	printf(" gombokkal lehet iranyitani!\n");
	piros();
	printf("Az akarmikori kilepeshez 0 - at kell megnyomni!");
	reset();
	while (!kbhit());//akarmilyen billenyugomb lenyomasara lepjen tovabb
	system("cls");
}
void palyakkoztiatvezeto(int szint)
{
	system("cls");
	magenta();
	printf("\n\n\n\tLEVEL %i",szint);//kiirom az adot szintet
	delay(1000);
	system("cls");
	reset();
}
void jatekvege()
{
	FILE* fin;
	fin = fopen("Gameover.txt", "rt"); //gameover szoveg
	if (!fin)
	{
		printf("HIBA");
		return 1;
	}
	char jatek[200]; //100
	printf("\n\n");
	zold();
	while (fscanf(fin, "%[^\n]\n", &jatek) != EOF)
	{
		printf("\t   %s\n", jatek);
	}
	kek();
	printf("\n\n\t\t\t\t\t1.Jatek ujrakezdese\n");
	piros();
	printf("\n\t\t\t\t\t     2.KILEPES\n");
	reset();
}
int jatekvegevezerlo()
{
	jatekvege();//ha a jateknak vege
	int opcio = 0;
	scanf("%d", &opcio);
	if (opcio == 1)
	{
		system("cls");
		return 1;//ujrakezdi a jatekot
	}
	else if (opcio == 2) return 0; // elolrol kezdi a jatekot
	else {
		printf("HIBA");
		return 0;
	}
}
void vege(int orat)
{
	int min = 0;
	int sec = 0;
	if (orat >= 60)
	{
		min = orat / 60;
		sec = orat - (60 * (min));//kiirom az egesz jatekban eltoltott idot oraban es percben
	}
	cyan();
	if (sec <= 9)printf("\n\nA palyakat ennyi ido alatt sikerult kivinni: 0%d:0%d\n", min, sec);
	else printf("\n\nA palyakat ennyi ido alatt sikerult kivinni: 0%d:%d\n", min, sec);
	printf("TOBB PALYA HAMAROSAN!\n\n\n");
	reset();
	return 0;
}