all:
	@mkdir -p build
	@g++ src/* test/LinkedListTest.cpp -o build/LinkedListTest

test-build:
	@./build/*

test: all test-build

.PHONY: all test-build test