GCC=g++
INCLUDE=include

SRCDIR=src 
OBJDIR=obj
BINDIR=bin

BINARY=$(BINDIR)/test

_OBJ=TreeNode.o TSLTree.o Test.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(_OBJ))

all: $(BINARY)

$(OBJDIR)/%.o: src/%.cpp
	$(GCC) -c -o $@ -I$(INCLUDE) -std=c++17 $< 

${BINARY}: $(OBJ)
	$(GCC) -o $@ $^ 

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/*