#include <ctest.h>
#include <vector>

#include <play.h>
#include <input.h>
#include <settings.h>

// Given

CTEST(GameLogicTest_Suite, unexceeding_the_limit)
{
    const int dec = 1;
    const int matchesCount = 100;
    // When
    const bool result = TakeAway(matchesCount, dec);

    // Then
    const bool expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GameLogicTest_Suite,exceeding_the_limit)
{
    const int dec = 10;
    const int matchesCount = 1;
    // When
    const bool result = TakeAway(matchesCount, dec);

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

CTEST(Input_user_settings_Suite, Checking_correct_checkingFunctionWork)
{
    // When
    const unsigned int result = CheckInput("first");
    const unsigned int result_2 = CheckInput("second");
    const unsigned int result_3 = CheckInput("reset");
    const unsigned int result_4 = CheckInput("exit");
    const unsigned int result_5 = CheckInput("gajgjaga");

    const unsigned int result_6 = CheckInput("FIrsT");
    const unsigned int result_7 = CheckInput("SecoND");
    const unsigned int result_8 = CheckInput("RESet");
    const unsigned int result_9 = CheckInput("EXIt");
    // Then
    const unsigned int expected = 1;
    const unsigned int expected_2 = 2;
    const unsigned int expected_3 = 3;
    const unsigned int expected_4 = 4;
    const unsigned int expected_5 = 0;

    const unsigned int expected_6 = 1;
    const unsigned int expected_7 = 2;
    const unsigned int expected_8 = 3;
    const unsigned int expected_9 = 4;

    ASSERT_EQUAL(expected,result);
    ASSERT_EQUAL(expected_2,result_2);
    ASSERT_EQUAL(expected_3,result_3);
    ASSERT_EQUAL(expected_4,result_4);
    ASSERT_EQUAL(expected_5,result_5);
    ASSERT_EQUAL(expected_6,result_6);
    ASSERT_EQUAL(expected_7,result_7);
    ASSERT_EQUAL(expected_8,result_8);
    ASSERT_EQUAL(expected_9,result_9);
}

CTEST(Input_user_settings_Suite,CheckResetFunction)
{
    // When
    std::vector<int> defaultSettings = {200,50}; 
    ResetSettings(defaultSettings);

    // Then
    const unsigned int expected_1 = 100;
    const unsigned int expected_2 = 10;

    ASSERT_EQUAL(expected_1,defaultSettings[0]);
    ASSERT_EQUAL(expected_2,defaultSettings[1]);
}

CTEST(Input_user_settings_Suite,CheckApplyFirstSettingMethod)
{
    // When
    std::vector<int> defaultSettings = {150,15};
    InputHandler myHandler;
    const unsigned int userInput_1 = 100;// ok
    const unsigned int userInput_2 = -300;// no ok

    const bool result_1 = myHandler.ChangeFirstSettings(defaultSettings,userInput_1);
    const bool result_2 = myHandler.ChangeFirstSettings(defaultSettings,userInput_2);

    // Then
    const bool expected_1 = true;
    const bool expected_2 = false;

    ASSERT_EQUAL(expected_1,result_1);
    ASSERT_EQUAL(expected_2,result_2);
}

CTEST(Input_user_settings_Suite,CheckApplySecondSettingMethod)
{
    // When
    std::vector<int> defaultSettings = {150,15};
    InputHandler myHandler;
    const unsigned int userInput_1 = 15;// ok
    const unsigned int userInput_2 = -30;// no ok

    const bool result_1 = myHandler.ChangeSecondSettings(defaultSettings,userInput_1);
    const bool result_2 = myHandler.ChangeSecondSettings(defaultSettings,userInput_2);
    // Then
    const bool expected_1 = true;
    const bool expected_2 = false;

    ASSERT_EQUAL(expected_1,result_1);
    ASSERT_EQUAL(expected_2,result_2);  
}