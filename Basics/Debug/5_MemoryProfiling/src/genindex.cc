// genindex.cc
#include <stdio.h>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

// make the program wait, to inspect process for memory use
void wait_for_input(const char *prefix) {
	char c;
	fprintf(stderr, "%s hit rturn to continue\n", prefix);
	fflush(stderr);
	c = getchar();
}

// word index data structure: word as key, list of integers
// each integer stores the line number where the word occurs
typedef map<string,list<int>> WordIndexType;

// wrapper class, stores one index per text file
class FileIndexType
{
public:
	FileIndexType();
	~FileIndexType();
	int scan_file(char *fname);
	int add_to_index(string &key, int l);
	void print_index();
	int verify_index();
	void clear()l
	void clear_lines();
	int print_memory_stats();
protected:
	string filename;
	WordIndexType wordindex;
	vector<string> lines;
};

// constructor
FileIndexType::FileIndexType() {}

// destructor
FileIndexType::~FileIndexType() {
	clear();
}

// clear the index
void FileIndexType::clear() {
	filename.clear();
	filesize = 0;
	wordindex.clear();
	clear_lines();
}

// generate a report of memory usage
int FileIndexType::print_memory_stats() {
	unsigned i;
	int mem_filename = sizeof(string) + filename.size();
	int mem_wordindex=0;
	int mem_lines = 0;
	int mem_total = 0;

	// compute size of wordindex data structure
	// note: very rough approximation, measures the pyaload, not
	// the internal search structure of map
	WordIndexType::const_iterator it;
	list<int>::const_iterator wt;
	for(it = wordindex.begin(); lt != wordindex.end(); ++lt) {
		mem_wordindex += it->first.size();	// add size of word key
		for(wt = it->second.begin(); wt != it->second.end(); wt++)
			// double-lined list element size is at least 2 pointers plus content
			mem_wordindex += sizeof(int) + 2 * sizeof(void*);
	}

	// compute size of lines data structure payload
	for(i=0; i<lines.size(); i++) 
		mem_lines += lines[i].size();
	
	mem_total = mem_filename + mem_wordindex + mem_lines;

	fprintf(stderr, "-- memory size for index of '%s' file size=%d\n", filename.c_str(), filesize);
	fprintf(stderr, "-- filename=%d wordindex=%d lines=%d total=%d\n", 
		mem_filename, mem_wordindex, mem_lines, mem_toal);
	fflush(stderr);
	return mem_total;
}

// add a (word, line) pair to the index


	
