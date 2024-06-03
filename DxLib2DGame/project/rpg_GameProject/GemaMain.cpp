#define WIN_X (800)
#define WIN_Y (600)

#include <DxLib.h>
#include "Picture.h"

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR IpCmdLine,
    _In_ int nShowCmd)
{
    ChangeWindowMode(TRUE);
    DxLib_Init();

    /*Window初期化*/
    SetWindowText("DRAGON QUEST"); //ウィンドウのタイトル
    SetGraphMode(WIN_X, WIN_Y, 32); //ウィンドウの解像度
    SetBackgroundColor(255, 255, 255); //ウィンドウの背景色
    SetDrawScreen(DX_SCREEN_BACK); //裏画面描画

    int X = 0, Y = 0;
    Picture.Load();

    while (ScreenFlip() == 0 &&ClearDrawScreen &&ProcessMessage() == 0)
    {
        DrawGraph(X, Y, Picture.Player[0], TRUE);
        if (CheckHitKey(KEY_INPUT_W))
        {
            Y -= 10;
            Picture.Player_sprite = 3;
        }
        else if (CheckHitKey(KEY_INPUT_S))
        {
            Y += 10;
            Picture.Player_sprite = 0;

        }
        else if (CheckHitKey(KEY_INPUT_A))
        {
            X -= 10;
            Picture.Player_sprite = 1;
        }
        else if (CheckHitKey(KEY_INPUT_D))
        {
            X += 10;
            Picture.Player_sprite = 2;
        }
        if (CheckHitKeyAll()) { 
            DrawBox(0, 0, 800, 600, GetColor(0, 0, 0), TRUE);
        }

        Sleep(20);
        DrawGraph(X, Y, Picture.Player[Picture.Player_sprite*3], TRUE);
    }

    WaitKey();
    DxLib_End();
    return 0;

}