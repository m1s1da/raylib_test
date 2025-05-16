#pragma once

#include "CameraController.h"
#include "SceneRenderer.h"
#include "UIRenderer.h"

class CameraApp {
 public:
  CameraApp(const int& width, const int& height);
  ~CameraApp();
  void Run();

 private:
  void ProcessInput();
  void Draw();

 private:
  int zoomMode_ = 0;
  std::unique_ptr<CameraController> controller_;
  SceneRenderer sceneRenderer_;
  UIRenderer uiRenderer_;
  int width;
  int height;
};