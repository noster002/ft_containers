/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:04:43 by nosterme          #+#    #+#             */
/*   Updated: 2022/11/17 14:47:40 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP
# include <algorithm>

enum rb_tree_color
{
	red = false,
	black = true
};

struct rb_tree_node_base
{

	typedef rb_tree_node_base *				node_base_ptr;
	typedef rb_tree_node_base const *		const_node_base_ptr;

	rb_tree_color			m_color;
	node_base_ptr			m_parent;
	node_base_ptr			m_left;
	node_base_ptr			m_right;

};

template< typename Val >
struct rb_tree_node : public rb_tree_node_base
{

	typedef Val								value_type;
	typedef rb_tree_node< Val > *			node_ptr;

	value_type				m_value;

};

template< typename Val >
struct rb_tree_iterator
{

	public:

		typedef Val								value_type;
		typedef value_type *					pointer;
		typedef value_type &					reference;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		typedef rb_tree_node< Val > *			node_ptr;
		typedef rb_tree_node_base *				node_base_ptr;

	protected:

		node_base_ptr		m_current;

	public:

		rb_tree_iterator( void ) : m_current()
		{
			return ;
		}
		explicit rb_tree_iterator( node_ptr const & p ) : m_current( p )
		{
			return ;
		}
		rb_tree_iterator( rb_tree_iterator const & other ) : m_current( other.m_current )
		{
			return ;
		}
		~rb_tree_iterator( void )
		{
			return ;
		}
		rb_tree_iterator &		operator=( rb_tree_iterator const & rhs )
		{
			if ( this != &rhs )
				this->m_current = rhs.m_current;
			return ( *this );
		}

		reference				operator*( void ) const
		{
			return ( ( static_cast< node_ptr >( this->m_current ) )->m_value );
		}
		pointer					operator->( void ) const
		{
			return ( &( ( static_cast< node_ptr >( this->m_current ) )->m_value ) );
		}

		rb_tree_iterator &		operator++( void )
		{
			this->m_current = rb_tree_increment( this->m_current );
			return ( *this );
		}
		rb_tree_iterator &		operator--( void )
		{
			this->m_current = rb_tree_decrement( this->m_current );
			return ( *this );
		}
		rb_tree_iterator		operator++( int )
		{
			rb_tree_iterator	tmp( *this );

			this->m_current = rb_tree_increment( this->m_current );
			return ( tmp );
		}
		rb_tree_iterator		operator--( int )
		{
			rb_tree_iterator	tmp( *this );

			this->m_current = rb_tree_decrement( this->m_current );
			return ( tmp );
		}

		bool					operator==( rb_tree_iterator const & rhs )
		{
			return ( ( this->m_current == rhs.m_current ) );
		}
		bool					operator!=( rb_tree_iterator const & rhs )
		{
			return ( !( ( *this ) == rhs ) );
		}

};

template< typename Val >
struct rb_tree_const_iterator
{

	public:

		typedef Val								value_type;
		typedef value_type const *				pointer;
		typedef value_type const &				reference;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		typedef rb_tree_node< Val > const *		node_ptr;
		typedef rb_tree_node_base const *		node_base_ptr;

	protected:

		node_base_ptr		m_current;

	public:

		rb_tree_const_iterator( void ) : m_current()
		{
			return ;
		}
		explicit rb_tree_const_iterator( node_ptr const & p ) : m_current( p )
		{
			return ;
		}
		rb_tree_const_iterator( rb_tree_const_iterator const & other )\
		 : m_current( other.m_current )
		{
			return ;
		}
		~rb_tree_const_iterator( void )
		{
			return ;
		}
		rb_tree_const_iterator &	operator=( rb_tree_const_iterator const & rhs )
		{
			if ( this != &rhs )
				this->m_current = rhs.m_current;
			return ( *this );
		}

		reference					operator*( void ) const
		{
			return ( ( static_cast< node_ptr >( this->m_current ) )->m_value );
		}
		pointer						operator->( void ) const
		{
			return ( &( ( static_cast< node_ptr >( this->m_current ) )->m_value ) );
		}

		rb_tree_const_iterator &	operator++( void )
		{
			this->m_current = rb_tree_increment( this->m_current );
			return ( *this );
		}
		rb_tree_const_iterator &	operator--( void )
		{
			this->m_current = rb_tree_decrement( this->m_current );
			return ( *this );
		}
		rb_tree_const_iterator		operator++( int )
		{
			rb_tree_const_iterator	tmp( *this );

			this->m_current = rb_tree_increment( this->m_current );
			return ( tmp );
		}
		rb_tree_const_iterator		operator--( int )
		{
			rb_tree_const_iterator	tmp( *this );

			this->m_current = rb_tree_decrement( this->m_current );
			return ( tmp );
		}

		bool						operator==( rb_tree_const_iterator const & rhs )
		{
			return ( ( this->m_current == rhs.m_current ) );
		}
		bool						operator!=( rb_tree_const_iterator const & rhs )
		{
			return ( !( ( *this ) == rhs ) );
		}

};

template< typename Key, typename Val, typename Compare, typename Allocator >
class rb_tree
{

	private:

		typedef typename Allocator::template rebind< rb_tree_node< Val > >::other\
			node_allocator;

	protected:

		typedef rb_tree_node_base *								node_base_ptr;
		typedef rb_tree_node_base const *						const_node_base_ptr;

	public:

		typedef Key												key_type;
		typedef Val												value_type;
		typedef rb_tree_node< value_type > *					node_ptr;
		typedef rb_tree_node< value_type > const *				const_node_ptr;
		typedef Compare											compare_type;
		typedef value_type &									reference;
		typedef value_type const &								const_reference;
		typedef value_type *									pointer;
		typedef value_type const *								const_pointer;
		typedef rb_tree_iterator< value_type >					iterator;
		typedef rb_tree_const_iterator< value_type >			const_iterator;
		typedef typename ft::reverse_iterator< iterator >		reverse_iterator;
		typedef typename ft::reverse_iterator< const_iterator >	const_reverse_iterator;
		typedef typename ft::iterator_traits< iterator >::difference_type\
																difference_type;
		typedef typename std::size_t							size_type;
		typedef Allocator										allocator_type;

	protected:

		template< typename KeyCompare,\
				  typename ft::enable_if< \
				  !ft::is_integral< KeyCompare >::value >::type >
		struct rb_tree_allocator : public node_allocator
		{

			typedef KeyCompare		key_compare;

			key_compare				m_key_compare;
			rb_tree_node_base		m_head;
			size_type				m_node_count;

			rb_tree_allocator( void )\
			 : node_allocator(), m_key_compare(), m_head(), m_node_count( 0 )
			{
				m_initialize();
				return ;
			}
			rb_tree_allocator( key_compare const & comp, node_allocator const & alloc )\
			 : node_allocator( alloc ), m_key_compare( comp ), m_head(), m_node_count( 0 )
			{
				m_initialize();
				return ;
			}

		private:

			void	m_initialize( void )
			{
				m_head.m_color = red;
				m_head.m_parent = 0;
				m_head.m_left = &this->m_head;
				m_head.m_right = &this->m_head;
				return ;
			}

		};

		rb_tree_allocator		m_alloc;

	public:

		rb_tree( void )\
		 : m_alloc()
		{
			return ;
		}
		rb_tree( compare_type const & comp,\
				 allocator_type const & alloc = allocator_type() )\
		 : m_alloc( comp, alloc )
		{
			return ;
		}
		rb_tree( rb_tree const & other )\
		 : m_alloc( other.m_alloc.m_key_compare, other.get_node_allocator() )
		{
			// if not empty copy ( elements, node count, leftmost, rightmost )
		}
		~rb_tree( void )
		{
			// erase
		}

		rb_tree &					operator=( rb_tree const & rhs )
		{
			if ( this != &rhs )
			{
				
			}
			return ( *this );
		}

		node_allocator &			get_node_allocator( void )
		{
			return ( this->m_alloc );
		}
		node_allocator const &		get_node_allocator( void ) const
		{
			return ( this->m_alloc );
		}

};


#endif
