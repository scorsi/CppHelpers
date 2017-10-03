
#pragma once

#include "Singleton.hpp"

template<typename Object>
std::unique_ptr<Object> Singleton<Object>::instance = nullptr;

template <class Object>
static bool Singleton<Object>::createInstance(void)
{
	if (Singleton::instance != nullptr)
		return false;

	Singleton::instance = std::make_unique<Object>();
	return true;
}

template <class Object>
static void Singleton<Object>::destroyInstance(void)
{
	Singleton::instance.release();
}

template <class Object>
static Object& Singleton<Object>::getInstance(void)
{
	assert(Singleton::instance != nullptr);
	return *Singleton::instance.get();
}

template <class Object>
static Object* Singleton<Object>::getInstancePtr(void)
{
	assert(Singleton::instance != nullptr);
	return Singleton::instance.get();
}

template <class Object>
static bool Singleton<Object>::hasInstance(void)
{
	return instance != nullptr;

}
