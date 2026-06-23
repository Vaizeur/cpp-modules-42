#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

const T	&max(const T &x ,const T &y) {
	return (x > y ? x : y);
}

template <typename U>

const U	&min(const U &x ,const U &y) {
	return (x < y ? x : y);
}

template <typename V>

void	swap(V &x ,V &y) {
	V tmp = x;
	x = y;
	y = tmp;
}
#endif
