#include <iostream>
#include <cstring> // 使用strcmp进行字符串比较

int main(int argc, char *argv[]) {
    // 检查是否有任何参数传递
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [options]" << std::endl;
        std::cerr << "Options:" << std::endl;
        std::cerr << "  -h, --help       Show this help message" << std::endl;
        std::cerr << "  -v, --version    Show version information" << std::endl;
        return 1;
    }

    // 解析命令行选项
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -h, --help       Show this help message" << std::endl;
            std::cout << "  -v, --version    Show version information" << std::endl;
            return 0;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            std::cout << argv[0] << " version 1.0" << std::endl;
            return 0;
        } else {
            std::cerr << "Unknown option: " << argv[i] << std::endl;
            return 1;
        }
    }

    return 0;
}

