from my_test import *

def main():
    suit = TestSuite(TestCaseTest)
    result = TestResult()
    suit.run(result)
    print(result.summary())
    print(result.errors())


if __name__ == "__main__":
    main()