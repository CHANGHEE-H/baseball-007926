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

TEST_F(BaseballFixture, Guess2Strikes) {
	GuessResult ret = game.guess("124");

	EXPECT_FALSE(ret.solved);
	EXPECT_EQ(2, ret.strikes);
	EXPECT_EQ(0, ret.balls);
}

TEST_F(BaseballFixture, Guess1Strike2Ball) {
	GuessResult ret = game.guess("321");

	EXPECT_FALSE(ret.solved);
	EXPECT_EQ(1, ret.strikes);
	EXPECT_EQ(2, ret.balls);
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