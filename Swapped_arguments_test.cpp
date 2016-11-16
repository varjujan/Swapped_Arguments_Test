void foo_1(int aaaaaa, int bbbbbb) { }

void foo_2(int source, int aaaaaa) { }

void foo_3(int valToRet, int aaaaaa) { }

void foo_4(int pointer, int aaaaaa) { }

void foo_5(int aaaaaa, int bbbbbb, int cccccc, ...) { }

void foo_6(const int dddddd, bool& eeeeee) { }

class TestClass {
public:
  void thisFunction(int integerParam, int thisIsPARAM) {}
};

int main() {

	// Equality test.
  int aaaaaa, cccccc = 0;  
  foo_1(cccccc, aaaaaa); // Should fail.
    
  // Abbreviation test.
  int src = 0;
  foo_2(aaaaaa, src); // Should fail.
  
  // Levenshtein test.
  int aaaabb = 0;
  foo_1(cccccc, aaaabb); // Should fail.
  
  // Prefix test.
  int aaaa = 0;
  foo_1(cccccc, aaaa); // Should fail.
  
  // Suffix test.
  int urce = 0;
  foo_2(cccccc, urce); // Should fail.
  
  // Substring test.
  int ourc = 0;
  foo_2(cccccc, ourc); // Should fail.
  
  // Jaro-Winkler test.
  int iPonter = 0;
  foo_4(cccccc, iPonter); // Should fail.
  
  // Dice test.
  int aaabaa = 0;
  foo_1(cccccc, aaabaa); // Should fail.
   
  // Variadic function test.
  int bbbbbb = 0;
  foo_5(src, bbbbbb, cccccc, aaaaaa); // Should pass.
  foo_5(cccccc, bbbbbb, aaaaaa, src); // Should fail.
  
  //Type match
  bool dddddd = false;
  int eeeeee = 0;
  auto szam = 0;
  foo_6(eeeeee, dddddd); // Should pass.
  foo_1(szam, aaaaaa); // Should fail.
  
  // Test lambda.
  auto testMethod = [&](int method, int randomParam) { return 0; };
  int method = 0;
  testMethod(method, 0); // Should pass.

  // Member function test
  TestClass test;
  int integ, thisIsAnArg = 0;
  test.thisFunction(integ, thisIsAnArg); // Should pass.

  return 0;
}