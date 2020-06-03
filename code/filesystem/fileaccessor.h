#pragma once
#include <string>
#include <fstream>

class FileReader
{
public:
    FileReader();
    ~FileReader();

    FileReader( const FileReader& ) = delete;
    FileReader& operator=( const FileReader& ) = delete;

    bool openFile( const std::string &filePath );
    void closeFile();
    size_t fileLength();
    size_t readFile( char *buffer, size_t bufferSize );

private:
    std::ifstream m_file;
    size_t m_fileLength;
};
