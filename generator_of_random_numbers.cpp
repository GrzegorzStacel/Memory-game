#include "generator_of_random_numbers.h"
#include <ctime>
#include <cstdlib>

int Generator_of_random_numbers::RandomNumbers[52];

Generator_of_random_numbers::Generator_of_random_numbers(){

}

void Generator_of_random_numbers::GenerateNumber(int difficultLvl){

    srand(time ( nullptr ));

    int selectedAtRandom = 0;
    int number;

    do
       {
           number = rand() % difficultLvl;
           if( IfItWasDrawn( number, selectedAtRandom ) == false ){
               RandomNumbers[ selectedAtRandom ] = number;
               selectedAtRandom++;
           }

    } while( selectedAtRandom < difficultLvl );
}




bool Generator_of_random_numbers::IfItWasDrawn( int iNumber, int selectedAtRandom ){

    if( selectedAtRandom <= 0 )
         return false;

    for(int i = 0; i < selectedAtRandom; i++){
        if( RandomNumbers[i] == iNumber)
            return true;
    }

    return false;
}
