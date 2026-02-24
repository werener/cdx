VERSION = alpha 0.1.0
CONFIG_PATH = /mnt/c/Users/werener/Desktop/gitfolder/cdx/release/.cdx_config.json

cxx = g++
flags = -std=c++17 -Wall -DVERSION='"$(VERSION)"' -DCONFIG_PATH='"$(CONFIG_PATH)"'
target = cdx
target_dir = release

all: main config

main: $(target_dir)/$(target) 

config: 
	@> $(target_dir)/.cdx_config.json
	@echo "{\"version\": \"$(VERSION)\"}" >> $(target_dir)/.cdx_config.json
	
$(target_dir)/$(target): build/main.o build/cdx.o build/list.o build/add.o 
	@mkdir -p $(@D)
	$(cxx) $(flags) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(cxx) $(flags) -I src -c $< -o $@

build/%.o: src/cli/%.cpp src/cli/%.hpp src/utils.hpp src/defines.hpp
	@mkdir -p $(@D)
	@$(cxx) $(flags) -I src -c $< -o $@

clean:
	rm -rf build/
	rm -rf $(target_dir)/$(target)
    
run: $(target_dir)/$(target) 
	@./$(target_dir)/$(target) $(args)

.PHONY: all run clean
