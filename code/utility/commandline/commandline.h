#pragma once
#include <string>
#include <list>
#include <memory>

#include "ytype.h"

namespace UTL
{
    class CommandLine
    {
    public:
        struct Config
        {
            const std::string shortName;
            const std::string longName;
            const uint numPara;

            Config( const std::string &sn, const std::string &ln, const uint &np )
                : shortName( sn )
                , longName( ln )
                , numPara( np )
            {
            }
        };

        struct Result
        {
            std::string shortName;
            std::string longName;
            ListString arguments;

            Result( const std::string &sn, const std::string &ln )
                :shortName( sn )
                , longName( ln )
            {
            }
        };

        using ConfigList = std::list<Config>;
        using ResultList = std::list<Result>;
        using ConfigIter = ConfigList::iterator;
        using ResultIter = ResultList::iterator;
        using ConfigListPtr = std::unique_ptr<ConfigList>;
        using ResultListPtr = std::unique_ptr<ResultList>;

        CommandLine( ConfigListPtr &&config );
        void processArguments( int argc, char *argv[] );

        ResultIter begin() const;
        ResultIter end() const;

    private:
        bool isCommandName( const std::string &name ) const;
        bool isCommandShortName( const std::string &name ) const;
        bool isCommandLongName( const std::string &name ) const;
        std::string getCommandName( const std::string &name ) const;

        ConfigIter getConfigByShortOrLongName( const std::string &name ) const;

        ConfigListPtr configList;
        ResultListPtr resultList;
    };
}
