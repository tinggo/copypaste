#include <cassert>
#include <algorithm>

#include "fileaccessor.h"


FileReader::FileReader()
    : m_fileLength( 0 )
{
}


FileReader::~FileReader()
{
    closeFile();
}


bool FileReader::openFile( const std::string &filePath )
{
    m_file.open( filePath.c_str() );
    if ( m_file )
    {
        m_file.seekg( 0, std::ios_base::end );
        m_fileLength = m_file.tellg();
        m_file.seekg( 0, std::ios_base::beg );
        return true;
    }
    return false;
}


void FileReader::closeFile()
{
    if ( m_file )
    {
        m_file.close();
        m_fileLength = 0;
    }
}

size_t FileReader::fileLength()
{
    return m_fileLength;
}


size_t FileReader::readFile( char *buffer, size_t bufferSize )
{
    size_t curPosition = m_file.tellg();
    size_t remainToRead = m_fileLength - curPosition;
    size_t readLength = std::min( bufferSize, remainToRead );
    m_file.read(buffer, readLength );
    return  m_file.gcount();
}
