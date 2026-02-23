#include "cdx.hpp"

const std::unordered_set<std::string> COMMANDS = { "cdx", "add", "list", "rename", "remove", };
static bool IS_COMMAND(std::string s) { return COMMANDS.find(s) != COMMANDS.end(); }

void setup_cdx(CLI::App &app) {
    auto options = std::make_shared<CdxOptions>();

    app.add_option("alias", options->alias, "Alias of the directory you want to cd into"); // TOOD
    app.add_flag("--version, -v", options->version, "Show version");

    app.callback([options]() { run_cdx(*options); });
}

void run_cdx(CdxOptions &options) {
    if (options.version) {
        // std::ifstream config(".cdx_config.json");
        // if (config.is_open()) {
        //     std::cout << cofig;
        //     file.close();
        //     cout << "File created: " << filepath << endl;
        // }       
    }
        
    if (options.alias.empty() || IS_COMMAND(options.alias))
        return;
    std::cout << "You cd'ed into " << options.alias << std::endl;
}