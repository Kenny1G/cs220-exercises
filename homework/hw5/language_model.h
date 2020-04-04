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

		/* Populates all parameters needed to create a model */
		bool init(int argc, char **argv);
		bool create_model();
		bool display_model();

		
	private:
		enum Commands // enum of possible commands because I like switches
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
		
		/* Writes the words from the files listed in list_filename to the vector text
		 * Wraps words from each file with START and END tags
		 */
		bool set_text(std::string list_filename);


		bool parse_command(int argc, char **argv);
};

#endif //language_model.h
