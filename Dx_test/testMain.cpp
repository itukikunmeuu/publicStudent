#include "DxLib.h"
#include <iostream>
using namespace std;


/*関数宣言*/
//文字を出す。左上よせ(第二引数は行番号)
void SimpleDraw(string drawText, int i);

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//windowモード

	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;
	}

	// 白色の値を取得
	unsigned int Cr = GetColor(255, 255, 255);
	// 文字列の描画
	DrawString(250, 240 - 32, "Hello  World!", Cr);

	WaitKey();// キー入力待ち

	DxLib_End();// ＤＸライブラリ使用の終了処理

	return 0;// ソフトの終了 
}


/*関数定義*/
//文字を出す。左上よせ(第二引数は行番号)
void SimpleDraw(string drawText, int i)
{
	// 白色の値を取得
	unsigned int Cr = GetColor(255, 255, 255);
	// 文字列の描画
	DrawString(0, i * 20, const_cast<char*>(drawText.c_str()), Cr);
}