#include <regex>

#include "read-file.h"

regex TK_KEYWORD("(int|return)");
regex TK_OPEN_PARENTHESES("(\()");
regex TK_CLOSE_PARENTHESES("(\))");

int main(int argc, char **argv)
{
  FileReader fileReader;
  string current_line;

  if (argc < 2)
  {
    cout << "You need to pass a file" << endl;

    return 0;
  }

  fileReader = FileReader(argv[1]);

  try
  {
    do
    {
      cout << fileReader.get_next_line() << '\n';
    } while (!fileReader.is_eof());
  }
  catch (const std::exception &e)
  {
    cerr << e.what() << '\n';
  }

  return 0;
}