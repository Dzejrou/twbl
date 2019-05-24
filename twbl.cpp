#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char** argv)
{
    /**
     * Edit here with the proper path to your backlight.
	 * TODO: save these strings in a file maybe?
     */
    std::string fname{"/sys/devices/pci0000:00/0000:00:02.0/drm/card0/card0-eDP-1/intel_backlight/brightness"};
	std::string max_fname{"/sys/devices/pci0000:00/0000:00:02.0/drm/card0/card0-eDP-1/intel_backlight/max_brightness"};

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " {,+,-}N\n\n";
        return 1;
    }

    std::istringstream read_val{argv[1]};
    int val{};

    if (!(read_val >> val))
    {
        std::cerr << "Argument " << argv[1] << " is not a valid number.\n";
        return 1;
    }

    std::ifstream read_current{fname};
    int current_value{};

    if (!(read_current >> current_value))
    {
        std::cerr << "Could not read current brightness value.\n";
        return 1;
    }

    read_current.close();

	std::ifstream read_max{max_fname};
	int max_value{};
	
	if (!(read_max >> max_value))
	{
		std::cerr << "Could not read max brightness value.\n";
		return 1;
	}

	read_max.close();

	if ((current_value + val) > max_value)
	{
		std::cerr << "Invalid input value: " << val << " is greater than max value " << max_value;
		return 1;
	}

    val += current_value;

    std::ofstream write_value{fname};

    if (!(write_value << std::to_string(val)))
    {
        std::cerr << "Could not write new brightness value.\n";
        return 1;
    }

    return 0;
}
