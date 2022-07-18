#ifndef ALERTER_HPP
#define ALERTER_HPP
typedef  int(* networkFuncPtr)(float);
namespace Alert
{
	extern int alertFailureCount;
	int networkAlertStub(float celcius);
	int networkAlert(float celcius);
	void alertInCelcius(float farenheit, networkFuncPtr assignedNetworkFunction);
	float convertFarenheitToCelcius(float farenheit);
}

#endif
