#include "baseball.cpp"
#include "gmock/gmock.h"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {

		}
	}
};

TEST_F(BaseballFixture, GuessSuccess) {
	GuessResult ret = game.guess("123");

	EXPECT_TRUE(ret.solved);
	EXPECT_EQ(3, ret.strikes);
	EXPECT_EQ(0, ret.balls);
}

TEST_F(BaseballFixture, ThrowInvalidCaseException) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}