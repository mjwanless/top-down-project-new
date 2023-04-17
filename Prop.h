#include "raylib.h"

class Prop
{
public:
   Prop(Vector2 pos, Texture2D tex);
   void Render(Vector2 knightPos);
   Rectangle GetCollisionRec(Vector2 knightPos);

private:
   float scale{4.0f};
   Vector2 worldPos{};
   Texture2D texture{};
};