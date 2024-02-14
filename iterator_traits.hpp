#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
	#if defined(_LIBCPP_ITERATOR) || defined(_STL_ITERATOR_H)

	typedef std::input_iterator_tag input_iterator_tag;
	typedef std::output_iterator_tag output_iterator_tag;
	typedef std::forward_iterator_tag forward_iterator_tag;
	typedef std::bidirectional_iterator_tag bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag random_access_iterator_tag;

	#else  
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	#endif

	template <typename Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template <typename Ty>
	struct iterator_traits<Ty*>
	{
		typedef ptrdiff_t difference_type;
		typedef Ty value_type;
		typedef Ty* pointer;
		typedef Ty& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <typename Ty>
	struct iterator_traits<const Ty*>
	{
		typedef ptrdiff_t difference_type;
		typedef Ty value_type;
		typedef const Ty* pointer;
		typedef const Ty& reference;
		typedef random_access_iterator_tag iterator_category;
	};
}

#endif
