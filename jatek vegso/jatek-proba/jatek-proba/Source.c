#include "jatek.h"
#include <time.h>


int main()
{
	time_t currentTime, startTime;
	float orat=0;
	char** palya;
	int gameover = 0;
	int elet = 0;
fomenu:
	elet = 3;
	menukiir();
	int valasztas=0;
	scanf("%i", &valasztas);
	switch (valasztas)
	{	
		case 1:
			startTime = time(NULL);
			level1:
				palyakkoztiatvezeto(1);
				palya = beolvasPalya("lvl1.txt");
				gameover = jatek(palya, gethossz("lvl1.txt"), getszel("lvl1.txt"), 6, 1, 10,elet);
				if (gameover == 1) goto level2;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level1;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level1; }
			level2:
				palyakkoztiatvezeto(2);
				palya = beolvasPalya("lvl2.txt");
				gameover = jatek(palya, gethossz("lvl2.txt"), getszel("lvl2.txt"), 4, 8, 11,elet);
				if (gameover == 1) goto level3;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level2;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level2; }
			level3:
				palyakkoztiatvezeto(3);
				palya = beolvasPalya("lvl3.txt");
				gameover = jatek(palya, gethossz("lvl3.txt"), getszel("lvl3.txt"), 7, 4, 22,elet);
				if (gameover == 1) goto level4;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level3;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level3; }
			level4:
				palyakkoztiatvezeto(4);
				palya = beolvasPalya("lvl4.txt");
				gameover = jatek(palya, gethossz("lvl4.txt"), getszel("lvl4.txt"), 12, 1, 20,elet);
				if (gameover == 1) goto level5;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level4;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level4; }
			level5:
				palyakkoztiatvezeto(5);
				palya = beolvasPalya("lvl5.txt");
				gameover = jatek(palya, gethossz("lvl5.txt"), getszel("lvl5.txt"), 11, 1, 44,elet);
				if (gameover == 1) goto level6;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level5;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level5; }
			level6:
				palyakkoztiatvezeto(6);
				palya = beolvasPalya("lvl6.txt");
				gameover = jatek(palya, gethossz("lvl6.txt"), getszel("lvl6.txt"), 1, 11, 25,elet);
				if (gameover == 1) goto level7;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level6;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level6; }
			level7:
				palyakkoztiatvezeto(7);
				palya = beolvasPalya("lvl7.txt");
				gameover = jatek(palya, gethossz("lvl7.txt"), getszel("lvl7.txt"), 6, 1, 43,elet);
				if (gameover == 1) goto level8;
				else if (gameover == -1) return 0;
				else if (gameover == -2) goto level7;
				else { elet--; if (elet == 0) { if (jatekvegevezerlo() == 1) goto fomenu; else return 0; }goto level7; }
			level8:
				currentTime = time(NULL);
				orat = difftime(currentTime, startTime);
				vege(orat);
				break;
		case 2:
			jatekleiras();
			goto fomenu;
			break;
		case 3:
			return 0;
			break;
		default:
			printf("HIBAS PARANCS!");
			break;
	}
	return 0;
}