#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

static const char orientation[] = {'N', 'E', 'S', 'W'};

void forward(int &x, int &y, int face,
             const std::vector<std::vector<char>> &maze) {
  int tx = x;
  int ty = y;
  switch (orientation[face]) {
  case 'N':
    tx = tx - 1;
    break;
  case 'S':
    tx = tx + 1;
    break;
  case 'E':
    ty = ty + 1;
    break;
  case 'W':
    ty = ty - 1;
    break;
  defult:
    break;
  }
  if (maze[tx][ty] != '*') {
    x = tx;
    y = ty;
  }
}

void solve_uva_problem(std::istream &is, std::ostream &os) {

  int times;
  is >> times;

  while (times--) {

    int row, col;
    is >> row >> col;
    is.ignore();

    std::vector<std::vector<char>> maze(row + 1, std::vector<char>(col + 1));
    for (int i = 1; i <= row; ++i) {
      std::string s;
      getline(is, s);
      for (int j = 1; j <= col; ++j) {
        maze[i][j] = s[j - 1];
      }
    }

    int posX, posY;
    int face = 0;
    is >> posX >> posY;
    is.ignore();

    std::string command;
    while (getline(is, command)) {
      command.erase(remove(command.begin(), command.end(), ' '), command.end());
      for (size_t i = 0; i < command.size(); ++i) {
        if (command[i] == 'R') {
          face = (face + 1) % 4;
        } else if (command[i] == 'L') {
          face = (face + 3) % 4;
        } else if (command[i] == 'F') {
          forward(posX, posY, face, maze);
        } else
          os << posX << " " << posY << " " << orientation[face] << std::endl;
      }

      if (command[command.size() - 1] == 'Q')
        break;
    }

    if (times)
      os << std::endl;
  }
}

int main(int argc, char **argv) {
#if !defined(WITH_GTEST)
  solve_uva_problem(std::cin, std::cout);
#else
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#endif
}
