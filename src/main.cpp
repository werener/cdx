#include "cli/cdx.hpp"
#include "cli/list.hpp"
#include "cli/add.hpp"
#include "cli/remove.hpp"

int main(int argc, char **argv) {
    CLI::App app{ "cdx" };

    setup_cdx(app);
    auto list = setup_list(app);
    auto add = setup_add(app);
    auto remove = setup_remove(app);

    add->excludes(list); add->excludes(remove);
    list->excludes(add); list->excludes(remove);
    remove->excludes(add); remove->excludes(list);
    
    CLI11_PARSE(app, argc, argv);

    return 0;
}
