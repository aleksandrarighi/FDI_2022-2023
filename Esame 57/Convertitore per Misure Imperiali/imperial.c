#include "imperial.h"

double to_meter(const char* imperial_length) {
	double numero;
	char unita[10];
	sscanf(imperial_length, "%lf %s", &numero, unita);

	if (strcmp(unita, "inch") == 0 || strcmp(unita, "inches") == 0 || strcmp(unita, "inc") == 0 || strcmp(unita, "in.") == 0 || strcmp(unita, "\"") == 0) {
		//converto da pollici a metri
		double metri = numero * 0.0254;
		return metri;
	}
	else if (strcmp(unita, "foot") == 0 || strcmp(unita, "feet") == 0 || strcmp(unita, "ft") == 0 || strcmp(unita, "ft.") == 0 || strcmp(unita, "\'") == 0) {
		//converto da piedi a metri
		double metri = numero * (12 * 0.0254);
		return metri;
	}
	else if (strcmp(unita, "yard") == 0 || strcmp(unita, "yards") == 0 || strcmp(unita, "yd") == 0 || strcmp(unita, "yd.") == 0) {
		//converto da iarde a metri
		double metri = numero * (36 * 0.0254);
		return metri;
	}
	else if (strcmp(unita, "mile") == 0 || strcmp(unita, "miles") == 0 || strcmp(unita, "mi") == 0 || strcmp(unita, "mi.") == 0) {
		//converto miglia in metri
		double metri = numero * (63360 * 0.0254);
		return metri;
	}
}