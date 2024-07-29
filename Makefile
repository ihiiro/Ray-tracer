GLOBAL_HEADER = include/rt.h

TARGET_CHECKER_SOURCES = tests/checks.c

TARGET_RT_SOURCES = src/make_tuple.c \
					src/math/general/general_math.c \
					src/math/tuple/tuple_math.c \
					src/math/vector/vector_math.c \
					src/math/color/color_math.c \
					src/color/color.c

TARGET_TICK_SOURCES = practice/tick.c

ALL_SOURCES = $(TARGET_CHECKER_SOURCES) $(TARGET_RT_SOURCES)

TARGET_CHECKER = checker

TARGET_TICK = tick

CFLAGS = -Wall -Wextra -Werror

all:
	@echo "no rule."

$(TARGET_CHECKER): $(ALL_SOURCES) $(GLOBAL_HEADER) Makefile
	cc $(CFLAGS) $(ALL_SOURCES) -o $@

$(TARGET_TICK): $(TARGET_RT_SOURCES) $(TARGET_TICK_SOURCES) Makefile include/rt.h
	cc  $(TARGET_RT_SOURCES) $(TARGET_TICK_SOURCES) -o $@

clean:
	rm -f $(TARGET_CHECKER)
	rm -f $(TARGET_TICK)

check: $(TARGET_CHECKER)

.PHONY: clean