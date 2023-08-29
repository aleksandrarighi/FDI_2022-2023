double discriminante(double a, double b, double c) {
	return (b * b) - 4 * (a * c);
}

double radice_quadrata(double a) {
	double t, x = a;
	if (x <= 0.) {
		return 0.;
	}
	while (x!= 0) {
		t = x;
		x = 0.5 * (t + a / t);
	}
	return x;
}

int soluzioni(double a, double b, double c, double* x1, double* x2) {
	double delta = discriminante(a, b, c);
	if (delta < 0) {
		return 0;
	}
	if (delta == 0) {
		*x1 = (-b) / 2 * a;
		return 1;
	}
	else {
		*x1 = ((-b) - radice_quadrata(delta)) / (2 * a);
		*x2 = ((-b) - radice_quadrata(delta)) / (2 * a);
		return 2;
	}
}

double potenza(double x, int n)
{
	//x^n= 1 x X x X x X... n- volte
	double pot = 1;
	for (int i = 0; i < n; ++i) {
		//moltiplico la potenza, cioè il val attuale per x
		pot *= x;
	}
	return pot;
}
//prendo un numero e lo moltiplico per x n- volte

double fattoriale(int n)
{
	//il fattoriale parte da 1 
	double fat = 1;
	for (int i = 2; i <= n; ++i) {
		//per n- volte devo moltiplicare il fattoriale per i che va da 2 a n incluso
		fat *= i;
	}
	return fat;
}


double exp(double x)
{
	double s = 0; // per fare una sommatoria devo incrementare, quindi parto da 0
	for (int n = 0; n < 10; ++n) //per n = 0, ma minore di 10, incrementa n 
	{
		s += potenza(x, n) / fattoriale(n); // parto da 0 e sommo x^n, poi devo dividere per n!
		// a questo punto ci manca la potenza e il fattoriale 
	}
	return s;
}

//idea: devo sommare tante volte x^n, diviso il fattoriale di n
//per calcolare l'exp si uso uno sviluppo in serie di Taylor

//int main(void) {
	//double x = exp(1);
	//return 0;
//}

//devo prima fare la potenza, poi il fattoriale e poi saper risolvere il problema