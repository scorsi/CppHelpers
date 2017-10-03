# CppHelpers
All my C++ Helpers

## DataSpinlock
The purpose of the DataSpinlock is to prevent multiple threads from concurrently accessing a shared data. It uses boost::atomic for the state which is more optimized than mutex. Be careful to unlock your data, otherwise the data will be always locked (think about exception).

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
