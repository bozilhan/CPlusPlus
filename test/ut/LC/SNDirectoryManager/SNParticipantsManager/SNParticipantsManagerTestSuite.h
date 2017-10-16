#ifndef SNPARTICIPANTSMANAGERTESTSUITE_H_
#define SNPARTICIPANTSMANAGERTESTSUITE_H_

#include <memory>

#include <cppunit/extensions/HelperMacros.h>

class SNParticipantsManagerStub;

class SNParticipantsManagerTestSuite : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( SNParticipantsManagerTestSuite );

		CPPUNIT_TEST( testProcessCompactAddress );

		CPPUNIT_TEST_SUITE_END();

	public:
		SNParticipantsManagerTestSuite();
		virtual ~SNParticipantsManagerTestSuite();

		void setUp();
		void tearDown();

		void testProcessCompactAddress();

	private:
		std::unique_ptr<SNParticipantsManagerStub> m_pSNParticipantsManagerStub;
};

#endif
