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
    if (options.new_config) 
        write_config(BASE_CONFIG);
        
    if (!validate_config())
        return;
    json config = get_config();
    
    if (options.version) 
        std::cout << config["version"].get<std::string>() << std::endl;
    

    std::string alias = options.alias; 
    if (alias.empty()) {
        if(app.get_subcommands().empty() && (!options.version) && (!options.new_config))
            std::cout << app.help();
        return;
    }
    
    if (IS_COMMAND(alias)) 
        ERROR_MESSAGE("Can't use command names as aliases");
    
    json associations = config["associations"].get<json>();
    if (!associations.contains(alias)) 
        ERROR_MESSAGE(std::format("Alias '{}' isn't associated with any directory", alias));
    

    std::cout << "[CDX_PATH]" << associations[alias].get<std::string>() << "[/CDX_PATH]";
}