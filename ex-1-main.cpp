// ex-1-main.cpp
#include <iostream>

#define CPP2_PRIME_UPPER_LIMIT 1000000//探索する値の上限値

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{
	int x, y, yakusuu;
	int times = 0;
	for (x = a; x <= 1000000; x += d)
	{
		yakusuu = 0;
		for (y = 1; y <= x; y++) {
			if (x%y == 0)
				yakusuu++;
		}
		if (yakusuu == 2)
			times += 1;
			if (times == n)
				return x;
	}
}

int main()
{
	std::cout <<"要素数・ 367, 186, 151"<<"   "<<"正・92809 "<< "　解・"<<nth_prime(367, 186, 151) << std::endl;
	std::cout <<"要素数・ 179,  10, 203"<<"   "<<"正・6709  "<< "　解・" <<nth_prime(179, 10, 203) << std::endl;
	std::cout <<"要素数・ 271,  37,  39"<<"   "<<"正・12037 "<< "　解・" <<nth_prime(271, 37, 39) << std::endl;
	std::cout <<"要素数・ 103, 230,   1"<<"   "<<"正・103   "<< "　解・" <<nth_prime(103, 230, 1) << std::endl;
	std::cout <<"要素数・  27, 104, 185"<<"   "<<"正・93523 "<< "　解・" <<nth_prime(27, 104, 185) << std::endl;
	std::cout <<"要素数・ 253,  50,  85"<<"   "<<"正・14503 "<< "　解・" <<nth_prime(253, 50, 85) << std::endl;
	std::cout <<"要素数・   1,   1,   1"<<"   "<<"正・2     "<< "　解・" <<nth_prime(1, 1, 1) << std::endl;
	std::cout <<"要素数・9075, 337, 210"<<"   "<<"正・899429"<< "　解・" <<nth_prime(9075, 337, 210) << std::endl;
	std::cout <<"要素数・ 307,  24,  79"<<"   "<<"正・5107  "<< "　解・" <<nth_prime(307, 24, 79) << std::endl;
	std::cout <<"要素数・ 331, 221, 177"<<"   "<<"正・412717"<< "　解・" <<nth_prime(331, 221, 177) << std::endl;
	std::cout <<"要素数・ 259, 170,  40"<<"   "<<"正・22699 "<< "　解・" <<nth_prime(259, 170, 40) << std::endl;
	std::cout <<"要素数・ 269,  58, 102"<<"   "<<"正・25673 "<< "　解・" <<nth_prime(269, 58, 102) << std::endl;
	//以下、同様に、入出力例通りになるか確認せよ。
	
    std::cin.get();
    return 0;
}
