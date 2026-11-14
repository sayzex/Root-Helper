#include "../include/raylib/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../include/raylib/raygui.h"

#include "../include/ru_font_helper.h"

#include "../include/ui.h"

// macross for ru language
#define DrawMyText(text, x, y, size, color) DrawTextEx(font, text, (Vector2){x, y}, size, 1, color)

int main(void)
{

    const int screenWidth = 1500;
    const int screenHeight = 900;
//dd
    InitWindow(screenWidth, screenHeight, "Root Helper");

    SetTargetFPS(240);

    Font font = LoadCyrillicFont("./fonts/JetBrainsMonoNerdFont-Regular.ttf", 32);
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

        DrawMainUI(font, &isRussian);
        
        EndDrawing();
    }




    CloseWindow();

    return 0;
}