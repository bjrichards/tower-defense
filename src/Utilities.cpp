#include <Utilities.h>

std::string utilities::IntToString(int x)
{
    char tmp[10000];
    sprintf(tmp, "%i", x);
    return std::string(tmp);
}