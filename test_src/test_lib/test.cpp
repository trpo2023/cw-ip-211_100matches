#include <ctest.h>
#include <vector>

#include <play.h>
#include <input.h>

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

CTEST(GameLogicTest_Suite, Change_Of_Course_False_to_true)
{
    const bool par = 0;
    // When
    const bool result = ChangeOfCourse(par);

    // Then
    const bool expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite, Change_Of_Course_True_to_False)
{
    const bool par = 1;
    // When
    const bool result = ChangeOfCourse(par);

    // Then
    const bool expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite, Select_Quantity_exceeding_the_limit)
{
    std ::string str = "12345";
    // When
    const int result = SelectQuantity(str);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite, Select_Quantity_the_presence_of_letters)
{
    std ::string str = "g";
    // When
    const int result = SelectQuantity(str);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite, Select_Quantity_correct_input)
{
    std ::string str = "12";
    // When
    const int result = SelectQuantity(str);

    // Then
    const int expected = 12;
    ASSERT_EQUAL(expected, result);
}

CTEST(Input_Suite, Checking_The_Input_exceeding_the_limit)
{
    std ::string str = "12";
    const unsigned int len = 1;
    // When
    const bool result = CheckingTheInput(str, len);

    // Then
    const bool expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(Input_Suite, Checking_The_Input_presence_of_letters)
{
    std ::string str = "d";
    const unsigned int len = 1;
    // When
    const bool result = CheckingTheInput(str, len);

    // Then
    const bool expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(Input_Suite, Checking_The_Input_correct_input)
{
    std ::string str = "1";
    const unsigned int len = 1;
    // When
    const bool result = CheckingTheInput(str, len);

    // Then
    const bool expected = 1;
    ASSERT_EQUAL(expected, result);
}