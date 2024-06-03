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
	
	int circleX = 0;
	int circleY = 0;
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);

		circleX += 2;
		circleY += 2;
		ScreenFlip();

	}
	DrawPixel(320, 240, GetColor(255, 0, 0));

	DxLib_End();

	return 0;
}