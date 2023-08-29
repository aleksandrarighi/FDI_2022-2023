#include <stdio.h>

void print_board(FILE* f, const unsigned short board[4][4]) {
	fprintf(f, "+----+----+----+----+\n");
	for (int i = 0; i < 4; i++) {
		fprintf(f, "|");
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				fprintf(f, "    ");
			}
			else {
				fprintf(f, "%4hu", board[i][j]);
			}
			fprintf(f, "|");
		}
		fprintf(f, "\n");
		fprintf(f, "+----+----+----+----+\n");
	}
}