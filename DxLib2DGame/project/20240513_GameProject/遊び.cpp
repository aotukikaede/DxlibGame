#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(800, 600, 32);
	

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	int a = 0;
	a = 5000+GetNowCount();
	int score = 0;
	int score2 = 0;
	int time = 0;

	int circleX = 200;
	int circleY = 300;

	int circleA = 600;
	int circleB = 300;

	int circleN = 0;
	int circleR = 0;

	int stringX = 10;
	int stringY = 15;
	int stringx = 700;
	int stringy = 15;
	int StringColor = GetColor(255, 255, 255);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);

		DrawCircle(circleA, circleB, 30, GetColor(255, 0, 0), TRUE);
		
		DrawCircle(circleN, circleR, 30, GetColor(0, 255, 0), TRUE);
		
		DrawFormatString(stringX, stringY, StringColor, "SCORE:%d", score);
		DrawFormatString(stringx, stringy, StringColor, "SCORE:%d", score2);
		//DrawPixel(320, 240, GetColor(255, 0, 0));

		if (CheckHitKey(KEY_INPUT_W))
		{
			circleY -= 10;
		}
		if (CheckHitKey(KEY_INPUT_S))
		{
			circleY += 10;
		}
		if (CheckHitKey(KEY_INPUT_A))
		{
			circleX -= 10;
		}
		if (CheckHitKey(KEY_INPUT_D))
		{
			circleX += 10;
		}
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			circleX = 200;
			circleY = 300;
		}

		if (CheckHitKey(KEY_INPUT_UP))
		{
			circleB -= 10;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			circleB += 10;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			circleA -= 10;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			circleA += 10;
		}
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			circleA = 600;
			circleB = 300;
		}
		
		//“–‚½‚è”»’è
		if ((circleX <= circleN + 20) && (circleX >= circleN - 20))
		{
			if ((circleY <= circleR + 20) && (circleY >= circleR - 20))
			{
				score += 10;
			}
		}
		if ((circleA <= circleN + 20) && (circleA >= circleN - 20))
		{
			if ((circleB <= circleR + 20) && (circleB >= circleR - 20))
			{
				score2 += 10;
			}
		}
		DrawFormatString(stringX, stringY, StringColor, "SCORE:%d", score);
		DrawFormatString(stringx, stringy, StringColor, "SCORE:%d", score2);

		time = GetNowCount();
		
		
		
		DrawFormatString(0, 100, StringColor, " %d,%d", time,a);

		if (a <= time)
		{
			circleN = rand() % 800 + 1;
			circleR = rand() % 600 + 1;
			
			a += 5000;
		}
		
		//rcleX += 2;
		//rcleY += 2;
		ScreenFlip();

	}

	
	
	DxLib_End();

	return 0;
}