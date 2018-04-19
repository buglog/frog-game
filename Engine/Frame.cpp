#include "Frame.h"

void Frame::init(int setx, int sety, int setWidth, int setHeight)
{
	x = setx;
	y = sety;
	width = setWidth;
	height = setHeight;
}

void Frame::offset(Frog & frog)
{
	frog.x = frog.x + x;
	frog.y = frog.y + y;
}

void Frame::offset(World::Wall & wall)
{
	wall.x0 = wall.x0 + x;
	wall.x1 = wall.x1 + x;
	wall.y0 = wall.y0 + y;
	wall.y1 = wall.y1 + y;
}

void Frame::offset(World::Spike & spike)
{
	spike.x += x;
	spike.y += y;
}

void Frame::clamp(Frog & frog)
{	
	//bottom
	if (frog.y + frog.height >= height)
	{
		frog.y = height - frog.height;
		frog.vy = 0;
		frog.onGround = true;
	}
	//left
	if (frog.x <= x - 5)
	{
		frog.x = x - 5;
		frog.vx = 0;
	}
	//right
	if (frog.x + frog.width >= width + 5)
	{
		frog.x = width + 5 - frog.width;
		frog.vx = 0;
	}
	//top
	if (frog.y <= y)
	{
		frog.y = y;
		frog.vy = 0;
	}
}

void Frame::draw(int spacing, Color c, Graphics & gfx)
{
	gfx.Rectangle(0, 0, x, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.Rectangle(0, 0, gfx.ScreenWidth - 1, y, 1, Colors::Black);
	gfx.Rectangle(width, 0, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.Rectangle(0, height, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.HorizontalLine(x, width, y, spacing, c);
	gfx.HorizontalLine(x, width, height, spacing, c);
	gfx.VerticalLine(y, height, x, spacing, c);
	gfx.VerticalLine(y, height, width, spacing, c);
}


