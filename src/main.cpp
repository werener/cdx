#include <iostream>
#include <filesystem>
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"


int main(int argc, char **argv) {
    CLI::App app{"cdx"};
    bool force{false};
    app.add_flag("-f,--force", force, "No confirmation")
        ->ignore_case();

    CLI::App* list = app.add_subcommand("list", "List all your aliases");
    
    std::string path;
    list->add_option("path", path, "Path to the dir");    

    CLI11_PARSE(app, argc, argv);
    std::cout << "Success!\n" 
        << "path: " << path << std::endl; 

    return 0;
}
