/*******************************************************************************
 *
 * (C) 2007 MilSOFT Yazilim Teknolojileri A.S.
 *
 * File: TestRunner.cpp
 *
 * CSU ID: COMMON
 *
 * Purpose: Common CPPUNIT test runner.
 *
 * History:
 *
 *    Date         Author        Changes
 *    ----------   ------------  -----------------
 *    01/08/2007   S.OZTURK      Created.
 * 	  23/06/2009   E.EROGLU      Return codes are changed.
                                 (For successful runs->0, for failures->119)
 *    07.04.2010   E.Eroglu      Updated for possible use multiple domains
 *    17.06.2013   H.GOLYERI     Removed the junk code.
 *
 * Notes:
 *    
 ******************************************************************************/

#include <fstream>
#include <stdlib.h>
#include <string.h>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestFailure.h>
#include <cppunit/SourceLine.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "SNCApp.h"

#if defined _WIN32
    #include <windows.h>
    #include <wincon.h>
#endif

extern SNCApp * pSNCApp = NULL;

#define UNIT_TEST_SUCCESS_RETURN_CODE 0
#define UNIT_TEST_FAILURE_RETURN_CODE 1

class TestProgressListenerSNC : public CppUnit::TestListener
{
public:
    TestProgressListenerSNC( CppUnit::CompilerOutputter* pOutputter ) :
        m_pOutputter( pOutputter ),
        m_bLastTestPassed( true )
    {
        #ifdef _WIN32
            consoleHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
            if ( consoleHandle != INVALID_HANDLE_VALUE )
            {
                CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                ::memset( &consoleInfo, 0, sizeof(consoleInfo) );
                if ( ::GetConsoleScreenBufferInfo( consoleHandle, &consoleInfo ) )
                {
                    defaultConsoleAttributes = consoleInfo.wAttributes;
                }
            }
        #endif
    }

private:
    #ifdef _WIN32
        enum Color
        {
            DEFAULT = 0,
            RED     = FOREGROUND_RED | FOREGROUND_INTENSITY,
            GREEN   = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
            BLUE    = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
            YELLOW  = RED | GREEN,
            CYAN    = BLUE | GREEN,
            MAGENTA = RED | BLUE,
        };
    #else
        enum Color
        {
            DEFAULT = 0,
            RED     = 1,
            GREEN   = 2,
            BLUE    = 4,
            YELLOW  = 3,
            CYAN    = 6,
            MAGENTA = 5
        };
    #endif

    static void SetConsoleColor( Color foregroundColor, Color backgroundColor = DEFAULT )
    {
        #ifdef _WIN32
            if ( consoleHandle != INVALID_HANDLE_VALUE )
            {
                WORD defaultForegroundColor = (defaultConsoleAttributes & 0x000F);
                WORD defaultBackgroundColor = (defaultConsoleAttributes & 0x00F0);

                WORD newConsoleColors = 0;
                newConsoleColors |= (foregroundColor == DEFAULT) ? defaultForegroundColor : foregroundColor;
                newConsoleColors |= (backgroundColor == DEFAULT) ? defaultBackgroundColor : backgroundColor;

                SetConsoleTextAttribute( consoleHandle, newConsoleColors );
            }
        #else
            if ( ::getenv("TERM") )
            {
                if ( backgroundColor == DEFAULT )
                {
                    std::cout << "\x1B[49m";// Set background color to default.
                }
                else
                {
                    std::cout << "\x1B[" << 40 + backgroundColor << "m";
                }

                if ( foregroundColor == DEFAULT )
                {
                    std::cout << "\x1B[22;39m";// Set text color and intensity to default.
                }
                else
                {
                    std::cout << "\x1B[1;" << 30 + foregroundColor << "m";
                }
            }
        #endif
    }

public:
    void startTest( CppUnit::Test *test )
    {
        SetConsoleColor( CYAN );
        std::cout << "TEST STARTED  : " << test->getName() << std::endl;
        SetConsoleColor( DEFAULT );
    }

    void endTest( CppUnit::Test *test )
    {
        if ( m_bLastTestPassed )
        {
            SetConsoleColor( GREEN );
            std::cout << "TEST PASSED   : " << test->getName() << std::endl;
            SetConsoleColor( DEFAULT );
        }        
        else
        {
            m_bLastTestPassed = true;
        }
    }

    void addFailure( const CppUnit::TestFailure &rFailure )
    {
        m_bLastTestPassed = false;
        CppUnit::TestFailure* pFailure = rFailure.clone();
        
        SetConsoleColor( RED );
        std::cout << "TEST FAILED   : " << pFailure->failedTest()->getName() << std::endl;
        m_pOutputter->printFailureDetail( pFailure );
        SetConsoleColor( DEFAULT );

        delete pFailure;
    }

    static void printTestResults( const CppUnit::TestResultCollector& rResults )
    {
        std::cout << std::endl;
        std::cout << std::endl;

        if ( rResults.testFailuresTotal() == 0 )
        {
            SetConsoleColor( GREEN );
            std::cout << "UNIT TEST REPORT : ";
            std::cout << " ALL (" << rResults.runTests() << ") TESTS PASSED" << std::endl;
            SetConsoleColor( DEFAULT );
        }
        else
        {
            SetConsoleColor( RED );
            std::cout << "UNIT TEST REPORT : ";
            std::cout << "FOLLOWING " << rResults.testFailuresTotal();
            std::cout << " TESTS (OUT OF " << rResults.runTests() << ") FAILED " << std::endl;
            std::cout << "=========================================================================" << std::endl;

            for ( int i = 0 ; i < rResults.testFailuresTotal() ; i++ )
            {
                CppUnit::TestFailure* pfailure = rResults.failures()[i];
                std::cout << pfailure->failedTestName() << " : "
                    << pfailure->sourceLine().fileName()
                    << "(" << pfailure->sourceLine().lineNumber() << ")"
                    << std::endl;
            }
            SetConsoleColor( DEFAULT );
        }

        std::cout << std::endl;
    }

private:
    CppUnit::CompilerOutputter* m_pOutputter;
    bool m_bLastTestPassed;

#ifdef _WIN32
    static HANDLE consoleHandle;
    static WORD defaultConsoleAttributes;
#endif
};

#ifdef _WIN32
    HANDLE TestProgressListenerSNC::consoleHandle = INVALID_HANDLE_VALUE;
    WORD TestProgressListenerSNC::defaultConsoleAttributes = 0;
#endif

int main(int argc, char** argv)
{
	SNCApp app;
	pSNCApp = &app;

    // Create the event manager and test controller.
    CPPUNIT_NS::TestResult controller;

    // Add a listener that collects test result.
    CPPUNIT_NS::TestResultCollector resultCollector;
    controller.addListener( &resultCollector );

	// Add the custom progress listener.
    CPPUNIT_NS::CompilerOutputter compilerOutputter( &resultCollector, std::cout );
    TestProgressListenerSNC mantdlListener( &compilerOutputter );
    controller.addListener( &mantdlListener );

    // Add the top suite to the test runner.
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);
    mantdlListener.printTestResults( resultCollector );

    // Write test results to an XML file.
    std::ofstream xmlFile( "TestResults.xml", (std::ios_base::out | std::ios_base::trunc) );
    if ( !xmlFile.bad() )
    {
        CPPUNIT_NS::XmlOutputter xmlOutputter( &resultCollector, xmlFile );
        xmlOutputter.write();
        xmlFile.close();
    }

    return resultCollector.wasSuccessful() ? UNIT_TEST_SUCCESS_RETURN_CODE : UNIT_TEST_FAILURE_RETURN_CODE;
}
