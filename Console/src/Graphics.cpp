// Copyright (C) FrankZ. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <iostream>

#include "GameLocations.h"


namespace Graphics
{
	// room coordinations
	// room 1,1 | 2,1 | 3,1 | 4,1
	// room 1,2 | 2,2 | 3,2 | 4,2
	// room 1,3 | 2,3 | 3,3 | 4,3
	// room 1,4 | 2,4 | 3,4 | 4,4
	// printf("=================================\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("=================================\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("=================================\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("=================================\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("|       |       |       |       |\n");
	// printf("=================================\n");

	void display_rooms_in_row(int row, const GameLocations& info)
	{
		for (int x = 1; x <= info.GetMapX(); x++)
			printf("========");
		printf("=\n");

		for (int x = 1; x <= info.GetMapX(); x++)
			printf("|       ");
		printf("|\n");

		// 	printf("|   %c    |   %c    |   %c    |   %c    |\n");
		for (int x = 1; x <= info.GetMapX(); x++) {
			char object = ' ';
			if (x == info.m_Player.room_x && row == info.m_Player.room_y) {
				if (info.m_Player.show)
					object = info.m_Player.icon;
			}
			else if (x == info.m_Wumpus.room_x && row == info.m_Wumpus.room_y) {
				if (info.m_Wumpus.show)
					object = info.m_Wumpus.icon;
			}
			printf("|   %c   ", object);
		}
		printf("|\n");

		for (int x = 1; x <= info.GetMapX(); x++)
			printf("|       ");
		printf("|\n");
	}

	void display_rooms(const GameLocations& info)
	{
		for (int y = 1; y <= info.GetMapY(); y++) {
			// the row
			display_rooms_in_row(y, info);
		}

		for (int x = 1; x <= info.GetMapX(); x++)
			printf("========");
		printf("=\n");
	}

	void DisplayGameMap(const GameLocations& info)
	{
		display_rooms(info);
	}
} // namespace Graphics