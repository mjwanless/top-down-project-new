#include "raylib.h"
#include "raymath.h"

class Character
{
private:
	Texture2D texture;
	Texture2D idle;
	Texture2D run;
	Vector2 screenPos{};
	Vector2 worldPos{};
	float rightLeft{1.0f};
	float runningTime{0};
	int frame{0};
	const int maxFrames{6};
	const float updateTime{1.0f / 12.0f};

public:
	Vector2 getWorldPos() { return this->worldPos; }
};

int main()
{
	const int windowWidth{480};
	const int windowheight{480};

	InitWindow(windowWidth, windowheight, "Malcolm's top-Down!");

	Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
	Vector2 mapPos{0.0, 0.0};
	float speed{4.0};

	Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
	Vector2 knightPos{
		 (windowWidth / 2.0f) - 4.0f * (0.5f * (float)knight.width / 6.0f),
		 (windowheight / 2.0f) - 4.0f * (0.5f * (float)knight.height)
		 // Buffer
	};

	Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
	Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		Vector2 direction{};

		if (IsKeyDown(KEY_A))
		{
			direction.x -= 1.0;
		}

		if (IsKeyDown(KEY_D))
		{
			direction.x += 1.0;
		}

		if (IsKeyDown(KEY_W))
		{
			direction.y -= 1.0;
		}

		if (IsKeyDown(KEY_S))
		{
			direction.y += 1.0;
		}

		if (Vector2Length(direction) != 0.0)
		{
			// set mapPos -= direction
			mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
			direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
			knight = knight_run;
			// buffer
		}
		else
		{
			knight = knight_idle;
		}

		// Draw the map
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

		// update animation frame

		runningTime += GetFrameTime();

		if (runningTime >= updateTime)
		{
			frame++;
			runningTime = 0.0f;
			if (frame > maxFrames)
			{
				frame = 0;
			}
		}

		// Draw the character
		Rectangle source{frame * ((float)knight.width / 6.0f), 0.0f, rightLeft * ((float)knight.width / 6.0f), rightLeft * (float)knight.height};
		Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width / 6.0f, 4.0f * (float)knight.height};
		DrawTexturePro(knight, source, dest, Vector2{}, 0.0f, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}