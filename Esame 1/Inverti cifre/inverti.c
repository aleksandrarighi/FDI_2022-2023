unsigned int inverti(unsigned int i) {
	unsigned int reversed = 0; 
	while (i > 0) {
		unsigned int res = i % 10;
		reversed = reversed * 10 + res;
		i /= 10;
	}
	return reversed;
}

/*int main(void) {
	unsigned int d;
	d = inverti(123);
	d = inverti(123456);
}*/