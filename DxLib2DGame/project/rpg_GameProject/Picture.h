#pragma once
/* Picture.h */
class PICTURE
{
public:
	
	int Player[12];
	int Player_sprite;

	void Load()
	{
		LoadDivGraph("img/adventurer01-09.png", 12, 3, 4, 32, 48, Player);
	};

private:
	
};

PICTURE Picture;