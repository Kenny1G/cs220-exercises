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
		void create_model();
		void display_model();

		
	private:
		enum Commands // enum of possible commands because I like switches
		{
			none,
			ascend_alpha,
			descend_alpha,
			count_ordered,
			most_frequent
		} cmnd;
		std::vector<std::pair<std::string, int>> model;
		std::vector<std::string> text;
		std::string word1, word2;
		
		/* Writes the words from the files listed in list_filename to the vector text
		 * Wraps words from each file with START and END tags
		 */
		bool set_text(std::string list_filename);


		bool parse_command(int argc, char **argv);

		void display_ascend_alpha();
		void display_descend_alpha();
		void display_count_ordered();
		void display_most_frequent();
};

#endif //language_model.h
