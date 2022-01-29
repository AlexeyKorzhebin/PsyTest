#include "pch.h"
#include "FileTestFactory.h"
#include <vector>
#include "Question.h"
#include "Test.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::wstring> split(const std::wstring& input, const wchar_t& delimiter) {

	std::vector<std::wstring> elements;
	std::wstringstream stream(input);
	std::wstring element;

	while (std::getline(stream, element, delimiter))
	{
		elements.push_back(element);
	}

	return elements;

}

std::wstring trim(std::wstring str)
{
	const wchar_t* whitespace_type = L" ";
	str.erase(str.find_last_not_of(whitespace_type) + 1);
	str.erase(0, str.find_first_not_of(whitespace_type));
	return str;
}

auto getInt(std::wstring str)
{
	int i;
	std::wstringstream trim_string;
	trim_string << str;
	str.clear();
	trim_string >> i;
	return i;
}



// loading multiline context from  pair of tags
std::wstring loadTag(std::wistream& is, const std::wstring& closing_tag)
{
	std::wstring wline;
	std::wstring res;
	while (is.good())
	{
		// read string
		std::getline(is, wline, L'\n');
		// if string doesn't contain the closing tag
		if (wline.find(closing_tag) == std::wstring::npos)
		{
			// add string to the buffer
			res += wline +L'\n';
		}
		else
		{
			// if we found the closing tag then break and return a result
			break;
		}
	}

	return res;
}

Question loadQuestion(std::wistream& is)
{
	std::wstring wline;
	Question question;
	while (is.good())
	{
		// read string
		std::getline(is, wline, L'\n');
		// if string doesn't contain the closing tag
		if (wline.find(L"</question>") == std::wstring::npos)
		{
			if (wline.find(L"<t>") != std::wstring::npos)
			{
				auto b = split(wline, L'>');
				if (b.size() != 2)
					throw std::exception("Can't split this text string in question:");

				auto t = b.at(1);
				question.setText(t);
			}
			else if (wline.find(L"<a>") != std::wstring::npos)
			{
				auto b = split(wline, L'>');

				if (b.size() != 2)
					throw std::exception("Can't split this answer string 1 in question:");

				auto b1 = split(b.at(1), L'%');

				if (b1.size() != 2)
					throw std::exception("Can't split this answer string 2 in question:");

				auto a = trim(b1.at(0));
				auto sc = getInt(b1.at(1));
				question.addAnswer(Answer(a, sc));
			}
		}
		else
		{
			// if we found the closing tag then break and return a result
			break;
		}
	}

	return question;
}


// param is a filename
std::shared_ptr<TestModel> FileTestFactory::Create(std::wstring param)
{
	std::wifstream ifs(param.c_str());

	if (ifs.is_open())
	{
		return Load(ifs);
	}
	else
	{
		throw std::exception("Can't open file with tests");
	}

	// return default value
	return std::make_shared<TestModel>();
}

std::shared_ptr<TestModel> FileTestFactory::Load(std::wistream& is)
{
	std::wstring wline;
	std::getline(is, wline, L'\n');

	auto quiz = std::make_shared<TestModel>();

	// check the file format. 
	if (wline.find(L"<quiz>") == std::wstring::npos)
		throw std::exception("Non correct file format");

	// pasing file until the closing tag "</quiz>" will be found
	do
	{
		std::getline(is, wline, L'\n');
		if (wline.find(L"<name>") != std::wstring::npos)
		{
			quiz->m_name = loadTag(is, L"</name>");
		}
		else if (wline.find(L"<question id=") != std::wstring::npos)
		{
			auto q = loadQuestion(is);
			quiz->m_questions.push_back(q);
		}
		else if (wline.find(L"<results>") != std::wstring::npos)
		{
			quiz->m_results_desc = loadTag(is, L"</results>");
		}

	} while (wline.find(L"</quiz>") == std::wstring::npos);

	return quiz;

}