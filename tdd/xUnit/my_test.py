class testCase:
    def __init__(self, name) -> None:
        self.name = name
    def setUp(self):
        pass
    def tearDown(self):
        pass
    def run(self):
        result = TestResult()
        result.testStarted()
        self.setUp()
        try:
            exec("self." + self.name + "()")
        except:
            result.testFailed()
        self.tearDown()
        return result


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
        raise Exception



class TestCaseTest(testCase):
    def setUp(self):
       pass
    def testTemplateMethod(self):
        self.test = wasRun("testMethod")
        self.test.run()
        assert("setUp testMethod tearDown " == self.test.log)
    def testResult(self):
        self.test = wasRun("testMethod")
        result = self.test.run()
        assert("1 run, 0 failed" == result.summary())
    def testFailedResult(self):
        self.test = wasRun("testBrokenMethod")
        result = self.test.run()
        assert("1 run, 1 failed" == result.summary())
    def testFailedResultFormating(self):
        result = TestResult()
        result.testStarted()
        result.testFailed()
        assert("1 run, 1 failed" == result.summary())

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
