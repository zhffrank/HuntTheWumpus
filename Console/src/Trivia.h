// Copyright (C) FrankZ. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HUNT_THE_WUMPUS_TRIVIA_H_
#define HUNT_THE_WUMPUS_TRIVIA_H_

namespace Trivia
{
	// need to call Init before we can use Trivia service
	void Init();

	bool IsAnswerToCurrentQuizCorrect(char answer);
	void DisplayNextQuiz();
} // namespace Trivia

#endif // HUNT_THE_WUMPUS_TRIVIA_H_