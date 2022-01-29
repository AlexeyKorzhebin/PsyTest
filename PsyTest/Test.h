#pragma once

#include "Question.h"

class TestModel
{
	Questions m_questions;
	std::wstring m_name;
	std::wstring m_results_desc;

	friend class FileTestFactory;

public:
	TestModel(){}

	QuestionsCIter getStart() const { return m_questions.begin(); }
	QuestionsCIter getEnd() const { return m_questions.end(); }

	auto getGreeting() const { return m_name; }
	auto getResultsDesc() const { return m_results_desc; }

};

typedef std::shared_ptr<TestModel> TestModelPtr;
