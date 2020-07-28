// Copyright (C) FrankZ. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <stdio.h>
#include <iostream>

#include "Graphics.h"
#include "Trivia.h"


namespace GameController
{

	bool ShouldExitGame(int command)
	{
		if (command == 'x')
			return true;

		return false;
	}

	void ClearInputBuffer()
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}
	}

	int GetUserInput()
	{
		int command = getchar();
		ClearInputBuffer();
		return command;
	}

	void DisplayGameMenu()
	{
		printf("n : new game\n");
		printf("t : toggle cheat mode\n");
		printf("i : move Up\n");
		printf("k : move Down\n");
		printf("j : move Left\n");
		printf("l : move Right\n");
		printf("x : Exit Game\n");
	}

	bool IsKilledWumpus() {
		printf("You have to answer correctly to win the game\n");
		printf("Question:\n");
		Trivia::DisplayNextQuiz();
		printf("press 'y' for Yes; 'n' for No\n");
		int command = GetUserInput();
		return Trivia::IsAnswerToCurrentQuizCorrect(command);
	}

	void HandleMoveCommands(GameLocations& info, int& command)
	{
		switch (command)
		{
		case 'j':
			info.Player_MoveLeft();
			break;
		case 'i':
			info.Player_MoveUp();
			break;
		case 'k':
			info.Player_MoveDown();
			break;
		case 'l':
			info.Player_MoveRight();
			break;
		}
	}

	void ToggleCheatMode(GameLocations& info) {
		info.ToggleCheatMode();
	}

	void NewGame(GameLocations& info) {
		int size;
		do {
			printf("please input map size(3-9): ");
			size = GetUserInput();
		} while (!info.ReInit(size));
	}


	bool IsGameEnded(GameLocations& info)
	{
		bool GameEnded = false;
		if (info.IsPlayerAndWumpusInTheSameRoom()) {
			printf("You found the Wumpus!\n");

			if (IsKilledWumpus()) {
				printf("Congraduations! You won the game!!\n");
			}
			else {
				printf("Sorry! You lose :-(\n");
			}
			printf("Game Over!\n");
			GameEnded = true;
		}

		return GameEnded;
	}

	// player move commands
	// j - toggle cheat mode
	// j - left
	// i - up
	// k - down
	// l - right
	void HandleCommands(GameLocations& info, int& command)
	{
		switch (command)
		{
		case 'j':
		case 'i':
		case 'k':
		case 'l':
		{
			HandleMoveCommands(info, command);
			if (IsGameEnded(info))
				info.ReInit();
		}
		break;
		case 't':
			ToggleCheatMode(info);
			break;
		case 'n':
			NewGame(info);
			break;
		}

		return;
	}

	void Main()
	{
		Trivia::Init();
		GameLocations game_map;
		int command;
		do {
			Graphics::DisplayGameMap(game_map);
			DisplayGameMenu();
			command = GetUserInput();
			HandleCommands(game_map, command);
		} while (!ShouldExitGame(command));
	}
} // namespace GameController