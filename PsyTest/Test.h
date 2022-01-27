#pragma once


class Test
{
	Questions m_questions;
	std::wstring m_name;
	std::wstring m_results_desc;

	void Load(std::wistream& is);

public:
	Test(){}

	void Load(const std::string&);
	void Draw( std::wostream&);
};

