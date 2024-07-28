from my_test import *

def main():
    suit = TestSuite()
    suit.add(TestCaseTest("testTemplateMethod"))
    suit.add(TestCaseTest("testResult"))
    suit.add(TestCaseTest("testFailedResult"))
    suit.add(TestCaseTest("testFailedResultFormating"))
    suit.add(TestCaseTest("testSuite"))
    suit.add(TestCaseTest("testTearDownAfterFail"))
    suit.add(TestCaseTest("testCatchSetUpError"))
    result = TestResult()
    suit.run(result)
    print(result.summary())
    print(result.errors())


if __name__ == "__main__":
    main()