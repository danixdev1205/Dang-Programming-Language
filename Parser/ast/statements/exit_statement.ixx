/**
 * Dang Programming Language Abstract Syntax exit statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:exit_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST exit statement component. */
    class exit_statement final : public statement
    {
    public:
        /**
         * Initializes new AST exit statement.
         * @param expression AST expression.
         */
        explicit exit_statement(const expression* const expression)
            : expression_(expression)
        {
        }


        /** AST exit statement destructor. */
        ~exit_statement() override { delete expression_; }

    private:
        /** AST expression. */
        const expression* const expression_;


        /** Outputs exit statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "exit(" << *expression_ << ");"; }
    };
}
