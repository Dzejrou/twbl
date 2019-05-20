#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char** argv)
{
    /**
     * Edit here with the proper path to your backlight.
     */
    std::string fname{"/sys/devices/pci0000:00/0000:00:02.0/drm/card0/card0-eDP-1/intel_backlight/brightness"};

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " {,+,-}N\n";
        return 1;
    }

    std::istringstream iss{argv[1]};
    int val{};

    if (!(iss >> val))
    {
        std::cerr << "Argument " << argv[1] << " is not a valid number.\n";
        return 1;
    }

    std::ifstream ifs{fname};

    int curr{};
    if (!(ifs >> curr))
    {
        std::cerr << "Could not read current brightness value.\n";
        return 1;
    }
    ifs.close();

    val += curr;
    std::ofstream ofs{fname};
    if (!(ofs << std::to_string(val)))
    {
        std::cerr << "Could not write new brightness value.\n";
        return 1;
    }

    return 0;
}
