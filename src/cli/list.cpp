#include "list.hpp"

CLI::App* setup_list(CLI::App& app) {
    auto* list = app.add_subcommand("list", "Lists all your associations");
    list->callback([]() { run_list(); });
    return list;
}

void run_list() {
    if (!validate_config())
        return;

    json j = get_config();
    
    json associations = j["associations"].get<json>();
    for (auto& [alias, path] : associations.items()) {
        std::cout << RED << std::setw(j["max_alias_length"].get<int>()) << std::left << alias << RESET;
        std::cout << " | ";
        std::cout << GREEN << path << RESET << std::endl;
    }
}