#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader
{
public:
  string lineContent;

  FileReader();
  FileReader(string);

  void change_file(string);
  string get_next_line();
  bool is_eof();

private:
  string currentFile;
  ifstream fileStream;
};
