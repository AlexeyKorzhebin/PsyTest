#include "pch.h"
#include "TestSession.h"

void TestSession::Run()
{
	std::wcout <<  m_model->getGreeting() << std::endl;
	std::wcout <<  m_model->getResultsDesc() << std::endl;

	for (QuestionsCIter i = m_model->getStart(); i != m_model->getEnd(); i++)
	{
		int count = 1;
		std::wcout << i->getText().c_str() << std::endl;
		for (auto k : i->getAnswers())
		{
			std::wcout << count << L") " << k.text.c_str() << std::endl;
		}

	}
}

void TestSession::Greeting()
{

}

void TestSession::TestDraw()
{

}

void TestSession::Result()
{

}

