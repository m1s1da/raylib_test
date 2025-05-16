#pragma once

#include <memory>

#include "IZoomStrategy.h"

class CameraController {
 public:
  explicit CameraController(std::unique_ptr<IZoomStrategy> zoomStrategy,
                            const int& width, const int& height);
  void SetZoomStrategy(std::unique_ptr<IZoomStrategy> zs);
  void Update();
  Camera2D& GetCamera();

 private:
  void HandlePan();

 private:
  Camera2D camera_;
  std::unique_ptr<IZoomStrategy> zoomStrategy_;
};