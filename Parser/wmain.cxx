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
std::wstring read_file(const char* const filename)
{
    std::wifstream file(filename);

    std::wstring str;
    std::getline(file, str, L'\0');

    file.close();
    return str;
}

int main(const size_t argc, const char* const argv[])
{
    if (argc == 1)
        return 0;

    const auto cxx = std::format("{}.cpp", argv[1]);
    (std::wofstream(cxx)
        << *parser(lexer(read_file(argv[1])).tokenize()).parse()
    ).close();

    system(std::format("\"\"./bin/g++\" -static -o DangProgram \"{0}\"\"", cxx).c_str());
}
