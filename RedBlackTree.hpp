/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:04:43 by nosterme          #+#    #+#             */
/*   Updated: 2022/11/24 19:30:00 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP
# include <algorithm>
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "lexicographical_compare.hpp"
# include "equal.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include <iostream>

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

rb_tree_node_base *	rb_tree_increment( rb_tree_node_base * node );
rb_tree_node_base *	rb_tree_decrement( rb_tree_node_base * node );
void	rb_tree_insert_and_rebalance( bool const insert_left,\
									  rb_tree_node_base * node,\
									  rb_tree_node_base * parent,\
									  rb_tree_node_base & head );
rb_tree_node_base *	rb_tree_rebalance_for_erase( rb_tree_node_base * const node,\
												 rb_tree_node_base & head );

template< typename Val >
struct rb_tree_iterator
{

	typedef Val								value_type;
	typedef value_type *					pointer;
	typedef value_type &					reference;

	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;

	typedef rb_tree_node< Val > *			node_ptr;
	typedef rb_tree_node_base *				node_base_ptr;

	node_base_ptr		m_current;

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

	bool					operator==( rb_tree_iterator const & rhs ) const
	{
		return ( ( this->m_current == rhs.m_current ) );
	}
	bool					operator!=( rb_tree_iterator const & rhs ) const
	{
		return ( !( ( *this ) == rhs ) );
	}

};

template< typename Val >
struct rb_tree_const_iterator
{

	typedef Val								value_type;
	typedef value_type const *				pointer;
	typedef value_type const &				reference;

	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;

	typedef rb_tree_node< Val > const *		node_ptr;
	typedef rb_tree_node_base const *		node_base_ptr;

	node_base_ptr		m_current;

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

	bool						operator==( rb_tree_const_iterator const & rhs ) const
	{
		return ( ( this->m_current == rhs.m_current ) );
	}
	bool						operator!=( rb_tree_const_iterator const & rhs ) const
	{
		return ( !( ( *this ) == rhs ) );
	}

};

template< typename Key, typename Val, typename KeyOfValue, typename Compare, typename Allocator >
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
		typedef KeyOfValue										keyofvalue;
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

		node_allocator &			get_node_allocator( void )
		{
			return ( *( static_cast< node_allocator * >( &( this->m_alloc ) ) ) );
		}
		node_allocator const &		get_node_allocator( void ) const
		{
			return ( *( static_cast< node_allocator const * >( &( this->m_alloc ) ) ) );
		}
		allocator_type				get_allocator( void ) const
		{
			return ( allocator_type( this->get_node_allocator() ) );
		}

	protected:

		node_ptr					m_alloc_node( void )
		{
			return ( this->m_alloc.allocate( 1 ) );
		}
		void						m_dealloc_node( node_ptr p )
		{
			this->m_alloc.deallocate( p, 1 );
			return ;
		}
		node_ptr					m_create_node( value_type const & value )
		{
			node_ptr	node = this->m_alloc_node();

			this->get_allocator().construct( &( node->m_value ), value );
			return ( node );
		}
		void						m_destroy_node( node_ptr node )
		{
			this->get_allocator().destroy( &( node->m_value ) );
			this->m_dealloc_node( node );
			return ;
		}

		node_ptr					m_copy_initialize( node_ptr node,\
													   node_ptr parent,\
													   const_node_ptr other_node )
		{
			if ( other_node == 0 )
				node = 0;
			else
			{
				node = this->m_create_node( other_node->m_value );
				node->m_parent = parent;
				node->m_color = other_node->m_color;
				node->m_left = this->m_copy_initialize( s_left( node ), node, s_left( other_node ) );
				node->m_right = this->m_copy_initialize( s_right( node ), node, s_right( other_node ) );
			}
			return ( node );
		}

		template< typename KeyCompare,\
				  typename = typename ft::enable_if< \
				  !( ft::is_integral< KeyCompare >::value ), bool >::type >
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
				this->m_head.m_color = red;
				this->m_head.m_parent = 0;
				this->m_head.m_left = &this->m_head;
				this->m_head.m_right = &this->m_head;
				return ;
			}

		};

		rb_tree_allocator< compare_type >	m_alloc;

		node_base_ptr &				m_root( void )
		{
			return ( this->m_alloc.m_head.m_parent );
		}
		const_node_base_ptr			m_root( void ) const
		{
			return ( this->m_alloc.m_head.m_parent );
		}
		node_base_ptr &				m_leftmost( void )
		{
			return ( this->m_alloc.m_head.m_left );
		}
		const_node_base_ptr			m_leftmost( void ) const
		{
			return ( this->m_alloc.m_head.m_left );
		}
		node_base_ptr &				m_rightmost( void )
		{
			return ( this->m_alloc.m_head.m_right );
		}
		const_node_base_ptr			m_rightmost( void ) const
		{
			return ( this->m_alloc.m_head.m_right );
		}

		node_ptr					m_start( void )
		{
			return ( static_cast< node_ptr >( this->m_alloc.m_head.m_parent ) );
		}
		const_node_ptr				m_start( void ) const
		{
			return ( static_cast< const_node_ptr >( this->m_alloc.m_head.m_parent ) );
		}
		node_ptr					m_finish( void )
		{
			return ( static_cast< node_ptr >( &( this->m_alloc.m_head ) ) );
		}
		const_node_ptr				m_finish( void ) const
		{
			return ( static_cast< const_node_ptr >( &( this->m_alloc.m_head ) ) );
		}

		static const_reference		s_value( const_node_ptr node )
		{
			return ( node->m_value );
		}
		static key_type const &		s_key( const_node_ptr node )
		{
			return ( keyofvalue()( s_value( node ) ) );
		}
		static const_reference		s_value( const_node_base_ptr node )
		{
			return ( static_cast< const_node_ptr >( node )->m_value );
		}
		static key_type const &		s_key( const_node_base_ptr node )
		{
			return ( keyofvalue()( s_value( node ) ) );
		}
		static node_ptr				s_left( node_base_ptr node )
		{
			return ( static_cast< node_ptr >( node->m_left ) );
		}
		static const_node_ptr		s_left( const_node_base_ptr node )
		{
			return ( static_cast< const_node_ptr >( node->m_left ) );
		}
		static node_ptr				s_right( node_base_ptr node )
		{
			return ( static_cast< node_ptr >( node->m_right ) );
		}
		static const_node_ptr		s_right( const_node_base_ptr node )
		{
			return ( static_cast< const_node_ptr >( node->m_right ) );
		}

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
			*this = other;
			return ;
		}
		~rb_tree( void )
		{
			this->clear();
			return ;
		}

		rb_tree &					operator=( rb_tree const & rhs )
		{
			if ( this != &rhs )
			{
				this->clear();
				this->m_alloc.m_head.m_parent = \
					this->m_copy_initialize( static_cast< node_ptr >( this->m_root() ),\
											 this->m_finish(),\
											 static_cast< const_node_ptr >( rhs.m_root() ) );
				this->m_alloc.m_node_count = rhs.m_alloc.m_node_count;
			}
			return ( *this );
		}

		// iterators

		iterator					begin( void )
		{
			return ( iterator\
				( static_cast< node_ptr >( this->m_alloc.m_head.m_left ) ) );
		}
		const_iterator				begin( void ) const
		{
			return ( const_iterator\
				( static_cast< const_node_ptr >( this->m_alloc.m_head.m_left ) ) );
		}
		iterator					end( void )
		{
			return ( iterator\
				( static_cast< node_ptr >( &( this->m_alloc.m_head ) ) ) );
		}
		const_iterator				end( void ) const
		{
			return ( const_iterator\
				( static_cast< const_node_ptr >( &( this->m_alloc.m_head ) ) ) );
		}
		reverse_iterator			rbegin( void )
		{
			return ( reverse_iterator( this->end() ) );
		}
		const_reverse_iterator		rbegin( void ) const
		{
			return ( const_reverse_iterator( this->end() ) );
		}
		reverse_iterator			rend( void )
		{
			return ( reverse_iterator( this->begin() ) );
		}
		const_reverse_iterator		rend( void ) const
		{
			return ( const_reverse_iterator( this->begin() ) );
		}

		// capacity

		bool						empty( void ) const
		{
			return ( this->begin() == this->end() );
		}
		size_type					size( void ) const
		{
			return ( this->m_alloc.m_node_count );
		}
		size_type					max_size( void ) const
		{
			return ( this->get_node_allocator().max_size() );
		}

	private:

		iterator					m_insert( node_base_ptr node,\
											  node_base_ptr parent,\
											  value_type const & value )
		{
			bool		insert_left = ( ( node != 0 ) || ( parent == this->m_finish() ) ||\
										( this->m_alloc.m_key_compare( keyofvalue()( value ),\
																	   s_key( parent ) ) ) );
			node_ptr	new_node = m_create_node( value );

			rb_tree_insert_and_rebalance( insert_left, new_node, parent, this->m_alloc.m_head );
			++( this->m_alloc.m_node_count );
			return ( iterator( new_node ) );
		}
		void						m_erase( node_base_ptr node )
		{
			while ( node != 0 )
			{
				node_base_ptr	left = s_left( node );

				this->m_erase( s_right( node ) );
				this->m_destroy_node( static_cast< node_ptr >( node ) );
				node = left;
			}
			return ;
		}

	public:

		// modifiers

		typename ft::pair< iterator, bool >\
			insert( value_type const & value )
		{
			bool		comp = true;
			node_ptr	node = this->m_start();
			node_ptr	parent = this->m_finish();

			while ( node != 0 )
			{
				parent = node;
				comp = this->m_alloc.m_key_compare( keyofvalue()( value ), s_key( node ) );
				node = comp ? s_left( node ) : s_right( node );
			}
			iterator	it = iterator( parent );

			if ( comp )
			{
				if ( it == this->begin() )
					return ( ft::make_pair( this->m_insert( node, parent, value ), true ) );
				--it;
			}
			if ( this->m_alloc.m_key_compare( s_key( it.m_current ), keyofvalue()( value ) ) )
				return ( ft::make_pair( this->m_insert( node, parent, value ), true ) );
			return ( ft::make_pair( it, false ) );
		}
		iterator					insert( iterator position, value_type const & value )
		{
			if ( position == this->m_head() )
			{
				if ( ( this->size() > 0 ) &&\
					 ( this->m_alloc.m_key_compare( s_key( this->rightmost() ),\
													  keyofvalue()( value ) ) ) )
					return ( this->m_insert( 0, this->rightmost(), value ) );
				return ( this->insert( value ) );
			}
			else if ( this->m_alloc.m_key_compare( keyofvalue()( value ),\
												   s_key( position.m_current ) ) )
			{
				iterator	before = position;

				if ( position.m_current == this->leftmost() )
					return ( this->m_insert( this->leftmost(), this->leftmost(), value ) );
				else if ( this->m_alloc.m_key_compare( s_key( ( --before ).m_current ),\
													   keyofvalue()( value ) ) )
				{
					if ( s_right( before.m_current ) == 0 )
						return ( this->m_insert( 0, before.m_current, value ) );
					return ( this->m_insert( position.m_current, position.m_current, value ) );
				}
				return ( this->insert( value ) );
			}
			else if ( this->m_alloc.m_key_compare( s_key( position.m_current ),\
												   keyofvalue()( value ) ) )
			{
				iterator	after = position;

				if ( position.m_current == this->rightmost() )
					return ( this->m_insert( this->rightmost(), this->rightmost(), value ) );
				else if ( this->m_alloc.m_key_compare( keyofvalue()( value ),\
													   s_key( ( ++after ).m_current ) ) )
				{
					if ( s_right( position.m_current ) == 0 )
						return ( this->m_insert( 0, position.m_current, value ) );
					return ( this->m_insert( after.m_current, after.m_current, value ) );
				}
				return ( this->insert( value ) );
			}
			return ( position );
		}
		void						erase( iterator position )
		{
			node_ptr	node = static_cast< node_ptr >\
							   ( rb_tree_rebalance_for_erase\
								 ( position.m_current, this->m_alloc.m_head ) );

			this->m_destroy_node( node );
			--( this->m_alloc.m_node_count );
			return ;
		}
		void						clear( void )
		{
			this->m_erase( this->m_start() );
			this->m_root() = 0;
			this->m_leftmost() = this->m_finish();
			this->m_rightmost() = this->m_finish();
			this->m_alloc.m_node_count = 0;
			return ;
		}
		void						swap( rb_tree & other )
		{
			if ( this->m_root() == 0 )
			{
				if ( other.m_root() != 0 )
				{
					this->m_root() = other.m_root();
					this->m_leftmost() = other.m_leftmost();
					this->m_rightmost() = other.m_rightmost();
					this->m_root()->m_parent = this->m_finish();

					other.m_root() = 0;
					other.m_root() = other.m_finish();
					other.m_root() = other.m_finish();
				}
			}
			else if ( other.m_root() == 0 )
			{
				other.m_root() = this->m_root();
				other.m_leftmost() = this->m_leftmost();
				other.m_rightmost() = this->m_rightmost();
				other.m_root()->m_parent = other.m_finish();

				this->m_root() = 0;
				this->m_leftmost() = this->m_finish();
				this->m_rightmost() = this->m_finish();
			}
			else
			{
				std::swap( this->m_root(), other.m_root() );
				std::swap( this->m_leftmost(), other.m_leftmost() );
				std::swap( this->m_rightmost(), other.m_rightmost() );

				this->m_root()->m_parent = this->m_finish();
				other.m_root()->m_parent = other.m_finish();
			}
			std::swap( this->m_alloc.m_key_compare, other.m_alloc.m_key_compare );
			std::swap( this->m_alloc.m_node_count, other.m_alloc.m_node_count );
			return ;
		}

		// lookup

		size_type						count( key_type const & key ) const
		{
			ft::pair< const_iterator, const_iterator >	pair = this->equal_range( key );
			size_type									n = \
				size_type( std::distance( pair.first, pair.last ) );

			return ( n );
		}
		iterator						find( key_type const & key )
		{
			iterator		it = this->lower_bound( key );

			return ( ( it == this->end() || \
					   this->m_alloc.m_key_compare( key, s_key( it.m_current ) ) )\
					 ? this->end() : it );
		}
		const_iterator					find( key_type const & key ) const
		{
			const_iterator	it = this->lower_bound( key );

			return ( ( it == this->end() || \
					   this->m_alloc.m_key_compare( key, s_key( it.m_current ) ) )\
					 ? this->end() : it );
		}
		ft::pair< iterator, iterator >	equal_range( key_type const & key )
		{
			iterator		lower = this->lower_bound( key );
			iterator		upper = this->upper_bound( key );

			return ( ft::make_pair( lower, upper ) );
		}
		ft::pair< const_iterator,\
				  const_iterator >		equal_range( key_type const & key ) const
		{
			const_iterator	lower = this->lower_bound( key );
			const_iterator	upper = this->upper_bound( key );

			return ( ft::make_pair( lower, upper ) );
		}
		iterator						lower_bound( key_type const & key )
		{
			node_ptr		node = this->m_start();
			node_ptr		parent = this->m_finish();

			while ( node != 0 )
			{
				if ( !( this->m_alloc.m_key_compare( s_key( node ), key ) ) )
				{
					parent = node;
					node = s_left( node );
				}
				else
					node = s_right( node );
			}
			return ( iterator( parent ) );
		}
		const_iterator					lower_bound( key_type const & key ) const
		{
			const_node_ptr	node = this->m_start();
			const_node_ptr	parent = this->m_finish();

			while ( node != 0 )
			{
				if ( !( this->m_alloc.m_key_compare( s_key( node ), key ) ) )
				{
					parent = node;
					node = s_left( node );
				}
				else
					node = s_right( node );
			}
			return ( const_iterator( parent ) );
		}
		iterator						upper_bound( key_type const & key )
		{
			node_ptr		node = this->m_start();
			node_ptr		parent = this->m_finish();

			while ( node != 0 )
			{
				if ( this->m_alloc.m_key_compare( key, s_key( node ) ) )
				{
					parent = node;
					node = s_left( node );
				}
				else
					node = s_right( node );
			}
			return ( iterator( parent ) );
		}
		const_iterator					upper_bound( key_type const & key ) const
		{
			const_node_ptr	node = this->m_start();
			const_node_ptr	parent = this->m_finish();

			while ( node != 0 )
			{
				if ( this->m_alloc.m_key_compare( key, s_key( node ) ) )
				{
					parent = node;
					node = s_left( node );
				}
				else
					node = s_right( node );
			}
			return ( const_iterator( parent ) );
		}

};

// compare

template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
bool		operator==( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
						rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	return ( ( lhs.size() == rhs.size() ) && \
			   ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
}
template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
bool		operator!=( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
						rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	return ( !( lhs == rhs ) );
}

template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
bool		operator<( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
					   rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), \
										  rhs.begin(), rhs.end() ) );
}
template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
bool		operator<=( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
						rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	return ( !( rhs < lhs ) );
}
template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
bool		operator>( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
					   rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	return ( ( rhs < lhs ) );
}
template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
bool		operator>=( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
						rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	return ( !( lhs < rhs ) );
}

// swap

template< typename Key, typename T, typename KeyOfValue, typename Compare, typename Allocator >
void				swap( rb_tree< Key, T, KeyOfValue, Compare, Allocator > & lhs,\
						  rb_tree< Key, T, KeyOfValue, Compare, Allocator > & rhs )
{
	lhs.swap( rhs );
	return ;
}

#endif
