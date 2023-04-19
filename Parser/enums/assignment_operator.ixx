/**
 * Dang Programming Language Enumerations for binary expression.
 * @author danixdev1205
 */
export module dang.enums:assignment_operator;


import std;


export
/** Dang Programming Language Enumerations. */
namespace dang::enums
{
    /** Assignment statement operator. */
    enum struct assignment_operator final : uint8_t
    {
        /** @code = @endcode */
        equals,
        
        /** @code += @endcode */
        plus_equals,

        /** @code -= @endcode */
        minus_equals,

        /** @code *= @endcode */
        asterisk_equals,

        /** @code /= @endcode */
        slash_equals,

        /** @code %= @endcode */
        modulus_equals
    };


    /**
     * Assignment operator to a wide character string.
     * @param value Assignment operator.
     */
    [[nodiscard]]
    std::wstring to_wstring(const assignment_operator value)
    {
        switch (value)
        {
        case assignment_operator::equals:
            return L"=";
        case assignment_operator::plus_equals:
            return L"+=";
        case assignment_operator::minus_equals:
            return L"-=";
        case assignment_operator::asterisk_equals:
            return L"*=";
        case assignment_operator::slash_equals:
            return L"/=";
        case assignment_operator::modulus_equals:
            return L"%=";

        default:
            return L"assignment_operator";
        }
    }
}
