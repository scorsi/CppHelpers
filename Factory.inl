
#pragma once

#include "Factory.hpp"

template <class Object, typename Key>
std::map<Key, std::unique_ptr<Object>> Factory<Object, Key>::m_factoryMap = {};

template <class Object, typename Key>
template <class Prototype>
static void Factory<Object, Key>::registerPrototype(const Key& key)
{
	if (m_factoryMap.find(key) == m_factoryMap.end())
	{
		m_factoryMap[key] = std::make_unique<Prototype>();
	}
}

template <class Object, typename Key>
static Object* Factory<Object, Key>::getPrototype(const Key& key)
{
	if (m_factoryMap.find(key) == m_factoryMap.end())
	{
		return nullptr;
	}
	return m_factoryMap.at(key).get();
}

template <class Object, typename Key>
std::unique_ptr<Object> Factory<Object, Key>::create(const Key& key)
{
	std::unique_ptr<Object> tmp = nullptr;
	/*
	auto it = m_factoryMap.find(key);

	if (it != m_factoryMap.end())
	{
		tmp = ((*it).second)->clone();
	}
	*/
	return tmp;
}
