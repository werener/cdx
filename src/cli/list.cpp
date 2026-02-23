#include "list.hpp"

CLI::App* setup_list(CLI::App& app) {
    auto* list = app.add_subcommand("list", "Lists all your aliases");
    list->callback([]() { run_list(); });
    return list;
}

void run_list() {
    if (!validate_config())
        return;

    json j;
    std::ifstream config_file(CONFIG_PATH);
    if (config_file.is_open())
        config_file >> j;
    else {
        std::cerr << "Unable to open file: " << CONFIG_PATH << std::endl;
        return;
    }
    auto aliases = j["aliases"].get<json>();
    for (auto& [alias, path] : aliases.items()) {
        std::cout << RED << std::setw(j["max_alias_length"].get<int>()) << std::left << alias << RESET;
        std::cout << " | ";
        std::cout << GREEN << path << RESET << std::endl;
    }
}