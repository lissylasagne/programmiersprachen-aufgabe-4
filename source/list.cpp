#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>
#include <iostream>

// List .hpp

template <typename T>
struct List ;

template <typename T>
struct ListNode
{
	ListNode () : 	m_value (), 
					m_prev (nullptr), 
					m_next (nullptr) 
					{}
	ListNode (T const & v, ListNode * prev , ListNode * next )
		: 			m_value (v), 
					m_prev (prev), 
					m_next (next)
					{}
	T m_value ;
	ListNode * m_prev ;
	ListNode * m_next ;
};

template <typename T>
struct ListIterator
{
	typedef ListIterator <T> Self;
	
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	typedef std :: forward_iterator_tag iterator_category;

	friend class List <T>;

	ListIterator() : m_node {nullptr} {}
	ListIterator(ListNode <T>* n) :m_node{n} {}
	
	reference operator *() const 
	{
		return m_node -> m_value;
	}
	
	pointer operator ->() const 
	{
		return &(m_node -> m_value);
	}
	
	Self& operator ++() 
	{
		m_node = m_node -> m_next;
		return *this;
	}
	
	Self operator ++(int plus) 
	{
		for(int i = 0; i > plus; ++i)
		{
			m_node = m_node -> m_next;
		}
		return *this;
	}

	Self& operator --() 
	{
		m_node = m_node -> m_prev;
		return *this;
	}
	
	bool operator ==(const Self & x) const {
		return x.m_node == m_node;
	}
	
	bool operator !=(const Self & x) const {
		return x.m_node != m_node;
	}
	
	Self next() const
	{
		if (m_node)
			return ListIterator (m_node -> m_next);
		else
			return ListIterator (nullptr);
	}

private:
	// The Node the iterator is pointing to
	ListNode <T >* m_node = nullptr ;
};

template <typename T>
struct ListConstIterator
{
	friend class List <T >;
public :
// not implemented yet
private :
	ListNode <T >* m_node = nullptr ;
};

template <typename T>
class List
{
public :
	typedef T value_type ;
	typedef T* pointer ;
	typedef const T* const_pointer ;
	typedef T& reference ;
	typedef const T& const_reference ;
	typedef ListIterator <T> iterator ;
	typedef ListConstIterator <T> const_iterator ;
	
	friend class ListIterator <T >;
	friend class ListConstIterator <T>;

	//default constructor
	List():
			m_size{0},
			m_first{nullptr},
			m_last{nullptr}
			{}

	//destructor
	~List() {
		clear();
	}

	//copy constructor
	List(List<T> const& list1) :
				m_size{0},
				m_first{nullptr},
				m_last{nullptr}
	{
		List<T> list2;
		ListIterator<T> it = list1.begin();
		for(int i = 0; i > list1.size(); ++i)
		{
			list2.push_back(*it);
			++it;
		}
	}

	//empty
	bool empty() const
	{
		return(m_size == 0);
	}

	//size
	std::size_t size() const
	{
		return m_size;
	}

	void push_front(value_type data)
	{
		if(empty())
		{
			m_first = new ListNode<T>(data, nullptr, nullptr);
			m_last =m_first;
			m_size++;
		}
		else
		{
			m_first = new ListNode<T>(data, nullptr, m_first);
			m_first -> m_next -> m_prev = m_first;
			m_size++;
		}
	}

	void push_back(value_type data)
	{
		if(empty())
		{
			m_last = new ListNode<T>(data, nullptr, nullptr);
			m_first = m_last;
			m_size++;
		}
		else
		{
			m_last = new ListNode<T>(data, m_last, nullptr);
			m_last -> m_prev -> m_next = m_last;
			m_size++;
		}
		
	}

	void pop_front()
	{
		if(size() == 1)
		{
			m_first = nullptr;
			m_size = 0;
		}
		else 
		{
			m_first = m_first -> m_next;
			m_size--;
		}
	}

	void pop_back()
	{
		if(size() == 1)
		{
			m_first = nullptr;
			m_size = 0;
		}
		else 
		{
			m_last = m_last -> m_prev;
			m_size--;
		}
	}

	value_type const& front() const
	{
		return m_first -> m_value;
	}

	value_type const& back() const
	{
		return m_last -> m_value;
	}

	void clear()
	{
		while(!empty())
		{
			pop_front();
		}
	}

	iterator begin() const
	{
		return iterator{m_first};
	}

	iterator end() const
	{
		return iterator{m_last -> m_next};
	}

	void insert(ListIterator<T> const& it, value_type data)
	{
		if(it == begin())
			push_front(data);
		else if(it == end())
			push_back(data);
		else
		{
			ListIterator<T> prev = it;
			--prev;
			ListIterator<T> next = it;
			++next;
			ListNode<T> node(data, prev.m_node, it.m_node);
			prev.m_node -> m_next =& node;
			next.m_node -> m_prev =& node;
			m_size++;
		}
	}

	void reverse()
	{
		List<T> copy {*this};
		ListIterator<T> itCopy = copy.begin();
		for(ListIterator<T> it = begin(); it != end(); ++it)
		{
			*it = *itCopy;
			--itCopy;
		} 
	}

	
// not implemented yet
private :
	std :: size_t m_size = 0;
	ListNode <T>* m_first = nullptr ;
	ListNode <T>* m_last = nullptr ;
};

template<typename T>
bool operator ==(List<T> const& xs, List<T> const& ys)
{
	if(xs.size() != ys.size())
		return false;
	else
	{
		ListIterator<T> it_xs = xs.begin();
		ListIterator<T> it_ys = ys.begin();
		/*while(it_xs != xs.end())
		{
			if(*it_xs != *it_ys)
			{
				return false;
				break;
			}
			else
			{
				++it_xs;
				++it_ys;
			}
		}*/


		for(ListIterator<T> it_xs = xs.begin(); it_xs != xs.end(); ++it_xs)
		{
			if(*it_xs == *it_ys)
			{
				if(++it_xs == xs.end())
				{
					return true;
				}
				else ++it_ys;
			}

			else return false;
		}
	}
}

template<typename T>
bool operator !=(List<T> const& xs, List<T> const& ys)
{
	if(xs == ys)
		return false;
	else return true;
}

template<typename T>
List<T> reverse(List<T> list)
	{
		List<T> copy {list};
		ListIterator<T> it = list.begin();
		for(ListIterator<T> itCopy = copy.begin(); it != copy.end(); ++itCopy)
		{
			*itCopy = *it;
			--it;
		} 
		return copy;
	}


# endif // # define BUW_LIST_HPP