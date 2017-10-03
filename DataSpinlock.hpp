
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
	Object& getData(void);
	void lock(void);
	void unlock(void);

private:
	boost::atomic<DataSpinlockState> _state;
	Object _data;
};

#include "DataSpinlock.inl"
