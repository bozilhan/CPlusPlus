#ifndef STRINGAPPENDER_H_
#define STRINGAPPENDER_H_

#include <string>

namespace KSI
{
	class StringAppender
	{
		public:
			StringAppender();

			explicit StringAppender( const std::string& toAppend );

			std::string operator()(const std::string& str) const;

		protected:
			//Not copyable
			StringAppender( const StringAppender& rhs );
			StringAppender& operator=( const StringAppender& rhs );

		private:
			std::string m_ToAppend;
	};
}
#endif
