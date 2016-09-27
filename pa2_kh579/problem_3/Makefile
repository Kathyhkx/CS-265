PROGRAM = csv++ csv_c Csv
CFLAGS = -g -Wall
CXXFLAGS = $(CFLAGS)

all: $(PROGRAM)
csv++: CXXFLAGS += -Wno-sign-compare
csv++: csv++.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
csv_c%.o: csv_c%.c csv.h
Csv: Csv.java
clean:
	rm -f *.o *.class $(PROGRAM)

