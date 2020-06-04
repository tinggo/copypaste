#include <iostream>
#include "manager.h"
#include "utility/commandline/commandline.h"

void Manager::initialize( int argc, char *argv[] )
{
    std::unique_ptr<UTL::CommandLine::ConfigList> configs = std::make_unique<UTL::CommandLine::ConfigList>();
    configs->push_back( UTL::CommandLine::Config{"u", "user", 1} );
    configs->push_back( UTL::CommandLine::Config{"p", "password", 1} );
    configs->push_back( UTL::CommandLine::Config{"h", "helloworld", 2} );
    UTL::CommandLine commandLine( std::move( configs ) );
    commandLine.processArguments( argc, argv );
    for(const UTL::CommandLine::Result &result : commandLine)
    {
        std::cout << result.shortName << " " << result.longName;
        for(const std::string &argument : result.arguments)
        {
            std::cout << " " << argument;
        }
        std::cout << std::endl;
    }
    std::cout << "argument initialize complete" << std::endl;
}

void Manager::process( const std::string &command )
{

}


