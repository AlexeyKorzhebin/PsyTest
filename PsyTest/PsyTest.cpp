
#include "pch.h"
#include <iostream>
#include "Question.h"
#include "TestSession.h"
#include "Test.h"

#include <sstream>
#include <fstream>
#include <codecvt>
#include "FileTestFactory.h"
//#include <Windows.h>
#include <locale>

int main()
{
	std::locale::global(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	setlocale(LC_ALL, "");
	std::wcin.imbue(std::locale(".866"));

	ITestFactory* p = nullptr;
	try {
		// creating a factory object which works with text files 
		auto p = std::static_pointer_cast<ITestFactory>(std::make_shared<FileTestFactory>());
		// loading a model instance from a factory object filled with tests
		auto test_model = p->Create(L"quiz.txt");

		// Creating a test session
		TestSession session(test_model);
		// Launching the quiz
		session.Run();

	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

