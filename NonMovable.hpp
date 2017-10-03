
#pragma once

class NonMovable
{
public:
	NonMovable& operator=(const NonMovable&&) = delete;
	NonMovable(const NonMovable&&) = delete;
};
