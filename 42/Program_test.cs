namespace MyApp {
internal partial class Piscine {

  static void test_ft_str_is_numeric() {
    bool test1 = ft_str_is_numeric("12345689") == 1;
    bool test2 = ft_str_is_numeric("HelloWorld") == 0;
    bool test3 = ft_str_is_numeric("#%*# #($*%)") == 0;
    bool test4 = ft_str_is_numeric("Hell1World") == 0;
    bool test5 = ft_str_is_numeric("-12345") == 0;

    Console.WriteLine($"Test 1: {test1}");
    Console.WriteLine($"Test 2: {test2}");
    Console.WriteLine($"Test 3: {test3}");
    Console.WriteLine($"Test 4: {test4}");
    Console.WriteLine($"Test 5: {test5}");
  }

  static void test_ft_str_is_alpha() {
    bool test1 = ft_str_is_alpha("HelloWorld") == 1;
    bool test2 = ft_str_is_alpha("Hello123") == 0;
    bool test3 = ft_str_is_alpha("!@#$%^&*") == 0;
    bool test4 = ft_str_is_alpha("") == 1;
    bool test5 = ft_str_is_alpha("TestString") == 1;

    Console.WriteLine($"Test 1: {test1}");
    Console.WriteLine($"Test 2: {test2}");
    Console.WriteLine($"Test 3: {test3}");
    Console.WriteLine($"Test 4: {test4}");
    Console.WriteLine($"Test 5: {test5}");
  }

  static void test_ft_strcpy_intensive() {
    bool test1 = ft_strcpy_test("Hello", "World", "World");
    bool test2 = ft_strcpy_test("Test", "", "");
    bool test3 = ft_strcpy_test("", "Test", "Test");
    bool test4 = ft_strcpy_test("12345", "67890", "67890");
    bool test5 = ft_strcpy_test("Short", "LongerString", "LongerString");
    bool test6 = ft_strcpy_test("Same", "Same", "Same");

    Console.WriteLine($"Test 1: {test1}");
    Console.WriteLine($"Test 2: {test2}");
    Console.WriteLine($"Test 3: {test3}");
    Console.WriteLine($"Test 4: {test4}");
    Console.WriteLine($"Test 5: {test5}");
    Console.WriteLine($"Test 6: {test6}");
  }

  static bool ft_strcpy_test(string dest, string src, string expected) {
    ft_strcpy(ref dest, src);
    return dest == expected;
  }
  static void test_ft_strncpy_intensive() {
    bool test1 = ft_strncpy_test("Hello", "World", 3, "Wor");
    bool test2 = ft_strncpy_test("Test", "", 3, "\0\0\0");
    bool test3 = ft_strncpy_test("", "Test", 2, "Te");
    bool test4 = ft_strncpy_test("12345", "67890", 5, "67890");
    bool test5 = ft_strncpy_test("Short", "LongerString", 5, "Longe");
    bool test6 = ft_strncpy_test("Same", "Same", 4, "Same");

    Console.WriteLine($"Test 1: {test1}");
    Console.WriteLine($"Test 2: {test2}");
    Console.WriteLine($"Test 3: {test3}");
    Console.WriteLine($"Test 4: {test4}");
    Console.WriteLine($"Test 5: {test5}");
    Console.WriteLine($"Test 6: {test6}");
  }

  static bool ft_strncpy_test(string dest, string src, int n, string expected) {
    ft_strncpy(ref dest, src, n);
    return dest == expected;
  }
}
}
