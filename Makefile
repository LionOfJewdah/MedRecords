CXX 			= g++
STD				= -std=c++14
CPPFLAGS 	= -g -Wall
OBJ_DIR		= obj

Person: Person.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

Institution: Institution.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

Patient: Patient.hpp Person.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

Records: Record.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

HealthCareProvider: HealthCareProvider.hpp Institution.hpp Person.hpp
		$(CXX) $(CPPFLAGS) $(STD) $< -c -o $(OBJ_DIR)/$@.o

$(OBJ_DIR)/.dirstamp:
		-@mkdir -p $(OBJ_DIR)
		-@touch $@
