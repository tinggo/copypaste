#include <cassert>
#include "commandline.h"

namespace UTL
{
    CommandLine::CommandLine( ConfigListPtr &&config )
        : configList( std::forward<ConfigListPtr>( config ) )
    {
        resultList = std::make_unique<ResultList>();
    }

    void CommandLine::processArguments( int argc, char *argv[] )
    {
        ResultIter currentResultIt = resultList->end();
        ConfigIter currentConfigIt = configList->end();
        for(int i = 1; i < argc; ++i)
        {
            std::string name = argv[i];
            if(isCommandName( name ))
            {
                ConfigIter it = getConfigByShortOrLongName( name );
                if(it != configList->end())
                {
                    Result newResult{it->shortName, it->longName};
                    currentResultIt = resultList->insert( resultList->end(), newResult );
                    currentConfigIt = it;
                }
            }
            else
            {
                if(currentResultIt != resultList->end())
                {
                    assert( currentConfigIt != configList->end() );
                    currentResultIt->arguments.push_back( argv[i] );
                    if(currentResultIt->arguments.size() >= currentConfigIt->numPara)
                    {
                        currentResultIt = resultList->end();
                        currentConfigIt = configList->end();
                    }
                }
                else
                {
                    size_t resultListLen = resultList->size();
                    bool hasEmptyResult = false;
                    if(resultListLen > 0)
                    {
                        ResultIter it = resultList->begin();
                        if(it->shortName == "" && it->longName == "")
                            hasEmptyResult = true;
                    }
                    if(!hasEmptyResult)
                    {
                        Result noCommandResult{"", ""};
                        resultList->push_front( noCommandResult );
                    }
                    ResultIter noCommandResultIter = resultList->begin();
                    noCommandResultIter->arguments.push_back( argv[i] );
                }
            }
        }
    }

    CommandLine::ResultIter CommandLine::begin() const
    {
        return resultList->begin();
    }

    CommandLine::ResultIter CommandLine::end() const
    {
        return resultList->end();
    }

    bool CommandLine::isCommandName( const std::string &name ) const
    {
        return isCommandShortName( name ) || isCommandLongName( name );
    }

    bool CommandLine::isCommandShortName( const std::string &name ) const
    {
        if(name.length() >= 2)
            return name[0] == '-' && name[1] != '-';
        else
            return false;
    }

    bool CommandLine::isCommandLongName( const std::string &name ) const
    {
        if(name.length() >= 3)
            return name[0] == '-' && name[1] == '-';
        else
            return false;
    }

    std::string CommandLine::getCommandName( const std::string &name ) const
    {
        assert( isCommandName( name ) );
        if(isCommandShortName( name ))
            return name.substr( 1 );
        else
        {
            assert( isCommandLongName( name ) );
            return name.substr( 2 );
        }
    }

    CommandLine::ConfigIter CommandLine::getConfigByShortOrLongName( const std::string &name ) const
    {
        std::string commandName = getCommandName( name );
        for(ConfigIter it = configList->begin(); it != configList->end(); ++it)
        {
            if(it->shortName == commandName || it->longName == commandName)
            {
                return it;
            }
        }
        return configList->end();
    }
}
