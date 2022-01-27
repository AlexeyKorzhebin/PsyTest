#pragma once
#include <string>

struct Answer
{
	std::wstring text;
	int score;

	Answer():text(L""), score(0) {}
	Answer(std::wstring rh_text, int rh_score) :text(L""), score(0) {}
	Answer(const Answer& rh) :text(rh.text), score(rh.score) {}
};

typedef std::vector<Answer> Answers;

class Question
{
	std::wstring text;
	Answers answers;

public:
	
	Question():text(L""){}
	Question(std::wstring rh_text, Answers rh_answers):text(L""), answers(rh_answers){}
	Question(const Question& rh):text(rh.text), answers(rh.answers){}

	const std::wstring& getText() const { return text; }
	const Answers& getAnswers() const { return answers; }

};

