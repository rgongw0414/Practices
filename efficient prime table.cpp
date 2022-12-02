/*
	Sieve of Eratosthenes 簡稱埃氏篩，也稱質數篩
	定出要篩數值的範圍n，找出sqrt(n)以內的質數p1, p2, ..., pk，先用2去篩，把2留下，把2的倍數剔除掉；
	再用下個質數3篩，把3留下，把3的倍數剔除掉；
	接下去用下個質數5篩，把5留下，把5的倍數剔除掉，直至夠為止。
*/
vector<bool> primeT(MAX+1, true);
primeT[0] = false;
primeT[1] = false;

for (int i = 2; i*i < MAX+1; ++i) { // this is much more faster!
	for (int j = 2; j*i < MAX+1; ++j) {
		primeT[i*j] = false;
	}
}