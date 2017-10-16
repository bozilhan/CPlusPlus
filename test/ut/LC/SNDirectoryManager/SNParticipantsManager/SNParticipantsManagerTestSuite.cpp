#include "SNParticipantsManagerTestSuite.h"

#include <cppunit/TestAssert.h>

#include "ut/LC/SNDirectoryManager/SNParticipantsManager/Stubs/SNParticipantsStub.h"
#include "ut/LC/SNDirectoryManager/SNParticipantsManager/Stubs/SNParticipantsManagerStub.h"

#include "LC/TechnicalMessageManager/TechnicalMessages/DirectoryCompactAddress.h"

#include "LC/SNDirectory/SNParticipants/Participant.h"

CPPUNIT_TEST_SUITE_REGISTRATION( SNParticipantsManagerTestSuite );

SNParticipantsManagerTestSuite::SNParticipantsManagerTestSuite() :
	m_pSNParticipantsManagerStub( nullptr )
{
}

SNParticipantsManagerTestSuite::~SNParticipantsManagerTestSuite()
{
}

void SNParticipantsManagerTestSuite::setUp()
{
	m_pSNParticipantsManagerStub = std::unique_ptr<SNParticipantsManagerStub>(new SNParticipantsManagerStub());
}

void SNParticipantsManagerTestSuite::tearDown()
{
}

//void SNParticipantsManagerTestSuite::testGetCurrentVersionFromTechnicalCurrentVersion()
//{
//	uint32_t internalVersion = 94;
//
//	m_pSNParticipantsManagerStub->setVersion( internalVersion );
//
//	CPPUNIT_ASSERT_EQUAL( m_pSNParticipantsManagerStub->getCurrentVersionFromTechnicalCurrentVersion(1), static_cast<uint32_t>(94) );
//
//	CPPUNIT_ASSERT_EQUAL( m_pSNParticipantsManagerStub->getCurrentVersionFromTechnicalCurrentVersion(2), static_cast<uint32_t>(95) );
//}

void SNParticipantsManagerTestSuite::testProcessCompactAddress()
{
	uint16_t nua1 = 1001;
	uint16_t nua2 = 1002;
	uint16_t nua3 = 1003;

	uint8_t m1= 1;
	uint8_t m2= 2;
	uint8_t m3= 3;

	LC::Participant p1;
	p1.setLinkMAddress(nua1);
	p1.setMantdlAddress(m1);
	
	LC::Participant p2;
	p2.setLinkMAddress(nua2);
	p2.setMantdlAddress(m2);
	
	LC::Participant p3;
	p3.setLinkMAddress(nua3);
	p3.setMantdlAddress(m3);

	LC::SNParticipants::LinkMAddressToParticipantMapType linkMAddressToParticipantMap;
	linkMAddressToParticipantMap[nua1] = p1;
	linkMAddressToParticipantMap[nua2] = p2;
	linkMAddressToParticipantMap[nua3] = p3;

	SNParticipantsStub snps;
	snps.setLana(1);
	snps.setMaxMantdlAddress(3);
	snps.setLinkMAddressToParticipantMap(linkMAddressToParticipantMap);

	std::vector<LC::SNParticipants> snParticipantsList;
	snParticipantsList.emplace_back( snps );

	m_pSNParticipantsManagerStub->setSnParticipantsList( snParticipantsList );

	std::vector<LC::DirectoryCompactAddressPtr> dcaVector;

	for ( auto i = 0; i != 4; ++i ) 
	{
		LC::DirectoryCompactAddress dca;
		dca.setAddressVersionNumber( 3 + i );
		dca.setFirstNileAddress( 100 + i );

		dcaVector.emplace_back( &dca );
	}

	//for( const auto& msg : dcaVector )
	//{
	//	m_pSNParticipantsManagerStub->processCompactAddress(msg);
	//}
	m_pSNParticipantsManagerStub->processCompactAddress(dcaVector);

}
