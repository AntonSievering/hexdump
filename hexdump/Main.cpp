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
// hexdump <filename> [-n=bytes]
// 
// filename: The path to the target file.
// bytes: The amount of bytes to be written per line.


int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		std::size_t bytes = 16;

		for (int i = 0; i < argc; i++)
		{
			std::string s = argv[i];

			// -n=bytes
			if (s.size() > 3)
				if (s.substr(0, 3) == "-n=")
					bytes = atoi(s.substr(3).c_str());
			if (bytes == 0 || bytes > 1024)
			{
				std::cout << "bytes must be in range of 0 to 1024 (not " << bytes << ")" << std::endl;
				bytes = 16;
			}
		}

		hexdump(loadFile(argv[1]), bytes);
	}
	else
	{
		// help
		std::cout << "hexdump usage:" << std::endl;
		std::cout << "hexdump <filename> [-n=bytes]" << std::endl << std::endl;
		std::cout << "filename: The path to the target file." << std::endl;
		std::cout << "bytes: The amount of bytes to be written per line." << std::endl;
	}

	return EXIT_SUCCESS;
}
