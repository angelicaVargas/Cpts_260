CFLAGS = -g -c -Isrc -Wall -fprofile-arcs -ftest-coverage --coverage
LDFLAGS = -g --coverage

LIIBGATES = lib/libgates.a

LIB_SRCS = $(wildcard src/*.c)
TEST_SRCS = $(wildcard test/*.c)
LIB_OBJS = $(subst .c,.o,$(LIB_SRCS))
TEST_OBJS = $(subst .c,.o,$(TEST_SRCS))
STAMPS = $(subst .c,.stamp,$(TEST_SRCS))
TESTS = $(subst .c,,$(TEST_SRCS))
TEST_CHKS_OUT = $(subst .c,.out,$(TEST_SRCS))
TEST_CHKS_LOG = $(subst .c,.log,$(TEST_SRCS))

all: $(TESTS)

$(LIIBGATES): $(LIB_OBJS)
	$(AR) rc $(LIIBGATES) $^

%.stamp: %.o $(LIIBGATES)
	$(CC) $(LDFLAGS) -o $(subst .stamp,,$@) $^
	chmod +x $(subst .stamp,,$@)
	touch $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTS): $(STAMPS)

clean:
	rm -f $(STAMPS) $(LIIBGATES) $(LIB_OBJS) $(TEST_OBJS) $(TESTS) $(TEST_CHKS_LOG) $(TEST_CHKS_OUT) $(subst .c,.gcda, $(LIB_SRCS) $(TEST_SRCS)) $(subst .c,.gcno, $(LIB_SRCS) $(TEST_SRCS))

check: $(TEST_CHKS_OUT)

$(TEST_CHKS_OUT): $(TESTS)

%.out: %.stamp
	./test-driver --test-name $(subst .stamp,,$<) --log-file $(subst .stamp,,$<).log --trs-file $@ $(subst .stamp,,$<)

gcov: $(TEST_CHKS_OUT)
	gcov -t $(LIB_SRCS)

.PHONY: clean check $(TESTS) gcov
