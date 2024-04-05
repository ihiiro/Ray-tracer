GLOBAL_HEADER = include/rt.h
TARGET_CHECKER_SOURCES = tests/tuple.c
TARGET_RT_SOURCES = src/make_tuple.c
ALL_SOURCES = $(TARGET_CHECKER_SOURCES) $(TARGET_RT_SOURCES)
TARGET_CHECKER = checker
CFLAGS = -Wall -Wextra -Werror

all:
	@echo "no rule."

$(TARGET_CHECKER): $(ALL_SOURCES) $(GLOBAL_HEADER) Makefile
	cc $(CFLAGS) $(ALL_SOURCES) -o $@

clean:
	rm -f $(TARGET_CHECKER)

check: $(TARGET_CHECKER)

.PHONY: clean