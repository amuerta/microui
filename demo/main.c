#include <stdbool.h>
#include <raylib.h>
#include <raymath.h>
#include "../src/microui.h"
#include "../src/microui.c"
#define MU_RL_FONT_SIZE 10
#include "../backends/microui_raylib.c"


typedef struct {
    int         bg;
    mu_Context  ui;

    bool        exit;
} Context;
#include "ui.c"

Context ctx_create(void) {
    Context c = {
        .bg = 0x141414FF,
    }; return c;
}

int main(void) {
    Context ctx = ctx_create();
    mu_rl_init(&ctx.ui);

#ifdef DEMO_RAYLIB
    SetTargetFPS(60);
    InitWindow(800,600,"Microui demo");
    while(!WindowShouldClose() && !ctx.exit) {
        mu_rl_events(&ctx.ui);
        ui_logic(&ctx);
        BeginDrawing(); {
            ClearBackground(GetColor(ctx.bg));
            mu_rl_flush(&ctx.ui);
        } EndDrawing();
    }
    CloseWindow();
#endif
}
