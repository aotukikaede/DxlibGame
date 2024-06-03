#include "DxLib.h"

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
	
	int circleX = 200;
	int circleY = 300;
	//マウスの座標
	int mouseX = 0;
	int mouseY = 0;

	int stringX = 10;
	int stringY = 15;
	int stringXl = 10;
	int stringYl = 50;

	int StringColor = GetColor(255, 255, 255);
	int StringColor2 = GetColor(255, 0, 0);
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		//文字の大きさの指定
		SetFontSize(32);
		//画面に文字を表示
		//DrawString(10, 15, "HelloWould", StringColor);
		DrawFormatString(stringX, stringY,StringColor, "X:%dY:%d",mouseX,mouseY);
		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
		//マウスの座標の特定
		GetMousePoint(&mouseX, &mouseY);
		//マウスがクリックされたら
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			SetFontSize(30);
			DrawString(stringXl, stringYl, "Hit!",StringColor2);
		}
		DrawPixel(320, 240, GetColor(255, 0, 0));
		if (CheckHitKey(KEY_INPUT_UP))
		{
			if (circleY <= 40)
			{
				circleY += 3;
			}
			else
			{
				circleY -= 3;
			}
			
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			if (circleY >= 560)
			{
				circleY -= 3;
			}
			else
			{
				circleY += 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			if (circleX <= 40)
			{
				circleX += 3;
			}
			else
			{
				circleX -= 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			if (circleX >= 740)
			{
				circleX -= 3;
			}
			else
			{
				circleX += 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			circleX = 320;
			circleY = 240;
		}
		//rcleX += 2;
		//rcleY += 2;
		ScreenFlip();

	}
	

	DxLib_End();

	return 0;
}