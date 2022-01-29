#pragma once
#include "Test.h"

class TestSession
{
	TestModelPtr m_model;
	QuestionsCIter m_curQuestion;
	int score;


	// TestSeesion can't be created using the default constructor
	TestSession() :m_model(), m_curQuestion(), score(0) {}

	void Greeting();
	void TestDraw();
	void Result();

public:
	TestSession(TestModelPtr p):m_model(p), m_curQuestion(m_model->getStart()), score(0){}

	void Run();
};

