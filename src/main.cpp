//  libraries
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include <iostream>
#include <filesystem>

//  subcommands
#include "cli/cdx.hpp"
#include "cli/list.hpp"
#include "cli/add.hpp"

int main(int argc, char **argv) {
    CLI::App app{ "cdx" };

    setup_cdx(app);
    auto list = setup_list(app);
    auto add = setup_add(app);

    add->excludes(list);
    // app.require_subcommand();
    CLI11_PARSE(app, argc, argv);
}
