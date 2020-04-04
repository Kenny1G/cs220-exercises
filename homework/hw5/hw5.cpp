// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "language_model.h"

int main(int argc, char **argv)
{
	LanguageModel *lm = new LanguageModel;

	bool bRet = lm->init(argc, argv);
	if (!bRet) return -1;
	lm->create_model();
	lm->display_model();

	delete lm;
}