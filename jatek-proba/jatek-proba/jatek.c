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
	//ellenorzes
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

void kirajzolPalya(char** palya,int hossz,int szel)
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
			if (palya[i][j] == 'o')
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
				printf("*");
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
		}
		printf("\n");
	}
}

void piros()
{
	printf("\033[1;31m");
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
bool jobbraszabad(char** palya,int playerX,int playerY)
{
	if (palya[playerX][playerY] + 1 == '0')
	{
		return true;
	}
	else return false;
	
}
void delay(ms) 
{
	clock_t timeDelay = ms + clock();    
	while (timeDelay > clock());        
}
void sarga()
{
	printf("\033[1;33m");
}