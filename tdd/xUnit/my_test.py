class testCase:
    def __init__(self, name) -> None:
        self.name = name
    def setUp(self):
        pass
    def tearDown(self):
        pass
    def run(self, result):
        result.testStarted()
        self.setUp()
        try:
            method = getattr(self, self.name)
            method()
        except:
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
        suite = TestSuite()
        suite.add(wasRun("testMethod"))
        suite.add(wasRun("testBrokenMethod"))
        suite.run(self.result)
        assert("2 run, 1 failed" == self.result.summary())
    def testTearDownAfterFail(self):
        self.test = wasRun("testBrokenMethod")
        self.test.run(self.result)
        assert("setUp testBrokenMethod tearDown " == self.test.log)
        assert("1 run, 1 failed" == self.result.summary())

class TestResult():
    def __init__(self):
        self.runCount = 0
        self.errorCount = 0
    def testStarted(self):
        self.runCount += 1
    def testFailed(self):
        self.errorCount += 1 
    def summary(self):
        return "%d run, %d failed" % (self.runCount, self.errorCount)


class TestSuite():
    def __init__(self):
        self.tests = []
    def add(self, test):
        self.tests.append(test)
    def run(self, result):
        for test in self.tests:
            test.run(result)