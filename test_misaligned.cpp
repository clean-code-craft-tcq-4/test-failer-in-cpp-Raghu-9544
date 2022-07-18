#include"test_misaligned.hpp"
#include<iostream>
#include<assert.h>

void testGetMinorColor(TelCoColorCoder::ColorCode* colorDatabaseElement, const char* expectedMinorColor)
{
    assert(colorDatabaseElement->m_minorColor == expectedMinorColor);
}
void testGetMajorColor(TelCoColorCoder::ColorCode* colorDatabaseElement, const char* expectedMajorColor)
{
    assert(colorDatabaseElement->m_majorColor == expectedMajorColor);
}
void testGetPairNumber(TelCoColorCoder::ColorCode* colorDatabaseElement, int expectedPairNumber)
{
    assert(colorDatabaseElement->m_pairNumber == expectedPairNumber);
}
void testCreateColorCodeManual(TelCoColorCoder::ColorCode* colorCodeDatabase[], int databaseSize, const char* majorColor[], const char* minorColor[])
{
    for (int database_index = 0; database_index < databaseSize; database_index++)
    {
        assert(colorCodeDatabase[database_index]->m_majorColor == majorColor[database_index/5]);
        assert(colorCodeDatabase[database_index]->m_minorColor == minorColor[database_index%5]);
        assert(colorCodeDatabase[database_index]->m_pairNumber == database_index+1);
    }
}
