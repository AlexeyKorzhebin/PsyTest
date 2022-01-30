#include "pch.h"
#include "TestSession.h"

void TestSession::Run()
{
	std::wcout <<  m_model->getGreeting() << std::endl;
	std::wcout <<  L"Нажмите кнопку Enter для начала теста" << std::endl;

	wchar_t key;
	std::wcin.get(key);

	for (m_curQuestion = m_model->getStart(); m_curQuestion != m_model->getEnd(); m_curQuestion++)
	{
		int count = 1;
		std::wcout << m_curQuestion->getText() << std::endl;

		auto answers = m_curQuestion->getAnswers();
		for (auto k : answers)
		{
			std::wcout << count++ << L") " << k.text.c_str() << std::endl;
		}

		bool b_mistake = true;
		do {
			size_t ans_score = 0;
			std::wcin >> ans_score;

			// validate input data 
			// make index to correct answer for the vector
			ans_score--;
			if (ans_score >= 0 && ans_score < answers.size())
			{
				m_score += answers.at(ans_score).score;
				b_mistake = false;
			}
			else
			{
				std::wcout << L"Выбран не существующий ответ: " << ans_score << std::endl;
				std::wcout << L"Пожалуйста введите правильный: " << std::endl;
			}

		} while (b_mistake);

	}

	std::wcout <<  m_model->getResultsDesc() << std::endl;
	std::wcout << L"Ваше количество баллов: " << m_score << std::endl;
	std::wcout << L"Нажмите кнопку Enter для выхода из программы" << std::endl;

}
