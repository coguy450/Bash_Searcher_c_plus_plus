#include <iostream>
#include <filesystem>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include "Searcher.h"

using namespace std;
namespace fs = std::filesystem;

Searcher::Searcher(fs::path p)
{
  cout << "Instantiated searcher with path " << p << endl;
  fileList.push_back(p);
}

void Searcher::openFile(fs::path fp)
{
  ifstream f(fp);
  string str;
  ostringstream ss;
  ss << f.rdbuf();
  str = ss.str();
  searchText(str);
}

void Searcher::getFileList()
{
  for (auto i : fileList)
    openFile(i);
}

void Searcher::setSearchString(string s)
{
  if (!s.empty())
  {
    searchStringSet = s;
  }
  else
  {
    cout << "Please enter search string!";
  } 
}

int Searcher::getFilenames(fs::path &path)
{
  for (const auto& entry : fs::directory_iterator(path))
      fileList.push_back(entry.path());
  return 0;
}

string Searcher::getText(string &currentLine)
{
  if (currentLine.find(searchStringSet) != string::npos)
  {
    auto d = "\n";
    size_t posB = 0;
    posB = currentLine.find(d);
    // Could refactor this to use a boolean
    string goodLine = currentLine.substr(0, posB);
    return goodLine;
  }
  else
  {
    return "";
  }
};

void Searcher::searchText(string &fileText)
{
  size_t pos = 0;
  string currentL;
  
  auto d = "\n";
  while (fileText.length() > 0 && ((pos = fileText.find(d)) != string::npos))
  {
    // Grab the current line from the file
    currentL = fileText.substr(0, pos);

    // See if this line has the text in it
    string qResult = getText(currentL);

    // If you get a result, insert it in a set to eliminate dups
    if (qResult.length() > 0)
    {
      searchResults.insert(currentL);
    }
    // Delete the line you've just iterated through
    fileText.erase(0, pos + 1);
  }
}

// Loop through the contents of the set
void Searcher::getResults()
{
  for (auto it = searchResults.begin(); it != searchResults.end(); it++)
      cout << *it << " " << endl;
}