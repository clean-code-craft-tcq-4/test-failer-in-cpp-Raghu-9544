#include <iostream>
#include <assert.h>
#include "misaligned.hpp"
#include "test_misaligned.hpp"

namespace TelCoColorCoder
{
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int   numberOfMajorColor = sizeof(majorColor)/sizeof(*majorColor);
const int   numberOfMinorColor = sizeof(minorColor)/sizeof(*minorColor);
const int   databaseSize       = numberOfMajorColor * numberOfMinorColor;

void createColorCodeManual(const char* majorColor[], const char* minorColor[], ColorCode* ColorCodeDatabase[])
{

    for (int majorColorIdx = 0; majorColorIdx < numberOfMajorColor; majorColorIdx++)
    {
        for (int minorColorIdx = 0; minorColorIdx < numberOfMinorColor; minorColorIdx++)
        {
            ColorCodeDatabase[majorColorIdx * 5 + minorColorIdx] = new ColorCode;
            ColorCodeDatabase[majorColorIdx * 5 + minorColorIdx]->m_majorColor = majorColor[majorColorIdx];
            ColorCodeDatabase[majorColorIdx * 5 + minorColorIdx]->m_minorColor = minorColor[minorColorIdx];
            ColorCodeDatabase[majorColorIdx * 5 + minorColorIdx]->m_pairNumber = (majorColorIdx * 5 + minorColorIdx) + 1;
        }
    }
}
int ColorCode::getPairNumber() const
{       
    return m_pairNumber;  
}
char const * ColorCode::getMajorColor() const
{       
   return m_majorColor;
}
char const* ColorCode::getMinorColor() const
{
	return m_minorColor;
}
int printColorCodeManual(ColorCode* ColorCodeDatabase[]) {
    int database_index = 0;
    for( database_index = 0; database_index < databaseSize; database_index++)
            {
                std::cout<< ColorCodeDatabase[database_index]->m_pairNumber << "     |"<<ColorCodeDatabase[database_index]->m_majorColor << "    | " << ColorCodeDatabase[database_index]->m_minorColor << "  |   "   <<std::endl;
            }
    return database_index;
}
}

int main() {
    TelCoColorCoder::ColorCode* ColorCodeDatabase[TelCoColorCoder::databaseSize];
    TelCoColorCoder::createColorCodeManual(TelCoColorCoder::majorColor, TelCoColorCoder::minorColor, ColorCodeDatabase);
    testGetMinorColor(ColorCodeDatabase[1], TelCoColorCoder::minorColor[1]);
    testGetMajorColor(ColorCodeDatabase[1], TelCoColorCoder::majorColor[0]);
    testGetPairNumber(ColorCodeDatabase[1], 2);
    testCreateColorCodeManual(ColorCodeDatabase, TelCoColorCoder::databaseSize, TelCoColorCoder::majorColor, TelCoColorCoder::minorColor);
    assert(TelCoColorCoder::printColorCodeManual(ColorCodeDatabase) == TelCoColorCoder::databaseSize);


    std::cout << "All is well (maybe!)\n";
    return 0;
}
