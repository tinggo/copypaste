#include <iostream>
#include "core/manager.h"

int main( int argc, char* argv[] )
{
	Manager manager;
	manager.initialize( argc, argv );
	while( !manager.exiting() )
	{
		std::string command;
		std::cin>>command;
		manager.process( command );
	}
	return 0;
}