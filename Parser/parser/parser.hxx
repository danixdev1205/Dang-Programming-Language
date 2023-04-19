import "token.hxx";
import dang.ast;
import dang.enums;
import dang;


/** Dang Programming Language. */
export namespace dang
{
    /** Interpreted element parser. */
    class parser final
    {
        using enum enums::token_type;

    public:
        /**
         * Initializes new interpreted element parser.
         * @param tokens Vector of interpreted elements.
         */
        [[nodiscard]]
        explicit parser(const std::shared_ptr<std::vector<const token*>>& tokens)
            : tokens_(tokens),
              count_(tokens->size())
        {
        }


        /**
         * Parses interpreted elements.
         * @return Runnable block statement.
         */
        [[nodiscard]]
        const ast::block_statement* parse()
        {
            const auto block = new ast::block_statement();

            while (*get() != end_of_file)
                block->emplace(statement());

            return block;
        }

    private:
        /** Vector of interpreted elements. */
        const std::shared_ptr<std::vector<const token*>> tokens_;

        /** Count of interpreted elements. */
        const size_t count_ = 0;


        /** Current interpreted element index. */
        size_t index_ = 0;


#pragma region Recursive Descent

        /** Generates expression. */
        [[nodiscard]]
        const ast::statement* statement()
        {
            if (match(keyword_print))
                return new ast::print_statement(expression());

            throw;
        }

        /** Generates expression. */
        [[nodiscard]]
        const ast::expression* expression() { return primary(); }

        /** Generates primary expression. */
        [[nodiscard]]
        const ast::expression* primary()
        {
            const auto cur = get();

            if (match(literal_logical_false))
                return new ast::value_expression(new ast::boolean_value(false));
            if (match(literal_logical_true))
                return new ast::value_expression(new ast::boolean_value(false));
            if (match(literal_integer))
                return new ast::value_expression(new ast::integer_value(cur->read<integer>()));
            if (match(literal_decimal))
                return new ast::value_expression(new ast::decimal_value(cur->read<decimal>()));
            if (match(literal_symbol))
                return new ast::value_expression(new ast::symbol_value(cur->read<symbol>()));
            if (match(literal_string))
                return new ast::value_expression(new ast::string_value(cur->read<string>()));

            throw;
        }

#pragma endregion


        /**
         * Compares current interpreted element type with the given type. Moves index forward if types match.
         * @param type Interpreted element type to match.
         */
        void skip(const enums::token_type type)
        {
            if (*get() != type)
                throw;

            index_++;
        }

        /**
         * Compares current interpreted element type with the given type. Moves index forward if types match.
         * @param type Interpreted element type to match.
         * @return Whether the types match.
         */
        bool match(const enums::token_type type)
        {
            if (*get() != type)
                return false;

            index_++;

            return true;
        }

        /**
         * Compares interpreted element at index with the given type.
         * @param type Interpreted element type to match.
         * @param index Index of the interpreted element.
         * @return Whether the types match.
         */
        [[nodiscard]]
        bool look(const enums::token_type type, const size_t index) const { return *get(index) == type; }

        /**
         * Consumes current interpreted element if the type matches.
         * @param type Interpreted element to match.
         * @return Current interpreted element.
         */
        const token* consume(const enums::token_type type)
        {
            const auto cur = get();

            if (*cur != type)
                throw;

            index_++;

            return cur;
        }

        /**
         * Gets a character from the source Dang code.
         * @param offset Offset from the index.
         * @return Character in index.
         */
        [[nodiscard]]
        const token* get(const size_t offset = 0) const
        {
            const size_t index = index_ + offset;

            if (index >= count_)
                return new token(enums::token_type::end_of_file, {tokens_->back()->line() + 1, 1});

            return (*tokens_)[index];
        }
    };
}
