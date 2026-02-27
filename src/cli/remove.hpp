#pragma once
#include "../utils.hpp"

struct RemoveOptions {
    std::string alias;
};


CLI::App *setup_remove(CLI::App &app);
void run_remove(CLI::App& app, RemoveOptions &options);