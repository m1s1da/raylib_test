#pragma once
#include "raylib.h"

class IZoomStrategy {
 public:
  virtual ~IZoomStrategy() = default;
  virtual void ApplyZoom(Camera2D &camera) = 0;
};
