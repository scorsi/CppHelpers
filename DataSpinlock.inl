
#pragma once

#include "DataSpinlock.hpp"

template <class Object>
Object& DataSpinlock<Object>::getData(void)
{
	return this->_data;
}

template <class Object>
void DataSpinlock<Object>::lock(void)
{
	while (this->_state.exchange(DataSpinlockState::Locked, boost::memory_order_acquire)
		== DataSpinlockState::Locked);
}

template <class Object>
void DataSpinlock<Object>::unlock(void)
{
	this->_state.store(DataSpinlockState::Unlocked, boost::memory_order_release);
}
