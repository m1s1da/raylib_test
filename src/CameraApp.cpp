#include "CameraApp.h"

#include <memory>

#include "MouseDragZoom.h"
#include "MouseWheelZoom.h"
#include "raylib.h"

CameraApp::CameraApp(const int& width, const int& height)
    : width(width), height(height) {
  InitWindow(width, height,
             "raylib [core] example - 2d camera mouse zoom (SOLID)");
  SetTargetFPS(60);
  controller_ = std::make_unique<CameraController>(
      std::make_unique<MouseWheelZoom>(), width, height);
}

CameraApp::~CameraApp() { CloseWindow(); }

void CameraApp::Run() {
  while (!WindowShouldClose()) {
    ProcessInput();
    controller_->Update();
    Draw();
  }
}

void CameraApp::ProcessInput() {
  if (IsKeyPressed(KEY_ONE)) {
    zoomMode_ = 0;
    controller_->SetZoomStrategy(std::make_unique<MouseWheelZoom>());
  } else if (IsKeyPressed(KEY_TWO)) {
    zoomMode_ = 1;
    controller_->SetZoomStrategy(std::make_unique<MouseDragZoom>());
  }
}

void CameraApp::Draw() {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  sceneRenderer_.Render(controller_->GetCamera(), width, height);
  uiRenderer_.Render(zoomMode_);

  EndDrawing();
}
