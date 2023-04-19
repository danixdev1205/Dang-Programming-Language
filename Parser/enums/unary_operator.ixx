/**
 * Dang Programming Language Enumerations for unary expression.
 * @author danixdev1205
 */
export module dang.enums:unary_operator;


import std;


export
/** Dang Programming Language Enumerations. */
namespace dang::enums
{
    /** Unary expression operator. */
    enum struct unary_operator final : uint8_t
    {
        /** @code + @endcode */
        plus,

        /** @code - @endcode */
        minus,

        /** @code not @endcode */
        keyword_not
    };


    /**
     * Unary operator to a wide character string.
     * @param value Unary operator.
     */
    [[nodiscard]]
    std::wstring to_wstring(const unary_operator value)
    {
        switch (value)
        {
        case unary_operator::plus:
            return L"+";
        case unary_operator::minus:
            return L"-";
        case unary_operator::keyword_not:
            return L"!";

        default:
            return L"unary_operator";
        }
    }
}
