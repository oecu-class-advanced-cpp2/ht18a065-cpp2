#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi

		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。

		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {

			char car1[4] = { 'm','c','x','i' };
			char car2[8] = { '2','3','4','5','6','7','8','9' };
			int num[4] = { 1000,100,10,1};
			int result = 0;
			int sub = 1;

			for (auto pos = s.begin(); pos != s.end(); pos++) {
				for (int i = 0; i < 8; i++) {
					if (*pos == car1[i]) {
						result = result+(num[i]*sub);
						sub = 1;
					}else if (*pos == car2[i]) {
						sub = *pos - '0';
					}
				}
			}
			value_ = result;
		}


		/* ----------------------------------------------------------------- */
		/*
		operator+

		2 つのオブジェクトの加算結果を取得します。
		*/
		/* ----------------------------------------------------------------- */
		
		mcxi operator+(const mcxi &rhs) {	
			mcxi num = this->value_ + rhs.value_;
			return num;
		}

		mcxi(int value_) {
			this->value_ = value_;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string

		現在の値を mcxi 記法に変換します。
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {
			stringstream result0;
			int main = value_;
			int num[4] = { 1000,100,10,1};
			string str[4] = { "m","c","x","i" };

			for (int i = 0; i < 4; i++) {
				int q =  main/ num[i];
				if (q == 1) {
					result0 << str[i];
					main= main-num[i];
				}
				if (q > 1) {
					result0 << q;
					result0 << str[i];
					main=main- (num[i] * q);
				}
		}
		return	result0.str();
		}

	private:
		int value_;
	};
}

int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "正 " << "3x" << "      /解 " << result0.to_string() << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "正 " << "x" << "       /解 " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i"); //122
	cpp2::mcxi b2("4c8x8i");//488
	auto result2 = a2 + b2; //610
	std::cout << "正 " << "6cx" << "     /解 " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "正 " << "5m9c9x9i" << "/解 " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "正 " << "m" << "       /解 " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "正 " << "9m9c9x9i" << "/解 " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "正 " << "mi" << "      /解 " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "正 " << "mi" << "      /解 " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "正 " << "mx" << "      /解 " << result8.to_string() << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "正 " << "9m9c9x9i" << "/解 " << result9.to_string() << std::endl;

	std::cin.get();
	return 0;
}