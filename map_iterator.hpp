#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "tree.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

namespace ft
{
	template<typename Tp, typename node_type>
	class map_iterator
	{
	public:
		typedef Tp													iterator_type;
		typedef typename ft::bidirectional_iterator_tag				iterator_category;
		typedef typename iterator_traits<Tp>::value_type			value_type;
		typedef	typename iterator_traits<Tp>::difference_type		difference_type;
		typedef typename iterator_traits<Tp>::pointer				pointer;
		typedef typename iterator_traits<Tp>::reference				reference;

	private:
		node_type*	it_;

	public:
		map_iterator(): it_(NULL) {};
		explicit	map_iterator( node_type* x ): it_(x) {};
		template <typename Iter>
		map_iterator ( const map_iterator<Iter, node_type>& node_it,
			typename ft::enable_if<ft::is_convertible<Iter, iterator_type>::value>::type* = 0 ): it_(node_it.base()) {};

		node_type*		base() const		{ return (this->it_); };

		reference		operator* () const	{ return (this->it_->pair_data_); };
		map_iterator&	operator++()		{ this->it_ = successor(this->it_); return (*this); };
		map_iterator	operator++(int)		{ map_iterator temp(*this); ++(*this); return (temp); };
		map_iterator&	operator--()		{ this->it_ = predecessor(this->it_); return (*this); };
		map_iterator	operator--(int)		{ map_iterator temp(*this); --(*this); return (temp); };
		pointer			operator->() const	{ return (&(operator*())); };
	};

	template <typename Tp, typename Up, typename node_type>
	bool operator==(const map_iterator<Tp, node_type>& x, const map_iterator<Up, node_type>& y)
	{ return (x.base() == y.base()); }

	template <typename Tp, typename Up, typename node_type>
	bool operator!=(const map_iterator<Tp, node_type>& x, const map_iterator<Up, node_type>& y)
	{ return (x.base() != y.base()); }

	template <typename Tp, typename Up, typename node_type>
	bool operator< (const map_iterator<Tp, node_type>& x, const map_iterator<Up, node_type>& y)
	{ return (x.base() < y.base()); }

	template <typename Tp, typename Up, typename node_type>
	bool operator<=(const map_iterator<Tp, node_type>& x, const map_iterator<Up, node_type>& y)
	{ return (x.base() <= y.base()); }

	template <typename Tp, typename Up, typename node_type>
	bool operator> (const map_iterator<Tp, node_type>& x, const map_iterator<Up, node_type>& y)
	{ return (x.base() > y.base()); }

	template <typename Tp, typename Up, typename node_type>
	bool operator>= (const map_iterator<Tp, node_type>& x, const map_iterator<Up, node_type>& y)
	{ return (x.base() >= y.base()); }
}

#endif
