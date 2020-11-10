// ex-1-main.cpp
#include <iostream>

#define CPP2_PRIME_UPPER_LIMIT 1000000//�T������l�̏���l

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
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
	std::cout <<"�v�f���E 367, 186, 151"<<"   "<<"���E92809 "<< "�@���E"<<nth_prime(367, 186, 151) << std::endl;
	std::cout <<"�v�f���E 179,  10, 203"<<"   "<<"���E6709  "<< "�@���E" <<nth_prime(179, 10, 203) << std::endl;
	std::cout <<"�v�f���E 271,  37,  39"<<"   "<<"���E12037 "<< "�@���E" <<nth_prime(271, 37, 39) << std::endl;
	std::cout <<"�v�f���E 103, 230,   1"<<"   "<<"���E103   "<< "�@���E" <<nth_prime(103, 230, 1) << std::endl;
	std::cout <<"�v�f���E  27, 104, 185"<<"   "<<"���E93523 "<< "�@���E" <<nth_prime(27, 104, 185) << std::endl;
	std::cout <<"�v�f���E 253,  50,  85"<<"   "<<"���E14503 "<< "�@���E" <<nth_prime(253, 50, 85) << std::endl;
	std::cout <<"�v�f���E   1,   1,   1"<<"   "<<"���E2     "<< "�@���E" <<nth_prime(1, 1, 1) << std::endl;
	std::cout <<"�v�f���E9075, 337, 210"<<"   "<<"���E899429"<< "�@���E" <<nth_prime(9075, 337, 210) << std::endl;
	std::cout <<"�v�f���E 307,  24,  79"<<"   "<<"���E5107  "<< "�@���E" <<nth_prime(307, 24, 79) << std::endl;
	std::cout <<"�v�f���E 331, 221, 177"<<"   "<<"���E412717"<< "�@���E" <<nth_prime(331, 221, 177) << std::endl;
	std::cout <<"�v�f���E 259, 170,  40"<<"   "<<"���E22699 "<< "�@���E" <<nth_prime(259, 170, 40) << std::endl;
	std::cout <<"�v�f���E 269,  58, 102"<<"   "<<"���E25673 "<< "�@���E" <<nth_prime(269, 58, 102) << std::endl;
	//�ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	
    std::cin.get();
    return 0;
}
