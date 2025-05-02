#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		if (3 != str.length()) {
			throw length_error("Must be three letters");
		}
		for (char ch : str) {
			if ('0' > ch || '9' < ch) {
				throw invalid_argument("Must be number");
			}
		 }
	}
};