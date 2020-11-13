// hexdump - Hexdump.h
// AUTHOR: Anton Sievering
// DATE: 13. November 2020
// TIME: 09:09AM
// LICENSE: BSD-3


#pragma once
#include <string>
#include <iostream>
#include <iomanip>

void hexdump(const std::wstring &content, const std::size_t &bytes, const bool &bIndex, const bool &bHex, const bool &bText)
{
	for (std::size_t block = 0; block < content.size(); block += bytes)
	{
		// The offset of the line from the start
		if (bIndex)
		{
			// offset from the start of the file
			std::cout << "0x";
			std::cout << std::hex << std::setfill('0') << std::setw(16) << block << " ";
		}

		// The hexadecimal values
		if (bHex)
		{
			// hex values
			for (std::size_t offset = 0; offset < bytes; offset++)
			{
				std::size_t index = block + offset;

				if (index < content.size())
					std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)(uint8_t)content[index] << " ";
				else
					std::cout << "   ";
			}
		}

		// utf-8 text representation
		if (bText)
		{
			// string
			for (std::size_t offset = 0; offset < bytes; offset++)
			{
				std::size_t index = block + offset;
				if (index < content.size())
				{
					char c = content[index];

					if (c >= 32)
						std::cout << std::dec << c;
					else
						std::cout << std::dec << ".";
				}
			}
		}

		std::cout << std::endl;
	}
}