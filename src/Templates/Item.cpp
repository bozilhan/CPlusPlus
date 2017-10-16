#include "Item.h"

using namespace TMP;

template<typename T>
Item<T>::Item() :
		m_Data(),
		m_pDataSharedPtr( std::shared_ptr<T>( new T() ) ),
		m_pDataUniquePtr( std::unique_ptr<T>( new T() ) ),
		m_pDataRawPtr( new T() )
{
}

template<typename T>
Item<T>::Item( const T& data ) :
		m_Data( data ),
		m_pDataSharedPtr( std::shared_ptr<T>( new T() ) ),
		m_pDataUniquePtr( std::unique_ptr<T>( new T() ) ),
		m_pDataRawPtr( new T() )
{
}

template<typename T>
Item<T>::~Item()
{
	if ( m_pDataRawPtr )
	{
		delete m_pDataRawPtr;
		m_pDataRawPtr = nullptr;
	}
}

template<typename T>
Item<T>::Item( const Item& rhs )
{
}

template<typename T>
Item<T>& Item<T>::operator =( const Item& rhs )
{
	return *this;
}

template<typename T>
Item<T>::Item( Item&& rhs )
{
	
}

template<typename T>
Item<T>& Item<T>::operator =( Item&& rhs )
{
	return *this;
}

template<typename T>
T Item<T>::getData() const
{
	return m_Data;
}

template<typename T>
void Item<T>::setData( const T& data )
{
	m_Data = data;
}

template<typename T>
T* Item<T>::getDataRawPtr() const
{
	return m_pDataRawPtr;
}

template<typename T>
void Item<T>::setDataRawPtr( const T* pDataRawPtr )
{
	m_pDataRawPtr = pDataRawPtr;
}

template<typename T>
std::shared_ptr<T> Item<T>::getDataSharedPtr() const
{
	return m_pDataSharedPtr;
}

template<typename T>
void Item<T>::setDataSharedPtr( std::shared_ptr<T> pDataSharedPtr )
{
	m_pDataSharedPtr = pDataSharedPtr;
}

template<typename T>
const std::unique_ptr<T>& Item<T>::getDataUniquePtr() const
{
	return m_pDataUniquePtr;
}

template<typename T>
void Item<T>::setDataUniquePtr( const std::unique_ptr<T>& pDataUniquePtr )
{
	m_pDataUniquePtr = pDataUniquePtr;
}
