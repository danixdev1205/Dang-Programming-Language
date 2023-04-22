import ansi.colors;
import dang;
import dang.parser;
import std;


using namespace ansi;
using namespace dang;
using namespace std;


/**
 * Reads wide character (UTF-8 with BOM) file.
 * @param filename Path to the file.
 * @return File wide character content.
 */
std::wstring read_file(const wchar_t* const filename)
{
    std::wifstream file(filename);

    std::wstring str;
    std::getline(file, str, L'\0');

    file.close();
    return str;
}


/**
 * Program wide character entry point.
 * @param argc Command line argument count.
 * @param argwv Command line arguments wide character values.
 * @return Program exit code.
 * @retval 0 Success.
 */
int wmain(const size_t argc, const wchar_t* const argwv[])
{
    _setmode(_fileno(__acrt_iob_func(0)), 0x10000);
    _setmode(_fileno(__acrt_iob_func(1)), 0x10000);
    _setmode(_fileno(__acrt_iob_func(2)), 0x10000);

    boolalpha(wcin);
    boolalpha(wcout);
    boolalpha(wcerr);
    boolalpha(wclog);

    if (argc == 1)
        return 0;

    if (argc == 2)
        (std::wofstream(std::format(L"{}.cxx", argwv[1]))
            << *parser(lexer(read_file(argwv[1])).tokenize()).parse()
        ).close();
    
    return 0;
}
