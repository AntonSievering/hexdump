// hexdump - Main.cpp
// AUTHOR: Anton Sievering
// DATE: 13. November 2020
// TIME: 09:09AM
// LICENSE: BSD-3

#include <iostream>
#include <string>

#include "File.h"
#include "HexDump.h"

// hexdump usage:
// hexdump <filename> [-n=bytes][noIndex][noHex][noText]
// 
// filename: The path to the target file.
// bytes:    The amount of bytes to be written per line.
// noIndex:  Set this if the indicees should not be printed.
// noHex:    Set this if the hex values should not be printed.
// noText:   Set this if the text representation should not be printed.


int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		std::size_t bytes = 16;
		bool bIndex = true;
		bool bText  = true;
		bool bHex   = true;

		for (int i = 0; i < argc; i++)
		{
			std::string s = argv[i];

			// -n=bytes
			if (s == "noIndex")
			{
				bIndex = false;
			}
			else if (s == "noHex")
			{
				bHex = false;
			}
			else if (s == "noText")
			{
				bText = false;
			}
			else if (s.size() > 3)
			{
				if (s.substr(0, 3) == "-n=")
					bytes = atoi(s.substr(3).c_str());
			}

			if (bytes == 0 || bytes > 1024)
			{
				std::cout << "bytes must be in range of 0 to 1024 (not " << bytes << ")" << std::endl;
				bytes = 16;
			}
		}

		hexdump(loadFile(argv[1]), bytes, bIndex, bHex, bText);
	}
	else
	{
		// help
		std::cout << "hexdump usage:"                                                       << std::endl;
		std::cout << "hexdump <filename> [-n=bytes][noIndex][noHex][noText]"   << std::endl << std::endl;
		std::cout << "filename: The path to the target file."                               << std::endl;
		std::cout << "bytes:    The amount of bytes to be written per line."                << std::endl;
		std::cout << "noIndex:  Set this if the indicees should not be printed."            << std::endl;
		std::cout << "noHex:    Set this if the hex values should not be printed."          << std::endl;
		std::cout << "noText:   Set this if the text representation should not be printed." << std::endl;
	}

	return EXIT_SUCCESS;
}
