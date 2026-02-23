#include "cdx.hpp"
#include "../utils.hpp"


void setup_cdx(CLI::App &app) {
    auto options = std::make_shared<CdxOptions>();
    
    app.add_option("alias", options->alias, "Alias of the directory you want to cd into"); // TOOD
    app.add_flag("--version, -v", options->version, "Show version");

    app.callback([options]() { run_cdx(*options); });
}

void run_cdx(CdxOptions &options) {
    if (options.version)
        std::cout << "v0.1.0\n";
    if (options.alias.empty() || IS_COMMAND(options.alias))
        return;
    std::cout << "You cd'ed into " << options.alias << std::endl;
}