#include "SNParticipantsStub.h"

SNParticipantsStub::SNParticipantsStub() :
		LC::SNParticipants()
{
}

SNParticipantsStub::~SNParticipantsStub()
{
}

void SNParticipantsStub::setLinkMAddressToParticipantMap( const LC::SNParticipants::LinkMAddressToParticipantMapType& linkMAddressToParticipantMap )
{
	m_LinkMAddressToParticipantMap = linkMAddressToParticipantMap;
}

uint8_t SNParticipantsStub::getLana() const
{
	return m_LANA;
}

void SNParticipantsStub::setLana( const uint8_t& lana )
{
	m_LANA = lana;
}

uint8_t SNParticipantsStub::getMaxMantdlAddress() const
{
	return m_MaxMantdlAddress;
}

void SNParticipantsStub::setMaxMantdlAddress( const uint8_t& maxMantdlAddress )
{
	m_MaxMantdlAddress = maxMantdlAddress;
}
