class testCase:
    def __init__(self, name) -> None:
        self.name = name
    def run(self):
        method = getattr(self, self.name)
        method()


class wasRun(testCase):
    def __init__(self, name) -> None:
        self.wasRun = None
        testCase.__init__(self, name)
    def testMethod(self):
        self.wasRun = 1


class TestCaseTest(testCase):
    def testRunning(self):
        test = wasRun("testMethod")
        assert(not test.wasRun)
        test.run()
        assert(test.wasRun)