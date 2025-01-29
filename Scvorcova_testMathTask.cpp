#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
 //подключение модуля с тестируемыми методами
#include "Scvorcova_MathTask.h"

using namespace cute;
//тест, проверяющий отсев пустых значений
void testUserInput_Empty() {
    // исходные данные
    string str = "";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
    //тест, проверяющий отсев нецифровых символов
}

void testUserInput_Letter(){
    // исходные данные
    string str = "a";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_NegativeValue(){
    string str = "-10";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

void testConvertToGigabytes(){
    int B = 1024 * 1024;
    double expected = 1.;
    double actual = convertToGigabytes(B);
    ASSERT_EQUAL(expected, actual);
}

void testConvertToMegabytes(){
    int B = 1024 * 1024;
    double expected = 1024.;
    double actual = convertToMegabytes(B);
    ASSERT_EQUAL(expected, actual);
}

int main(){
    suite s;
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testConvertToGigabytes));
    s.push_back(CUTE(testConvertToMegabytes));
    ide_listener<> listener;
    makeRunner(listener)(s, "Test project");
    return 0;
}
