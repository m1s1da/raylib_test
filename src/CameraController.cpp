#include "CameraController.h"

#include <raymath.h>

CameraController::CameraController(std::unique_ptr<IZoomStrategy> zoomStrategy,
                                   const int& width, const int& height)
    : zoomStrategy_(std::move(zoomStrategy)) {
  camera_.zoom = 1.0f;
  camera_.target = {0.0f, 0.0f};
  camera_.offset = {width * 0.5f, height * 0.5f};
  camera_.rotation = 0.0f;
}

void CameraController::SetZoomStrategy(std::unique_ptr<IZoomStrategy> zs) {
  zoomStrategy_ = std::move(zs);
}

void CameraController::Update() {
  HandlePan();
  zoomStrategy_->ApplyZoom(camera_);
}

Camera2D& CameraController::GetCamera() { return camera_; }

void CameraController::HandlePan() {
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    Vector2 delta = Vector2Scale(GetMouseDelta(), -1.0f / camera_.zoom);
    camera_.target = Vector2Add(camera_.target, delta);
  }
}