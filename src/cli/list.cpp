#include "list.hpp"

CLI::App *setup_list(CLI::App &app) {
    auto *list = app.add_subcommand("list", "Lists all your aliases");
    list->callback([]() { run_list(); });
    return list;
}

void run_list() {
    std::cout << "list\n";
}