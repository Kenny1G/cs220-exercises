// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#ifndef DNASEARCH_H_
#define DNASEARCH_H_

/*
    Stores, in <file_array>, a character array containing every char in the file <filename>
    returns non zero if error occured.
*/
int parse_file(const char* filename, char* file_array);

/*
    Return value is the first offset *greater than or equal to* start_at
    where pattern occurs in text. Returns -1 if there is no such occurence.
 */
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at);

/*
    Prints out the offset of the 
*/
void show_match(int pattern_size, char* user_pattern, char* dna_array);

#endif //DNASEARCH_H_