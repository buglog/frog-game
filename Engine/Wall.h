#pragma once
#include "Vampire.h"

// IMPORTANT NOTE:
// i decided having all the world objects in the same file is actually a dumb idea. When i have free time i am going to remake Wall.h and Spike.h.
// What i forgot was that i can put files into folders if I want to. If the world objects get to be too many, just stick em in a folder.
// it way easier than scrolling down an endless list of subclasses.


	class Wall
	{
		//pass frog by ref: wall0.block(frog);
		//and then draw over top. wall.draw(gfx);
		//easy right?
		//also, if drawing onto a frame, pass wall through frame.offset(wall);
	public:
		void init(int setx0, int sety0, int setx1, int sety1, Color setc, int setSpacing);
		void block(Vampire& vamp);
		void draw(Graphics& gfx);
	public:
		int x0 = 0;
		int y0 = 0;
		int x1 = 0;
		int y1 = 0;
		//rangeY checks if the frog is over or under the box.
		//the box can only block the frog on one axis at a time to avoid corner issues and the frog entering the box.
		bool rangeY = true;
		int spacing = 0;
		Color c;
	};

