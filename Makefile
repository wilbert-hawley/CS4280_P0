FINAL = P0
CXX = g++
CXXFLAGS = -Wall
MAIN_CPP = main.cpp
OBJS = main.o tree.o fileOp.o stringOp.o fileOp.o
DEPS = tree.h node.h fileOp.h stringOp.h fileOp.h

%.o: %.c $(MAIN_CPP) $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(FINAL): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	/bin/rm -f $(FINAL) *.o *.txt *.inorder *.preorder *.postorder
