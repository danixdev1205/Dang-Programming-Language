/**
 * Dang Programming Language Enumerations for binary expression.
 * @author danixdev1205
 */
export module dang.enums:binary_operator;


import std;


export
/** Dang Programming Language Enumerations. */
namespace dang::enums
{
    /** Binary expression operator. */
    enum struct binary_operator final : uint8_t
    {
        /** @code + @endcode */
        plus,

        /** @code - @endcode */
        minus,

        /** @code * @endcode */
        asterisk,

        /** @code / @endcode */
        slash,

        /** @code % @endcode */
        modulus,

        /** @code == @endcode */
        equals_equals,

        /** @code != @endcode */
        exclamation_equals,

        /** @code < @endcode */
        less,

        /** @code <= @endcode */
        less_equals,

        /** @code > @endcode */
        greater,

        /** @code >= @endcode */
        greater_equals,

        /** @code and @endcode */
        keyword_and,

        /** @code or @endcode */
        keyword_or,

        /** @code xor @endcode */
        keyword_xor
    };


    /**
     * Binary operator to a wide character string.
     * @param value Binary operator.
     */
    [[nodiscard]]
    std::wstring to_wstring(const binary_operator value)
    {
        switch (value)
        {
        case binary_operator::plus:
            return L"+";
        case binary_operator::minus:
            return L"-";
        case binary_operator::asterisk:
            return L"*";
        case binary_operator::slash:
            return L"/";
        case binary_operator::modulus:
            return L"%";;
        case binary_operator::equals_equals:
            return L"==";
        case binary_operator::exclamation_equals:
            return L"!=";
        case binary_operator::less:
            return L"<";
        case binary_operator::less_equals:
            return L"<=";
        case binary_operator::greater:
            return L">";
        case binary_operator::greater_equals:
            return L">=";
        case binary_operator::keyword_and:
            return L"&&";
        case binary_operator::keyword_or:
            return L"||";
        case binary_operator::keyword_xor:
            return L"^";

        default:
            return L"binary_operator";
        }
    }
}
