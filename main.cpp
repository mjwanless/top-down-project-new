#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
	const int windowWidth{480};
	const int windowheight{480};

	InitWindow(windowWidth, windowheight, "Malcolm's top-Down!");

	Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
	Vector2 mapPos{0.0, 0.0};

	const float mapScale{4.0f};

	Character knight{windowWidth, windowheight};

	Prop rock{Vector2{0.0f, 0.0f}, LoadTexture("nature_tileset/Rock.png")};

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.0f);

		// Draw the map
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
		rock.Render(knight.getWorldPos());
		knight.tick(GetFrameTime());

		// Check map bounds
		if (knight.getWorldPos().x < 0.0f ||
			 knight.getWorldPos().y < 0.0f ||
			 knight.getWorldPos().x + windowWidth > map.width * mapScale ||
			 knight.getWorldPos().y + windowheight > map.height * mapScale)
		{
			knight.undoMovement();
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}