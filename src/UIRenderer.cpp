#include "UIRenderer.h"

#include "raylib.h"

void UIRenderer::Render(int zoomMode) {
  DrawCircleV(GetMousePosition(), 4, DARKGRAY);
  Vector2 pos = GetMousePosition();
  DrawTextEx(GetFontDefault(), TextFormat("[%i, %i]", GetMouseX(), GetMouseY()),
             {pos.x - 44, pos.y - 24}, 20, 2, BLACK);

  DrawText("[1][2] Select mouse zoom mode", 20, 20, 20, DARKGRAY);
  const char *modeText = (zoomMode == 0)
                             ? "Left-drag to pan, Mouse wheel to zoom"
                             : "Left-drag to pan, Right-drag to zoom";
  DrawText(modeText, 20, 50, 20, DARKGRAY);
}