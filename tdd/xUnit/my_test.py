class testCase:
    def __init__(self, name) -> None:
        self.name = name
    def setUp(self):
        pass
    def run(self):
        self.setUp()
        method = getattr(self, self.name)
        method()


class wasRun(testCase):
    def __init__(self, name) -> None:
        testCase.__init__(self, name)
    def testMethod(self):
        self.wasRun = 1
    def setUp(self):
        self.wasRun = None
        self.wasSetUp = 1


class TestCaseTest(testCase):
    def setUp(self):
        self.test = wasRun("testMethod")
    def testRunning(self):
        self.test.run()
        assert(self.test.wasRun)
    def testSetUp(self):
        self.test.run()
        assert(self.test.wasSetUp)