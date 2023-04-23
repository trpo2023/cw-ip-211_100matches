#include <ctest.h>
#include <play.h>

// Given

CTEST(BOOL_suite, exceeding_the_limit)
{
    const int dec = 1;
    const int matchesCount = 100;
    // When
    const bool result = takeAway(matchesCount, dec);

    // Then
    const bool expected = 1;
    ASSERT_EQUAL(expected, result);
}
