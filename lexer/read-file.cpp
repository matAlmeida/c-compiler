#include "read-file.h"

FileReader::FileReader()
{
}

FileReader::FileReader(string filePath)
{
  this->change_file(filePath);
}

void FileReader::change_file(string filePath)
{
  this->lineContent.clear();
  this->currentFile = filePath;
  this->fileStream.open(filePath);

  if (!this->fileStream)
  {
    throw "Unable to open file";
  }
}

bool FileReader::is_eof()
{
  if (!this->fileStream.is_open() || this->fileStream.eof())
  {
    return true;
  }

  return false;
}

string FileReader::get_next_line()
{
  if (!this->fileStream.is_open())
  {
    throw "Unable to read file";
  }

  getline(this->fileStream, this->lineContent);

  if (this->fileStream.eof())
  {
    this->fileStream.close();
  }

  return this->lineContent;
}
