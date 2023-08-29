/*
	   1234 --> 0x1234
	   1234 = 1*1000 + 2*100 + 3*10 + 4*1
	   0x1234= 1*4096 + 2*256 + 3*16 + 4*1

	   xywz --> 0xxywz
	   xywz = x*1000 + y*100 + w*10 + z*1
	   0xxywz= x*4096 + y*256 + w*16 + z*1
	*/

	/*
		val = xywz --> 0xxywz
		xywz = x*1000 + y*100 + w*10 + z*1
		0xxywz= x*4096 + y*256 + w*16 + z*1
	*/

unsigned short bin2bcd(unsigned short val) {
	int z = (val / 1) % 10;
	int w = (val / 10) % 10;
	int y = (val / 100) % 10;
	int x = (val / 1000) % 10;

	return x * 4096 + y * 256 + w * 16 + z * 1;
}