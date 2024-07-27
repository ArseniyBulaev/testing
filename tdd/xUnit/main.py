from my_test import *

def main():
    print(TestCaseTest("testTemplateMethod").run().summary())
    print(TestCaseTest("testResult").run().summary())
    print(TestCaseTest("testFailedResult").run().summary())
    print(TestCaseTest("testFailedResultFormating").run().summary())

if __name__ == "__main__":
    main()