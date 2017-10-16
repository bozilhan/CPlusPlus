#include "SNParticipantsManagerStub.h"

SNParticipantsManagerStub::SNParticipantsManagerStub() :
		LC::SNParticipantsManager()
{
}

SNParticipantsManagerStub::~SNParticipantsManagerStub()
{
}

const std::vector<LC::SNParticipants>& SNParticipantsManagerStub::getSnParticipantsList() const
{
	return m_SNParticipantsList;
}

void SNParticipantsManagerStub::setSnParticipantsList( const std::vector<LC::SNParticipants>& snParticipantsList )
{
	m_SNParticipantsList = snParticipantsList;
}

uint32_t SNParticipantsManagerStub::getVersion() const
{
	return m_Version;
}

void SNParticipantsManagerStub::setVersion( const uint32_t& version )
{
	m_Version = version;
}
