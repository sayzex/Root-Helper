#include "../include/ui.h"
#include "../include/raylib/raygui.h"

// Макрос для отрисовки текста со шрифтом
#define DrawMyText(f, text, x, y, size, color) DrawTextEx(f, text, (Vector2){x, y}, size, 1, color)

void DrawMainUI(Font font, bool *isRussian) {
    // Состояния кнопок (static сохраняет значения между вызовами функции в цикле)
    static bool adbButton = false;
    static bool rebootBootloaderButton = false;
    static bool fastbootButton = false;
    static bool fastbootFlash = false;
    static bool fastbootReboot = false;

    DrawMyText(font, "Root Helper built for you!", 510, 20, 30, WHITE);
    DrawLine(10, 55, 1490, 55, GRAY);
    DrawMyText(font, "TG: @wipestonehere", 10, 35, 20, RED);

    // Переключение языка (с разыменованием указателя через *)
    const char *langButtonText = (*isRussian) ? "Language: RU" : "Language: EN";
    if (GuiButton((Rectangle){1290, 15, 200, 35}, langButtonText)) {
        *isRussian = !(*isRussian);
    }

    // Кнопки интерфейса с переключением их логических состояний
    if (GuiButton((Rectangle){10, 70, 250, 60}, "adb devices")) {
        adbButton = !adbButton;
    }

    if (GuiButton((Rectangle){10, 160, 250, 60}, "adb reboot bootloader")) {
        rebootBootloaderButton = !rebootBootloaderButton;
    }

    if (GuiButton((Rectangle){10, 250, 250, 60}, "fastboot devices")) {
        fastbootButton = !fastbootButton;
    }      

    if (GuiButton((Rectangle){10, 340, 250, 60}, "fastboot flash")) {
        fastbootFlash = !fastbootFlash;
    }

    if (GuiButton((Rectangle){10, 430, 250, 60}, "fastboot reboot")) {
        fastbootReboot = !fastbootReboot;
    }

    // Вывод статуса
    if (*isRussian) {
        DrawMyText(font, "Статус: Ожидание действия...", 280, 80, 22, GRAY);
    } else {
        DrawMyText(font, "Status: Waiting for action...", 280, 80, 22, GRAY);
    }
}