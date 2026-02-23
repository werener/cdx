#include "cdx.hpp"

const std::unordered_set<std::string> COMMANDS = { "cdx", "add", "list", "rename", "remove", };
static bool IS_COMMAND(std::string s) { return COMMANDS.find(s) != COMMANDS.end(); }

void setup_cdx(CLI::App &app) {
    auto options = std::make_shared<CdxOptions>();

    app.add_option("alias", options->alias, "Alias of the directory you want to cd into"); // TOOD
    app.add_flag("--version, -v", options->version, "Show version");
    app.add_flag("--new-config", options->new_config, "Resets your cdx configuration");

    app.callback([&app, options]() { run_cdx(app, *options); });
}

void run_cdx(CLI::App& app, CdxOptions &options) {
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

    if (IS_COMMAND(options.alias))
        return;
    
    if (options.alias.empty()) {
        std::cout << app.help();
        return;
    }
    std::cout << "[CDX_PATH] /home/user/proj1 [/CDX_PATH]";
}