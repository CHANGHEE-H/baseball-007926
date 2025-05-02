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
		else {
			return { false, getStrikes(guessNum), getBalls(guessNum) };
		}

		return { false, 0, 0 };
	}
private:
	string answer;

	int getStrikes(const string& guessNum) {
		int ret = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNum[i] == answer[i]) {
				ret++;
			}	
		}

		return ret;
	}

	int getBalls(const string& guessNum) {
		int ret = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;

				if (guessNum[i] == answer[j]) {
					ret++;
				}
			}
		}
		return ret;
	}

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