#pragma once

#include "raylib.h"

class SceneRenderer {
 public:
  void Render(const Camera2D& camera, const int& width, const int& height);
};
