// #pragma once
#ifndef HUNT_THE_WUMPUS_GAME_LOCATIONS_H_
#define HUNT_THE_WUMPUS_GAME_LOCATIONS_H_

// make sure they are bigger than 3
#define MAX_ROOM_X 9
#define MAX_ROOM_Y 9

#define MIN_ROOM_X 3
#define MIN_ROOM_Y 3

struct MapObject
{
	bool	show; // true will show the objec; false will hide the object
	char	icon;
	int		room_x;
	int		room_y;
};

class GameLocations
{
public:
	GameLocations();
	~GameLocations();

	bool IsPlayerAndWumpusInTheSameRoom();
	void ToggleCheatMode();
		
	int GetMapX() const;
	int GetMapY() const;

	bool ReInit(char size);
	bool ReInit(void);

	void Player_MoveLeft();
	void Player_MoveRight();
	void Player_MoveUp();
	void Player_MoveDown();

	MapObject m_Player;
	MapObject m_Wumpus;

private:
	bool Init(int x, int y);

	int map_x;
	int map_y;
};

#endif  // HUNT_THE_WUMPUS_GAME_LOCATIONS_H_