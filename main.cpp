#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{
   const int windowWidth{480};
   const int windowheight{480};

   InitWindow(windowWidth, windowheight, "Malcolm's top-Down!");

   Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
   Vector2 mapPos{0.0, 0.0};

   const float mapScale{4.0f};

   Character knight{windowWidth, windowheight};

   Prop props[2]{
       Prop{Vector2{600.0f, 300.0f}, LoadTexture("nature_tileset/Rock.png")},
       Prop{Vector2{400.0f, 500.0f}, LoadTexture("nature_tileset/Log.png")}

       // held
   };

   Enemy goblin{
       Vector2{},
       LoadTexture("characters/goblin_idle_spritesheet.png"),
       LoadTexture("characters/goblin_run_spritesheet.png")

       // held
   };

   goblin.setTarget(&knight);

   SetTargetFPS(60);
   while (!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(WHITE);

      mapPos = Vector2Scale(knight.getWorldPos(), -1.0f);

      // Draw the map
      DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

      for (auto prop : props)
      {
         prop.Render(knight.getWorldPos());
      }

      knight.tick(GetFrameTime());
      // Check map bounds
      if (knight.getWorldPos().x < 0.0f ||
          knight.getWorldPos().y < 0.0f ||
          knight.getWorldPos().x + windowWidth > map.width * mapScale ||
          knight.getWorldPos().y + windowheight > map.height * mapScale)
      {
         knight.undoMovement();
      }

      // Check prop collisions
      for (auto prop : props)
      {
         if (CheckCollisionRecs(prop.GetCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
         {
            knight.undoMovement();
         }
      }

      goblin.tick(GetFrameTime());

      EndDrawing();
   }

   CloseWindow();

   return 0;
}