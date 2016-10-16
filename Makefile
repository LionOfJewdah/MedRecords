CXX 			= g++
STD				= -std=c++14
CPPFLAGS 	= -g -Wall
OBJ_DIR		= obj
BIN_DIR 	= bin

Project: test.cpp Patient.cpp Person.hpp Doctor.cpp HealthCareProvider.hpp InsuranceProvider.cpp EMT.cpp Oncologist.cpp Nurse.cpp Surgeon.cpp TypesOfRecord.hpp PhysicianAssistant.cpp
	$(CXX) $(CPPFLAGS) $(STD) $^ -o $(BIN_DIR)/$@.out

Person: Person.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

Institution: Institution.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o


Records: Record.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

HealthCareProvider: HealthCareProvider.hpp Institution.hpp Person.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

$(OBJ_DIR)/.dirstamp:
		-@mkdir -p $(OBJ_DIR)
		-@touch $@
