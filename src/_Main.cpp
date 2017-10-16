#include <cstdint> 
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <memory>

#include <boost/variant.hpp>

#include "CopyMoveAssignment/BSVector.h"
#include "CopyMoveAssignment/BSVector.h"
#include "CopyMoveAssignment/BSVectorRP.h"
#include "CopyMoveAssignment/BSVectorSP.h"

#include "Concurrency/MyStruct.h"
#include "Concurrency/MyCounter.h"
#include "Concurrency/MyAsync.h"

#include "Templates/Item.h"

#include "KafamdakiSoruIsaretleri/ReferenceMember.h"
#include "KafamdakiSoruIsaretleri/RecursirveFunctions.h"
#include "KafamdakiSoruIsaretleri/STLContainerIlklendirme.h"
#include "KafamdakiSoruIsaretleri/Casting/Widget.h"
#include "KafamdakiSoruIsaretleri/Casting/SpecialWidget.h"
#include "KafamdakiSoruIsaretleri/Casting/CastingClient.h"

//#include "DSAlgorithms/ArrayOperations.h"

#include "Interface/Animal.h"
#include "Interface/Canine.h"
#include "Interface/Feline.h"
#include "Interface/Dog.h"
#include "Interface/Tiger.h"
#include "Interface/Lion.h"

#include "KafamdakiSoruIsaretleri/CopyAssignment/MyClass.h"
#include "KafamdakiSoruIsaretleri/CopyAssignment/WhenCopyWhenAssignment.h"
#include "KafamdakiSoruIsaretleri/SmartPointers/MySmartPointerClass.h"
#include "KafamdakiSoruIsaretleri/FunctionObjects/StringAppender.h"
#include "Concurrency/CounterBaptisteWitch.h"
#include "Concurrency/ConditionalVariable/Laundary.h"

struct TRANSFERPROTOCOLHEADERSTRUCT
{
   /// number of 16-bit words contained in the upper layer message. The length of the header is excluded
   uint16_t uUsefulLength:10;   
   /// reserved
   uint16_t uReserved:6;
};

//void threadFunction()
//{
//	std::cout << "Enter - threadFunction" << std::endl;
//
//	std::lock_guard < std::mutex > guard1( myMutex1 );
//
//	std::cout << "threadFunction locked" << std::endl;
//
//	for ( auto i = -100 ; i != 0 ; ++i )
//	{
//		//std::lock_guard<std::mutex> guard2( myMutex2 );
//		std::cout << "threadFunction: " << i << std::endl;
//	}
//
//	std::cout << "Exit - threadFunction" << std::endl;
//}

struct Tree
{
   char data;
   Tree* left;
   Tree* right;
   Tree* parent;
};

void printTreePreOrder(struct Tree *node)
{
   if(node == NULL) return;

   std::cout << node->data << " ";
   printTreePreOrder(node->left);
   printTreePreOrder(node->right);
}

std::mutex myMutex1;
std::mutex myMutex2;

void printHalfOfNxNMatrix( const uint8_t& size )
{
   for(auto i = 0; i < size; i++)
   {
      for(auto j = i+1; j < size; j++)
      {
         std::cout << "*";
      }

      std::cout << "\n";
   }
}

bool isPalindrome( const std::string& input )
{
   bool bReturn = true;

   for (int i = 0; i < input.length()/2 ; i++)
   {
   	char other = input[input.length()-i-1];
      char temp = input[i];

      if ( other == temp)
      {
         bReturn = true;
      }
      else
      {
         bReturn = false;
         break;
      }
   }
   
   return bReturn;
}

void foo1( uint16_t& bag )
{
	std::lock( myMutex1, myMutex2 );

	std::lock_guard<std::mutex> printGuard( myMutex1, std::adopt_lock );
	std::cout << "Making apple juice" << std::endl;

	std::lock_guard<std::mutex> bagGuard( myMutex2, std::adopt_lock );
	bag++;
}

void foo2( uint16_t& bag )
{

	std::lock( myMutex1, myMutex2 );

	std::lock_guard<std::mutex> bagGuard( myMutex2, std::adopt_lock );
	bag++;

	std::lock_guard<std::mutex> printGuard( myMutex1, std::adopt_lock );
	std::cout << "Throwing out all pears" << std::endl;
}

void foo3( uint16_t& bag )
{

	std::lock_guard<std::mutex> printGuard( myMutex1 );
	std::cout << "Making carrot juice" << std::endl;

	std::lock_guard<std::mutex> bagGuard( myMutex2 );
	bag++;
}

//int main( int, char ** )
//{
//	std::cout << "Enter - Main" << std::endl;
//
//   const std::string& abcd = "abcd";
//   const std::string& abca = "abca";
//   const std::string& aba = "aba";
//   const std::string& d = "d";
//
//
//
//   isPalindrome(abca);
//   isPalindrome(aba);
//   isPalindrome(d);
//
//
//   TRANSFERPROTOCOLHEADERSTRUCT tph1;
//   TRANSFERPROTOCOLHEADERSTRUCT tph2 = {};
//	
//   std::vector<uint16_t> aaa;
//
//	//aaa.reserve(3);
//
//	//aaa.shrink_to_fit();
//
//	aaa.emplace_back(1);
//	aaa.emplace_back(2);
//	aaa.emplace_back(3);
//	aaa.emplace_back(4);
//	aaa.emplace_back(5);
//
//
//	aaa.shrink_to_fit();
//
//	//aaa[5]=1;
//	//aaa[6]=6;
//
//	auto a = aaa[4];
//
//	std::cout << "Exit - Main" << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//
//	//
//	//	uint8_t number1 = 6;
//	//	uint8_t number2 = 8;
//	//
//	//	const uint8_t* pNumber1 = nullptr;
//	//
//	//	uint8_t* const pNumber2 = &number2;
//	//
//	//	*pNumber2 = 88;
//	//
//	//	pNumber1 = &number1;
//	//
//	//	number1 = 66;
//	//
//	//	pNumber1 = &number2;
//	//
//	//	pNumber1++;
//	//	//pNumber2++;
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//	CONC::Laundary laundary;
//	//
//	//	std::thread mother( std::bind( &CONC::Laundary::cleanLaundary, &laundary) );
//	//	std::thread son( std::bind( &CONC::Laundary::playAround, &laundary) );
//	//
//	//	//std::thread mother2( &CONC::Laundary::cleanLaundary);
//	//	//std::thread son2( &CONC::Laundary::playAround );
//	//
//	//	mother.join();
//	//	son.join();
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	//std::cout << "Enter - Main" << std::endl;
//
//	//uint16_t bag = 0;
//
//	//std::thread t1(foo1, std::ref(bag));
//	//std::thread t2(foo2, std::ref(bag));
//
//	//t1.join();
//	//t2.join();
//
//	//std::cout << "bag: " << bag << std::endl;
//
//	//std::cout << "Exit - Main" << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//	std::vector<std::thread> threads1;
//	//
//	//	for ( auto i = 0 ; i < 5 ; ++i ) {
//	//		threads1.push_back( std::thread( []() {std::cout<< "Hello from thread " << std::this_thread::get_id() << std::endl;} ) );
//	//	}
//	//
//	//	// const auto& olmaz cunku join() fonksiyonu thread instanceinin stateini degistirir
//	//	for ( auto& t : threads1 ) {
//	//		t.join();
//	//	}
//	//
//	//	KSI::CounterBaptisteWitch cbw;
//	//
//	//	std::vector<std::thread> threads2;
//	//
//	//	for ( auto i = 0 ; i < 5 ; ++i ) {
//	//		threads2.push_back( std::thread( [&cbw]() {
//	//			for (auto i = 0; i < 100; ++i) {
//	//				cbw.incrementValue();
//	//			}
//	//		} ) );
//	//	}
//	//
//	//	// const auto& olmaz cunku join() fonksiyonu thread instanceinin stateini degistirir
//	//	for ( auto& t : threads2 ) {
//	//		t.join();
//	//	}
//	//
//	//	std::cout << "Main cbw: " << cbw << std::endl;
//
//	//std::cout << "Exit - Main" << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//	std::vector<uint8_t> v1;
//	//	v1.push_back( 1 );
//	//	v1.push_back( 2 );
//	//	v1.push_back( 3 );
//	//	v1.push_back( 4 );
//	//
//	//	auto aaa = [ &v1 ](const uint8_t& a )->double
//	//	{
//	//		v1.at(0) = 11 + a;
//	//		return (v1.at(0)*1.0);
//	//	};
//	//
//	//	std::cout << "Double: " << aaa( 3 ) << std::endl;
//	//
//	//	std::cout << "Double: " << [&v1](const uint8_t& a )->double
//	//	{
//	//		v1.at(0) = 12 + a;
//	//		return (v1.at(0)*1.0);
//	//	}( 3 ) << std::endl;
//	//
//	//	auto bbb = [&v1]()->double
//	//	{
//	//		v1.at(0) = 21;
//	//		return v1.at(0)*1.0;};
//	//
//	//	std::cout << "Double: " << bbb() << std::endl;
//	//
//	//	std::cout << "Double: " << [&v1]()->double
//	//	{
//	//		v1.at(0) = 22;
//	//		return v1.at(0)*1.0;
//	//	}() << std::endl;
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//	std::cout << KSI::StringAppender("is awesome")("C++") << std::endl;
//	//
//	//	std::cout << KSI::StringAppender("is awesome").operator()("Java") << std::endl;
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//std::cout << "Enter - Main" << std::endl;
//
//	//KSI::MySmartPointerClass mspc;
//
//	//auto usp = mspc.getUniquePointer();
//
//	//auto ssp = mspc.getSharedPointer();
//
//	//std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//	std::vector<double> bbb(3);
//	//
//	//	std::vector<double> aaa(32,9.9);
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//std::cout << "Enter - Main" << std::endl;
//
//	//KSI::WhenCopyWhenAssignment wcwa;
//	//KSI::MyClass mc;
//
//	//mc.setMember( 5 );
//
//	//wcwa.setMyClass(mc);
//
//	//KSI::WhenCopyWhenAssignment wcwa2 = wcwa;
//
//	//KSI::WhenCopyWhenAssignment wcwa3;
//
//	//wcwa3 = wcwa;
//
//	//KSI::MyClass mc2 = wcwa.getMyClass();
//
//	//KSI::MyClass mc3;
//
//	//mc3 = wcwa.getMyClass();
//
//	//const KSI::MyClass& mc4 = wcwa.getMyClass();
//
//	//const KSI::MyClass& mc5 = wcwa.getMyClassLocal();
//
//	//KSI::MyClass mc6 = wcwa.getMyClassLocal();
//
//	//KSI::MyClass mc7;
//	//mc7 = wcwa.getMyClassLocal();
//
//	//const KSI::MyClass& mc8 = wcwa.getMyClassLocal();
//
//	//std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	//	std::cout << "Enter - Main" << std::endl;
//	//
//	//	KSI::Widget w;
//	//	KSI::SpecialWidget sw;
//	//	KSI::CastingClient cc;
//	//
//	//	cc.update( dynamic_cast<KSI::SpecialWidget*>(&w) );
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	//	std::string s1( "Nancy" );
//	//
//	//	std::string s2( "Clancy" );
//	//
//	//	std::string& rs = s1;
//	//
//	//	std::string* ps = &s1;
//	//
//	//	rs = s2;
//	//
//	//	ps = &s2;
//	//
//	//	std::string s3(*ps);
//	//
//	//	std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//std::vector<uint8_t> localVector;
//
//	//KSI::STLContainerIlklendirme sci;
//
//	//const std::vector<uint8_t> fromClass = sci.getVector();
//
//	//	//cannot instantiate abstract class
//	//	//INT::Animal animal;
//	//	//INT::Canine canine;
//	//	///std::shared_ptr<INT::Animal> pAnimal = std::shared_ptr<INT::Canine>( new INT::Canine() );
//	//	//std::shared_ptr<INT::Canine> pCanine = std::shared_ptr<INT::Canine>( new INT::Canine() );
//	//
//	//	INT::Dog dog;
//	//	std::cout << "" << std::endl;
//	//
//	//	std::shared_ptr<INT::Animal> pAnimalDog = std::shared_ptr<INT::Animal>( new INT::Dog() );
//	//	std::cout << "" << std::endl;
//	//
//	//	std::shared_ptr<INT::Feline> pFelineLion = std::shared_ptr<INT::Feline>( new INT::Lion() );
//	//	std::cout << "" << std::endl;
//	//
//	//	INT::Tiger tiger;
//	//	std::cout << "" << std::endl;
//	//
//	//	tiger.sleep();
//	//	tiger.roam();
//	//
//	//	tiger.eat();
//	//
//	//
//	// std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	const uint8_t aaa(8);
//	//
//	//
//	//	auto bbb = 5;
//	//
//	//	auto ccc = 4.3;
//	//
//	//	auto sss = "aa";
//	//
//	//	auto ddd = 'a';
//	//
//	//	std::cout << "sizeof(bbb): " << static_cast<uint32_t>(sizeof(bbb)) << std::endl;
//	//
//	//	std::cout << "sizeof(ccc): " << static_cast<uint32_t>(sizeof(ccc)) << std::endl;
//	//
//	//	std::cout << "sizeof(sss): " << static_cast<uint32_t>(sizeof(sss)) << std::endl;
//	//
//	//	std::cout << "sizeof(ddd): " << static_cast<uint32_t>(sizeof(ddd)) << std::endl;
//
//	//KSI::RecursirveFunctions rf;
//
//	//rf.printStar( 3, 4 );
//
//	//rf.printStarRecursive( 3 );
//
//	//std::string aaa("aaa");
//
//	//std::wstring bbb(aaa.begin(),aaa.end());
//
//	//DSA::ArrayOperations ao;
//
//	//ao.performInsertion();
//
//	//std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//std::cout << "Enter - Main" << std::endl;
//
//	//uint8_t aaaa = 5;
//
//	//KSI::ReferenceMember rm( aaaa );
//
//	//uint8_t bbbb = 6;
//
//	//rm.setRefMem( bbbb );
//
//	//uint8_t cccc = rm.getRefMem();
//
//	//std::cout << "Exit - Main" << std::endl;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//boost::variant<uint8_t, char, std::string> v(1, 'A', "hello world");
//
//	//uint16_t aaa = 21;
//
//	//boost::variant<uint16_t, double, char, std::string> v;
//
//	//v = aaa;
//	//v = 3.14;
//	//v = 'a';
//	//v = "hello world!";
//
//	//std::cout << "v: " << v << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//	TMP::Item<uint8_t> tiUINT8Default;
//	//
//	//	TMP::Item<double> tiDoubleDefault;
//	//
//	//	TMP::Item<std::string> tiStringDefault;
//	//
//	//	uint8_t aaa = 6;
//	//
//	//	tiUINT8Default.setData( aaa );
//	//
//	//	std::cout << "tiUINT8Default.getData: " << static_cast<uint32_t>( tiUINT8Default.getData() ) << std::endl;
//	//
//	//	tiDoubleDefault.setData( 1234.5 );
//	//
//	//	std::cout << "tiDoubleDefault.getData: " << tiDoubleDefault.getData() << std::endl;
//	//
//	//	tiStringDefault.setData( "Never Give Up!!!" );
//	//
//	//	std::cout << "tiStringDefault.getData: " << tiStringDefault.getData() << std::endl;
//	//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	//	uint8_t value = 5;
//	//
//	//	uint8_t val = 3;
//	//
//	//	CONC::MyStruct ms( value );
//	//
//	//	//std::thread t1( ( MyStruct( value ) ), std::ref( val ) );
//	//
//	//	std::thread t1( std::ref( ms ), std::ref( val ) );
//	//
//	//	std::thread t2( std::ref( ms ), std::ref( val ) );
//	//
//	//	t1.join();
//	//	t2.join();
//	//
//	//	std::cout << " Main - value: " << static_cast<uint32_t>( value ) << std::endl;
//	//	std::cout << " Main - val: " << static_cast<uint32_t>( val ) << std::endl;
//	//	std::cout << " Main - ms.value: " << static_cast<uint32_t>( ms.getValue() ) << std::endl;
//	//
//	//	CONC::MyCounter counter;
//	//
//	//	std::vector < std::thread > threads;
//	//
//	//	for ( auto i = 0 ; i != 5 ; ++i )
//	//	{
//	//		threads.push_back( std::thread( [&counter]()
//	//		{
//	//			for ( auto ii = 0; ii != 100; ++ii )
//	//			{
//	//				counter.increment();
//	//			}
//	//		} ) );
//	//	}
//	//
//	//	for ( auto& thre : threads )
//	//	{
//	//		thre.join();
//	//	}
//	//
//	//	std::cout << "counter.value: " << static_cast<uint32_t>( counter.getValue() ) << std::endl;
//	//
//	//	std::thread t( []()
//	//	{
//	//		for ( auto i = -10; i != 0; ++i )
//	//		{
//	//			std::lock_guard < std::mutex > guard1( myMutex1 );
//	//			std::cout << "threadFunction locked" << std::endl;
//	//			//std::lock_guard<std::mutex> guard2( myMutex2 );
//	//		std::cout << "threadFunction: " << i << std::endl;
//	//	}
//	//} );
//	//
//	//	for ( auto i = 0 ; i != 10 ; ++i )
//	//	{
//	//		std::lock_guard < std::mutex > guard1( myMutex1 );
//	//		std::cout << " Main locked" << std::endl;
//	//		//std::lock_guard<std::mutex> guard2( myMutex2 );
//	//		std::cout << " Main thread: " << i << std::endl;
//	//	}
//	//
//	//	t.join();
//	//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	//
//	// BSVectorRP
//	//CMA::BSVectorRP bsvrp;
//
//	//std::cerr << __LINE__ << " Main Before BSVectorRP.getElem: " << bsvrp.getElem() << std::endl;
//
//	//{
//	//	CMA::BSVectorRP bsvrpCC = bsvrp;
//
//	//	CMA::BSVectorRP bsvrpAO;
//	//	bsvrpAO = bsvrp;
//	//}
//
//	//std::cerr << __LINE__ << " Main After BSVectorRP.getElem: " << bsvrp.getElem() << std::endl
//	//	<< std::endl;
//
//	//// BSVectorSP
//	//CMA::BSVectorSP bsvsp;
//
//	//std::cerr << __LINE__ << " Main Before BSVectorSP.getElem: " << bsvsp.getElemSP() << std::endl;
//
//	//{
//	//	CMA::BSVectorSP bsvspCC = bsvsp;
//
//	//	CMA::BSVectorSP bsvspAO;
//	//	bsvspAO = bsvsp;
//	//}
//
//	//std::cerr << __LINE__ << " Main After BSVectorSP.getElem: " << bsvsp.getElemSP() << std::endl
//	//	<< std::endl;
//
//	//// BSVectorUP
//	//CMA::BSVectorUP bsvup;
//
//	//std::cerr << __LINE__ << " Main Before BSVectorUP.getElem: " << bsvup.getElemUP() << std::endl;
//
//	//{
//	//	CMA::BSVectorUP bsvupCC = bsvup;
//
//	//	CMA::BSVectorUP bsvupAO;
//	//	bsvupAO = bsvup;
//	//}
//
//	//std::cerr << __LINE__ << " Main After BSVectorUP.getElem: " << bsvup.getElemUP() << std::endl
//	//	<< std::endl << std::endl;
//
//	//CMA::BSVector bsv;
//
//	//std::cerr << std::endl << std::endl << std::endl << __LINE__ << " Main CMA::BSVector members "
//	//	<< std::endl;
//
//	//CMA::BSVectorRP bsVectorRPRV = bsv.getBSVectorRPRV();
//	//CMA::BSVectorUP bsVectorUPRV = bsv.getBSVectorUPRV();
//	//CMA::BSVectorSP bsVectorSPRV = bsv.getBSVectorSPRV();
//
//	//CMA::BSVectorRP& bsVectorRPRR = bsv.getBSVectorRPRR();
//	//CMA::BSVectorUP& bsVectorUPRR = bsv.getBSVectorUPRR();
//	//CMA::BSVectorSP& bsVectorSPRR = bsv.getBSVectorSPRR();
//
//	//const CMA::BSVectorRP& bsVectorRPCRR = bsv.getBSVectorRPCRR();
//	//const CMA::BSVectorUP& bsVectorUPCRR = bsv.getBSVectorUPCRR();
//	//const CMA::BSVectorSP& bsVectorSPCRR = bsv.getBSVectorSPCRR();
//
//	//std::cerr << std::endl << std::endl << std::endl << __LINE__ << " Main CMA::BSVector move local "
//	//	<< std::endl;
//
//	//CMA::BSVectorRP bsVectorRPRVLMA;
//	//bsVectorRPRVLMA = bsv.getBSVectorRPRVL();
//
//	//CMA::BSVectorRP bsVectorRPRVLMA2 = bsv.getBSVectorRPRVL();
//
//	//CMA::BSVectorRP& bsVectorRPRVLMA3 = bsv.getBSVectorRPRVL();
//
//	//const CMA::BSVectorRP& bsVectorRPRVLMA4 = bsv.getBSVectorRPRVL();
//
//	//CMA::BSVectorUP bsVectorUPRVLMCA;
//	//bsVectorUPRVLMCA = bsv.getBSVectorUPRVL();
//
//	//CMA::BSVectorSP bsVectorSPRVLMCA;
//	//bsVectorSPRVLMCA = bsv.getBSVectorSPRVL();
//
//	//std::cerr << std::endl << std::endl << std::endl << __LINE__ << " Main CMA::BSVector copy"
//	//	<< std::endl;
//
//	//CMA::BSVector bsv2 = bsv;
//
//	//CMA::BSVector bsv3;
//	//bsv3 = bsv;
//
//	//std::cout << "Exit - Main" << std::endl;
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//	return 0;
//}