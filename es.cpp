#include <iostream>
#include <filesystem>
#include "Searcher.h"
#include <string>
#include <set>
namespace fs = std::filesystem;
using namespace std;
// clang++ --std=c++17 -Wall -g -o es ./es.cpp

int main()
{
  fs::path p = getenv("HOME");
  fs::path dr = getenv("HOME");
  dr += "/.bash_sessions";
  // add bash history to bash sessions
  p += "/.bash_history";
  string searchString;
  Searcher se(p);

  // Get search string
  cout << "Enter Search string: ";
  
  cin >> searchString;

  se.setSearchString(searchString);
  se.getFilenames(dr);
  se.getFileList();
  se.getResults();

  return 0;
}
