#pragma once

struct Answer
{
	std::wstring text;
	int score;

	Answer():text(L""), score(0) {}
	Answer(std::wstring rh_text, int rh_score) :text(rh_text), score(rh_score) {}
	Answer(const Answer& rh) :text(rh.text), score(rh.score) {}
};

typedef std::vector<Answer> Answers;

class Question
{
	std::wstring text;
	Answers answers;

public:
	
	Question():text(L""){}
	Question(std::wstring rh_text, Answers rh_answers, int rh_id):text(L""), answers(rh_answers){}
	Question(const Question& rh):text(rh.text), answers(rh.answers) {}

	const std::wstring& getText() const { return text; }
	const Answers& getAnswers() const { return answers; }

	void setText(std::wstring& t) { text = t; }
	void addAnswer(const Answer& ans) 
	{
		answers.push_back(ans); 
	}

};

typedef std::vector<Question> Questions;
typedef Questions::iterator  QuestionsIter;
typedef Questions::const_iterator  QuestionsCIter;