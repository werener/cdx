#include "add.hpp"

const std::unordered_set<std::string> COMMANDS = { "cdx", "add", "list", "rename", "remove", };
static bool IS_COMMAND(std::string s) { return COMMANDS.find(s) != COMMANDS.end(); }

const std::string get_absolute_path(std::string const path) {
    return std::filesystem::weakly_canonical(std::filesystem::absolute(path)).string();
}

CLI::App* setup_add(CLI::App& app) {
    auto options = std::make_shared<AddOptions>();
    auto* add = app.add_subcommand("add", "Adds an association");

    add->add_flag("-r,--relative", options->relative, "Adds a relative path to the config");
    // add->add_option("-g,--generate", options->generate, "Generate bash function that substitutes for using cdx");

    add->add_option("alias", options->alias, "Alias of your directory")->required();
    add->add_option("path", options->path, "Path to your directory (defaults to .)");

    add->callback([&app, options]() { run_add(app, *options); });
    return add;
}

void run_add(CLI::App& app, AddOptions& options) {
    if (IS_COMMAND(options.alias)) 
        ERROR_MESSAGE("Can't use command names as aliases");
    
    std::string alias = options.alias;

    if (!validate_config())
        return;
    json config = get_config();
    
    if (options.path == "")
        options.path = ".";
    std::string path;

    if (options.relative)
        path = options.path;
    else
        path = get_absolute_path(options.path);

    if (config["associations"].contains(alias)) 
       ERROR_MESSAGE("Trying to add an existing alias");
    
    if (!std::filesystem::is_directory(path)) 
        ERROR_MESSAGE(std::format("'{}' isn't a directory", path));
    
    if (!std::filesystem::exists(path)) 
        ERROR_MESSAGE(std::format("Directory '{}' doesn't exist", path));
    
    config["associations"][alias] = path;

    config["max_alias_length"] = std::max(config["max_alias_length"].get<size_t>(), alias.length());
    write_config(config);
    std::cout << "Successfully added: "
        << RED << alias << RESET << " | "
        << GREEN << path << RESET << std::endl;
}