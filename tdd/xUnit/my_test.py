class testCase:
    def __init__(self, name) -> None:
        self.name = name
    def setUp(self):
        pass
    def tearDown(self):
        pass
    def run(self):
        self.setUp()
        exec("self." + self.name + "()")
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



class TestCaseTest(testCase):
    def setUp(self):
       pass
    def testTemplateMethod(self):
        self.test = wasRun("testMethod")
        self.test.run()
        assert("setUp testMethod tearDown " == self.test.log)