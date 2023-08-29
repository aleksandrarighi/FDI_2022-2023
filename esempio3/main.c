unsigned int m = 15, n = 6, t, mcd;

int main(void)
{
	while (m!=n){
		if (m < n) {
			t = m;
			m = n;
			n = t;
		}
		m = m - n; 
	}
	mcd = m;
	return 0;
}
