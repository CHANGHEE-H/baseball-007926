#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNum) {
		assertIllegalArgument(guessNum);
	}
private:
	bool isDup(const string& guessNum) {
		return (guessNum[0] == guessNum[1] ||
			guessNum[1] == guessNum[2] ||
			guessNum[0] == guessNum[2]);
	}

	void assertIllegalArgument(const std::string& guessNum)
	{
		if (3 != guessNum.length()) {
			throw length_error("Must be three letters");
		}
		for (char ch : guessNum) {
			if ('0' > ch || '9' < ch) {
				throw invalid_argument("Must be number");
			}
		}
		if (true == isDup(guessNum)) {
			throw invalid_argument("Must not have the same number.");
		}
	}
};