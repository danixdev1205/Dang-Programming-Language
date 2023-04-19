/**
 * ANSI utilities.
 * @details @n The named module @code ansi @endcode exports implementations in namespace @code ansi @endcode
 * for easy use of ANSI escape sequences.
 * @author danixdev1205
 */
export module ansi;


import std;


export
/**
 * ANSI escape sequences.
 */
namespace ansi
{
    /**
     * Resets all styles and colors.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[0m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& reset(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('0'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Resets all ANSI styles.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[0m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& res(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('0'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Resets all ANSI styles and finishes a line.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[0m\n @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& resl(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('0'));
        os.put(os.widen('m'));
        os.put(os.widen('\n'));
        os.flush();

        return os;
    }
}
