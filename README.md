# CppHelpers
All my C++ Helpers

## DataSpinlock
The purpose of the DataSpinlock is to prevent multiple threads from concurrently accessing a shared data. In contrast to a mutex, threads will busy-wait and waste CPU cycles instead of yielding the CPU to another thread. Do not use spinlocks unless you are certain that you understand the consequences.

### Examples

Declaration:
```cpp

#include "DataSpinlock.hpp"

class IntDataSpinlock : public DataSpinlock<int>
{
public:
  IntDataSpinlock(void) : _state(DataSpinlockState::Unlocked), _data(0) {}
  virtual ~IntDataSpinlock(void) {}
}

```
How to use:
```cpp
  IntDataSpinlock intDataSpinlock();
  
  intDataSpinlock.lock();
  int data = intDataSpinlock.getData();
  data += 3;
  data *= 3;
  intDataSpinlock.setData(data);
  intDataSpinlock.unlock();
```
