#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "type_traits.hpp"

namespace ft
{
	template <typename Tp>
	class vector_iterator
	{
	public:
		typedef Tp															iterator_type;
		typedef typename ft::random_access_iterator_tag						iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;

	private:
		iterator_type it;

	public:
		vector_iterator() throw() {}
		template <typename Up>
		vector_iterator(const vector_iterator<Up>& u,
			typename ft::enable_if<ft::is_convertible<Up, iterator_type>::value>::type* = 0) throw()
			: it(u.base()) {}
		vector_iterator(iterator_type x) : it(x) {}

		iterator_type		base() const { return it; }

		reference			operator* () const { return *it; }
		pointer				operator->() const { return it; }
		vector_iterator&	operator++() { ++it; return *this; }
		vector_iterator		operator++(int) { vector_iterator tmp(*this); ++(*this); return tmp; }
		vector_iterator&	operator--() { --it; return *this; }
		vector_iterator		operator--(int) { vector_iterator tmp(*this); --(*this); return tmp; }
		vector_iterator		operator+ (difference_type n) const { vector_iterator w(*this); w += n; return w; }
		vector_iterator&	operator+=(difference_type n) { it += n; return *this; }
		vector_iterator		operator- (difference_type n) const { return (*this + (-n)); }
		vector_iterator&	operator-=(difference_type n) { *this += -n; return *this; }
		reference			operator[](difference_type n) const { return it[n]; }
	};

	template <typename Iter1, typename Iter2>
	inline bool operator==(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return x.base() == y.base(); }

	template <typename Iter1, typename Iter2>
	inline bool operator<(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return x.base() < y.base(); }

	template <typename Iter1, typename Iter2>
	inline bool operator!=(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return !(x == y); }

	template <typename Iter1, typename Iter2>
	inline bool operator>(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return y < x; }

	template <typename Iter1, typename Iter2>
	inline bool operator>=(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return !(x < y); }

	template <typename Iter1, typename Iter2>
	inline bool operator<=(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return !(y < x); }

	template <typename Iter1>
	inline bool operator!=(const vector_iterator<Iter1>& x, const vector_iterator<Iter1>& y) throw()
	{ return !(x == y); }

	template <typename Iter1>
	inline bool operator>(const vector_iterator<Iter1>& x, const vector_iterator<Iter1>& y) throw()
	{ return y < x; }

	template <typename Iter1>
	inline bool operator>=(const vector_iterator<Iter1>& x, const vector_iterator<Iter1>& y) throw()
	{ return !(x < y); }

	template <typename Iter1>
	inline bool operator<=(const vector_iterator<Iter1>& x, const vector_iterator<Iter1>& y) throw()
	{ return !(y < x); }

	template <typename Iter1, typename Iter2>
	inline typename vector_iterator<Iter1>::difference_type
	operator-(const vector_iterator<Iter1>& x, const vector_iterator<Iter2>& y) throw()
	{ return x.base() - y.base(); }

	template <typename Tp>
	inline vector_iterator<Tp>
	operator+(typename vector_iterator<Tp>::difference_type n,
			vector_iterator<Tp> x) throw()
	{ x += n; return x; }
}

#endif
