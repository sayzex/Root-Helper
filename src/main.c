#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

#include "../include/ru_font_helper.h"

// macross for ru language
#define DrawMyText(text, x, y, size, color) DrawTextEx(font, text, (Vector2){x, y}, size, 1, color)

int main(void)
{

    const int screenWidth = 1500;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Root Helper");

    SetTargetFPS(240);

    Font font = LoadCyrillicFont("./Fonts/JetBrainsMonoNerdFont-Regular.ttf", 32);
    SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);
    GuiSetFont(font);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

        
        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt((Color){ 50, 100, 250, 255 }));   
        GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, ColorToInt((Color){ 43, 246, 0, 255 }));
        GuiSetStyle(BUTTON, BASE_COLOR_PRESSED, ColorToInt((Color){ 30, 80, 200, 255 }));   
        
       
        GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(WHITE));
        GuiSetStyle(BUTTON, TEXT_COLOR_FOCUSED, ColorToInt(WHITE));
        GuiSetStyle(BUTTON, TEXT_COLOR_PRESSED, ColorToInt(WHITE));
        
    bool adbButton = false;
    bool rebootBootloaderButtton = false;
    bool fastbootButton = false;
    bool fastbootFlash = false;
    bool fastbootReboot = false;

    bool isRussian = false;
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawMyText("Root Helper built for you!", 510, 20, 30, WHITE);
        DrawLine(10, 55, 1490, 55, GRAY);
        DrawMyText("TG: @wipestonehere", 10, 35, 20, RED);

        const char *langButtonText = isRussian ? "Language: RU" : "Language: EN";
                if (GuiButton((Rectangle){1290, 15, 200, 35}, langButtonText)) {
                    isRussian = !isRussian;
                }

        if (GuiButton((Rectangle){10, 70, 250, 60 }, "adb devices")) {
            adbButton = !adbButton;
        }

        if (GuiButton((Rectangle){10, 160, 250, 60 }, "adb reboot bootloader")) {
            rebootBootloaderButtton = !rebootBootloaderButtton;
        }

        if (GuiButton((Rectangle){10, 250, 250, 60 }, "fastboot devices")) {
            fastbootButton = !fastbootButton;
        }     
     
        if (GuiButton((Rectangle){10, 340, 250, 60}, "fastboot flash")) {
            fastbootFlash = !fastbootFlash;
        }

        if (GuiButton((Rectangle){10, 430, 250, 60}, "fastboot reboot")) {
            fastbootReboot = !fastbootReboot;
        }

        if (isRussian) {
                    DrawMyText("Статус: Ожидание действия...", 280, 80, 22, GRAY);
                } else {
                    DrawMyText("Status: Waiting for action...", 280, 80, 22, GRAY);
                }
        
        EndDrawing();
    }




    CloseWindow();

    return 0;
}