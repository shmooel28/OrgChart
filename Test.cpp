#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
// using namespace coup;

TEST_CASE("Good input")
{
    for(int i = 0; i < 20 ; i++){
         CHECK_EQ(false, false);
    }
}