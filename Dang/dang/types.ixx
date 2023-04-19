/**
 * Dang Programming Language type aliases.
 * @author danixdev1205
 */
export module dang:types;


import std;
import trilean;


export
/** Dang Programming Language Visual C++23 Translation Libraries. */
namespace dang
{
    /**
     * Dang Boolean.
     * @details @n Stores one of two binary logic values: true or false.
     */
    using boolean = bool;

    /**
     * Dang Trilean.
     * @details @n Stores one of three ternary logic values: true, false or unsure.
     */
    using trilean = trilean;

    /**
     * Dang Integer.
     * @details @n Stores an integral value.
     */
    using integer = int64_t;

    /**
     * Dang Decimal.
     * @details @n Stores a fractional value.
     */
    using decimal = double_t;

    /**
     * Dang Symbol.
     * @details @n Stores a single character.
     */
    using symbol = wchar_t;

    /**
     * Dang String.
     * @details @n Stores a sequence character.
     */
    using string = std::wstring;

    /**
     * Dang Array.
     * @tparam T Dang primitive type.
     * @details @n Stores a sequence of values.
     */
    template <typename T>
    using array = std::vector<T>;
}
