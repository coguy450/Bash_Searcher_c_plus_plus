#include <set>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

class Searcher
{
private:
  set<string> searchResults;
  vector<fs::path> myVector;
  string searchStringSet;
  string getText(string &currentLine);
  void searchText(string &fileText);

  void openFile(fs::path p);

public:
  Searcher(fs::path p);
  void sayHi();
  void getFileList();
  void setSearchString(string s);
  int getFilenames(fs::path &path);
  void getResults();
};