#include <iostream>
#include <assert.h>
#include "test_alerter.hpp"

// static internal function decalration --> declared in .cpp since not intended for other files usage
static void testNetworkAlertStubImpl(float celcius, int expectedReturnValue);
static void testNetworkAlertImpl(float celcius, int expectedReturnValue);
static void testAlertInCelciusImpl(float farenheit, networkFuncPtr testAssignedNetworkFunction, int expectedAlertCount);
static void testConvertFarenheitToCelciusImpl(float farenheit, float expectedCelciusValue);

void testNetworkAlertStub(void)
{
	testNetworkAlertStubImpl(100.5, 200);
	testNetworkAlertStubImpl(200.0, 200);
	testNetworkAlertStubImpl(300.5, 500);
	testNetworkAlertStubImpl(1000.5, 500);
}
void testNetworkAlert(void)
{
	testNetworkAlertImpl(100.5, 200);
	testNetworkAlertImpl(200.0, 200);
	testNetworkAlertImpl(300.5, 500);
	testNetworkAlertImpl(1000.5, 500);
}
void testConvertFarenheitToCelcius(void)
{
	testConvertFarenheitToCelciusImpl(32, 0);
	testConvertFarenheitToCelciusImpl(-4,-20);
	testConvertFarenheitToCelciusImpl(104, 40);
	testConvertFarenheitToCelciusImpl(50, 10);
	testConvertFarenheitToCelciusImpl(212, 100);
}
void testAlertInCelcius(networkFuncPtr testAssignedNetworkFunction)
{
	testAlertInCelciusImpl(303.6f, testAssignedNetworkFunction, 0);
	testAlertInCelciusImpl(500.6f, testAssignedNetworkFunction, 1);
	testAlertInCelciusImpl(100.6f, testAssignedNetworkFunction, 1);
	testAlertInCelciusImpl(1200.6f, testAssignedNetworkFunction, 2);
	testAlertInCelciusImpl(0, testAssignedNetworkFunction, 2);
	testAlertInCelciusImpl(-10, testAssignedNetworkFunction, 2);
	testAlertInCelciusImpl(392, testAssignedNetworkFunction, 2); //boundary value of 200 threshold
}


static void testNetworkAlertStubImpl(float celcius, int expectedReturnValue)
{
	assert(Alert::networkAlertStub(celcius) == expectedReturnValue);
}
static void testNetworkAlertImpl(float celcius, int expectedReturnValue)
{
	assert(Alert::networkAlert(celcius) == expectedReturnValue);
}
static void testConvertFarenheitToCelciusImpl(float farenheit, float expectedCelciusValue)
{
	assert(Alert::convertFarenheitToCelcius(farenheit) == expectedCelciusValue);
}

static void testAlertInCelciusImpl(float farenheit, networkFuncPtr assignedNetworkFunction, int expectedAlertCount)
{
	Alert::alertInCelcius(farenheit, assignedNetworkFunction);
	assert(Alert::alertFailureCount == expectedAlertCount);
}

