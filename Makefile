cxx = g++
Flags = -std=c++11 -Wall
target = cdx

all: main
	@rm -rf build/*.o

main: $(target)

$(target): build/$(target)

build/$(target): build/main.o build/cdx.o  build/list.o build/add.o
	@mkdir -p $(@D)
	$(cxx) $(Flags) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(cxx) $(Flags) -I src -c $< -o $@

build/%.o: src/cli/%.cpp src/cli/%.hpp
	@mkdir -p $(@D)
	$(cxx) $(Flags) -I src -c $< -o $@

clean:
	rm -rf build/ 
    
run: $(target)
	@./build/$(target) $(args)

.PHONY: all run clean
