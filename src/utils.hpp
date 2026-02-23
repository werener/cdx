#include <unordered_set>
#include <string>

const std::unordered_set<std::string> COMMANDS = { "cdx", "add", "list", "rename", "remove", };

const bool IS_COMMAND(std::string s) { return COMMANDS.find(s) != COMMANDS.end(); }