
.SUFFIXES: .cxx .o .x .hxx
NAME1 = setSimple
NAME2 = setLinked
NAME3 = generator
NAME4 = tester
NAME5 = setSimpleBool
NAME6 = dictionarySimple

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx
CXX5 = $(NAME5).cxx
CXX6 = $(NAME6).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x
EXEC6 = $(NAME6).x

CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5) $(EXEC6)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS) 

$(EXEC4): 
	$(CO) -o $@ $(CXX4) $(FLAGS)

$(EXEC5): 
	$(CO) -o $@ $(CXX5) $(FLAGS)

$(EXEC6): 
	$(CO) -o $@ $(CXX6) $(FLAGS)



##dictionarySimple##
testBool: $(EXEC5) 

.PHONY: dictionarySimple
dictionarySimple: testBool
	@echo "\n*dictionarySimple*\n"
	@./$(EXEC5) 



##setSimpleBool##
testSetBool: $(EXEC6) 

.PHONY: setSimpleBool
setSimpleBool: testSetBool
	@echo "\n*setSimpleBool*\n"
	@./$(EXEC6) 

##setSimple##
testA: $(EXEC1) 

.PHONY: setSimple
setSimple: testA
	@echo "\n*ZADANIE A*\n"
	@./$(EXEC1) 

##setLinkede##
testB: $(EXEC2)

.PHONY: setLinkede
setLinkede: testB
	@echo "\n*ZADANIE B*\n"
	@./$(EXEC2) 

##setSimple vs setLinkede##
testAB: $(EXEC3) $(EXEC4)
compare: testAB
	@echo "\n*setSimple vs setLinkede*\n"
	@./$(EXEC3) 10000 10000 | ./$(EXEC4)



.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt graphs.pdf *.dat core core* a.out; rm -rf ${LIB_DIR}