// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#ifndef DNASEARCH_H_
#define DNASEARCH_H_

/*
    Return value is a character array containing every char in the file filename
*/
char* parse_file(const char* filename);

/*
    Return value is the first offset *greater than or equal to* start_at
    where pattern occurs in text. Returns -1 if there is no such occurence.
 */
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at);

#endif //DNASEARCH_H_