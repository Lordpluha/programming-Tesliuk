# Compiler properties
CC = clang
CC_props = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla

# Scripts
clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin
main.bin: src/main.c
	$(CC) $(CC_props) $< -o ./dist/$@ -lm
run:
	./dist/main.bin
doxygen:
	doxygen Doxyfile
all: clean prep compile run
check:
	clang-format --verbose -dry-run --Werror src/* test/*
	cppcheck --enable=all --inconclusive --addon=cert \
	--error-exitcode=1 -v --suppress=unreadVariable:*/main.c \
	--suppress=knownConditionTrueFalse:*/main.c --suppress=missingIncludeSystem \
	--check-config --suppress=*:*/test.c --suppress=unmatchedSuppression:*/main.c .
	rm -rf src/*.dump test/*.dumpА 
