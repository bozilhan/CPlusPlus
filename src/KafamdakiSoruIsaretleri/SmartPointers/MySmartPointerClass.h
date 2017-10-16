#ifndef MYSMARTPOINTERCLASS_H_
#define MYSMARTPOINTERCLASS_H_

#include <memory>

namespace KSI
{
	class MySmartPointerClass
	{
		public:
			MySmartPointerClass();

			const std::shared_ptr<uint8_t>& getSharedPointer() const;
			void setSharedPointer( const std::shared_ptr<uint8_t>& sharedPointer );

			std::unique_ptr<uint8_t> getUniquePointer() const;
			//void setUniquePointer( const std::unique_ptr<uint8_t>& uniquePointer );

		protected:
			//Not copyable
			MySmartPointerClass( const MySmartPointerClass& rhs );
			MySmartPointerClass& operator=( const MySmartPointerClass& rhs );

		private:
			std::shared_ptr<uint8_t> m_SharedPointer;
	};
}
#endif
