int x;
int y;
int z;
int t = 5;

int main(void) {
	x = 3;
	y = x + 5;
	z = y * 3 + 2;
	x = 2 + y * 3;
	y = x / -t;
	z = x % -t;
	return 0;
}