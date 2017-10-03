
#pragma once

#include <boost/atomic.hpp>

#include "NonCopyable.hpp"
#include "NonMovable.hpp"

enum class DataSpinlockState
{
	Locked,
	Unlocked
};

template <class Object>
class DataSpinlock
	: public NonCopyable, public NonMovable
{
public:
	DataSpinlock(void) : _state(DataSpinlockState::Unlocked) {}
	virtual ~DataSpinlock(void) {}

	Object& getData(void);
	void setData(const Object& data);
	
	void lock(void);
	void unlock(void);

protected:
	boost::atomic<DataSpinlockState> _state;
	Object _data;
};

#include "DataSpinlock.inl"
