#ifndef SNPARTICIPANTSMANAGERSTUB_H_
#define SNPARTICIPANTSMANAGERSTUB_H_

#include "LC/SNDirectory/SNParticipants/SNParticipantsManager.h"

class SNParticipantsManagerStub : public LC::SNParticipantsManager
{
	public:
		SNParticipantsManagerStub();

		virtual ~SNParticipantsManagerStub();

		const std::vector<LC::SNParticipants>& getSnParticipantsList() const;
		void setSnParticipantsList( const std::vector<LC::SNParticipants>& snParticipantsList );

		uint32_t getVersion() const;
		void setVersion( const uint32_t& version );

	protected:
		//Not copyable
		SNParticipantsManagerStub( const SNParticipantsManagerStub& rhs );
		SNParticipantsManagerStub& operator=( const SNParticipantsManagerStub& rhs );

	private:
		uint32_t m_Version;
};

#endif
