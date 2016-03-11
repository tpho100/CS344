#include "Integer.h"

int Integer::get_value() const
{
	return value;
}
		
int Integer::get_count() const
{
	return count;
}

bool Integer::operator<(const Integer& i)
{
	count++;
	if(value < i.value)
	{
		return true;
	}
	return false;
}

bool Integer::operator<=(const Integer& i)
{
	count++;
	if(value <= i.value)
	{
		return true;
	}
	return false;
}
		
