#include "jatek.h"

int main()
{
	char** palya;
	palya = beolvasPalya("be.txt");
	bool start=true;
	int regiX, regiY;
	int playerX = 1, playerY = 1;
	while (1)
	{
		kirajzolPalya(palya, 8, 9);
		char irany = getch();
		/*if (start == true)
		{
			ora();
			start = false;
		}*/
		regiX = playerX;
		regiY = playerY;
		if (irany == 'd')
		{
			while (palya[playerX][playerY+1] == '0' || palya[playerX][playerY + 1] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerY++;
			}
		}
		else if (irany == 'a')
		{
			while (palya[playerX][playerY - 1] == '0' || palya[playerX][playerY -1] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerY--;
				
			}
		}
		else if(irany == 's')
		{
			while (palya[playerX+1][playerY] == '0' || palya[playerX + 1][playerY] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerX++;
			}
		}
		else if (irany == 'w')
		{
			while (palya[playerX-1][playerY] == '0' || palya[playerX - 1][playerY] == 'g')
			{
				palya[playerX][playerY] = 'g';
				playerX--;
			}
		}
		if (palya[playerX][playerY] == '0' || palya[playerX][playerY] == 'g')
		{
			palya[playerX][playerY] = 'P';
			palya[regiX][regiY] = 'g';
		}
		
		
		
	}

	//ora();
}