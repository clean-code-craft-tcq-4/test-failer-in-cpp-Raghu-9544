#ifndef TEST_ALERTER_HPP
#define TEST_ALERTER_HPP
#include "alerter.hpp"

//Implememtation functions for test exposed to alerter.cpp
void testNetworkAlertStub(void);
void testNetworkAlert(void);
void testAlertInCelcius(networkFuncPtr testAssignedNetworkFunction);
void testConvertFarenheitToCelcius(void);
#endif
