
#include "pch.h"
#include <iostream>
#include "Question.h"
#include "TestSession.h"
#include "Test.h"

#include <sstream>
#include <fstream>
#include <codecvt>


int main()
{
	std::locale::global(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	//std::locale(std::locale::empty(), new std::codecvt<char16_t, wchar_t, std::mbstate_t>);
	//SetConsoleOutputCP(CP_UTF8);

	Test test;
	try {
		test.Load("quiz.txt");
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

