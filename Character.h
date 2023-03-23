#include "raylib.h"

class Character
{

public:
   Character();
   Vector2 getWorldPos() { return this->worldPos; }
   void setScreenPos(int winWidth, int winHeight);
   void tick(float deltaTime);

private:
   Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
   Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
   Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
   Vector2 screenPos{0};
   Vector2 worldPos{0};
   float rightLeft{1.0f};
   float runningTime{0};
   int frame{0};
   int maxFrames{6};
   float updateTime{1.0f / 12.0f};
   float speed{4.0f};
   float width{};
   float height{};
};