#define OLC_PGE_APPLICATION
#include "Objects/ObjectTypes.h"

using namespace olc;

// Override base class with your custom functionality
class mainGame : public PixelGameEngine
{
public:
	mainGame(std::string title)
	{
		// Name your application
		sAppName = title;
	}

public:
	void checkUserInput(Player& usr, float delta) {
		if (GetKey(Key::W).bHeld) { usr.movePosition(Vector2i(0, -1 * usr.getspeed() * delta )); }
		if (GetKey(Key::S).bHeld) { usr.movePosition(Vector2i(0, 1 * usr.getspeed() * delta)); }
		if (GetKey(Key::D).bHeld) { usr.movePosition(Vector2i(1 * usr.getspeed() * delta, 0)); }
		if (GetKey(Key::A).bHeld) { usr.movePosition(Vector2i(-1 * usr.getspeed() * delta, 0)); }
	}

	bool OnUserCreate() override
	{
		worldTiles = std::make_unique<int[]>(16 * 16);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		fAccumulatedTime += fElapsedTime;
		if (fAccumulatedTime >= fTargetFrameTime)
		{
			fAccumulatedTime -= fTargetFrameTime;
			fElapsedTime = fTargetFrameTime;
		}
		else {
			return true;
		}
		Clear(BLACK);
		
		checkUserInput(user, fElapsedTime);
		sprTile = std::make_unique<olc::Sprite>(user.getSkin());
		DrawSprite(user.getPosition().x, user.getPosition().y, sprTile.get(), 1);
		
		return true;
	}
private:
	olc::Pixel clearClr = olc::Pixel(0.3f, 0.9f, 0.3f);
	Player user;
	std::vector<Object> gameItems = { user };

	Vector2i wTileSize = { 16, 16 };
	std::unique_ptr<int[]> worldTiles;

	std::unique_ptr<olc::Sprite> sprTile; 
	float fTargetFrameTime = 1.0f / 165.0f; // Virtual FPS of 165fps
	float fAccumulatedTime = 0.0f;
};

int main()
{
	mainGame demo("Testgame");
	if (demo.Construct(640, 360, 2, 2, false, false))
		demo.Start();
	return 0;
}