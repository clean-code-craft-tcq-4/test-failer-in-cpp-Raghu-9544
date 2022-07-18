#ifndef TEST_MISALIGNED_HPP
#define TEST_MISALIGNED_HPP
#include"misaligned.hpp"

void testCreateColorCodeManual(TelCoColorCoder::ColorCode* colorCodeDatabase[], int databaseSize, const char* majorColor[], const char* minorColor[]);
void testGetMinorColor(TelCoColorCoder::ColorCode* colorDatabaseElement, const char* expectedMinorColor);
void testGetMajorColor(TelCoColorCoder::ColorCode* colorDatabaseElement, const char* expectedMajorColor);
void testGetPairNumber(TelCoColorCoder::ColorCode* colorDatabaseElement, int expectedPairNumber);

#endif
