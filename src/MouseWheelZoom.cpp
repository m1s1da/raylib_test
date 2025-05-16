#include "MouseWheelZoom.h"

#include <algorithm>
#include <cmath>

void MouseWheelZoom::ApplyZoom(Camera2D &camera) {
  float wheel = GetMouseWheelMove();
  if (wheel == 0.0f) return;

  Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera);
  camera.offset = GetMousePosition();
  camera.target = worldPos;

  float scale = 0.2f * wheel;
  camera.zoom =
      std::clamp(std::exp(std::log(camera.zoom) + scale), 0.125f, 64.0f);
}