#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "comp.hpp"
#include "algorithm.hpp"

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() {}

		template <typename U1, typename U2>
		pair(const pair<U1, U2> &other)
			: first(other.first), second(other.second) {}

		pair(const T1 &t1, const T2 &t2) : first(t1), second(t2) {}

		pair &operator=(pair const &other)
		{
			first = other.first;
			second = other.second;
			return *this;
		}
	};

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return lhs.first == rhs.first && lhs.second == rhs.second; }

	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return !(lhs == rhs); }

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return rhs < lhs; }

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return !(lhs < rhs); }

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return !(rhs < lhs); }

	template <typename T1, typename T2>
	inline pair<T1, T2> make_pair(T1 x, T2 y)
	{ return pair<T1, T2>(x, y); }

	template <typename T>
	void swap(T &x, T &y)
	{
		T tmp(x);
		x = y;
		y = tmp;
	}

	template <typename InputIter>
	typename iterator_traits<InputIter>::difference_type
	distance(InputIter first, InputIter last, input_iterator_tag)
	{
		typename iterator_traits<InputIter>::difference_type i(0);
		for (; first != last; ++first)
			++i;
		return i;
	}

	template <typename RandIter>
	typename iterator_traits<RandIter>::difference_type
	distance(RandIter first, RandIter last, random_access_iterator_tag)
	{ return last - first; }

	template <typename InputIter>
	typename iterator_traits<InputIter>::difference_type
	distance(InputIter first, InputIter last)
	{ return ft::distance(first, last, typename iterator_traits<InputIter>::iterator_category()); }
}

#endif
