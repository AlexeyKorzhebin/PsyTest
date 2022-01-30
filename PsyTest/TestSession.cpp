#include "pch.h"
#include "TestSession.h"

void TestSession::Run()
{
	std::wcout <<  m_model->getGreeting() << std::endl;

	std::wcout <<  L"����������� ������� \"exit\" ��� ������ q ��� ���������� ������ " << std::endl;
	std::wcout <<  L"����������� ������� \"restart\" ��� ������ r ��� ������� ����� � ������ " << std::endl;
	std::wcout <<  L"������� ������ Enter ��� ������ �����" << std::endl;

	/*wchar_t key;
	std::wcin.get(key);
	*/
	std::wstring wline;
	std::getline(std::wcin, wline, L'\n');

	bool b_restart = false;

	for (m_curQuestion = m_model->getStart(); m_curQuestion != m_model->getEnd(); m_curQuestion++)
	{
		if (b_restart == true)
		{
			m_curQuestion = m_model->getStart();
			b_restart = false;
		}

		int count = 1;
		std::wcout << m_curQuestion->getText() << std::endl;

		auto answers = m_curQuestion->getAnswers();
		for (auto k : answers)
		{
			std::wcout << count++ << L") " << k.text << std::endl;
		}

		bool b_mistake = true;
		do {
			int ans_score = 0;

			std::getline(std::wcin, wline, L'\n');
			
			if (wline == L"exit" || wline == L"q")
				return;
			
			if (wline == L"restart" || wline == L"r")
			{
				b_restart = true;
				m_score = 0;
				break;
			}


			ans_score = _wtoi(wline.c_str());

			// validate input data 
			// make index to correct answer for the vector
			ans_score--;
			if (ans_score >= 0 && ans_score < static_cast<int>(answers.size()))
			{
				m_score += answers.at(ans_score).score;
				b_mistake = false;
			}
			else
			{
				std::wcout << L"������ �� ������������ �����: " << ans_score + 1 << std::endl;
				std::wcout << L"���������� ������� ����������: " << std::endl;
			}

		} while (b_mistake);

	}

	std::wcout <<  m_model->getResultsDesc() << std::endl;
	std::wcout << L"���� ���������� ������: " << m_score << std::endl;
	std::wcout << L"������� ������ Enter ��� ������ �� ���������" << std::endl;
	std::getline(std::wcin, wline, L'\n');
}
