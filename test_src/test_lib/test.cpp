#include <ctest.h>
#include <play.h>
#include <vector>

// Given

CTEST(GameLogicTest_Suite, unexceeding_the_limit)
{
    const int dec = 1;
    const int matchesCount = 100;
    // When
    const bool result = takeAway(matchesCount, dec);

    // Then
    const bool expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite,exceeding_the_limit)
{
    const int dec = 10;
    const int matchesCount = 1;
    // When
    const bool result = takeAway(matchesCount, dec);

    // Then
    const bool expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite, unexceeding_settings_limit)
{
    const int dec = 5;
    std::vector<int> settings = {100,10};
    // When
    const bool result = TestDec(settings, dec);
    // Then
    const bool expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite, exceeding_settings_limit)
{
    const int dec = 20;
    std::vector<int> settings = { 100,10 };
    // When
    const bool result = TestDec(settings, dec);

    // Then
    const bool expected = 0;
    ASSERT_EQUAL(expected, result);
}
