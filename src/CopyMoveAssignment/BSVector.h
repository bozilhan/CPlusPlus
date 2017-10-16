#ifndef BSVECTOR_H_
#define BSVECTOR_H_

#include "BSVectorRP.h"
#include "BSVectorSP.h"
#include "BSVectorUP.h"

namespace CMA
{
	class BSVector
	{
		public:
			BSVector();
			~BSVector();

			BSVectorRP getBSVectorRPRV() const;
			BSVectorUP getBSVectorUPRV() const;
			BSVectorSP getBSVectorSPRV() const;

			BSVectorRP getBSVectorRPRVL();
			BSVectorUP getBSVectorUPRVL();
			BSVectorSP getBSVectorSPRVL();

			BSVectorRP& getBSVectorRPRR();
			BSVectorUP& getBSVectorUPRR();
			BSVectorSP& getBSVectorSPRR();

			const BSVectorRP& getBSVectorRPCRR() const;
			const BSVectorUP& getBSVectorUPCRR() const;
			const BSVectorSP& getBSVectorSPCRR() const;

			BSVector( const BSVector& rhs );
			BSVector& operator=( const BSVector& rhs );

			BSVector( BSVector&& rhs );
			BSVector& operator=( BSVector&& rhs );

		private:
			BSVectorRP m_BSVectorRP;
			BSVectorUP m_BSVectorUP;
			BSVectorSP m_BSVectorSP;
	};
}

#endif

// BSVectorRP
//CMA::BSVectorRP bsvrp;

//std::cerr << __LINE__ << " Main Before BSVectorRP.getElem: " << bsvrp.getElem() << std::endl;

//{
//	CMA::BSVectorRP bsvrpCC = bsvrp;

//	CMA::BSVectorRP bsvrpAO;
//	bsvrpAO = bsvrp;
//}

//std::cerr << __LINE__ << " Main After BSVectorRP.getElem: " << bsvrp.getElem() << std::endl
//	<< std::endl;

//// BSVectorSP
//CMA::BSVectorSP bsvsp;

//std::cerr << __LINE__ << " Main Before BSVectorSP.getElem: " << bsvsp.getElemSP() << std::endl;

//{
//	CMA::BSVectorSP bsvspCC = bsvsp;

//	CMA::BSVectorSP bsvspAO;
//	bsvspAO = bsvsp;
//}

//std::cerr << __LINE__ << " Main After BSVectorSP.getElem: " << bsvsp.getElemSP() << std::endl
//	<< std::endl;

//// BSVectorUP
//CMA::BSVectorUP bsvup;

//std::cerr << __LINE__ << " Main Before BSVectorUP.getElem: " << bsvup.getElemUP() << std::endl;

//{
//	CMA::BSVectorUP bsvupCC = bsvup;

//	CMA::BSVectorUP bsvupAO;
//	bsvupAO = bsvup;
//}

//std::cerr << __LINE__ << " Main After BSVectorUP.getElem: " << bsvup.getElemUP() << std::endl
//	<< std::endl << std::endl;

//CMA::BSVector bsv;

//std::cerr << std::endl << std::endl << std::endl << __LINE__ << " Main CMA::BSVector members "
//	<< std::endl;

//CMA::BSVectorRP bsVectorRPRV = bsv.getBSVectorRPRV();
//CMA::BSVectorUP bsVectorUPRV = bsv.getBSVectorUPRV();
//CMA::BSVectorSP bsVectorSPRV = bsv.getBSVectorSPRV();

//CMA::BSVectorRP& bsVectorRPRR = bsv.getBSVectorRPRR();
//CMA::BSVectorUP& bsVectorUPRR = bsv.getBSVectorUPRR();
//CMA::BSVectorSP& bsVectorSPRR = bsv.getBSVectorSPRR();

//const CMA::BSVectorRP& bsVectorRPCRR = bsv.getBSVectorRPCRR();
//const CMA::BSVectorUP& bsVectorUPCRR = bsv.getBSVectorUPCRR();
//const CMA::BSVectorSP& bsVectorSPCRR = bsv.getBSVectorSPCRR();

//std::cerr << std::endl << std::endl << std::endl << __LINE__ << " Main CMA::BSVector move local "
//	<< std::endl;

//CMA::BSVectorRP bsVectorRPRVLMA;
//bsVectorRPRVLMA = bsv.getBSVectorRPRVL();

//CMA::BSVectorRP bsVectorRPRVLMA2 = bsv.getBSVectorRPRVL();

//CMA::BSVectorRP& bsVectorRPRVLMA3 = bsv.getBSVectorRPRVL();

//const CMA::BSVectorRP& bsVectorRPRVLMA4 = bsv.getBSVectorRPRVL();

//CMA::BSVectorUP bsVectorUPRVLMCA;
//bsVectorUPRVLMCA = bsv.getBSVectorUPRVL();

//CMA::BSVectorSP bsVectorSPRVLMCA;
//bsVectorSPRVLMCA = bsv.getBSVectorSPRVL();

//std::cerr << std::endl << std::endl << std::endl << __LINE__ << " Main CMA::BSVector copy"
//	<< std::endl;

//CMA::BSVector bsv2 = bsv;

//CMA::BSVector bsv3;
//bsv3 = bsv;

//std::cout << "Exit - Main" << std::endl;
