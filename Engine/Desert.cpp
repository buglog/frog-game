#include "Desert.h"

Desert::Desert()
{
	frame.init(200, 20, 780, 580);
	c0.init(300, 250, 0);
	c1.init(400, 420, 1);
	c2.init(660, 40, 0);
	c3.init(230, 370, 2);
	c4.init(600, 450, 2);
	c5.init(690, 340, 0);
}

void Desert::process(Vampire & vamp, Graphics& gfx, Instructions& inst, Message& msg)
{
	//set e_message at the start of every frame. this way, it will have a default and only change when processed (soon, by Saloon.h and Graveyard.h)
	inst.e_message = inst.enter;
	drawSand(gfx);
	placeCactuses(vamp, gfx, inst,msg);
	frame.clamp(vamp);
	cframe.SetR(255);
	cframe.SetG(0);
	cframe.SetB(0);
	frame.draw(1, cframe, gfx);
}

void Desert::spawn(int x, int y, Vampire & vamp)
{
	vamp.x = float(x);
	vamp.y = float(y);
}

void Desert::drawSand(Graphics & gfx)
{
	// draws sand
	csand.SetR(150);
	csand.SetG(100);
	csand.SetB(70);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 1, csand);
	csand.SetR(255);
	csand.SetG(50);
	csand.SetB(30);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 5, csand);
	csand.SetR(100);
	csand.SetG(200);
	csand.SetB(50);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 12, csand);
	csand.SetR(255);
	csand.SetG(220);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 24, csand);
	//draw vignette
	//csand.SetR(0);
	//csand.SetG(0);
	//csand.SetB(255);
	//gfx.Rectangle(frame.x, frame.y, frame.width,frame.y + 100,4,csand);
}

void Desert::placeCactuses(Vampire & vamp, Graphics& gfx, Instructions& inst, Message& msg)
{
	c0.place(gfx, vamp, inst, msg);
	c1.place(gfx, vamp, inst, msg);
	c2.place(gfx, vamp, inst, msg);
	c3.place(gfx, vamp, inst, msg);
	c4.place(gfx, vamp, inst, msg);
	c5.place(gfx, vamp, inst, msg);
}

