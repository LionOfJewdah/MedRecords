//
//  Analyst.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Analyst_hpp
#define Analyst_hpp

#include "Person.hpp"

enum class whatTheAnalystCanSee {
    NOTHING = 0, ALLERGY = 1, PRESCRIPTION = 2, AP = 3, SURGERY = 4, AS = 5, PS = 6, APS = 7, DISEASE = 8, AD = 9, PD = 10, APD = 11, SD = 12, ASD = 13, PSD = 14, APSD = 15;
} // yay binary

class Analyst : public Person {
private:

public:
    Analyst();
    ~Analyst();
    bool
protected:

};


#endif /* Analyst_hpp */
