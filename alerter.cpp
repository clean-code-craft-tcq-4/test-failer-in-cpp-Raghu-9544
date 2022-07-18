#include <iostream>
#include <assert.h>
#include "alerter.hpp"
#include "test_alerter.hpp"

//Software development cycle
#define PRODUCTION 1
#define UNIT_TEST 0
#define SW_STAGE PRODUCTION


static networkFuncPtr assignFunctionToFuncPtr(networkFuncPtr networkAlert, networkFuncPtr networkAlertStub);
namespace Alert
{
    int alertFailureCount = 0;

// Fake Dependency
    int networkAlertStub(float celcius)
    {
        //stuff function to imitate network alert in absence of real network.
        if (celcius <= 200)
        {
            std::cout << "Relax: Temperature is " << celcius << " celcius.\n";
            return 200;
        }
        else
        {
            std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
            return 500;
        }
    }
 // Real Dependency   
    int networkAlert(float celcius)
    {
        // do some network connections, http and other stuff.
        if (celcius <= 200)
        {
            std::cout << "Relax: Temperature is " << celcius << " celcius.\n";
            return 200;
        }
        else
        {
            std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
            return 500;
        }
    }
 // Pure function and implement one responsiblity 
    float convertFarenheitToCelcius(float farenheit)
    {
        return ((farenheit - 32) * 5 / 9);
    }
// Actual function with dependency 
    void alertInCelcius(float farenheit, networkFuncPtr assignedNetworkFunction)
    {
        float celcius = convertFarenheitToCelcius(farenheit);
        int returnCode = assignedNetworkFunction(celcius);
        if (returnCode != 200) {
            alertFailureCount += 1;
        }
        else
        {
            alertFailureCount += 0;  // doesnot impact functionality just added for sake of completion of if_else pair for code coverage
        }

    }
}
static networkFuncPtr assignFunctionToFuncPtr(networkFuncPtr networkAlert, networkFuncPtr networkAlertStub)
{
    networkFuncPtr assignNetworkFunc = nullptr;
#if (SW_STAGE == PRODUCTION)
    {
        assignNetworkFunc = networkAlert;
    }
#elif (SW_STAGE == UNIT_TEST)
    {
        assignNetworkFunc = networkAlertStub;
    }
#else
    {
        //future implementation
    }
#endif
    // dummy if...else to use 2nd function address to avoid usused parameter warning error in git.
    if (networkAlertStub == nullptr)
    {
      //do nothing }  
    }
	else
	{
		//do nothing
	}
	return assignNetworkFunc;
}
int main()
{
    networkFuncPtr assignedNetworkFunc;
    assignedNetworkFunc = assignFunctionToFuncPtr(&(Alert::networkAlert), &(Alert::networkAlertStub));

    testNetworkAlertStub();
    testNetworkAlert();
    testConvertFarenheitToCelcius();
    testAlertInCelcius(assignedNetworkFunc); // injected dependency 


    std::cout << "All is well (Definitely!)\n";
    return 0;
}
