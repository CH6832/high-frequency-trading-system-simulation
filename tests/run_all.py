import unittest

if __name__ == "__main__":
    loader = unittest.TestLoader()
    tests = loader.discover('.')
    testRunner = unittest.TextTestRunner(verbosity=2)
    testRunner.run(tests)
