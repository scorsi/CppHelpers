
#pragma once

#include "Manager.hpp"

#include <cassert>
#include <memory>
#include <map>
#include <algorithm>

/*
template <class Object, typename Key>
Manager<Object, Key>::Manager()
{
}

template <class Object, typename Key>
Manager<Object, Key>::~Manager()
{
}
*/

template <class Object, typename Key>
bool Manager<Object, Key>::initialize(void)
{
	return true;
}

template <class Object, typename Key>
bool Manager<Object, Key>::shutdown(void)
{
	this->clear();
	return true;
}

template <class Object, typename Key>
bool Manager<Object, Key>::exists(const Key& key)
{
	return this->getIteratorByKey(key) != this->m_managerMap.end();
}

template <class Object, typename Key>
bool Manager<Object, Key>::empty(void) const
{
	return this->m_managerMap.empty();
}

template <class Object, typename Key>
std::size_t Manager<Object, Key>::getSize(void) const
{
	return this->m_managerMap.size();
}

template <class Object, typename Key>
void Manager<Object, Key>::clear(void)
{
	this->m_managerMap.clear();
}

template <class Object, typename Key>
void Manager<Object, Key>::destroy(void)
{
	this->m_managerMap.clear();
}

template <class Object, typename Key>
bool Manager<Object, Key>::addObject(const Key& key, Object* object)
{
	std::assert(object != nullptr);

	if (this->getIteratorByKey(key) != this->m_managerMap.end())
		return false;
	
	this->m_managerMap[key] = std::make_shared<Object>(object);
	return true;
}

template <class Object, typename Key>
bool Manager<Object, Key>::addObject(const Key& key, std::shared_ptr<Object>& object)
{
	std::assert(object != nullptr);

	if (this->getIteratorByKey(key) != this->m_managerMap.end())
		return false;

	this->m_managerMap[key] = object;
	return true;
}

template <class Object, typename Key>
bool Manager<Object, Key>::removeObject(const Key& key)
{
	std::map<Key, std::shared_ptr<Object>>::const_iterator it = this->getIteratorByKey(key);
	if (it == this->m_managerMap.end())
		return false;

	this->m_managerMap.erase(it);
	return true;
}

template <class Object, typename Key>
std::shared_ptr<Object>& Manager<Object, Key>::getObject(const Key& key)
{
	return this->m_managerMap.at(key);
}

template <class Object, typename Key>
const std::map<Key, std::shared_ptr<Object>>& Manager<Object, Key>::getAllObjects(void) const
{
	return this->m_managerMap;
}

template <class Object, typename Key>
typename std::map<Key, std::shared_ptr<Object>>::const_iterator Manager<Object, Key>::getIteratorByKey(Key key) const
{
	std::map<Key, std::shared_ptr<Object>>::const_iterator it = std::find_if(this->m_managerMap.begin(), this->m_managerMap.end(),
		[id](std::pair<Key, std::shared_ptr<Object>> pair)
	{
		return id == pair.first;
	});

	return it;
}
