#include "SceneRenderer.h"

#include "rlgl.h"

void SceneRenderer::Render(const Camera2D& camera, const int& width,
                           const int& height) {
  BeginMode2D(camera);

  // Рисуем 3D-сетку, повернутую в XY-плоскость (оригинальная логика)
  rlPushMatrix();
  rlTranslatef(0.0f, 25 * 50.0f, 0.0f);
  rlRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  DrawGrid(100, 50);
  rlPopMatrix();

  // Справочная окружность в центре экрана
  DrawCircle(width / 2, height / 2, 50, MAROON);

  EndMode2D();
}