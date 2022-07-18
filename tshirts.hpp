#include<iostream>

#define SIZE_S_LIMIT 38
#define SIZE_M_LIMIT 42

enum SIZE
{ S,M,L};

struct sizeMap
{
    int length;
    SIZE size;
    
};

void mapLengthToSizeName(int cms, sizeMap* item);
void test_tshirtsImplementation(void);
