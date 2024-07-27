from my_test import *

def main():
    suit = TestSuite()
    suit.add(TestCaseTest("testTemplateMethod"))
    suit.add(TestCaseTest("testResult"))
    suit.add(TestCaseTest("testFailedResult"))
    suit.add(TestCaseTest("testFailedResultFormating"))
    suit.add(TestCaseTest("testSuite"))
    result = TestResult()
    suit.run(result)
    print(result.summary())


if __name__ == "__main__":
    main()