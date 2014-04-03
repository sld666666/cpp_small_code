#pragma once

template<typename To, typename From>
To safeReinterpret_cast(From from)
{
	assert(sizeof(From) <= sizeof(To));
	return reinterpret_cast<To> from;
}