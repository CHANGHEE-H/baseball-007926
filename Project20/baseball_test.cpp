#include "baseball.cpp"
#include "gmock/gmock.h"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {

		}
	}
};

TEST_F(BaseballFixture, ThrowInvalidCaseException) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}