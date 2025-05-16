#include "CameraApp.h"

static constexpr int SCREEN_WIDTH = 800;
static constexpr int SCREEN_HEIGHT = 450;

int main() {
  CameraApp app(SCREEN_WIDTH, SCREEN_HEIGHT);
  app.Run();
  return 0;
}