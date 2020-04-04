// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "language_model.h"
#include <iostream>
#include <fstream>

LanguageModel::LanguageModel():
word1(""),
word2(""),
cmnd(none)
{}

bool LanguageModel::init(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "Invalid file list: " << std::endl;
		return false;
	}

	bool bRet = set_text(argv[1]); //bRet means boolean return
	if (!bRet) return false;

	for (std::vector<std::string>::iterator it = text.begin(); it != text.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	if (argc < 3)
	{
		std::cout << "Invalid command: valid options are a, d, c, and f" << std::endl;
		return false;
	}

	//bRet = parse_command(argv[2]);
	//if (!bRet) return false;
	return true;
}


bool LanguageModel::set_text(std::string list_filename)
{
	std::ifstream list_file(list_filename);
	if (!list_file.is_open())
	{
		std::cout << "Invalid file list: " << list_filename << std::endl;
		return false;
	}

	std::string filename;
	while (list_file >> filename)
	{
		std::ifstream file_stream(filename);
		if (!file_stream.is_open())
		{
			std::cout << "Invalid file: " << filename << std::endl;
			continue;
		}

		text.push_back("<START_1>");
		text.push_back("<START_2>");
		std::string word;
		while (file_stream >> word)
		{
			text.push_back(word);
		}
		text.push_back("<END_1>");
		text.push_back("<END_2>");

	}
	return true;
}

