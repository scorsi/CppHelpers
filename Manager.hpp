
#pragma once

#include <vector>
#include <map>
#include <memory>

template <class Object, typename Key>
class Manager
{
public:
	virtual bool initialize(void);
	virtual bool shutdown(void);

	bool exists(const Key& key);

	bool empty(void) const;
	std::size_t getSize(void) const;

	void clear(void);
	void destroy(void);

	bool addObject(const Key& key, Object*);
	bool addObject(const Key& key, std::shared_ptr<Object>&);

	bool removeObject(const Key& key);

	std::shared_ptr<Object>& getObject(const Key& key);

	const std::map<Key, std::shared_ptr<Object>>& getAllObjects(void) const;

private:
	typename std::map<Key, std::shared_ptr<Object>>::const_iterator getIteratorByKey(Key key) const;

private:
	std::map<Key, std::shared_ptr<Object>> m_managerMap;
};

#include "Manager.inl"
