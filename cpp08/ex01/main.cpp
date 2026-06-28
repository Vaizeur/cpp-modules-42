#include <cstdlib>
#include "Span.hpp"
#include <ctime>
#include <iostream>
#include <vector>

static void subjectTest()
{
    std::cout << "===== SUBJECT TEST =====" << std::endl;

    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

static void emptySpanTest()
{
    std::cout << "===== EMPTY SPAN TEST =====" << std::endl;

    try
    {
        Span sp(5);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void oneElementTest()
{
    std::cout << "===== ONE ELEMENT TEST =====" << std::endl;

    try
    {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void fullSpanTest()
{
    std::cout << "===== FULL SPAN TEST =====" << std::endl;

    try
    {
        Span sp(2);

        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void addRangeTest()
{
    std::cout << "===== ADD RANGE TEST =====" << std::endl;

    Span sp(10);

    std::vector<int> values;

    values.push_back(100);
    values.push_back(15);
    values.push_back(-5);
    values.push_back(42);
    values.push_back(18);

    sp.addNumbers(values.begin(), values.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;

    std::cout << std::endl;
}

static void rangeOverflowTest()
{
    std::cout << "===== RANGE OVERFLOW TEST =====" << std::endl;

    try
    {
        Span sp(3);

        std::vector<int> values;

        values.push_back(1);
        values.push_back(2);
        values.push_back(3);
        values.push_back(4);

        sp.addNumbers(values.begin(), values.end());
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void bigNumbersTest()
{
    std::cout << "===== 10K NUMBERS TEST =====" << std::endl;

    Span sp(10000);
    for (int i = 0; i < 10000; ++i){
        sp.addNumber(std::rand());
    }
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp.longestSpan() << std::endl;
}
int main()
{
    std::srand(std::time(NULL));
    subjectTest();
    emptySpanTest();
    oneElementTest();
    fullSpanTest();
    addRangeTest();
    rangeOverflowTest();
    bigNumbersTest();
    return 0;
}