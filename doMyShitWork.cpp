#include <iostream>
//#include "boost/date_time/gregorian/gregorian.hpp"
#include "Patient.hpp"
#include "TypesOfRecord.hpp"
#include "EMT.hpp"
#include "Oncologist.hpp"
#include "Surgeon.hpp"
#include "Hospital.hpp"
#include "PhysicianAssistant.hpp"
#include "InsuranceProvider.hpp"
//#include <cassert>
using boost::gregorian::from_undelimited_string;
//using boost::gregorian::local_day;
// using namespace boost::gregorian;

int main(int argc, char* argv[])
{
    Hospital Keck("USC Keck School of Medicine", 90210);
    Doctor Kevin("Kevin Wu", 420, &Keck);
    InsuranceProvider Aetna("Aetna Medical Insurance", 666);
    Patient David ("D. Silv", 1337, sex::MALE, from_undelimited_string("19970912"), &Aetna);
    David.authorize(&Kevin);
    //assert (David.isAuthorized(&Kevin) == true);

    std::cout << "David.isAuthorized(&Kevin) == " << std::boolalpha << David.isAuthorized(&Kevin) << "\n";

    return 0;
}
