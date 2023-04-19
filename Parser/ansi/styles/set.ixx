/**
 * ANSI utilities styles setters.
 * @details @n The named module partition @code set @endcode for the module @code ansi.styles @endcode exports implementations
 * in namespace @code ansi::styles @endcode for setting text styles.
 * @author danixdev1205
 */
export module ansi.styles:set;


import std;


export
/**
 * Setting styles.
 * @author danixdev1205
 */
namespace ansi::set
{
    /**
     * Makes text <b>bold</b>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[1m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& bold(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('1'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text <b>dim</b>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[2m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& dim(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text <i>italic</i>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[3m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& italic(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('3'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text <u>underline</u>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[4m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& underline(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('4'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text blink.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[5m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& blink(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('5'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text invert.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[7m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& invert(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('7'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text hidden.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[8m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& hide(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('8'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text <s>strikethrough</s>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[9m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& strike(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('9'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text <u>doubly underline</u>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[21m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& double_underline(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('1'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text overline.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[52m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& overline(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('5'));
        os.put(os.widen('3'));
        os.put(os.widen('m'));

        return os;
    }
}