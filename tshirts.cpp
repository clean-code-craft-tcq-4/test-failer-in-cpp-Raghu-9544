#include <iostream>
#include <assert.h>
#include "tshirts.hpp"

void mapLengthToSizeName(int cms, sizeMap* tshirt_item) {
    tshirt_item->length = cms;
    if(cms <= SIZE_S_LIMIT) {
        tshirt_item->size = S;
    } 
    else if(cms > SIZE_S_LIMIT && cms <= SIZE_M_LIMIT) {
        tshirt_item->size = SIZE::M;   
    } 
    else if(cms > SIZE_M_LIMIT) {
        tshirt_item->size = L;
    }
}

void test_tshirtsImplementation(void)
{   
    struct sizeMap tshirt_item;
    sizeMap* commodity = &tshirt_item;

    mapLengthToSizeName(37,commodity);
    assert(commodity->size == SIZE::S);
    std::cout<<"Length = " <<commodity->length << "    Size = " <<commodity->size <<std::endl;
	mapLengthToSizeName(38,commodity);
    assert(commodity->size == SIZE::S);
    std::cout<<"Length = " <<commodity->length << "    Size = " <<commodity->size <<std::endl;
    mapLengthToSizeName(40,commodity);
    assert(commodity->size == SIZE::M);
    std::cout<<"Length = " <<commodity->length << "    Size = " <<commodity->size <<std::endl;
	mapLengthToSizeName(42,commodity);
    assert(commodity->size == SIZE::M);
    std::cout<<"Length = " <<commodity->length << "    Size = " <<commodity->size <<std::endl;
    mapLengthToSizeName(43,commodity);
    assert(commodity->size == SIZE::L);
    std::cout<<"Length = " <<commodity->length << "    Size = " <<commodity->size <<std::endl;
    mapLengthToSizeName(50,commodity);
    assert(commodity->size == SIZE::L);
    std::cout<<"Length = " <<commodity->length << "    Size = " <<commodity->size <<std::endl;
}

int main() {
    std::cout<<"calling test"<<std::endl;
    test_tshirtsImplementation();
    std::cout << "All is well (DEFINETLY!)\n";
    return 0;
}
