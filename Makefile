VERSION = "alpha 0.1.0"
cxx = g++
flags = -std=c++11 -Wall
target = cdx
target_dir = release

all: main config

main: $(target_dir)/$(target)

config: 
	@> $(target_dir)/.cdx_config.json
	@echo "{\n\t\"version\": \"$(VERSION)\"\n}" >> $(target_dir)/.cdx_config.json
	
$(target_dir)/$(target): build/main.o build/cdx.o  build/list.o build/add.o 
	@mkdir -p $(@D)
	
	$(cxx) $(flags) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(cxx) $(flags) -I src -c $< -o $@

build/%.o: src/cli/%.cpp src/cli/%.hpp
	@mkdir -p $(@D)
	$(cxx) $(flags) -I src -c $< -o $@

clean:
	rm -rf build/
	rm -rf $(target_dir)/$(target)
    
run: $(target)
	@./$(target_dir)/$(target) $(args)

.PHONY: all run clean
