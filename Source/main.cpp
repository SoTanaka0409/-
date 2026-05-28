#include <DxLib.h>
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include"SceneManager.h"
#include"Master.h"

SceneManager* Master::mpSceneManager = new SceneManager();



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Enable background operation and window mode
    SetAlwaysRunFlag(TRUE);
    ChangeWindowMode(TRUE);
    SetGraphMode(800, 600, 32);

    if (DxLib_Init() == -1) {
        return -1;
    }
    SetDrawScreen(DX_SCREEN_BACK);

    // Initialize Z-buffer
    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);
    
    ObjectManager objManager;
    
    // Add player
    objManager.AddObject(new Player());

    // Add some test enemies
    objManager.AddObject(new Enemy(VGet(200.0f, 0.0f, 200.0f)));
    objManager.AddObject(new Enemy(VGet(-200.0f, 0.0f, 200.0f)));
    objManager.AddObject(new Enemy(VGet(200.0f, 0.0f, -200.0f)));
    objManager.AddObject(new Enemy(VGet(-200.0f, 0.0f, -200.0f)));

    // Set camera
    VECTOR cameraPos = VGet(0.0f, 300.0f, -300.0f);
    VECTOR cameraTarget = VGet(0.0f, 0.0f, 0.0f);
    SetCameraPositionAndTarget_UpVecY(cameraPos, cameraTarget);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
        ClearDrawScreen();

        // Draw the core (origin)
        DrawSphere3D(VGet(0.0f, 0.0f, 0.0f), 20.0f, 16, GetColor(0, 0, 255), GetColor(0, 0, 255), TRUE);

        // Update and draw all objects
        objManager.Update();
        objManager.Draw();

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
