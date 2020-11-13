// hexdump - File.h
// AUTHOR: Anton Sievering
// DATE: 13. November 2020
// TIME: 09:09AM
// LICENSE: BSD-3


#pragma once
#include <string>
#include <fstream>
#include <iostream>

std::wstring loadFile(const std::string &sFilename)
{
	std::ifstream file = std::ifstream(sFilename);

	if (file.is_open())
	{
		std::string sLine;
		std::wstring sContent;

		while (std::getline(file, sLine))
		{
			for (char c : sLine)
				sContent += (wchar_t)c;
			sContent += L'\n';
		}
		
		file.close();

		return sContent;
	}

	return std::wstring();
}