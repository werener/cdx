#include "list.hpp"

void setup_list(CLI::App &app) {
    auto *list = app.add_subcommand("list", "Lists all you aliases");
    list->add_flag("-f,--force", "No confirmation required");

    list->callback([]() { run_list(); });
}

void run_list() {
    std::cout << "All your aliases: " << '\n';
}