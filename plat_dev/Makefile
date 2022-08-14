NAME=mysl
CC=g++
CFLAGS=-g -Wno-format-security -Wno-write-strings -I$(IDIR)
LDFLAGS=-lncurses
SRC=src
OBJ=obj
IDIR=$(SRC)/include
SRCS=$(wildcard $(SRC)/*.cc)
OBJS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN=$(BINDIR)/$(NAME)

TEST_SRCS=$(filter-out src/main.cc, $(SRCS))
TEST_SUITE=unit_tests.cc
TEST_BIN=unit_tests

all: $(BIN)

$(BIN): $(BINDIR) $(OBJ) $(OBJS) $(IDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir $@

$(OBJ):
	mkdir $@

.PHONY: test
test: LDFLAGS+=-lcriterion
test:
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_SUITE) $(TEST_SRCS) $(LDFLAGS) 
	-./$(TEST_BIN)

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/* $(TEST_BIN)

