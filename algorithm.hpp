#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "comp.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1; ++first1, (void) ++first2)
			if (!pred(*first1, *first2))
				return false;
		return true;
	}

	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		typedef typename ft::iterator_traits<InputIterator1>::value_type v1;
		typedef typename ft::iterator_traits<InputIterator2>::value_type v2;

		return ft::equal(first1, last1, first2, ft::__equal_to<v1, v2>());
	}

	template <typename Compare, typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		for (; first2 != last2; ++first1, (void) ++first2)
		{
			if (first1 == last1 || comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return false;
	}

	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		return ft::lexicographical_compare(first1, last1, first2, last2,
											ft::__less<typename ft::iterator_traits<InputIterator1>::value_type,
													typename ft::iterator_traits<InputIterator2>::value_type>());
	}
}

#endif
