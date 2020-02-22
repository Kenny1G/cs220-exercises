// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#ifndef DNASEARCH_H_
#define DNASEARCH_H_

/*
    stores, in file_array, a character array containing every char in the file filename
*/
int parse_file(const char* filename, char* file_array);

/*
    Return value is the first offset *greater than or equal to* start_at
    where pattern occurs in text. Returns -1 if there is no such occurence.
 */
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at);

#endif //DNASEARCH_H_