#pragma once
#include <CLI/CLI.hpp>

struct CdxOptions {
    std::string alias;
    bool version;
};

void setup_cdx(CLI::App &app);
void run_cdx(CdxOptions &options);
