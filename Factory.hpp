
#pragma once

#include <memory>
#include <map>

template <class Object, class Key>
class Factory
{
public:
	Factory(void) = default;
	virtual ~Factory(void) = default;

	template <class Prototype>
	static void registerPrototype(const Key& key);

	static Object* getPrototype(const Key& key);

	std::unique_ptr<Object> create(const Key& key);

private:
	static std::map<Key, std::unique_ptr<Object>> m_factoryMap;
};

#include "Factory.inl"
