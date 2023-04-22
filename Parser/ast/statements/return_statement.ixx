/**
 * Dang Programming Language Abstract Syntax return statement component.
 * @author danixdev1205
 */
export module dang.ast.statements:return_statement;


import "statement.hxx";
import dang.ast.expressions;


export
/** Dang Programming Language Abstract Syntax Tree. */
namespace dang::ast
{
    /** AST return statement component. */
    class return_statement final : public statement
    {
    public:
        /**
         * Initializes new AST return statement.
         * @param expression AST expression.
         */
        explicit return_statement(const expression* const expression)
            : expression_(expression)
        {
        }


        /** AST return statement destructor. */
        ~return_statement() override { delete expression_; }

    private:
        /** AST expression. */
        const expression* const expression_;


        /** Outputs return statement to a wide character output stream. */
        [[nodiscard]]
        std::wostream& out(std::wostream& os) const override { return os << "return " << *expression_ << ";"; }
    };
}
