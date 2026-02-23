#pragma once
#include "../utils.hpp"

struct CdxOptions {
    std::string alias;
    bool version;
    bool new_config;
};

void setup_cdx(CLI::App &app);
void run_cdx(CdxOptions &options);
