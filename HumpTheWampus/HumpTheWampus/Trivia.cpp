// Copyright (C) FrankZ. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct TriviaQuiz
{
	string quiz;
	int correct_answer;
};

vector<TriviaQuiz> Quiz;
size_t current_qusetion = 0;

namespace Trivia
{

	void Init()
	{
		TriviaQuiz quiz;
		quiz.quiz = "Is Microsoft company founded in 1975?\n";
		quiz.correct_answer = 'y';
		Quiz.push_back(quiz);

		quiz.quiz = "Is Microsoft current CEO Bill Gates?\n";
		quiz.correct_answer = 'n';
		Quiz.push_back(quiz);

		quiz.quiz = "Is Seattle the capital of Washington state?\n";
		quiz.correct_answer = 'n';
		Quiz.push_back(quiz);
	}

	void DisplayNextQuiz()
	{
		if (Quiz.size() == 0) {
			printf("No questions found!\n");
		}
		else {
			current_qusetion = rand() % Quiz.size();
			printf(Quiz[current_qusetion].quiz.c_str());
		}
	}

	bool IsAnswerToCurrentQuizCorrect(char answer)
	{
		if (Quiz[current_qusetion].correct_answer == answer) {
			printf("Your answer is correct!\n");
			return true;
		}
		else {
			printf("Wrong answer!\n");
			return false;
		}
	}

} // namespace Trivia