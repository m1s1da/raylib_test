#pragma once

#include "IZoomStrategy.h"

class MouseWheelZoom : public IZoomStrategy {
 public:
  void ApplyZoom(Camera2D &camera) override;
};
