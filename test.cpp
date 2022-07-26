#include "main.cpp"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
TEST(TestCase1, Solution) {
  auto Solve = [](std::istream &is) -> std::string {
    std::ostringstream oss;
    solve_uva_problem(is, oss);
    return std::string("\n") + oss.str();
  };
  {
    std::stringstream fake_cin;
    fake_cin << R"(
1

7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ
)";

    EXPECT_EQ(
        R"(
5 6 W
)",
        Solve(fake_cin));
  }
}

#if 1
TEST(TestCase3, Solution) {
  auto Solve = []() -> std::string {
    std::ifstream fs("./data1");
    std::ostringstream oss;
    solve_uva_problem(fs, oss);
    return std::string("\n") + oss.str();
  };
  {
    EXPECT_EQ(
        R"(
11 5 E

2 10 N

11 2 S

7 2 S

6 5 W

3 7 N

10 9 N

4 13 N

7 6 N

4 5 E

5 7 N

6 3 S

3 4 N

4 3 W

3 10 E

7 5 S

3 4 W

7 12 W

6 5 N

2 10 E

4 6 W

2 3 N

9 3 N

7 3 N

10 9 E

3 3 N

7 22 N

8 8 S

7 12 W

2 2 N

5 6 N

13 2 S

2 4 N

4 7 W

10 7 N

7 2 W

7 10 S

5 8 N

4 3 E

3 18 S

4 11 E

4 9 S

3 7 E

6 5 W

3 2 S

9 6 E

2 10 N

2 2 W

4 6 E

5 9 N

3 8 E

15 4 E

2 2 E

7 2 S

6 12 W

6 7 N

2 3 E

10 7 S

4 2 N

8 2 E

4 4 E

6 6 N

3 2 W

17 2 S

4 3 S

4 5 N

2 18 N

17 6 S

13 12 E

8 5 N

4 3 W

12 2 E

10 9 E

7 18 S

11 2 E

8 3 W

11 11 E

4 2 S

2 12 E

14 4 E

4 7 W

5 8 S

4 7 W

18 2 W

6 16 N

5 8 W

3 6 E

2 3 W

3 4 E

17 5 S

4 13 N

5 3 N

5 2 S

13 2 E

2 4 N

6 2 W

9 4 N

2 20 E

3 3 S

2 5 S
)",
        Solve());
  }
}
#endif
