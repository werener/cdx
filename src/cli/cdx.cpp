#include "cdx.hpp"

const std::unordered_set<std::string> COMMANDS = { "cdx", "add", "list", "rename", "remove", };
static bool IS_COMMAND(std::string s) { return COMMANDS.find(s) != COMMANDS.end(); }

void setup_cdx(CLI::App &app) {
    auto options = std::make_shared<CdxOptions>();

    auto cdx = app.add_subcommand("cdx", "");
    cdx->group("");

    cdx->add_option("alias", options->alias, "Alias of the directory you want to cd into"); // TOOD
    cdx->add_flag("--version, -v", options->version, "Show version");
    cdx->add_flag("--new-config", options->new_config, "Resets your cdx configuration");

    cdx->callback([options]() { run_cdx(*options); });
}

void run_cdx(CdxOptions &options) {
    if (options.new_config) {
        std::ofstream config_file(CONFIG_PATH);
        if (config_file.is_open()) {
            config_file << BASE_CONFIG;
            std::cout << "Configuration file succesfully created!" << std::endl;
        }
        else {
            std::cerr << "Unable to open file: " << CONFIG_PATH << std::endl;
            return;
        }
    }
    
    if (!validate_config())
        return;
    
    if (options.version) {
        std::ifstream config_file(CONFIG_PATH);
        json j;
        config_file >> j;
        std::cout << j["version"].get<std::string>() << std::endl;
    }

    if (options.alias.empty() || IS_COMMAND(options.alias))
        return;
    
    chdir(options.alias.c_str());
    std::cout << "You cd'ed into " << options.alias << std::endl;
}