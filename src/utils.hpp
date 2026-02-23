#pragma once

#include "defines.hpp"
#include "CLI/CLI.hpp"
#include "json.hpp"

using json = nlohmann::json;

// #include <iostream>
#include <filesystem>
#include <unordered_set>
#include <fstream>

#ifdef _WIN32
#include <direct.h>
#define chdir _chdir
#else
#include <unistd.h>
#endif


static json BASE_CONFIG =
{
    {"version", VERSION},
    {"max_alias_length", 0},
    {"associations", {}}
};

static bool validate_config(std::string cfg_path = CONFIG_PATH) {
    //  config file exists
    std::ifstream cfg_file(cfg_path);
    if (!cfg_file.is_open()) {
        std::cerr << "Configuration file " << cfg_path << " doesn't exist" << std::endl;
        cfg_file.close();
        return false;
    }

    //  config file can be parsed
    json j;
    try {
        cfg_file >> j;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing " << cfg_path << ": " << e.what() << std::endl;
        return false;
    }

    //  config file fits the schema
    bool is_valid = true;
    for (auto& [key, value] : BASE_CONFIG.items()) {
        if (!j.contains(key)) {
            std::cerr << "Configuration file " << cfg_path << " has to contain " << std::quoted(key, '\'') << " field" << std::endl;
            is_valid = false;
        }
    }

    return is_valid;
}