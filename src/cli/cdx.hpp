#pragma once
#include <CLI/CLI.hpp>
#include "../utils.hpp"

struct CdxOptions {
    std::string alias;
};

CLI::App* setup_cdx(CLI::App &app);
void run_cdx(CdxOptions &options);
