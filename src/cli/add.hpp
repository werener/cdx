#pragma once
#include <CLI/CLI.hpp>

struct AddOptions {
    std::string alias;
    std::string path;

    bool force;
    std::string generate;
};


CLI::App *setup_add(CLI::App &app);
void run_add(AddOptions &options);