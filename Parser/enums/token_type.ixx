﻿/**
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

        /** @code += @endcode */
        operator_plus_equals,

        /** @code - @endcode */
        operator_minus,

        /** @code -> @endcode */
        operator_arrow,
        
        /** @code -= @endcode */
        operator_minus_equals,

        /** @code * @endcode */
        operator_asterisk,

        /** @code *= @endcode */
        operator_asterisk_equals,

        /** @code / @endcode */
        operator_slash,

        /** @code /= @endcode */
        operator_slash_equals,

        /** @code % @endcode */
        operator_modulus,

        /** @code %= @endcode */
        operator_modulus_equals,

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

        /** @code : @endcode */
        operator_colon,

#pragma endregion

#pragma region Containers

        /** @code ( @endcode */
        container_paren_left,

        /** @code ) @endcode */
        container_paren_right,

        /** @code { @endcode */
        container_brace_left,

        /** @code } @endcode */
        container_brace_right,

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
         * Print keyword.
         * @code print @endcode
         */
        keyword_println,

        /**
         * Print keyword.
         * @code print @endcode
         */
        keyword_read,
        
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

        /**
         * Constant declaration.
         * @code const @endcode
         */
        keyword_const,

        /**
         * If statement.
         * @code if @endcode
         */
        keyword_if,

        /**
         * Else statement.
         * @code else @endcode
         */
        keyword_else,

        /**
         * While statement.
         * @code while @endcode
         */
        keyword_while,

        /**
         * Do statement.
         * @code do @endcode
         */
        keyword_do,

        /**
         * For statement.
         * @code for @endcode
         */
        keyword_for,

        /**
         * Loop break statement.
         * @code break @endcode
         */
        keyword_break,

        /**
         * Loop skip iteration statement.
         * @code continue @endcode
         */
        keyword_continue,
        
        /**
         * Return statement.
         * @code return @endcode
         */
        keyword_return,

        /**
         * Program termination statement.
         * @code exit @endcode
         */
        keyword_exit,

        /**
         * Function declaration statement.
         * @code func @endcode
         */
        keyword_func,
        
#pragma endregion

        comma,

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
        case token_type::operator_arrow:
            return L"->";
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
        case token_type::container_brace_left:
            return L"{";
        case token_type::container_brace_right:
            return L"}";
            
        case token_type::comma:
            return L",";

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
        case token_type::keyword_const:
            return L"const";
        case token_type::keyword_if:
            return L"if";
        case token_type::keyword_else:
            return L"else";
        case token_type::keyword_while:
            return L"while";
        case token_type::keyword_do:
            return L"do";
        case token_type::keyword_for:
            return L"for";
        case token_type::keyword_break:
            return L"break";
        case token_type::keyword_continue:
            return L"continue";
        case token_type::keyword_return:
            return L"return";
        case token_type::keyword_exit:
            return L"exit";

        case token_type::identifier:
            return L"identifier";

        case token_type::end_of_file:
            return L"EOF";

        default:
            return L"token_type";
        }
    }
}
