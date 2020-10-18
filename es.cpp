#include <iostream>
#include <filesystem>
#include "Searcher.h"
#include <string>
#include <set>
namespace fs = std::filesystem;
using namespace std;

// clang++ --std=c++17 -Wall -g -o esearch ./esearch.cpp
// clang++ --std=c++17 -Wall -o out -I ./ *.cpp /*.cpp
// Extra credit, loop through multiple bash history session files
//.bash_sessions/002BEBF8-5BE9-4019-A849-D38E88C6BB19.history etc

int main()
{
  fs::path p = getenv("HOME");
  fs::path dr = getenv("HOME");
  dr += "/.bash_sessions";
  p += "/.bash_history";
  string searchString;
  Searcher se(p);
  // Get search string
  cout << "Enter Search string: ";
  
  cin >> searchString;
  cout << searchString;
  se.setSearchString(searchString);
  se.getFilenames(dr);
  se.getFileList();
  se.getResults();

  return 0;
}
