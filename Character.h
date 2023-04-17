#include "raylib.h"

class Character
{

public:
   Character(int winWidth, int winHeight);
   Vector2 getWorldPos() { return this->worldPos; }
   void tick(float deltaTime);
   void undoMovement();

private:
   Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
   Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
   Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
   Vector2 screenPos{};
   Vector2 worldPos{};
   Vector2 worldPosLastFrame{};
   float rightLeft{1.0f};
   float runningTime{0};
   int frame{0};
   int maxFrames{6};
   float updateTime{1.0f / 12.0f};
   float speed{4.0f};
   float width{};
   float height{};
   float scale{4.0f};
};