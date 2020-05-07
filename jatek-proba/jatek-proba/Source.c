#include "jatek.h"

int main()
{
	char** palya;
level1:
	palya = beolvasPalya("be.txt");
	if (iranyitas(palya, 8, 9) == 1)
	{
		goto level2;
	}
	else goto level1;
level2:
	printf("LEVEL2");


	
	return 0;
}