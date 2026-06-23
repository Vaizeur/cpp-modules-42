#ifndef ITER_HPP
# define ITER_HPP

template <typename T>

void	iter(T *ptrArray, const size_t len, void (*fn)(T &))
{
	if (!ptrArray || !fn)
		return;
	for (size_t i = 0; i < len; i++)
		fn(ptrArray[i]);
}

template <typename U>

void	iter(U *ptrArray, const size_t len, void (*fn)(U const &))
{
	if (!ptrArray || !fn)
		return;
	for (size_t i = 0; i < len; i++)
		fn(ptrArray[i]);
}

#endif
