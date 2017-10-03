
#pragma once

#include <memory>

template<class Object>
class Prototype
{
public:
	virtual std::unique_ptr<Object> clone(void) const = 0;
};
