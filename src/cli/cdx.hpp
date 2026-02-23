#pragma once
#include <CLI/CLI.hpp>

struct CdxOptions {
    std::string alias;
};

void setup_cdx(CLI::App &app);
void run_cdx(CdxOptions &options);
