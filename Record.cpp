#include "Record.hpp"

bool pRecordLess(const Record* lhs, const Record* rhs) {
    return (lhs->getDateIssued() < rhs->getDateIssued());
}

typedef std::vector<Record*>::iterator vRit;
// bool itRecordLess(const vRit lhs, const vRit rhs) {
//     //return ((*lhs)->getDateIssued() < (*rhs)->getDateIssued());
//     return (pRecordLess(*lhs, *rhs));
// }

void RecordList::addRecord(Record* record) {
   patientRecords.push_back(record);
   //std::sort(patientRecords);
   if (record->getDateIssued() != day_clock::local_day())
       sort(); // inefficient to sort every time; only need to on non-recent documents
}

void RecordList::sort() {
   std::sort(patientRecords.begin(), patientRecords.end(), &pRecordLess);
}

RecordList::~RecordList() {
    while (!patientRecords.empty()) {
        if (patientRecords.back() != nullptr) delete patientRecords.back();
        patientRecords.pop_back();
    } // dynamic memory management
}
