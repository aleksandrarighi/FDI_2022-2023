#include <math.h>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		return 1;
	}

	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double c = atof(argv[3]);

	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	double area = sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c)) / 4;
	printf("%f\n", area);

	return 0;
}