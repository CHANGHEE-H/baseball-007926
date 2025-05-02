#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& answer) : answer(answer) {}

	GuessResult guess(const string& guessNum) {
		assertIllegalArgument(guessNum);
		if (guessNum == answer) {
			return { true, 3, 0 };
		}

		return { false, 0, 0 };
	}
private:
	string answer;

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