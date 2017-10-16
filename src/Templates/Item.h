#ifndef ITEM_H_
#define ITEM_H_

#include <memory>

namespace TMP
{
	template<typename T>
	class Item
	{
		public:
			Item();

			explicit Item( const T& data );

			~Item();

			T getData() const;
			void setData( const T& data );

			T* getDataRawPtr() const;
			void setDataRawPtr( const T* pDataRawPtr );

			std::shared_ptr<T> getDataSharedPtr() const;
			void setDataSharedPtr( std::shared_ptr<T> pDataSharedPtr );

			const std::unique_ptr<T>& getDataUniquePtr() const;
			void setDataUniquePtr( const std::unique_ptr<T>& pDataUniquePtr );

			Item( const Item& rhs );
			Item<T>& operator=( const Item& rhs );

			Item( Item&& rhs );
			Item<T>& operator=( Item&& rhs );

		private:
			T m_Data;
			std::shared_ptr<T> m_pDataSharedPtr;
			std::unique_ptr<T> m_pDataUniquePtr;
			T* m_pDataRawPtr;
	};
}
#endif
