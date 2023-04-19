/**
 * ANSI utilities styles unsetters.
 * @details @n The named module partition @code set @endcode for the module @code ansi.styles @endcode exports implementations
 * in namespace @code ansi::styles @endcode for unsetting text styles.
 * @author danixdev1205
 */
export module ansi.styles:unset;


import std;


export
/**
 * Unsetting styles.
 * @author danixdev1205
 */
namespace ansi::unset
{
    /**
     * Makes text normal intensity.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[22m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& bold(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('2'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text not <b>dim</b>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[22m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& dim(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('2'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text not <i>italic</i>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[23m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& italic(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('3'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text un<u>underline</u>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[24m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& underline(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('4'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text stop blinking.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[25m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& blink(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('5'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text invert back.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[27m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& invert(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('7'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text visible.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[28m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& hide(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('8'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text not <s>strikethrough</s>.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[29m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& strike(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('2'));
        os.put(os.widen('9'));
        os.put(os.widen('m'));

        return os;
    }

    /**
     * Makes text not overline.
     * @tparam Elem Output stream element.
     * @tparam Traits Output stream element traits.
     * @param os Output stream.
     * @return @code ESC[55m @endcode
     */
    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>& overline(std::basic_ostream<Elem, Traits>& os)
    {
        os.put(os.widen('\x1b'));
        os.put(os.widen('['));
        os.put(os.widen('5'));
        os.put(os.widen('5'));
        os.put(os.widen('m'));

        return os;
    }
}