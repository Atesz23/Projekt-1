#pragma once
#ifndef JATEK_H
#define JATEK_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h> //kbhit,geth();
#include <stdbool.h>

typedef struct
{
	int ido_sec;
	int ido_min;
}IDO;

char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya, int hossz, int szel,int lepesekszama,int elet);
void piros();
void sarga();
void reset();
void ora();
void delay(int ms);
void zold();
void cyan();
void kek();
void magenta();
void boldsarga();
int jatek(char** palya, int hossz, int szel, int playerX, int playerY, int lepesekszama,int elet);
int gethossz(const char* fajlNev);
int getszel(const char* fajlNev);
int mozoghatoresz(char** palya, int hossz, int szel);
bool teljesapalya(char** palya, int hossz, int szel, int lepes);
void menukiir();
void jatekleiras();
void palyakkoztiatvezeto(int szint);
void lvlkirajzolo();
void orakiir();
void jatekvege();
int jatekvegevezerlo();
void vege(int orat);
#endif