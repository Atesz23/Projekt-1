#pragma once
#ifndef JATEK_H
#define JATEK_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>  //clock()
#include <conio.h> //kbhit,geth();
#include <stdbool.h>

char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya, int hossz, int szel);
void piros();
void sarga();
void reset();
void ora();
void delay(int ms);
bool jobbraszabad(char** palya, int playerX, int playerY);

#endif