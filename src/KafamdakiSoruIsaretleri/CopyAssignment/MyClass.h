#ifndef MYCLASS_H_
#define MYCLASS_H_

#include <cstdint>

namespace KSI
{
	class MyClass
	{
		public:
			MyClass();
			~MyClass();

			uint8_t getMember() const;
			void setMember( const uint8_t& member );

			MyClass& operator=( const MyClass& rhs);
			MyClass( const MyClass& rhs);

	//protected:
		MyClass( MyClass&& rhs );
		MyClass& operator=( MyClass&& rhs );

		private:
			uint8_t m_Member;
	};
}
#endif
