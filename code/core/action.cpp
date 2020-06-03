#include <string>
#include "action.h"


ActionDelete::ActionDelete( const std::string& path )
{

}


bool ActionDelete::Do()
{
	return true;
}


ActionCopy::ActionCopy( const std::string& path )
{

}


bool ActionCopy::Do()
{
	return true;
}