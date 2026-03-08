#pragma once

#include "defines.hpp"
#include "CLI/CLI.hpp"
#include "json.hpp"

using json = nlohmann::json;

// #include <iostream>
#include <filesystem>
#include <unordered_set>
#include <fstream>
#include <format>

#ifdef _WIN32
#include <direct.h>
#define chdir _chdir
#else
#include <unistd.h>
#endif


static json BASE_CONFIG = {
    {"version", VERSION},
    {"max_alias_length", 0},
    {"associations", json::object()}
};

static json get_config() {
    json config;
    std::ifstream(CONFIG_PATH) >> config;
    return config;
}

static void write_config(const json& j) {
    std::ofstream config_file(CONFIG_PATH);
    if (config_file.is_open())
        config_file << j.dump(4);
    else {
        std::cerr << "Unable to open file: " << CONFIG_PATH << std::endl;
        return;
    }
}

static bool validate_config() {
    //  config file exists
    std::ifstream cfg_file(CONFIG_PATH);
    if (!cfg_file.is_open()) {
        std::cerr << "Configuration file " << CONFIG_PATH << " doesn't exist" << std::endl;
        cfg_file.close();
        return false;
    }

    //  config file can be parsed
    json config;
    try {
        cfg_file >> config;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing " << CONFIG_PATH << ": " << e.what() << std::endl;
        return false;
    }

    //  config file fits the schema
    for (auto& [key, value] : BASE_CONFIG.items()) {
        if (!config.contains(key)) {
            std::cerr << "Configuration file " << CONFIG_PATH << " has to contain "
                << std::quoted(key, '\'') << " field" << std::endl;

            config[key] = BASE_CONFIG[key];
            write_config(config);
            std::cout << "Added field " << std::quoted(key, '\'') << std::endl;
        }
    }

    //  max_alias_length has to be accurate
    std::size_t max_alias_length = 0;
    for (auto& [key, value] : config["associations"].items())
        max_alias_length = std::max(key.length(), max_alias_length);

    if (max_alias_length != config["max_alias_length"]) {
        std::cerr << "Configuration file " << CONFIG_PATH
            << " has a wrong max_alias_length: " << config["max_alias_length"]
            << ". Has to be " << max_alias_length << std::endl;

        config["max_alias_length"] = max_alias_length;
        write_config(config);
        std::cout << "Fixed max_alias_length to be " << max_alias_length << std::endl;
    }
    return true;
}