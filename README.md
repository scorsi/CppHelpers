# CppHelpers
All my C++ Helpers, you can use and modify as you wish.

## DataSpinlock
The purpose of the DataSpinlock is to prevent multiple threads from concurrently accessing a shared data. It uses boost::atomic for the state which is more optimized than mutex. Be careful to unlock your data, otherwise the data will be always locked (think about exception).

### Examples

Declaration:
```cpp

#include "DataSpinlock.hpp"

class IntDataSpinlock : public DataSpinlock<int>
{
public:
  IntDataSpinlock(void) : DataSpinlock(0) {}
  virtual ~IntDataSpinlock(void) {}
}
```
How to use:
```cpp
IntDataSpinlock spinlock;

spinlock.lock();
int data = spinlock.getData();
data++;
spinlock.setData(data);
spinlock.unlock();
```
