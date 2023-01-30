#include "Input.h"
#include "WinApp.h"
#include "DirectXcommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基盤システム初期化
    // windowsAPIの初期化
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();

    //DxCommon
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    //入力の初期化
    Input* input = nullptr;
    input = new Input();
    input->Initialize(winApp);

    //スプライトコモンの初期化
    SpriteCommon* spriteCommon = nullptr;
    spriteCommon = new SpriteCommon;
    spriteCommon->Initialize(dxCommon);
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "reimu.png");

#pragma endregion

#pragma region 最初のシーン初期化
    //スプライトの初期化
    Sprite* sprite = nullptr;
    sprite = new Sprite();
    sprite->Initialize(spriteCommon, 1);

#pragma endregion

    // ゲームループ
    while (true) {

#pragma region 基盤システム更新
        //windowsのメッセージ処理
        if (winApp->ProcessMessage()) {
            //ゲームループを抜ける
            break;
        }

        //入力の更新
        input->Update();
#pragma endregion

#pragma region 最初のシーン更新
        sprite->Update();

#pragma endregion

        //描画前処理
        dxCommon->PreDraw();

#pragma region 最初のシーン描画
        //スプライトの描画
        spriteCommon->PreDraw();
        sprite->Draw();
        spriteCommon->PostDraw();

#pragma endregion

        //描画後処理
        dxCommon->PostDraw();
    }
#pragma region 最初のシーン終了

#pragma endregion

#pragma region 基盤システム終了
    // Sprite
    delete sprite;
    sprite = nullptr;

    // SpriteCommon
    delete spriteCommon;
    spriteCommon = nullptr;

    // Input
    delete input;
    input = nullptr;

    // DxCommon
    delete dxCommon;
    dxCommon = nullptr;

    // WinApp
    winApp->Finalize();
    delete winApp;
    winApp = nullptr;

#pragma endregion
    return 0;
}