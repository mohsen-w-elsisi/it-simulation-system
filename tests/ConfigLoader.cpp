#include "ConfigLoader.h"

int main()
{
    ConfigLoader loader("test_input.txt");
    AppConfig config = loader.load();
}