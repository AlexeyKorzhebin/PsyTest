#pragma once
#include "Test.h"

class TestSession
{
	TestModelPtr m_model;
	QuestionsCIter m_curQuestion;
	int m_score;


	// TestSeesion can't be created using the default constructor
	TestSession() :m_model(), m_curQuestion(), m_score(0) {}

public:
	TestSession(TestModelPtr p):m_model(p), m_curQuestion(m_model->getStart()), m_score(0){}

	void Run();
};

