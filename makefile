CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= stack.h depot.h test_depot.h shortcut.h memcheck.h

TEST = test_depot
PROGRAM = depot_prg

TESTOBJECT = depot_test_driver.o
MAINOBJECT = depot_main_driver.o
OBJS = shortcut.o stack.o test_depot.o depot.o memcheck.o

DOXY            = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp stack.cpp.sample stack.cpp
	cp stack.h.sample stack.h
	cp depot.cpp.sample depot.cpp
	cp depot.h.sample depot.h

#sets project as assignment
setassignment:
	cp stack.cpp.assignment stack.cpp
	cp stack.h.assignment stack.h
	cp depot.cpp.assignment depot.cpp
	cp depot.h.assignment depot.h

# defines current state of project as sample solution
definesample:
	cp stack.cpp stack.cpp.sample
	cp stack.h stack.h.sample
	cp depot.cpp depot.cpp.sample
	cp depot.h depot.h.sample

# defines current sate of project as assignment
defineassignment:
	cp stack.cpp stack.cpp.assignment
	cp stack.h stack.h.assignment
	cp depot.cpp depot.cpp.assignment
	cp depot.h depot.h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setsample
	make doxy
	make setassignment
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
