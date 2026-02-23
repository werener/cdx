cxx = g++
Flags = -std=c++11 -Wall
target = cdx

all: main

main: cdx

clean:
	rm -rf build/ 
    
run: $(target)
	@./build/$(target) $(args)

.PHONY: all run clean

$(target): build/$(target)

build/$(target): src/main.cpp
	@mkdir -p $(@D)
	$(cxx) $(Flags) $< -o $@
	
