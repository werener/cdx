#include "add.hpp"

CLI::App* setup_add(CLI::App &app) {
    auto options = std::make_shared<AddOptions>();
    auto *add = app.add_subcommand("add", "Adds an alias")->excludes(list);

    add->add_flag("-f,--force", options->force, "No confirmation required");
    add->add_option("-g,--generate", options->generate, "Generate bash function that substitutes for using cdx");

    add->add_option("alias", options->alias, "Alias of your directory")->required();
    add->add_option("path", options->alias, "Path to your directory");

    add->callback([&app, options]() {
        run_add(*options);
        // if (app.get_subcommands().empty()) {
        //     run_add(*options);
        // }
    });
}

void run_add(AddOptions &options) {
    if (options.force)
        std::cout << "add with --force\n";
    else
        std::cout << "add\n";

    std::cout << "alias:" << options.alias << "\n";
    std::cout << "path:" << options.path << "\n";
    std::cout << "generate stuff:" << options.generate << "\n";
}