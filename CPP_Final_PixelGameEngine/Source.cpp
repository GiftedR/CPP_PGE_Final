#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Objects/Object.h"

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
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(clearClr);
		return true;
	}
protected:
	olc::Pixel clearClr = olc::Pixel(0.3f, 0.9f, 0.3f);
private:
};

int main()
{
	mainGame demo("Testgame");
	if (demo.Construct(640, 360, 1, 1))
		demo.Start();
	return 0;
}