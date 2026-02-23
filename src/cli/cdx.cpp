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
            config_file << BASE_CONFIG.dump(4);
            std::cout << "Configuration file succesfully created!" << std::endl;
        }
        else {
            std::cerr << "Unable to open file: " << CONFIG_PATH << std::endl;
        }
        return;
    }

    std::string alias = options.alias; 
    if (alias.empty() && app.get_subcommands().empty()) {
        std::cout << app.help();
        return;
    }
    if (alias.empty() && !app.get_subcommands().empty())
        return;
    if (!validate_config())
        return;

    json config = get_config();
    if (options.version)
        std::cout << config["version"].get<std::string>() << std::endl;
    
    if (IS_COMMAND(alias)) {
        std::cerr << "Can't use command names as aliases" << std::endl;
        return;
    }


    json associations = config["associations"].get<json>();
    if (!associations.contains(alias)) {
        std::cerr << "Alias " << std::quoted(alias, '\'') << " isn't associated with any directory" << std::endl;
        return;
    }

    std::cout << "[CDX_PATH]" << associations[alias] << "[/CDX_PATH]";
}