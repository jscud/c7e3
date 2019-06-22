# C7E3 Testing Library

This helper library provides a mechanism for writing simple unit tests in C
programs. Use the c7e3_assert to check comparison statements that are expected
to evaluate true. After listing all assertions, call c7e3_report to print any
failure messages from the tests that have been run.

Here's a simple example of a program that runs tests using this library:

    int main(void)
    {
      c7e3_assert(1 == 1, "1 should equal 1");
      c7e3_assert(2 == 2, "2 should equal 2");
      c7e3_report();
      return 0;
    }
