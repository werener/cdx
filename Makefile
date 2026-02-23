cxx = g++
Flags = -std=c++11 -Wall
target = cdx

all: main
	rm -rf build/*.o

main: $(target)

$(target): build/$(target)

build/$(target): build/main.o build/list.o
	@mkdir -p $(@D)
	$(cxx) $(Flags) $^ -o $@

build/main.o: src/main.cpp src/cli/list.hpp
	@mkdir -p $(@D)
	$(cxx) $(Flags) -c $< -o $@

build/list.o: src/cli/list.cpp src/cli/list.hpp
	@mkdir -p $(@D)
	$(cxx) $(Flags) -c $< -o $@

clean:
	rm -rf build/ 
    
run: $(target)
	@./build/$(target) $(args)

.PHONY: all run clean
