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
	fscanf(fin, "%i%i\n", &hossz, &szel);
	char** palya = (char**)(calloc(hossz, sizeof(char*)));
	for (int i = 0; i < hossz; ++i) {
		palya[i] = (char*)(calloc(szel, sizeof(char)));
	}
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);
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
				printf("%c", 187);
			}
			if (palya[i][j] == 'i')
			{
				printf("%c", 188);
			}
			if (palya[i][j] == 'O')
			{
				printf("%c", 201);
			}
			if (palya[i][j] == 'y')
			{
				printf("%c", 200);
			}
			if (palya[i][j] == '3')
			{
				printf("%c", 205);
			}
			if (palya[i][j] == '4')
			{
				printf("%c", 186);
			}
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == '1') {
				printf("%c", 219);
			}
			if (palya[i][j] == 'R') {
				printf("X");
			}
			if (palya[i][j] == 'P') {
				piros();
				printf("%c", 219);
				reset();
			}
			if (palya[i][j] == 'g') {
				sarga();
				printf("%c", 219);
				reset();
			}
			//printf("%c", palya[i][j]);
		}
		printf("\n");
		
	}
	printf("A hatralevo lepesek szama: ");
	if (lepesekszama > 5)
	{
		printf("%i", lepesekszama);
	}
	else
	{
		piros();
		printf("%i", lepesekszama);
	}
	boldsarga();
	printf("\nA palya urjatoltesehez nyomja meg az R-t");
	piros();
	printf("\nA jatek elhagyasahoz nyomja meg a 0-t");
	zold();
	printf("\nHatramaradt eletek szama : %i",elet);
	reset();

	//ora();
}
void piros(){
	printf("\033[0;31m");
}
void reset() {
	printf("\033[0m");
}
void ora()
{
	int ido = 10;
	while (ido >= 0)
	{
		printf("%i       ", ido);
		delay(1000);
		ido--;
		system("cls");
	}
	printf("lejart az ido");
}
void delay(ms) 
{
	clock_t timeDelay = ms + clock();    
	while (timeDelay > clock());        
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
//int iranyitas(char** palya,int hossz,int szel)
//{
//	int regiX, regiY;
//	int playerX = 1, playerY = 1;
//	int lepesekszama = 12;
//	int db = 0;
//	while (1)
//	{
//		kirajzolPalya(palya, hossz, szel, lepesekszama);
//		char irany = getch();
//		regiX = playerX;
//		regiY = playerY;
//		if (irany == 'd')
//		{
//			while (palya[playerX][playerY + 1] == '0' || palya[playerX][playerY + 1] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerY++;
//			}
//		}
//		else if (irany == 'a')
//		{
//			while (palya[playerX][playerY - 1] == '0' || palya[playerX][playerY - 1] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerY--;
//
//			}
//		}
//		else if (irany == 's')
//		{
//			while (palya[playerX + 1][playerY] == '0' || palya[playerX + 1][playerY] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerX++;
//			}
//		}
//		else if (irany == 'w')
//		{
//			while (palya[playerX - 1][playerY] == '0' || palya[playerX - 1][playerY] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerX--;
//			}
//		}
//		if (palya[playerX][playerY] == '0' || palya[playerX][playerY] == 'g')
//		{
//			palya[playerX][playerY] = 'P';
//			palya[regiX][regiY] = 'g';
//			lepesekszama--;
//		}
//		system("cls");
//		if (level1teljes(palya, 8, 9))
//		{
//			system("cls");
//			piros();
//			printf("\n\n\n          SIKER");
//			reset();
//			delay(1000);
//			system("cls");
//			return 1;
//		}
//		if (lepesekszama < 0)
//		{
//			system("cls");
//			piros();
//			printf("\n\n\n          GAME OVER");
//			reset();
//			delay(1000);
//			system("cls");
//			return 0;
//		}
//	}
//}
//int iranyitas2(char** palya, int hossz, int szel)
//{
//	int regiX, regiY;
//	int playerX = 1, playerY = 11;
//	int lepesekszama1 = 25;
//	int db = 0;
//	while (1)
//	{
//		kirajzolPalya(palya, hossz, szel, lepesekszama1);
//		char irany = getch();
//		regiX = playerX;
//		regiY = playerY;
//		if (irany == 'd')
//		{
//			while (palya[playerX][playerY + 1] == '0' || palya[playerX][playerY + 1] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerY++;
//			}
//		}
//		else if (irany == 'a')
//		{
//			while (palya[playerX][playerY - 1] == '0' || palya[playerX][playerY - 1] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerY--;
//
//			}
//		}
//		else if (irany == 's')
//		{
//			while (palya[playerX + 1][playerY] == '0' || palya[playerX + 1][playerY] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerX++;
//			}
//		}
//		else if (irany == 'w')
//		{
//			while (palya[playerX - 1][playerY] == '0' || palya[playerX - 1][playerY] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerX--;
//			}
//		}
//		if (palya[playerX][playerY] == '0' || palya[playerX][playerY] == 'g')
//		{
//			palya[playerX][playerY] = 'P';
//			palya[regiX][regiY] = 'g';
//			lepesekszama1--;
//		}
//		system("cls");
//		if (level2teljes(palya, 15, 15))
//		{
//			system("cls");
//			piros();
//			printf("\n\n\n          SIKER");
//			reset();
//			delay(1000);
//			system("cls");
//			return 1;
//		}
//		if (lepesekszama1< 0)
//		{
//			system("cls");
//			piros();
//			printf("\n\n\n          GAME OVER");
//			reset();
//			delay(1000);
//			system("cls");
//			return 0;
//		}
//	}
//}
//int iranyitas3(char** palya, int hossz, int szel)
//{
//	int regiX, regiY;
//	int playerX = 6, playerY = 1;
//	int lepesekszama1 = 44;
//	int db = 0;
//	while (1)
//	{
//		kirajzolPalya(palya, hossz, szel, lepesekszama1);
//		char irany = getch();
//		regiX = playerX;
//		regiY = playerY;
//		if (irany == 'd')
//		{
//			while (palya[playerX][playerY + 1] == '0' || palya[playerX][playerY + 1] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerY++;
//			}
//		}
//		else if (irany == 'a')
//		{
//			while (palya[playerX][playerY - 1] == '0' || palya[playerX][playerY - 1] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerY--;
//
//			}
//		}
//		else if (irany == 's')
//		{
//			while (palya[playerX + 1][playerY] == '0' || palya[playerX + 1][playerY] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerX++;
//			}
//		}
//		else if (irany == 'w')
//		{
//			while (palya[playerX - 1][playerY] == '0' || palya[playerX - 1][playerY] == 'g')
//			{
//				palya[playerX][playerY] = 'g';
//				playerX--;
//			}
//		}
//		if (palya[playerX][playerY] == '0' || palya[playerX][playerY] == 'g')
//		{
//			palya[playerX][playerY] = 'P';
//			palya[regiX][regiY] = 'g';
//			lepesekszama1--;
//		}
//		system("cls");
//		if (level3teljes(palya, 15, 15))
//		{
//			system("cls");
//			piros();
//			printf("\n\n\n          SIKER");
//			reset();
//			delay(1000);
//			system("cls");
//			return 1;
//		}
//		if (lepesekszama1 < 0)
//		{
//			system("cls");
//			piros();
//			printf("\n\n\n          GAME OVER");
//			reset();
//			delay(1000);
//			system("cls");
//			return 0;
//		}
//	}
//}
int jatek(char** palya, int hossz, int szel, int playerX, int playerY, int lepesekszama,int elet)
{
	int regiX, regiY;
	int mozog=mozoghatoresz(palya,hossz,szel);
	while (1)
	{
		kirajzolPalya(palya, hossz, szel, lepesekszama,elet);
		char irany = getch();
		regiX = playerX;
		regiY = playerY;
		if (irany == '0')
		{
			return -1;
		}
		if (irany == 'r')
		{
			return -2;
		}
		if (irany == 'd')
		{
			while (palya[playerX][playerY + 1] == '0' || palya[playerX][playerY + 1] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerY++;
			}
		}
		else if (irany == 'a')
		{
			while (palya[playerX][playerY - 1] == '0' || palya[playerX][playerY - 1] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerY--;

			}
		}
		else if (irany == 's')
		{
			while (palya[playerX + 1][playerY] == '0' || palya[playerX + 1][playerY] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerX++;
			}
		}
		else if (irany == 'w')
		{
			while (palya[playerX - 1][playerY] == '0' || palya[playerX - 1][playerY] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerX--;
			}
		}
		if (palya[playerX][playerY] == '0' || palya[playerX][playerY] == 'g')
		{
			palya[playerX][playerY] = 'P';
			palya[regiX][regiY] = 'g';
			lepesekszama--;
		}
		system("cls");
		if (teljesapalya(palya, hossz, szel,mozog))
		{
			return 1;
		}
		if (lepesekszama <= 0)
		{
			system("cls");
			piros();
			printf("\n\n\n          SIKERTELEN!");
			printf("\n            -1 ELET");
			reset();
			delay(1000);
			system("cls");
			return 0;
		}
	}
}
//bool level1teljes(char** palya,int hossz, int szel)
//{
//	int db = 0;
//	for (int i = 0; i < hossz; i++)
//	{
//		for (int j = 0; j < szel; j++)
//		{
//			if (palya[i][j] == 'g') db++;
//		}
//	}
//	if (db == 30) return true;
//	else return false;
//}
//bool level2teljes(char** palya, int hossz, int szel)
//{
//	int db = 0;
//	for (int i = 0; i < hossz; i++)
//	{
//		for (int j = 0; j < szel; j++)
//		{
//			if (palya[i][j] == 'g') db++;
//		}
//	}
//	if (db == 99) return true;
//	else return false;
//}
//bool level3teljes(char** palya, int hossz, int szel)
//{
//	int db = 0;
//	for (int i = 0; i < hossz; i++)
//	{
//		for (int j = 0; j < szel; j++)
//		{
//			if (palya[i][j] == 'g') db++;
//		}
//	}
//	if (db == 97) return true;
//	else return false;
//}
int gethossz(const char* fajlNev)
{
	int hossz, szel;
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	return hossz;
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
	return szel;
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
	return db;
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
	else return false;
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
	char startmenu[500];
	printf("\n\n");
	zold();
	while (fscanf(fin, "%[^\n]\n", &startmenu) != EOF)
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
	while (!kbhit());
	system("cls");
}
void palyakkoztiatvezeto(int szint)
{
	system("cls");
	magenta();
	printf("\n\n\n\tLEVEL %i",szint);
	delay(1000);
	system("cls");
	reset();
}
void lvlkirajzolo()
{
	magenta();
	printf("1.konnyu");
	reset();
	printf("\tNEM szamitanak a lepsek!");
	magenta();
	printf("\n2.kozepes");
	reset();
	printf("\tSzamiranak a lepesek");

}
void orakiir()
{
	
}
void jatekvege()
{
	FILE* fin;
	fin = fopen("Gameover.txt", "rt");
	if (!fin)
	{
		printf("HIBA");
		return 1;
	}
	char jatek[500];
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
	jatekvege();
	int opcio = 0;
	scanf("%d", &opcio);
	if (opcio == 1)
	{
		system("cls");
		return 1;
	}
	else if (opcio == 2) return 0;
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
		sec = orat - (60 * (min));
	}
	cyan();
	if (sec <= 9)printf("\n\nA palyakat ennyi ido alatt sikerult kivinni: 0%d:0%d\n", min, sec);
	else printf("\n\nA palyakat ennyi ido alatt sikerult kivinni: 0%d:%d\n", min, sec);
	printf("TOBB PALYA HAMAROSAN!\n\n\n");
	reset();
	return 0;
}

