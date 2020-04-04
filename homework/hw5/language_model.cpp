// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "language_model.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <algorithm>


LanguageModel::LanguageModel():
cmnd(none),
word1(""),
word2("")
{}

bool LanguageModel::init(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cerr << "Invalid file list: " << std::endl;
		return false;
	}

	bool bRet = set_text(argv[1]); //bRet means boolean return
	if (!bRet) return false;

	if (argc < 3)
	{
		std::cerr << "Invalid command: valid options are a, d, c, and f" << std::endl;
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
		std::cerr << "Invalid file list: " << list_filename << std::endl;
		return false;
	}

	std::string filename;
	while (list_file >> filename)
	{
		std::ifstream file_stream(filename);
		if (!file_stream.is_open())
		{
			std::cerr << "Invalid file: " << filename << std::endl;
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
			std::cerr << "Invalid argument list: f requires two additional command-line arguments" << std::endl;
			return false;
		}
		word1 = argv[3];
		word2 = argv[4];
	}
	else
	{
		std::cerr << "Invalid command: valid options are a, d, c, and f" << std::endl;
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
			display_descend_alpha();
			break;
		case count_ordered:
			display_count_ordered();
			break;
		case most_frequent:
			display_freq_third();
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
	std::vector<std::pair<std::string, int>> inverse_model;
	for (std::map<std::string, int>::iterator it = model.begin(); it != model.end(); ++it)
	{
		inverse_model.push_back( std::make_pair(it->first, it->second));
	}

	std::sort(inverse_model.begin(), inverse_model.end(), count_sort);

	for (std::vector<std::pair<std::string, int>>::iterator inverse_it = inverse_model.begin(); inverse_it != inverse_model.end(); ++inverse_it)
	{
		std::cout << inverse_it->second << " - " << inverse_it->first << std::endl;
	}
}


void LanguageModel::display_freq_third()
{
	std::vector<std::pair<std::string, int>> matches; 
	std::stringstream regex;
	regex << "[" << word1 << " " << word2;
	for (std::map<std::string, int>::iterator it = model.begin(); it != model.end(); ++it)
	{
		if (strncmp(it->first.c_str(), regex.str().c_str(),word1.length()+ word2.length() + 2) == 0)
		{
			matches.push_back(std::make_pair(it->first, it->second));
		}
	}
	if (matches.empty())
	{
		std::cout << "No trigrams of the form [x y ?] appear" << std::endl;
	}
	else
	{
		std::sort(matches.begin(), matches.end(), count_sort);
		std::cout << matches[0].second << " - " << matches[0].first << std::endl;
	}
}


bool LanguageModel::count_sort(std::pair<std::string, int> &elem, std::pair<std::string, int> &elem2)
{
	if (elem.second != elem2.second) return elem.second > elem2.second;
	return strcmp(elem.first.c_str(), elem2.first.c_str()) < 0;
}