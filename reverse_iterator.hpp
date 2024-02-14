#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
	protected:
		Iter current;
	public:

		typedef Iter														iterator_type;
		typedef typename iterator_traits<Iter>::difference_type				difference_type;
		typedef typename iterator_traits<Iter>::reference					reference;
		typedef typename iterator_traits<Iter>::pointer						pointer;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;

		reverse_iterator() : current() {}
		explicit reverse_iterator(Iter x) : current(x) {}
		template <typename Up>
		reverse_iterator(const reverse_iterator<Up>& u) : current(u.base()) {}

		Iter	base() const { return current; }

		reference			operator* () const { Iter tmp = current; return *--tmp; }
		pointer				operator->() const { Iter tmp = current; return &(*(--tmp)); }
		reverse_iterator&	operator++() { --current; return *this; }
		reverse_iterator	operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
		reverse_iterator&	operator--() { ++current; return *this; }
		reverse_iterator	operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
		reverse_iterator	operator+ (difference_type n) const;
		reverse_iterator&	operator+=(difference_type n) { current -= n; return *this; }
		reverse_iterator 	operator- (difference_type n) const;
		reverse_iterator&	operator-=(difference_type n) { current += n; return *this; }
		reference			operator[](difference_type n) const { Iter tmp = (current - n); return *--tmp; }
	};
	
	template <typename Iter>
	reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator+ (difference_type n) const
	{ return reverse_iterator(current - n); }
	
	template <typename Iter>
	reverse_iterator<Iter>  ft::reverse_iterator<Iter>::operator- (difference_type n) const
	{ return reverse_iterator(current + n); }
	

	template <typename Iter1, typename Iter2>
	bool operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() == y.base(); }

	template <typename Iter1, typename Iter2>
	bool operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() != y.base(); }

	template <typename Iter1, typename Iter2>
	bool operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() > y.base(); }

	template <typename Iter1, typename Iter2>
	bool operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() >= y.base(); }

	template <typename Iter1, typename Iter2>
	bool operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() < y.base(); }

	template <typename Iter1, typename Iter2>
	bool operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() <= y.base(); }

	template <typename Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
	{ return reverse_iterator<Iter>(x.base() - n); }

	template <typename Iter1, typename Iter2>
	typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return y.base() - x.base(); }
}

#endif
