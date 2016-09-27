PROGRAM = csv++
CFLAGS = -g -Wall
CXXFLAGS = $(CFLAGS)

all: $(PROGRAM)
csv++: CXXFLAGS += -Wno-sign-compare
csv++: csv++.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
clean:
	rm -f *.o *.class $(PROGRAM)
