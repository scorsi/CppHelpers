
#pragma once

class NonCopyable
{
public:
	NonCopyable& operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
};
