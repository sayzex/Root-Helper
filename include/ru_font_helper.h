#ifndef FONT_HELPER_H
#define FONT_HELPER_H

#include "../include/raylib/raylib.h"

static inline Font LoadCyrillicFont(const char *path, int fontSize) {
    int codepoints[512] = {0};
    int count = 0;
    for (int i = 0; i < 95; i++) codepoints[count++] = 32 + i;
    for (int i = 1040; i < 1103; i++) codepoints[count++] = i; // Russian Alphabet
    codepoints[count++] = 1025; codepoints[count++] = 1105; // Ё, ё

    return LoadFontEx(path, fontSize, codepoints, count);
}

#endif