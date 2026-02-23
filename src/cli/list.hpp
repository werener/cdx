#pragma once

#include <CLI/CLI.hpp>

struct ListOptions {
    bool force;
};


void setup_list(CLI::App &app);
void run_list(ListOptions &options);