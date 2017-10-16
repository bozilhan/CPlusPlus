#ifndef SNPARTICIPANTSSTUB_H_
#define SNPARTICIPANTSSTUB_H_

#include <map>

#include "LC/SNDirectory/SNParticipants/SNParticipants.h"

class SNParticipantsStub : public LC::SNParticipants
{
	public:
		SNParticipantsStub();

		virtual ~SNParticipantsStub();

		void setLinkMAddressToParticipantMap( const LC::SNParticipants::LinkMAddressToParticipantMapType& linkMAddressToParticipantMap );

		uint8_t getLana() const;
		void setLana( const uint8_t& lana );

		uint8_t getMaxMantdlAddress() const;
		void setMaxMantdlAddress( const uint8_t& maxMantdlAddress );

	protected:
		//Not copyable
		SNParticipantsStub( const SNParticipantsStub& rhs );
		SNParticipantsStub& operator=( const SNParticipantsStub& rhs );

	private:
};

#endif
