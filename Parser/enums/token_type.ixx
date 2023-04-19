/**
 * Dang Programming Language Enumerations for parsing.
 * @author danixdev1205
 */
export module dang.enums:token_type;


import std;


/** Dang Programming Language Enumerations. */
export namespace dang::enums
{
    /** Interpreted element type. */
    enum struct token_type final : uint8_t
    {
#pragma region Operators

        /** @code + @endcode */
        operator_plus,

        /** @code - @endcode */
        operator_minus,

        /** @code * @endcode */
        operator_asterisk,

        /** @code ** @endcode */
        operator_asterisk_asterisk,

        /** @code / @endcode */
        operator_slash,

        /** @code // @endcode */
        operator_slash_slash,

        /** @code % @endcode */
        operator_modulus,

        /** @code = @endcode */
        operator_equals,

        /** @code == @endcode */
        operator_equals_equals,

        /** @code != @endcode */
        operator_exclamation_equals,

        /** @code < @endcode */
        operator_less,

        /** @code <= @endcode */
        operator_less_equals,

        /** @code > @endcode */
        operator_greater,

        /** @code >= @endcode */
        operator_greater_equals,

        /** @code ? @endcode */
        operator_question,

        /** @code ?? @endcode */
        operator_question_question,

        /** @code : @endcode */
        operator_colon,

#pragma endregion

#pragma region Containers

        /** @code ( @endcode */
        container_paren_left,

        /** @code ) @endcode */
        container_paren_right,

#pragma endregion

#pragma region Literals

        /**
         * Null literal.
         * @code null @endcode
         */
        literal_null,

        /**
         * Logical literal.
         * @code false @endcode
         */
        literal_logical_false,

        /**
         * Logical literal.
         * @code unsure @endcode
         */
        literal_logical_unsure,

        /**
         * Logical literal.
         * @code true @endcode
         */
        literal_logical_true,

        /**
         * Integral number literal.
         * @code 42 @endcode
         */
        literal_integer,

        /**
         * Decimal number literal.
         * @code 36.6 @endcode
         */
        literal_decimal,

        /**
         * Symbol literal.
         * @code 'a' @endcode
         */
        literal_symbol,

        /**
         * String literal.
         * @code "Hello, world!" @endcode
         */
        literal_string,

#pragma endregion

#pragma region Keywords

        /**
         * Print keyword.
         * @code print @endcode
         */
        keyword_print,

        /**
         * Logical inverse.
         * @code not @endcode
         */
        keyword_not,

        /**
         * Logical and.
         * @code and @endcode
         */
        keyword_and,

        /**
         * Logical or.
         * @code or @endcode
         */
        keyword_or,

        /**
         * Logical exclusive or.
         * @code xor @endcode
         */
        keyword_xor,

        /**
         * Logical implication.
         * @code imp @endcode
         */
        keyword_imp,

        /**
         * Variable declaration.
         * @code var @endcode
         */
        keyword_var,

#pragma endregion

        /** User-defined identifier. */
        identifier,

        /** End of file. */
        end_of_file
    };


    /**
     * Converts interpreted element type to a wide character string.
     * @param value Interpreted element type.
     */
    [[nodiscard]]
    std::wstring to_wstring(const token_type value)
    {
        switch (value)
        {
        case token_type::operator_plus:
            return L"+";
        case token_type::operator_minus:
            return L"-";
        case token_type::operator_asterisk:
            return L"*";
        case token_type::operator_slash:
            return L"/";
        case token_type::operator_modulus:
            return L"%";
        case token_type::operator_equals:
            return L"=";
        case token_type::operator_equals_equals:
            return L"==";
        case token_type::operator_exclamation_equals:
            return L"!=";
        case token_type::operator_less:
            return L"<";
        case token_type::operator_less_equals:
            return L"<=";
        case token_type::operator_greater:
            return L">";
        case token_type::operator_greater_equals:
            return L">=";
        case token_type::operator_question:
            return L"?";
        case token_type::operator_colon:
            return L":";

        case token_type::container_paren_left:
            return L"(";
        case token_type::container_paren_right:
            return L")";

        case token_type::literal_null:
            return L"null";
        case token_type::literal_logical_false:
            return L"false";
        case token_type::literal_logical_unsure:
            return L"unsure";
        case token_type::literal_logical_true:
            return L"true";
        case token_type::literal_integer:
            return L"integer literal";
        case token_type::literal_decimal:
            return L"decimal literal";
        case token_type::literal_symbol:
            return L"symbol literal";
        case token_type::literal_string:
            return L"string literal";

        case token_type::keyword_print:
            return L"print";
        case token_type::keyword_not:
            return L"not";
        case token_type::keyword_and:
            return L"and";
        case token_type::keyword_or:
            return L"or";
        case token_type::keyword_xor:
            return L"xor";
        case token_type::keyword_imp:
            return L"imp";
        case token_type::keyword_var:
            return L"var";

        case token_type::identifier:
            return L"identifier";

        case token_type::end_of_file:
            return L"EOF";

        default:
            return L"token_type";
        }
    }
}
