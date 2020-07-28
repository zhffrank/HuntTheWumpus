// Copyright (C) FrankZ. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <stdlib.h>

#include "GameLocations.h"

void GameLocations::Player_MoveLeft() {
	if (m_Player.room_x > 1) {
		m_Player.room_x = m_Player.room_x - 1;
	}
}

void GameLocations::Player_MoveRight() {
	if (m_Player.room_x < map_x) {
		m_Player.room_x = m_Player.room_x + 1;
	}
}

void GameLocations::Player_MoveUp() {
	if (m_Player.room_y > 1) {
		m_Player.room_y = m_Player.room_y - 1;
	}
}

void GameLocations::Player_MoveDown() {
	if (m_Player.room_y < map_y) {
		m_Player.room_y = m_Player.room_y + 1;
	}
}

GameLocations::GameLocations() {
	// default minimum map size
	Init(MIN_ROOM_X, MIN_ROOM_Y);
}

GameLocations::~GameLocations() {};

bool GameLocations::Init(int x, int y) {
	// invalid map size
	if (x < MIN_ROOM_X || x > MAX_ROOM_X || y < MIN_ROOM_Y || y > MAX_ROOM_Y)
		return false;

	map_x = x;
	map_y = y;

	// initial values for game player
	m_Player.show = true;
	m_Player.room_x = 1;
	m_Player.room_y = 1;
	m_Player.icon = 'p'; // stand for Player

	// initial values for wumpus
	// ramdomized to assign room to wumpus
	m_Wumpus.show = false; // should be false by default
	m_Wumpus.room_x = rand() % map_x + 1;
	m_Wumpus.room_y = rand() % map_y + 1;

	// if wumpus happened to be assigned to room(1,1)
	// we move it to room(2,2) so that it won't be in the same room as the player at the beginning
	if (m_Wumpus.room_x == 1 && m_Wumpus.room_y == 1) {
		m_Wumpus.room_x++;
		m_Wumpus.room_y++;
	}
	m_Wumpus.icon = 'w'; // stand for Wumpus
	return true;
};

// this is called from user input
// should check 
bool GameLocations::ReInit(char size) {
	int map_size = size - '0';
	return Init(map_size, map_size);
}

// use exising map size to reinit
bool GameLocations::ReInit(void) {
	return Init(map_x, map_y);
}

bool GameLocations::IsPlayerAndWumpusInTheSameRoom() {
	if ((m_Player.room_x == m_Wumpus.room_x) && (m_Player.room_y == m_Wumpus.room_y))
		return true;
	else
		return false;
}

void GameLocations::ToggleCheatMode() {
	m_Wumpus.show = !m_Wumpus.show;
}

int GameLocations::GetMapX() const {
	return map_x;
}

int GameLocations::GetMapY() const {
	return map_y;
};