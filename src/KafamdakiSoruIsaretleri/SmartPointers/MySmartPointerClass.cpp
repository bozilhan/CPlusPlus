#include "MySmartPointerClass.h"

using namespace KSI;

MySmartPointerClass::MySmartPointerClass() :
	m_SharedPointer( std::shared_ptr<uint8_t>(new uint8_t() ) )
{
}

const std::shared_ptr<uint8_t>& MySmartPointerClass::getSharedPointer() const
{
	return m_SharedPointer;
}

void MySmartPointerClass::setSharedPointer( const std::shared_ptr<uint8_t>& sharedPointer )
{
	m_SharedPointer = sharedPointer;
}

std::unique_ptr<uint8_t> MySmartPointerClass::getUniquePointer() const
{
	std::unique_ptr<uint8_t> m_UniquePointer = std::unique_ptr<uint8_t>(new uint8_t());

	return m_UniquePointer;
}

//void MySmartPointerClass::setUniquePointer( const std::unique_ptr<uint8_t>& uniquePointer )
//{
//	m_UniquePointer = uniquePointer;
//}
