#include "stringhe.h"
#include <string.h>

void accodaCifra(char** vs, unsigned char n) {
	char* numeri[10][3] = {
		{ " _ "
		, "| |"
		, "|_|" },
		{ "   "
		, "  |"
		, "  |" },
		{ " _ "
		, " _|"
		, "|_ "},
		{ " _ "
		, " _|"
		, " _|"},
		{ "  "
		, "|_|"
		, "  |"},
		{ " _ "
		, "|_"
		, " _|"},
		{ " _ "
		, "|_ "
		, "|_|"},
		{ " _ "
		, " _|"
		, "  |"},
		{ " _ "
		, "|_|"
		, "|_|"},
		{ " _ "
		, "|_|"
		, " _|"},
	};
	
	for (int i = 0; i < 3; i++) {
		strcat(vs[i], numeri[n][i]);
		}
}