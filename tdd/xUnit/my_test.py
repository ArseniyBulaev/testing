import inspect

class testCase:
    def __init__(self, name) -> None:
        self.name = name
    def __repr__(self) -> str:
        return self.name
    def setUp(self):
        pass
    def tearDown(self):
        pass
    def run(self, result):
        result.testStarted()
        try:
            self.setUp()
            method = getattr(self, self.name)
            method()
        except Exception as e:
            result.saveErrorMessage(str(e))
            result.testFailed()
        self.tearDown()


class wasRun(testCase):
    def __init__(self, name) -> None:
        testCase.__init__(self, name)
    def testMethod(self):
        self.log += "testMethod "
    def setUp(self):
        self.log = "setUp "
    def tearDown(self):
         self.log += "tearDown "
    def testBrokenMethod(self):
        self.log += "testBrokenMethod "
        raise Exception



class TestCaseTest(testCase):
    def __repr__(self) -> str:
        return super().__str__()
    def setUp(self):
       self.result = TestResult()
    def testTemplateMethod(self):
        self.test = wasRun("testMethod")
        self.test.run(self.result)
        assert("setUp testMethod tearDown " == self.test.log)
    def testResult(self):
        self.test = wasRun("testMethod")
        result = self.test.run(self.result)
        assert("1 run, 0 failed" == self.result.summary())
    def testFailedResult(self):
        self.test = wasRun("testBrokenMethod")
        self.test.run(self.result)
        assert("1 run, 1 failed" == self.result.summary())
    def testFailedResultFormating(self):
        self.result.testStarted()
        self.result.testFailed()
        assert("1 run, 1 failed" == self.result.summary())
    def testSuite(self):
        suite = TestSuite(wasRun)
        suite.run(self.result)
        assert("2 run, 1 failed" == self.result.summary())
    def testTearDownAfterFail(self):
        self.test = wasRun("testBrokenMethod")
        self.test.run(self.result)
        assert("setUp testBrokenMethod tearDown " == self.test.log)
        assert("1 run, 1 failed" == self.result.summary())
    def testCatchSetUpError(self):
        self.test = hasErrorInSetUp("testCatchSetUpError")
        self.test.run(self.result)
        assert("setUp error" == self.result.errors())
        assert("1 run, 1 failed" == self.result.summary())


class hasErrorInSetUp(testCase):
    def __init__(self, name) -> None:
        super().__init__(name)
    def setUp(self):
        raise Exception("setUp error")


class TestResult():
    def __init__(self):
        self.runCount = 0
        self.errorCount = 0
        self.errorMessages = []
    def testStarted(self):
        self.runCount += 1
    def testFailed(self):
        self.errorCount += 1
    def saveErrorMessage(self, errorMessage):
        self.errorMessages.append(errorMessage) 
    def errors(self):
        return "\n".join(self.errorMessages)
    def summary(self):
        return "%d run, %d failed" % (self.runCount, self.errorCount)


class TestSuite():
    def __init__(self, testCaseInstance=None):
        self.tests = []
        self.testCaseInstance = testCaseInstance
        self.__extractTests__()
    def __extractTests__(self):
        testCaseFunctions = inspect.getmembers(self.testCaseInstance, predicate=inspect.isfunction)
        for testCaseFunctionName, testCaseFunction in testCaseFunctions:
            if(testCaseFunctionName.startswith("test")):
                self.tests.append(self.testCaseInstance(testCaseFunctionName))
    def run(self, result):
        for test in self.tests:
            test.run(result)