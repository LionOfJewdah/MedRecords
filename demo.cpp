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
#include "Doctor.hpp"
//#include <cassert>
using boost::gregorian::from_undelimited_string;
//using boost::gregorian::local_day;
// using namespace boost::gregorian;

std::ostream& operator<< (std::ostream& o, const Institution& h) {
    o << h.typeOfInst() << ": " << h.getName();
    return o;
}

std::ostream& operator<< (std::ostream& o, const Patient& pt) {
    o << "Patient: " << pt.getName() << "\tID: " << pt.getID() << "\tLocation: ";
    if (!pt.whereAmIAt()) o << "not being treated";
    else o << (pt.whereAmIAt())->getName();
    o << "\tInsurance: ";
    if (!pt.amICovered()) o << "None";
    else o << (pt.whosCoveringMe())->getName();
    return o;
}

std::ostream& operator<< (std::ostream& o, const HealthCareProvider& hcp) {
    o << hcp.typeOfProvider() << ": " << hcp.getName() << "\tID: " << hcp.getID() << '\t' << (hcp.getInstitution())->typeOfInst() << ": " << (hcp.getInstitution())->getName() << std::endl;
    return o;
}

void listWhoCanTreatTheDude(const Patient& pt) {
     std::cout << pt.getName() << "\'s authorized health care providers:\n";
     for (const auto& HCPs : pt.whosMyDoctors()) {
         std::cout << '\t' << *HCPs;
     }
}

int main(int argc, char* argv[])
{
    Hospital Keck("USC Keck School of Medicine", 90210), UWMC("University of Washington Medical Center", 98080);
    Doctor Kevin("Kevin Wu", 420, &Keck), Meera("Meera Mistry", 350, &UWMC);
    InsuranceProvider Aetna("Aetna Medical Insurance", 666), blueX("BlueCross BlueShield", 888);
    Patient David ("D. Silv", 1337, sex::MALE, from_undelimited_string("19970912"), &Aetna);
    David.authorize(&Kevin);
    //assert (David.isAuthorized(&Kevin) == true);
    std::vector<Patient> patients;
    do {
        patients.emplace_back("Marcella Wemple", 1000, sex::FEMALE, from_undelimited_string("20070519"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Jackson Laseter", 1000, sex::MALE, from_undelimited_string("19960510"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Johnette Sabatino", 1000, sex::FEMALE, from_undelimited_string("19780405"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Emelia Mcgirt", 1000, sex::FEMALE, from_undelimited_string("19810624"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Rich Silvestri", 1000, sex::MALE, from_undelimited_string("20081202"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Marisa Roma", 1000, sex::FEMALE, from_undelimited_string("19860525"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Katherin Dossey", 1000, sex::FEMALE, from_undelimited_string("19890112"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Joleen Gillispie", 1000, sex::FEMALE, from_undelimited_string("19980809"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Benita Carollo", 1000, sex::FEMALE, from_undelimited_string("19910606"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Russ Nickell", 1000, sex::MALE, from_undelimited_string("19781225"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Setsuko Kendig", 1000, sex::MALE, from_undelimited_string("19890306"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Ilona Tannenbaum", 1000, sex::FEMALE, from_undelimited_string("20080925"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Kimi Rohman", 1000, sex::MALE, from_undelimited_string("19890429"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Sarai Schreffler", 1000, sex::FEMALE, from_undelimited_string("20090607"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Vada Hawes", 1000, sex::FEMALE, from_undelimited_string("20031019"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Bettie Riebel", 1000, sex::FEMALE, from_undelimited_string("19910531"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Hollie Vankirk", 1000, sex::FEMALE, from_undelimited_string("20010607"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Joellen Bugg", 1000, sex::FEMALE, from_undelimited_string("19940517"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Roseann Bittinger", 1000, sex::FEMALE, from_undelimited_string("19780527"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Darlene Hick", 1000, sex::FEMALE, from_undelimited_string("20140423"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Eloise Traver", 1000, sex::FEMALE, from_undelimited_string("19950725"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Dortha Labounty", 1000, sex::FEMALE, from_undelimited_string("19950430"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Lakendra Truelove", 1000, sex::FEMALE, from_undelimited_string("19850209"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Tonja Judah", 1000, sex::FEMALE, from_undelimited_string("19850413"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Melida Prosser", 1000, sex::FEMALE, from_undelimited_string("19950223"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Darren Garlitz", 1000, sex::MALE, from_undelimited_string("19780714"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Leatha Wand", 1000, sex::FEMALE, from_undelimited_string("19841210"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Lazaro Estepp", 1000, sex::MALE, from_undelimited_string("19910110"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Laine Roessler", 1000, sex::FEMALE, from_undelimited_string("19790920"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Lulu Samora", 1000, sex::FEMALE, from_undelimited_string("19930819"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Ashlie Burriss", 1000, sex::FEMALE, from_undelimited_string("20061130"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Rhea Hypolite", 1000, sex::FEMALE, from_undelimited_string("20100706"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Emilee Moyers", 1000, sex::FEMALE, from_undelimited_string("20091207"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Hannelore Stockwell", 1000, sex::FEMALE, from_undelimited_string("19791020"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Barry Austell", 1000, sex::MALE, from_undelimited_string("19971024"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Juli Bailon", 1000, sex::FEMALE, from_undelimited_string("19730925"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Millard Doubleday", 1000, sex::MALE, from_undelimited_string("19780825"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Nadia Dula", 1000, sex::FEMALE, from_undelimited_string("19970506"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Manda Calaway", 1000, sex::FEMALE, from_undelimited_string("20060702"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Demarcus Hoch", 1000, sex::MALE, from_undelimited_string("20050918"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Margart Kinser", 1000, sex::FEMALE, from_undelimited_string("20131103"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Arnita Holzinger", 1000, sex::FEMALE, from_undelimited_string("20010121"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Catrice Eddy", 1000, sex::FEMALE, from_undelimited_string("20110201"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Somer Reeve", 1000, sex::MALE, from_undelimited_string("19720306"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Amelia Otterson", 1000, sex::FEMALE, from_undelimited_string("19990905"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Edgardo Tawney", 1000, sex::MALE, from_undelimited_string("20080718"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Tajuana Redden", 1000, sex::FEMALE, from_undelimited_string("19860804"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Ciera Rothchild", 1000, sex::FEMALE, from_undelimited_string("19770522"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Hyman Byrnes", 1000, sex::MALE, from_undelimited_string("20001202"), &Aetna);
        (patients.back().pointToRecords())->setOwner(&patients.back());
        patients.emplace_back("Erich Chappel", 1000, sex::MALE, from_undelimited_string("19860122"), &blueX);
        (patients.back().pointToRecords())->setOwner(&patients.back());
    } while (false);

    for (unsigned i = 0; i < patients.size(); i++) {
        if (i % 2) patients[i].authorize(&Kevin);
        else patients[i].authorize(&Meera);
        if (i % 6 == 3) patients[i].authorize(&Meera);
    }
    std::cout << "David.isAuthorized(&Kevin) == " << std::boolalpha << David.isAuthorized(&Kevin) << "\n";
    std::cout << "All patients are: \n";
    for (const auto& dudes : patients) {
        std::cout << dudes << std::endl;
        listWhoCanTreatTheDude(dudes);
        std::cout << "*********************************" << std::endl;
    }

    return 0;
}
