#include "MouseDragZoom.h"

#include <algorithm>
#include <cmath>

void MouseDragZoom::ApplyZoom(Camera2D &camera) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
    Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera);
    camera.offset = GetMousePosition();
    camera.target = worldPos;
  }
  if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
    float deltaX = GetMouseDelta().x;
    float scale = 0.005f * deltaX;
    camera.zoom =
        std::clamp(std::exp(std::log(camera.zoom) + scale), 0.125f, 64.0f);
  }
}