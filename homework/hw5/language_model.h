// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#ifndef LANGUAGE_MODEL_H_
#define LANGUAGE_MODEL_H_

#include <map>
#include <vector>

class LanguageModel
{
	public:
		

		LanguageModel();
		bool init(int argc, char **argv);
		bool create_model();
		bool display_model();

		
	private:
		enum Commands
		{
			none,
			ascend_alpha,
			descend_alpha,
			count_ordered,
			most_frequent
		} cmnd;
		std::map<int, std::string> model;
		std::vector<std::string> text;
		std::string word1, word2;
		
		bool set_text(std::string list_filename);
		bool parse_command(std::string command);
};

#endif //language_model.h
