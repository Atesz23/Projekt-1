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
void kirajzolPalya(char** palya, int hossz, int szel,int lepesekszama);
void piros();
void sarga();
void reset();
void ora();
void delay(int ms);
void zold();
void cyan();
void kek();
int iranyitas(char**palya,int hossz,int szel);
int iranyitas2(char** palya, int hossz, int szel);
int iranyitas3(char** palya, int hossz, int szel);
int jatek(char** palya, int hossz, int szel, int playerX, int playerY, int lepesekszama);
bool level1teljes(char** palya,int hossz, int szel);
bool level2teljes(char** palya, int hossz, int szel);
bool level3teljes(char** palya, int hossz, int szel);
void menukiir();
void jatekleiras();
#endif