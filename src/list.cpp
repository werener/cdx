#include "list.hpp"

void setup_list(CLI::App &app) {
    auto *list = app.add_subcommand("list", "performs subcommand a");

    list->callback([]() { run_list(); });
}

void run_list() {
    std::cout << "All your aliases: " << '\n';
}