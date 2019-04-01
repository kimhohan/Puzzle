#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define MAX 9
#define RANDOM 40
#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)
#define AUTO_UP 1
#define AUTO_DOWN 2
#define AUTO_LEFT 3
#define AUTO_RIGHT 4


int GetKey();

void DrawMap(int, int, int *, int *, int(*p)[3]);
void Control(int, int, int, int(*p)[3]);
void DrawLine();
void gotoxy(int, int);

void main()
{
	int map[3][3] = {
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,0 }
	};
	int keyinfo = 0;
	int zero_xPos = 0;
	int zero_yPos = 0;
	int puzzle_run = 1;
	int randomNumber = 0;
	srand((unsigned)time(0));
	printf("game start ? (0/1) : ");
	scanf_s("%d", &randomNumber);

	if (randomNumber == 1)
	{
		for (int i = 0; i < RANDOM; i++)
		{
			system("cls");
			DrawLine();
			DrawMap(3, 3, &zero_xPos, &zero_yPos, map);
			Control(0, zero_xPos, zero_yPos, map);
			Sleep(500);
		}
	}

	while (puzzle_run)
	{
		system("cls");
		DrawMap(3, 3, &zero_xPos, &zero_yPos, map);
		Control(1, zero_xPos, zero_yPos, map);
	}
}


void DrawMap(int lx, int ry, int *px, int *py, int(*p)[3])
{
	printf("\n");
	for (int y = 0; y < ry; y++)
	{
		for (int x = 0; x < lx; x++)
		{
			if (p[y][x] == 0)
			{
				*py = y;
				*px = x;
				//gotoxy(py, px);
				printf(" □");
			}
			else if (p[y][x] > 0)
			{
				//gotoxy(x, y);
				printf(" %d ", p[y][x]);
			}
		}
		printf("\n");
	}
}


void Control(int flag, int x, int y, int(*p)[3])
{
	int swapDataTemp = 0;
	if (flag == 0)
	{
		int autoControl = 0;
		autoControl = (rand() % 4) + 1;

		switch (autoControl)
		{
		case AUTO_UP:
			y--;
			if (y != -1)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				y++;
				p[y][x] = swapDataTemp;
			}
			break;
		case AUTO_DOWN:
			y++;
			if (y != 3)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				y--;
				p[y][x] = swapDataTemp;
			}
			break;
		case AUTO_LEFT:
			x--;
			if (x != -1)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				x++;
				p[y][x] = swapDataTemp;
			}
			break;
		case AUTO_RIGHT:
			x++;
			if (x != 3)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				x--;
				p[y][x] = swapDataTemp;
			}
			break;
		}
	}

	else
	{
		int key = GetKey();
		switch (key)
		{
		case KEY_UP:
			y--;
			if (y != -1)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				y++;
				p[y][x] = swapDataTemp;
			}
			break;
		case KEY_DOWN:
			y++;
			if (y != 3)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				y--;
				p[y][x] = swapDataTemp;
			}
			break;
		case KEY_LEFT:
			x--;
			if (x != -1)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				x++;
				p[y][x] = swapDataTemp;
			}
			break;
		case KEY_RIGHT:
			x++;
			if (x != 3)
			{
				swapDataTemp = p[y][x];
				p[y][x] = 0;
				x--;
				p[y][x] = swapDataTemp;
			}
			break;
		}
	}
}


void DrawLine()
{
	int i, j;
	unsigned char a = 0xa6;

	/************* 맨 윗단 그리기*********************/
	printf("%c%c", a, 0xa3);
	for (i = 0; i<5 - 2; i++)printf("%c%c", a, 0xa1);
	printf("%c%c\n", a, 0xa4);

	/************* 중간 그리가************************/
	for (j = 0; j<5 - 2; j++) {
		printf("%c%c", a, 0xa2);
		for (i = 0; i<5 - 2; i++)printf("  ");
		printf("%c%c", a, 0xa2);
		printf("\n");
	}
	/************* 맨 밑단 그리기*********************/
	printf("%c%c", a, 0xa6);
	for (i = 0; i<5 - 2; i++)printf("%c%c", a, 0xa1);
	printf("%c%c\n", a, 0xa5);

}


void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
		

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int GetKey()
{
	int keyinfo = _getch();
	if (keyinfo == 0 || keyinfo == 224)
	{
		keyinfo = 256 + _getch();
	}
	return keyinfo;
}