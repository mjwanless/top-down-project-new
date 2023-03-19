#include "raylib.h"

int main()
{
   const int windowWidth{384};
   const int windowheight{384};

   InitWindow(windowWidth, windowheight, "Malcolm's top-Down!");

   Texture2D map = LoadTexture("nature_tileset/WorldMap.png");

   SetTargetFPS(60);

   while (!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(WHITE);

      Vector2 mapPos{0.0, 0.0};
      DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

      EndDrawing();
   }

   CloseWindow();

   return 0;
}