#include "remove.hpp"

CLI::App* setup_remove(CLI::App& app) {
    auto options = std::make_shared<RemoveOptions>();
    auto* remove = app.add_subcommand("remove", "Removes an association by alias");

    remove->add_option("alias", options->alias, "Alias of the directory")->required();

    remove->callback([&app, options]() { run_remove(app, *options); });
    return remove;
}

void run_remove(CLI::App& app, RemoveOptions& options) {
    if (!validate_config())
        return;
    json config = get_config();

    std::string alias = options.alias;
    if (!config["associations"].contains(alias)) 
        ERROR_MESSAGE(std::format("No associations with {} in the configuration file", alias));
    
    std::string path = config["associations"][alias].get<std::string>();
    config["associations"].erase(alias);

    std::size_t max_alias_length = 0;
    for (auto& [key, value] : config["associations"].items())
        max_alias_length = std::max(key.length(), max_alias_length);
    config["max_alias_length"] = max_alias_length;
    write_config(config);
    
    std::cout << "Successfully removed: "
        << RED << alias << RESET << " | "
        << GREEN << path << RESET << std::endl;
}