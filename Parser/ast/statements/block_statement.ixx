/**
 * Dang Programming Language Abstract Syntax block statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:block_statement;


import "statement.hxx";


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST block statement component. */
    class block_statement final : public statement
    {
    public:
        /** Initializes new AST (empty) block statement. */
        explicit block_statement() = default;

        /**
         * Initializes new AST block statement.
         * @param block Block of AST statements.
         */
        explicit block_statement(const std::vector<const statement*>& block)
            : block_(block)
        {
        }


        /** Executes every statement in the block. */
        void emplace(const statement* const statement) { block_.emplace_back(statement); }

    private:
        /** Block of AST statements. */
        std::vector<const statement*> block_;


        /** Outputs block statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override
        {
            os << "{\n";
            for (const auto statement : block_)
                os << *statement << '\n';

            return os << "}";
        }
    };
}
