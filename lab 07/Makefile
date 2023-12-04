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
	doxygen
all: clean prep compile run
check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump 
