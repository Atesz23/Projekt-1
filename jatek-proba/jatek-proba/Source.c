#include "jatek.h"


int main()
{
	char** palya;
	char** palya1;
fomenu:
	menukiir();
	int valasztas=0;
	scanf("%i", &valasztas);
	switch (valasztas)
	{	
		case 1:
			level1:
				system("cls");
				palya = beolvasPalya("be.txt");
				if (iranyitas(palya, 8, 9) == 1)
				{
					goto level2;
				}
				else goto level1;
			level2:
				printf("LEVEL2");
				delay(1000);
				system("cls");
				palya1 = beolvasPalya("lvl2.txt");
				if (iranyitas2(palya1, 15, 15) == 1)
				{
					goto level3;
				}
				else goto level2;
			level3:
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
	system("pause");
	return 0;
}