#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"

#ifndef CONFIG_PATH
#define CONFIG_PATH "./release/.cdx_config.json"
#endif 

#ifndef VERSION
#define VERSION "unknown"
#endif 

#define ERROR_MESSAGE(content) std::cerr << content << std::endl;return