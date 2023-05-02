import "token.hxx";
import dang.enums;


/** Dang Programming Language. */
export namespace dang
{
    /** Lexical analyzer. */
    class lexer final
    {
    public:
        using enum enums::token_type;


        /**
         * Initializes lexical analyzer.
         * @param source Source Dang code.
         */
        [[nodiscard]]
        explicit lexer(const std::wstring_view& source)
            : source_(source),
              length_(source_.length())
        {
        }


        /**
         * Interpreters source Dang code into a vector of interpreted elements.
         * @return Vector of interpreted elements.
         */
        [[nodiscard]]
        std::shared_ptr<std::vector<const token*>> tokenize()
        {
            while (caret_ <= length_)
            {
                switch (const wchar_t cur = peek())
                {
#pragma region Operators

                case L'+':
                    switch (next())
                    {
                    case L'=':
                        add(operator_plus_equals, line_, column_ - 1);
                        break;
                    default:
                        add(operator_plus, line_, column_);
                        continue;
                    }
                    break;

                case L'-':
                    switch (next())
                    {
                    case L'=':
                        add(operator_minus_equals, line_, column_ - 1);
                        break;
                    case L'>':
                        add(operator_arrow, line_, column_ - 1);
                        break;
                    default:
                        add(operator_minus, line_, column_);
                        continue;
                    }
                    break;

                case L'*':
                    switch (next())
                    {
                    case L'=':
                        add(operator_asterisk_equals, line_, column_ - 1);
                        break;
                    default:
                        add(operator_asterisk, line_, column_);
                        continue;
                    }
                    break;

                case L'/':
                    if (column_ == 1 && peek(1) == L'/')
                        tokenize_comment(false);
                    else if (peek(1) == L'*')
                        tokenize_comment(true);
                    else
                        switch (next())
                        {
                        case L'=':
                            add(operator_slash_equals, line_, column_ - 1);
                            break;
                        default:
                            add(operator_slash, line_, column_);
                            continue;
                        }
                    break;

                case L'%':
                    switch (next())
                    {
                    case L'=':
                        add(operator_modulus_equals, line_, column_ - 1);
                        break;
                    default:
                        add(operator_modulus, line_, column_);
                        continue;
                    }
                    break;

                case L'=':
                    switch (next())
                    {
                    case L'=':
                        add(operator_equals_equals, line_, column_ - 1);
                        break;
                    default:
                        add(operator_equals, line_, column_);
                        continue;
                    }
                    break;

                case L'!':
                    switch (next())
                    {
                    case L'=':
                        add(operator_exclamation_equals, line_, column_ - 1);
                        break;
                    }
                    break;

                case L'<':
                    switch (next())
                    {
                    case L'=':
                        add(operator_less_equals, line_, column_ - 1);
                        break;
                    default:
                        add(operator_less, line_, column_);
                        continue;
                    }
                    break;

                case L'>':
                    switch (next())
                    {
                    case L'=':
                        add(operator_greater_equals, line_, column_ - 1);
                        break;
                    default:
                        add(operator_greater, line_, column_);
                        continue;
                    }
                    break;

                case L'?':
                    add(operator_question, line_, column_);
                    break;

                case L':':
                    add(operator_colon, line_, column_);
                    break;

#pragma endregion

                case L'(':
                    add(container_paren_left, line_, column_);
                    break;
                case L')':
                    add(container_paren_right, line_, column_);
                    break;

                case L'{':
                    add(container_brace_left, line_, column_);
                    break;
                case L'}':
                    add(container_brace_right, line_, column_);
                    break;

                case L',':
                    add(comma, line_, column_);
                    break;

                case L'"':
                    tokenize_string(line_, column_);
                    continue;

                case L'\'':
                    tokenize_symbol(line_, column_);
                    continue;

                default:
                    if (iswalpha(cur))
                    {
                        tokenize_keyword(line_, column_);
                        continue;
                    }
                    if (iswdigit(cur) || (cur == L'.' && iswdigit(peek(1))))
                    {
                        tokenize_number(line_, column_);
                        continue;
                    }

                    break;
                }

                next();
            }

            return std::make_shared<std::vector<const token*>>(tokens_);
        }

    private:
        /** Source Dang code. */
        const std::wstring_view source_;

        /** Length of source Dang code. */
        const size_t length_ = 0;


        /** Current caret position in the source code. */
        size_t caret_ = 0;

        /** Current caret position in the source code file. */
        size_t line_ = 1, column_ = 1;

        /** Vector of interpreted elements. */
        std::vector<const token*> tokens_{};


#pragma region tokenization

        /** Skips comment segment in the Dang source code file. */
        void tokenize_comment(const bool multiline)
        {
            next();
            next();

            wchar_t cur = peek();

            if (!multiline)
            {
                while (cur != L'\n' && cur != L'\r' && cur != L'\0')
                    cur = next();

                return;
            }

            while (true)
            {
                if (cur == L'\0')
                    throw;

                if (cur == L'*' && peek(1) == L'/')
                    break;

                cur = next();
            }

            next();
            next();
        }

        /**
         * Creates a keyword or an identifier interpreted element.
         * @param line Interpreted element start line.
         * @param column Interpreted element start column.
         */
        void tokenize_keyword(const size_t line, const size_t column)
        {
            std::wstringstream buf;
            wchar_t cur = peek();

            while (iswalnum(cur) || cur == L'_')
            {
                buf << cur;
                cur = next();
            }

            if (const auto res = buf.str(); res == L"print")
                add(keyword_print, line, column);
            else if (res == L"null")
                add(literal_null, line, column);
            else if (res == L"true")
                add(literal_logical_true, line, column);
            else if (res == L"unsure")
                add(literal_logical_unsure, line, column);
            else if (res == L"false")
                add(literal_logical_false, line, column);
            else if (res == L"not")
                add(keyword_not, line, column);
            else if (res == L"and")
                add(keyword_and, line, column);
            else if (res == L"or")
                add(keyword_or, line, column);
            else if (res == L"xor")
                add(keyword_xor, line, column);
            else if (res == L"imp")
                add(keyword_imp, line, column);
            else if (res == L"var")
                add(keyword_var, line, column);
            else if (res == L"const")
                add(keyword_const, line, column);
            else if (res == L"if")
                add(keyword_if, line, column);
            else if (res == L"else")
                add(keyword_else, line, column);
            else if (res == L"while")
                add(keyword_while, line, column);
            else if (res == L"do")
                add(keyword_do, line, column);
            else if (res == L"for")
                add(keyword_for, line, column);
            else if (res == L"break")
                add(keyword_break, line, column);
            else if (res == L"continue")
                add(keyword_continue, line, column);
            else if (res == L"return")
                add(keyword_return, line, column);
            else if (res == L"exit")
                add(keyword_exit, line, column);
            else if (res == L"func")
                add(keyword_func, line, column);
            else
                add(identifier, res, line, column);
        }

        /**
         * Creates an integer or a decimal interpreted element.
         * @param line Interpreted element start line.
         * @param column Interpreted element start column.
         */
        void tokenize_number(const size_t line, const size_t column)
        {
            std::wstringstream buf;
            wchar_t cur = peek();

            bool has_dot = false, invalid = false;

            while (true)
            {
                if (!iswdigit(cur))
                {
                    if (cur == L'\'')
                    {
                        cur = next();
                        continue;
                    }

                    if (cur != L'.')
                        break;

                    if (has_dot)
                        invalid = true;

                    has_dot = true;
                }

                buf << cur;
                cur = next();
            }

            if (invalid)
                throw;

            add(has_dot ? literal_decimal : literal_integer, buf.str(), line, column);
        }

        /**
         * Creates a string literal interpreted element.
         * @param line Interpreted element start line.
         * @param column Interpreted element start column.
         * @todo Escape sequences.
         * @bug Column brakes if string is multiline
         */
        void tokenize_string(const size_t line, const size_t column)
        {
            std::wstringstream buf;
            wchar_t cur = next();

            while (cur != L'"')
            {
                buf << cur;
                cur = next();
            }

            next();
            add(literal_string, buf.str(), line, column);
        }

        /**
         * Creates a symbol literal interpreted element.
         * @param line Interpreted element start line.
         * @param column Interpreted element start column.
         */ // ToDo: Escape sequences.
        void tokenize_symbol(const size_t line, const size_t column)
        {
            std::wstringstream buf;
            wchar_t cur = next();

            bool end = false;
            while (cur != L'\'')
            {
                buf << cur;

                if (end)
                    throw;

                cur = next();
                end = true;
            }

            next();
            add(literal_symbol, buf.str(), line, column);
        }

#pragma endregion


        /**
         * Adds new interpreted element.
         * @param type Interpreted element type.
         * @param value Interpreted element value.
         * @param line Interpreted element start line.
         * @param column Interpreted element start column.
         */
        void add(const enums::token_type type, const std::wstring& value, const size_t line, const size_t column)
        {
            tokens_.emplace_back(new token(type, value, {line, column}));
        }

        /**
         * Adds new interpreted element.
         * @param type Interpreted element type.
         * @param line Interpreted element start line.
         * @param column Interpreted element start column.
         */
        void add(const enums::token_type type, const size_t line, const size_t column)
        {
            tokens_.emplace_back(new token(type, {line, column}));
        }

        /**
         * Moves caret forward.
         * @return Character in the new position.
         */
        wchar_t next()
        {
            caret_++;
            column_++;

            const auto cur = peek();
            if (cur == '\n')
            {
                line_++;
                column_ = 0;
            }

            return cur;
        }

        /**
         * Peeks a character from the source Dang code.
         * @param offset Offset from the caret.
         * @return Character in index.
         */
        [[nodiscard]]
        wchar_t peek(const size_t offset = 0) const
        {
            const size_t index = caret_ + offset;

            if (index >= length_)
                return L'\0';

            return source_[index];
        }
    };
}
