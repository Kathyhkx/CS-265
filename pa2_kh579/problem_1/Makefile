PROGRAM = $(MARKOV++_VARIATIONS)
MARKOV++_VARIATIONS = \
	$(foreach queue,deque list vector array, \
		$(foreach list,list vector, \
			markov++-$(queue)-$(list)))
CFLAGS = -g -Wall
CXXFLAGS = $(CFLAGS)
all: $(PROGRAM)
markov++: CXXFLAGS += -Wno-sign-compare
$(MARKOV++_VARIATIONS): CXXFLAGS += -Wno-sign-compare
$(MARKOV++_VARIATIONS): markov++.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ \
		$(join -DQUEUE_TYPE_ -DLIST_TYPE_,\
		$(shell echo $@ | sed -e "s/^markov++-//" | tr a-z- "A-Z "))
clean:
	rm -f *.o *.class $(PROGRAM)

