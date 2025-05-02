#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
	void guess(const string& string) {
		throw length_error("Must be three letters");
	}
};