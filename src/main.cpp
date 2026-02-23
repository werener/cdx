#include <iostream>
#include <filesystem>
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "cli/list.hpp"
#include "cli/cdx.hpp"

int main(int argc, char **argv) {
    CLI::App app{"cdx"};

    setup_list(app);
    setup_cdx(app);
    // app.require_subcommand();
    CLI11_PARSE(app, argc, argv);
}
