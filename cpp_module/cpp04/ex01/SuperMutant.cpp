#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
{
	
}

SuperMutant::~SuperMutant()
{

}

SuperMutant::SuperMutant(SuperMutant const& origin)
{
	*this = origin;
}

SuperMutant& SuperMutant::operator=(SuperMutant const& origin)
{
	this->/*value*/ = origin./*value*/;
	return (*origin);
}


