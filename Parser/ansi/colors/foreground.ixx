/**
 * ANSI utilities foreground colors setters.
 * @details @n The named module partition @code foreground @endcode for the module @code ansi.colors @endcode
 * exports implementations in namespace @code ansi::colors @endcode for setting colors.
 * @author danixdev1205
 */
export module ansi.colors:foreground;


import std;


export
/**
 * Foreground colors.
 * @author danixdev1205
 */
namespace ansi::fg
{
    /**
     * Bright foreground colors.
     * @author danixdev1205
     */
    namespace bright
    {
        /**
         * Sets foreground color to bright black.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[90m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& black(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('0'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright red.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[91m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& red(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('1'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright green.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[92m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& green(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('2'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright yellow.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[93m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& yellow(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('3'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright blue.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[94m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& blue(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('4'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright magenta.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[95m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& magenta(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('5'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright cyan.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[96m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& cyan(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('6'));
            os.put(os.widen('m'));

            return os;
        }

        /**
         * Sets foreground color to bright white.
         * @tparam Elem Output stream element.
         * @tparam Traits Output stream element traits.
         * @param os Output stream.
         * @return @code ESC[97m @endcode
         */
        template <class Elem, class Traits>
        std::basic_ostream<Elem, Traits>& white(std::basic_ostream<Elem, Traits>& os)
        {
            os.put(os.widen('\x1b'));
            os.put(os.widen('['));
            os.put(os.widen('9'));
            os.put(os.widen('7'));
            os.put(os.widen('m'));

            return os;
        }
    }


    /**
     * Sets foreground color to black.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[30m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& black(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('0'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to red.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[31m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& red(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('1'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to green.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[32m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& green(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('2'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to yellow.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[33m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& yellow(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('3'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to blue.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[34m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& blue(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('4'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to magenta.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[35m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& magenta(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('5'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to cyan.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[36m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& cyan(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('6'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to white.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[37m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& white(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('7'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color to regular.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[39m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& regular(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('9'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Sets foreground color.\n
     * 0 - 7        standard colors.\n
     * 8 - 15       high intensity colors.\n
     * 16 - 231     216 color cube.\n
     * 232 - 255    grayscale colors.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @param code Color code.
     * @return @code ESC[38;5;<code>m @endcode
     */
    template <class Elem, class Traits>
    constexpr char set(std::basic_ostream<Elem, Traits>& os, const uint8_t code)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('8'));
        os.put(os.widen(';'));
        os.put(os.widen('5'));
        os.put(os.widen(';'));

        if (code < 10)
            os.put(os.widen(code + '0'));
        else if (code < 100)
        {
            os.put(os.widen((code / 10) + '0'));
            os.put(os.widen((code % 10) + '0'));
        }
        else
        {
            os.put(os.widen((code / 100) + '0'));
            os.put(os.widen((code / 10 % 10) + '0'));
            os.put(os.widen((code % 10) + '0'));
        }

        os.put(os.widen('m'));

        return '\0';
    }

    /**
     * Sets foreground color via RGB values.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @param red Red channel.
     * @param green Green channel.
     * @param blue Blue channel.
     * @return @code ESC[38;2;<red>;<green>;<blue>m @endcode
     */
    template <class Elem, class Traits>
    constexpr char rgb(std::basic_ostream<Elem, Traits>& os, const uint8_t red, const uint8_t green, const uint8_t blue)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('8'));
        os.put(os.widen(';'));
        os.put(os.widen('2'));
        os.put(os.widen(';'));

        if (red < 10)
            os.put(os.widen(red + '0'));
        else if (red < 100)
        {
            os.put(os.widen((red / 10) + '0'));
            os.put(os.widen((red % 10) + '0'));
        }
        else
        {
            os.put(os.widen((red / 100) + '0'));
            os.put(os.widen((red / 10 % 10) + '0'));
            os.put(os.widen((red % 10) + '0'));
        }
        os.put(os.widen(';'));

        if (green < 10)
            os.put(os.widen(green + '0'));
        else if (green < 100)
        {
            os.put(os.widen((green / 10) + '0'));
            os.put(os.widen((green % 10) + '0'));
        }
        else
        {
            os.put(os.widen((green / 100) + '0'));
            os.put(os.widen((green / 10 % 10) + '0'));
            os.put(os.widen((green % 10) + '0'));
        }
        os.put(os.widen(';'));

        if (blue < 10)
            os.put(os.widen(blue + '0'));
        else if (blue < 100)
        {
            os.put(os.widen((blue / 10) + '0'));
            os.put(os.widen((blue % 10) + '0'));
        }
        else
        {
            os.put(os.widen((blue / 100) + '0'));
            os.put(os.widen((blue / 10 % 10) + '0'));
            os.put(os.widen((blue % 10) + '0'));
        }

        os.put(os.widen('m'));

        return '\0';
    }
}
