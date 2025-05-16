#pragma once

#include "IZoomStrategy.h"

class MouseDragZoom : public IZoomStrategy {
 public:
  void ApplyZoom(Camera2D &camera) override;
};
