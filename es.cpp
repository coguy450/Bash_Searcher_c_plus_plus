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
  fs::path z = getenv("HOME");
  p += "/.bash_history";
  dr += "/.bash_sessions";
  z += "/.zsh_history";
   // Need to add zsh history .zsh_history
  // add bash history to bash sessions

  string searchString;
  Searcher se(z);
  se.addPath(p);
  // Get search string
  cout << "Enter Search string: ";
  getline(cin, searchString);

  se.setSearchString(searchString);
  se.getFilenames(dr);
  se.getFileList();
  se.getResults();

  return 0;
}
