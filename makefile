GCC=clang++
INCLUDE=include
DEPS=animal.hpp diet.hpp dog.hpp

SRCDIR=src 
OBJDIR=obj
BINDIR=bin

BINARY=$(BINDIR)/test

_OBJ=TreeNode.o Test.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(_OBJ))

all: $(BINARY)

$(OBJDIR)/%.o: src/%.cpp
	$(GCC) -c -o $@ -I$(INCLUDE) -std=c++17 $< 

${BINARY}: $(OBJ)
	$(GCC) -o $@ $^ 

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/*