// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "language_model.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>


LanguageModel::LanguageModel():
cmnd(none),
word1(""),
word2("")
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

	if (argc < 3)
	{
		std::cout << "Invalid command: valid options are a, d, c, and f" << std::endl;
		return false;
	}

	bRet = parse_command(argc, argv);
	if (!bRet) return false;
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


bool LanguageModel::parse_command(int argc, char **argv)
{
	std::string command(argv[2]);
	if (command.compare("a") == 0) cmnd = ascend_alpha;
	else if (command.compare("d") == 0 ) cmnd = descend_alpha;
	else if (command.compare("c") == 0) cmnd = count_ordered;
	else if (command.compare("f") == 0)
	{
		cmnd = most_frequent;
		if ((argc - 3) < 2)
		{
			std::cout << "Invalid argument list: f requires two additional command-line arguments" << std::endl;
			return false;
		}
		word1 = argv[3];
		word2 = argv[4];
	}
	else
	{
		std::cout << "Invalid command: valid options are a, d, c, and f" << std::endl;
		return false;
	}
	return true;
	
}


void LanguageModel::create_model()
{
	for (std::vector<std::string>::iterator it = text.begin(); it != text.end(); ++it)
	{
		// create trigram
		std::stringstream trigram;
		trigram << "[" << *it << " " << *(it + 1) << " " << *(it + 2) << "]";

		std::map<std::string, int>::iterator mapit = model.find(trigram.str());
		if (mapit == model.end()) model[trigram.str()] = 1;
		else model[trigram.str()]++;
	}

	//removing unnecessary elements that only contain tags.
	std::map<std::string, int>::iterator start = model.begin();
	std::map<std::string, int>::iterator end = model.find("[<END_2> <START_1> <START_2>]");
	model.erase(start,++end);
}


void LanguageModel::display_model()
{
	switch(cmnd)
	{
		case ascend_alpha:
			display_ascend_alpha();
			break;
		case descend_alpha:
			break;
		case count_ordered:
			break;
		case most_frequent:
			break;
	}
}


void LanguageModel::display_ascend_alpha()
{
	for (std::map<std::string, int>::iterator it = model.begin(); it != model.end(); ++it)
	{
		std::cout << it->second << " - " << it->first << std::endl;
	}
}

void LanguageModel::display_descend_alpha()
{
	for (std::map<std::string, int>::reverse_iterator rit = model.rbegin(); rit != model.rend(); ++rit)
	{
		std::cout << rit->second << " - " << rit->first << std::endl;
	}
}


void LanguageModel::display_count_ordered()
{
	for ()
}