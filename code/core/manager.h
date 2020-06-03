#pragma once
#include <string>

class Manager
{
public:
    Manager() : m_exiting( false ) {}
    void initialize( int argc, char* argv[] );
    void process( const std::string& command );
    inline bool exiting() { return m_exiting; }
private:
    bool m_exiting;
};
