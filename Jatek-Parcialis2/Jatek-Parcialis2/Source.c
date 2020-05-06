#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>

char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya);

int hossz, szel;

int main()
{
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	//printf(“\033[0; 31m”);
	printf("\033[1;31m");
	char i = 254;
	printf("\n\n%c\n\n", i);
	palya = beolvasPalya("be.txt");
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	//kirajzolPalya(palya);
	while (1) {
		currentTime = time(NULL);
		kirajzolPalya(palya);
		printf("jobb: j\nle: l\n");
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'j') {
			jatekosY++;
		}
		else if (option == 'l') {
			jatekosX++;
		}
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		//Sleep(300);
		system("CLS");
		//	/*if (currentTime - startTime > 10) {
		//		printf("Time limit exceeded!\n Game over\n");
		//		break;*/
		//}

	}
	return(0);
}

char** beolvasPalya(const char* fajlNev)
{
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

void kirajzolPalya(char** palya)
{
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
				printf("-");
			}
			else if (palya[i][j] == '3') {
				printf("|");
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
				printf("P");
			}
		}
		printf("\n");
	}
	system("pause");
}