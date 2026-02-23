CXX = g++
FLAGS = -std=c++11 -Wall
target = cdx

$(target): build/$(target)

clean:
	rm -rf build/ 
    
run: $(target)
	./build/$(target)

build/$(target): src/main.cpp
	@mkdir -p $(@D)
	$(CXX) $(FLAGS) $< -o $@
	
