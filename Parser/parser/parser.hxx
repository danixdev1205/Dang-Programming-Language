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
         * @return Entry point.
         */
        [[nodiscard]]
        const ast::entry_statement* parse()
        {
            const auto block = new ast::entry_statement();

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

        /** Generates statement. */
        [[nodiscard]]
        const ast::statement* statement()
        {
            if (match(keyword_print))
                return new ast::print_statement(expression());
            if (match(keyword_var))
            {
                const auto name = consume(identifier);
                const token* type = nullptr;

                if (match(operator_colon))
                    type = consume(identifier);

                skip(operator_equals);

                return new ast::variable_statement(expression(), name->value(),
                                                   type == nullptr ? L"auto" : type->value());
            }
            if (match(keyword_const))
            {
                const auto name = consume(identifier);
                const token* type = nullptr;

                if (match(operator_colon))
                    type = consume(identifier);

                skip(operator_equals);

                return new ast::constant_statement(expression(), name->value(),
                                                   type == nullptr ? L"auto" : type->value());
            }
            if (match(keyword_else))
                return new ast::else_statement(body());
            if (match(keyword_break))
                return new ast::break_statement();
            if (match(keyword_continue))
                return new ast::continue_statement();
            if (match(keyword_return))
                return new ast::return_statement(expression());
            if (match(keyword_exit))
                return new ast::exit_statement(expression());
            
            return assignment_statement();
        }

        /** Generates assignment statement. */
        [[nodiscard]]
        const ast::statement* assignment_statement()
        {
            using enum enums::assignment_operator;

            const auto cur = get();

            if (match(identifier))
            {
                if (match(operator_equals))
                    return new ast::assignment_statement(expression(), cur->value(), equals);
                if (match(operator_plus_equals))
                    return new ast::assignment_statement(expression(), cur->value(), plus_equals);
                if (match(operator_minus_equals))
                    return new ast::assignment_statement(expression(), cur->value(), minus_equals);
                if (match(operator_asterisk_equals))
                    return new ast::assignment_statement(expression(), cur->value(), asterisk_equals);
                if (match(operator_slash_equals))
                    return new ast::assignment_statement(expression(), cur->value(), slash_equals);
                if (match(operator_modulus_equals))
                    return new ast::assignment_statement(expression(), cur->value(), modulus_equals);

                throw;
            }

            return flow_control();
        }

        /** Generates if, while, do-while and for statements. */
        [[nodiscard]]
        const ast::statement* flow_control()
        {
            if (match(keyword_if))
            {
                const auto cond = expression();                
                return new ast::if_statement(cond, body());
            }
            if (match(keyword_do))
            {
                const auto loop = body();
                skip(keyword_while);

                return new ast::do_statement(expression(), loop);
            }
            if (match(keyword_while))
            {
                const auto cond = expression();
                return new ast::while_statement(cond, body());
            }
            if (match(keyword_for))
            {
                const auto init = statement();
                const auto cond = expression();
                const auto modi = statement();
                return new ast::for_statement(init, cond, modi, body());
            }

            throw;
        }

        /** Generates block statement or a single statement. */
        [[nodiscard]]
        const ast::statement* body()
        {
            if (match(container_brace_left))
            {
                const auto block = new ast::block_statement();

                while (*get() != container_brace_right)
                    block->emplace(statement());

                skip(container_brace_right);
                return block;
            }

            return statement();
        }

        /** Generates expression. */
        [[nodiscard]]
        const ast::expression* expression() { return binary_and(); }

        /**
         * Generates binary logical and expression.
         * @details @n Handles binary logical 'and'.
         */
        [[nodiscard]]
        const ast::expression* binary_and()
        {
            auto expr = binary_or();

            while (true)
            {
                if (match(keyword_and))
                {
                    expr = new ast::binary_expression(expr, binary_or(), enums::binary_operator::keyword_and);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates binary logical or expression.
         * @details @n Handles binary logical 'or'.
         */
        [[nodiscard]]
        const ast::expression* binary_or()
        {
            auto expr = binary_xor();

            while (true)
            {
                if (match(keyword_or))
                {
                    expr = new ast::binary_expression(expr, binary_xor(), enums::binary_operator::keyword_or);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates binary logical exclusive or expression.
         * @details @n Handles binary logical exclusive 'xor'.
         */
        [[nodiscard]]
        const ast::expression* binary_xor()
        {
            auto expr = binary_comparison();

            while (true)
            {
                if (match(keyword_xor))
                {
                    expr = new ast::binary_expression(expr, binary_comparison(), enums::binary_operator::keyword_xor);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates binary comparison expression.
         * @details @n Handles binary comparison '==' and '!='.
         */
        [[nodiscard]]
        const ast::expression* binary_comparison()
        {
            using enum enums::binary_operator;

            auto expr = binary_relational();

            while (true)
            {
                if (match(operator_equals_equals))
                {
                    expr = new ast::binary_expression(expr, binary_relational(), equals_equals);
                    continue;
                }
                if (match(operator_exclamation_equals))
                {
                    expr = new ast::binary_expression(expr, binary_relational(), exclamation_equals);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates binary relational expression.
         * @details @n Handles binary relational '<', '<=', '>' and '>='.
         */
        [[nodiscard]]
        const ast::expression* binary_relational()
        {
            using enum enums::binary_operator;

            auto expr = binary_additive();

            while (true)
            {
                if (match(operator_less))
                {
                    expr = new ast::binary_expression(expr, binary_additive(), less);
                    continue;
                }
                if (match(operator_less_equals))
                {
                    expr = new ast::binary_expression(expr, binary_additive(), less_equals);
                    continue;
                }
                if (match(operator_greater))
                {
                    expr = new ast::binary_expression(expr, binary_additive(), greater);
                    continue;
                }
                if (match(operator_greater_equals))
                {
                    expr = new ast::binary_expression(expr, binary_additive(), greater_equals);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates binary additive expression.
         * @details @n Handles binary operators '+' and '-'.
         */
        [[nodiscard]]
        const ast::expression* binary_additive()
        {
            using enum enums::binary_operator;

            auto expr = binary_multiplicative();

            while (true)
            {
                if (match(operator_plus))
                {
                    expr = new ast::binary_expression(expr, binary_multiplicative(), plus);
                    continue;
                }
                if (match(operator_minus))
                {
                    expr = new ast::binary_expression(expr, binary_multiplicative(), minus);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates binary multiplicative expression.
         * @details @n Handles binary multiplicative '*', '/' and '%'.
         */
        [[nodiscard]]
        const ast::expression* binary_multiplicative()
        {
            using enum enums::binary_operator;

            auto expr = unary();

            while (true)
            {
                if (match(operator_asterisk))
                {
                    expr = new ast::binary_expression(expr, unary(), asterisk);
                    continue;
                }
                if (match(operator_slash))
                {
                    expr = new ast::binary_expression(expr, unary(), slash);
                    continue;
                }
                if (match(operator_modulus))
                {
                    expr = new ast::binary_expression(expr, unary(), modulus);
                    continue;
                }

                break;
            }

            return expr;
        }

        /**
         * Generates unary expression.
         * @details @n Handles unary operators '+', '-' and 'not'.
         */
        [[nodiscard]]
        const ast::expression* unary()
        {
            using enum enums::unary_operator;

            if (match(operator_plus))
                return new ast::unary_expression(primary(), plus);
            if (match(operator_minus))
                return new ast::unary_expression(primary(), minus);
            if (match(enums::token_type::keyword_not))
                return new ast::unary_expression(primary(), keyword_not);

            return primary();
        }

        /** Generates primary expression. */
        [[nodiscard]]
        const ast::expression* primary()
        {
            const auto cur = get();

            if (match(literal_logical_false))
                return new ast::value_expression(new ast::boolean_value(false));
            if (match(literal_logical_true))
                return new ast::value_expression(new ast::boolean_value(true));
            if (match(literal_integer))
                return new ast::value_expression(new ast::integer_value(cur->read<integer>()));
            if (match(literal_decimal))
                return new ast::value_expression(new ast::decimal_value(cur->read<decimal>()));
            if (match(literal_symbol))
                return new ast::value_expression(new ast::symbol_value(cur->read<symbol>()));
            if (match(literal_string))
                return new ast::value_expression(new ast::string_value(cur->read<string>()));

            if (match(identifier))
                return new ast::variable_expression(cur->value());

            if (match(container_paren_left))
            {
                const auto expr = expression();
                skip(container_paren_right);

                return expr;
            }

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
         * @param offset Index of the interpreted element.
         * @return Whether the types match.
         */
        [[nodiscard]]
        bool look(const enums::token_type type, const size_t offset = 1) const { return *get(offset) == type; }

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
