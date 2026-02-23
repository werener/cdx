#include "list.hpp"

CLI::App* setup_list(CLI::App &app) {
    auto options = std::make_shared<ListOptions>();
    auto *list = app.add_subcommand("list", "Lists all your aliases");

    list->add_flag("-f,--force", options->force, "No confirmation required");
    list->callback([options]() { run_list(*options); });
    return list;
}

void run_list(ListOptions &options) {
    if (options.force)
        std::cout << "list with --force\n";
    else
        std::cout << "list\n";
}