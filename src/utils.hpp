#pragma once

#include "CLI/CLI.hpp"
#include "json.hpp"
using json = nlohmann::json;

// #include <iostream>
// #include <filesystem>
#include <unordered_set>
#include <fstream>

const std::string CONFIG_PATH = "./release/.cdx_config.json";


static bool validate_config(std::string cfg_path) {
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
    catch (const std::exception &e) {
        std::cerr << "Error parsing " << cfg_path << ": " << e.what() << std::endl;
        return false;
    }
    //  config file contains version
    if (!j.contains("version"))  {
        std::cerr << "Configuration file " << cfg_path << " has to contain 'version'" << std::endl;
        return false; 
    }
    return true;
}