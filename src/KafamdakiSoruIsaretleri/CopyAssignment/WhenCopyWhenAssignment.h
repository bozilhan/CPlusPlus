#ifndef WHENCOPYWHENASSIGNMENT_H_
#define WHENCOPYWHENASSIGNMENT_H_

#include "MyClass.h"

namespace KSI
{
	class WhenCopyWhenAssignment
	{
		public:
			WhenCopyWhenAssignment();

			const MyClass& getMyClass() const;
			void setMyClass( const MyClass& myClass );

			WhenCopyWhenAssignment( const WhenCopyWhenAssignment& rhs);
			WhenCopyWhenAssignment& operator=( const WhenCopyWhenAssignment& rhs);

			WhenCopyWhenAssignment( WhenCopyWhenAssignment&& rhs );
			WhenCopyWhenAssignment& operator=( WhenCopyWhenAssignment&& rhs );

			MyClass getMyClassLocal() const;

		private:
			MyClass m_MyClass;
	};
}
#endif
