#include "add.hpp"

CLI::App *setup_add(CLI::App &app) {
    auto options = std::make_shared<AddOptions>();
    auto *add = app.add_subcommand("add", "Adds an association");

    add->add_flag("-f,--force", options->force, "No confirmation required");
    add->add_option("-g,--generate", options->generate, "Generate bash function that substitutes for using cdx");

    add->add_option("alias", options->alias, "Alias of your directory")->required();
    add->add_option("path", options->path, "Path to your directory (defaults to .)");

    add->callback([&app, options]() { run_add(app, *options); });
    return add;
}

void run_add(CLI::App& app, AddOptions &options) {
    if (options.path == "")
        options.path = ".";

    /* main logic */
    if (!validate_config())
        return;

    if (options.generate != "") {

    }
    if (options.force)
        return;
    // std::cout << "Confirm your actions (Y/n): \n";
}