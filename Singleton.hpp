
#pragma once

#include <memory>
#include <cassert>

template <class Object>
class Singleton
{
public:
	static bool createInstance(void);

	static void destroyInstance(void);

	static Object& getInstance(void);

	static Object* getInstancePtr(void);

	static bool hasInstance(void);

protected:
	Singleton(void) {}
	virtual ~Singleton(void) {}

private:

	//Disable copy constructor & assignment operator
	Singleton(Singleton const&) {}
	Singleton& operator=(Singleton const&) {}

	static std::unique_ptr<Object> instance;
};

#include "Singleton.inl"
